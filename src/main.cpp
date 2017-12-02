#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <functions.h>
#include <configurations.h>

#define NZEROS 4
#define NPOLES 4
#define GAIN   1.509971716e+00

void TaskControlLightMode( void *pvParameters );
void TaskReadModeButton( void *pvParameters );
void TaskReadLightSensor( void *pvParameters );
void TaskBlink( void *pvParameters );

int light_mode = LIGHT_OFF;
int blink_mode = BLINK_OFF;
int press_duration = 0;

int intensity_mode = MODO_INTENSIDAD_NORMAL;

int short_press_flag = 0;
int blink_counter = 0;

int light_sensor_read = 0;
int light_sensor_read2 = 0;
int light_sensor_normalized_mapped = 0;
float light_sensor_filtered = 0;
float light_sensor_filtered_mapped = 0;

int battery_3_7_voltage = 0;


void setup() {
  
  Serial.begin(9600);
  
  /* Configuración de los pines de entrada y salida */
  pinMode(MODE_BUTTON, INPUT);
  pinMode(LED_PIN_FOCUS, OUTPUT);
  pinMode(LED_PIN_WIDE, OUTPUT);
  pinMode(LED_PIN_BATTERY_RED, OUTPUT);
  pinMode(LED_PIN_BATTERY_YELLOW, OUTPUT);
  pinMode(LED_PIN_BATTERY_GREEN, OUTPUT);

  /* Creación de las tareas */
  xTaskCreate(
    TaskControlLightMode
    ,  (const portCHAR *)"ControlLightMode"   
    ,  128  // Stack size
    ,  NULL
    ,  3    // Priority
    ,  NULL );

  xTaskCreate(
    TaskReadModeButton
    ,  (const portCHAR *) "ReadModeButton"
    ,  128   // Stack size
    ,  NULL
    ,  2     // Priority
    ,  NULL );

  xTaskCreate(
    TaskReadLightSensor
    ,  (const portCHAR *) "ReadLightSensor"
    ,  128  // Stack size
    ,  NULL
    ,  2    // Priority
    ,  NULL );

  xTaskCreate(
    TaskBlink
    ,  (const portCHAR *)"Blink"   
    ,  128  // Stack size
    ,  NULL
    ,  2    // Priority
    ,  NULL );


}

void loop()
{
  // Nada. La magia sucede en las tareas 
}

/* Tarea encargada de controlar la intensidad de los LEDs principales */
void TaskControlLightMode(void *pvParameters)  
{
  (void) pvParameters;
  
  for (;;) 
  {

    switch(light_mode)
     {
       case LIGHT_OFF:
         analogWrite(LED_PIN_FOCUS, 0);
         analogWrite(LED_PIN_WIDE, 0);
         blink_mode = BLINK_OFF;
         break;
       case LIGHT_ADAPTABLE:
         blink_mode = BLINK_BREATH;
          switch(intensity_mode)
          {
            case MODO_INTENSIDAD_CERCA:
              analogWrite(LED_PIN_FOCUS, PWM_CERCA );
              analogWrite(LED_PIN_WIDE, PWM_CERCA );
              break;
            case MODO_INTENSIDAD_NORMAL:
              analogWrite(LED_PIN_FOCUS, PWM_NORMAL );
              analogWrite(LED_PIN_WIDE, PWM_NORMAL );
              break;
            case MODO_INTENSIDAD_LEJOS:
              analogWrite(LED_PIN_FOCUS, PWM_LEJOS );
              analogWrite(LED_PIN_WIDE, PWM_LEJOS );
              break;
          }
         break;
       case LIGHT_WIDE:
         analogWrite(LED_PIN_WIDE, PWM_CERCA);
         analogWrite(LED_PIN_FOCUS, PWM_APAGADO);
         blink_mode = BLINK_SLOW;
         break;
       case LIGHT_FOCUS:
         analogWrite(LED_PIN_FOCUS, PWM_MAXIMO);
         analogWrite(LED_PIN_WIDE, PWM_APAGADO);
         blink_mode = BLINK_SLOW;
         break;
       case LIGHT_WIDE_AND_FOCUS:
         analogWrite(LED_PIN_FOCUS, PWM_LEJOS);
         analogWrite(LED_PIN_WIDE, PWM_LEJOS);
         blink_mode = BLINK_FAST;
         break;
       default:
         light_mode = LIGHT_OFF;
         break;
     }

    vTaskDelay( 100 / portTICK_PERIOD_MS ); 
  }
}

/* Tarea encargada de leer el botón de modo. 
 * Controla cuanto tiempo se mantuvo presionado el botón */
void TaskReadModeButton(void *pvParameters) 
{
  (void) pvParameters;
  
  pinMode(MODE_BUTTON, INPUT);

  for (;;)
  {
  if (!digitalRead(MODE_BUTTON))
  {
    press_duration++;
    if (press_duration == PRESS_DURATION_LONG)
    {
      light_mode = LIGHT_ADAPTABLE;
      short_press_flag = FALSE;
    }
    if(press_duration < PRESS_DURATION_SHORT)
    {
      short_press_flag = TRUE;
    }
  }
  else
  {
      if (short_press_flag == TRUE) 
      {
        if (light_mode <  CONT_MODE_LIGHT)
        {
          light_mode++;
        }
        else
        {
          light_mode = LIGHT_ADAPTABLE;  
        }
      }
      press_duration = 0;
      short_press_flag = FALSE;
  }
  

  check_battery_level(battery_3_7_voltage);

    vTaskDelay(1);
  }
}

/* Tarea encargada de leer el fototransistor. 
 * Además actualiza el estado que controla la intensidad de los LED  */
void TaskReadLightSensor(void *pvParameters) 
{
  (void) pvParameters;

  pinMode(7, INPUT);
  pinMode(8, INPUT);
  
  for (;;)
  {


    light_sensor_read = analogRead(A0);

    battery_3_7_voltage = analogRead(A1);

    /* Controlador de la máquina de estados para el control de la intensidad */
    check_brightness_level( light_sensor_read);

    vTaskDelay( 90 / portTICK_PERIOD_MS ); 
  }
}

/* Tarea encargada de realizar el parpadeo del led RGB */
void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  
  pinMode(LED_PIN_BLINK_BLUE, OUTPUT);
  pinMode(LED_PIN_BLINK_GREEN, OUTPUT);

  for (;;) 
  {
    switch(blink_mode)
    {
      case BLINK_OFF:
        analogWrite(LED_PIN_BLINK_BLUE, PWM_BLINK_OFF);
        analogWrite(LED_PIN_BLINK_GREEN, PWM_BLINK_OFF);
        break;
      case BLINK_SLOW:
        blink_counter++;
        if (blink_counter < BLINK_DURATION_SLOW) 
        {
          analogWrite(LED_PIN_BLINK_BLUE, PWM_BLINK_OFF);
          analogWrite(LED_PIN_BLINK_GREEN, PWM_BLINK_OFF);
        }
        if ( blink_counter == BLINK_DURATION_SLOW ) 
        {
          analogWrite(LED_PIN_BLINK_BLUE, PWM_BLINK_ON);
          analogWrite(LED_PIN_BLINK_GREEN, PWM_BLINK_ON);
        }
        if ( blink_counter > BLINK_DURATION_SLOW ) 
        {
          blink_counter = 0;
        }
        break;
      case BLINK_FAST:
        blink_counter++;
        if (blink_counter < BLINK_DURATION_FAST) 
        {
          analogWrite(LED_PIN_BLINK_BLUE, PWM_BLINK_OFF);
          analogWrite(LED_PIN_BLINK_GREEN, PWM_BLINK_OFF);
        }
        if ( blink_counter == BLINK_DURATION_FAST ) 
        {
          analogWrite(LED_PIN_BLINK_BLUE, PWM_BLINK_OFF);
          analogWrite(LED_PIN_BLINK_GREEN, PWM_BLINK_OFF);
        }
        if ( blink_counter > BLINK_DURATION_FAST ) 
        {
          blink_counter = 0;
        }
        break;
      case BLINK_BREATH:
        blink_counter++;
        if ( blink_counter <= 127 ) 
        {
          analogWrite(LED_PIN_BLINK_BLUE, 512 - blink_counter*2 );
          analogWrite(LED_PIN_BLINK_GREEN, 512 - blink_counter*2 );

        }
        if ( blink_counter > 127 && blink_counter < 255 ) 
        {
          analogWrite(LED_PIN_BLINK_BLUE,blink_counter*2);
          analogWrite(LED_PIN_BLINK_GREEN,blink_counter*2);
        }
        if ( blink_counter == 255 ) 
        {
          blink_counter = 0;
        }

        break;
    }

    vTaskDelay( 25 / portTICK_PERIOD_MS ); 
  }
}


