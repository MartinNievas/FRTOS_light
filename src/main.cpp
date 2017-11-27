#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <functions.h>

#define NZEROS 4
#define NPOLES 4
#define GAIN   1.509971716e+00

static float xv[NZEROS+1], yv[NPOLES+1];


void TaskControlLightMode( void *pvParameters );
void TaskReadModeButton( void *pvParameters );
void TaskReadLightSensor( void *pvParameters );
void TaskBlink( void *pvParameters );

int light_mode = LIGHT_OFF;
int blink_mode = BLINK_OFF;
int press_duration = 0;

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
  
  pinMode(LED_PIN_FOCUS, OUTPUT);
  pinMode(LED_PIN_WIDE, OUTPUT);
  pinMode(MODE_BUTTON, INPUT);

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
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tareas ---------------------*/
/*--------------------------------------------------*/

void TaskControlLightMode(void *pvParameters)  // This is a task.
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
         // analogWrite(LED_PIN_FOCUS, 255 - light_sensor_read);
         // analogWrite(LED_PIN_WIDE, 255 - light_sensor_read);
         analogWrite(LED_PIN_FOCUS, 255 - light_sensor_filtered_mapped);
         analogWrite(LED_PIN_WIDE, 255 - light_sensor_filtered_mapped);
         break;
       case LIGHT_WIDE:
         analogWrite(LED_PIN_WIDE, 255);
         analogWrite(LED_PIN_FOCUS, 0);
         blink_mode = BLINK_BREATH;
         break;
       case LIGHT_FOCUS:
         analogWrite(LED_PIN_FOCUS, 255);
         analogWrite(LED_PIN_WIDE, 0);
         blink_mode = BLINK_SLOW;
         break;
       case LIGHT_WIDE_AND_FOCUS:
         analogWrite(LED_PIN_FOCUS, 255);
         analogWrite(LED_PIN_WIDE, 255);
         blink_mode = BLINK_FAST;
         break;
       default:
         light_mode = LIGHT_OFF;
         break;
     }

    vTaskDelay( 100 / portTICK_PERIOD_MS ); 
  }
}

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
   
    vTaskDelay(1);
  }
}

void TaskReadLightSensor(void *pvParameters) 
{
  (void) pvParameters;

  pinMode(7, INPUT);
  pinMode(8, INPUT);
  
  for (;;)
  {


    light_sensor_read2 = analogRead(A0);
    // while (digitalRead(8) == 1 && digitalRead(7) == 1) {
    light_sensor_read = analogRead(A0);
    // }
    battery_3_7_voltage = analogRead(A1);
    light_sensor_normalized_mapped = map(light_sensor_read, 
                                         0, battery_3_7_voltage, 
                                         0, 255);

xv[0] = light_sensor_read2 / GAIN;
        yv[0] = yv[1]; yv[1] = yv[2]; yv[2] = yv[3]; yv[3] = yv[4]; 
        yv[4] =   xv[0]
                     + ( -0.2247842916 * yv[0]) + (  1.2272168645 * yv[1])
                     + ( -2.5933688894 * yv[2]) + (  2.5404665013 * yv[3]);
        light_sensor_filtered = yv[4];
    light_sensor_filtered_mapped = map(light_sensor_filtered, 
                                         0, 8000, 
                                         0, 255);


    Serial.print(light_sensor_read);
    Serial.print("\t");
    // Serial.print(light_sensor_read2);
    // Serial.print("\t");
    Serial.print(light_sensor_filtered_mapped);
    Serial.print("\t");
    Serial.print(battery_3_7_voltage);
    Serial.print("\t");
    Serial.print(light_sensor_normalized_mapped);
    Serial.print("\n");
    
    vTaskDelay( 90 / portTICK_PERIOD_MS ); 
  }
}

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
        analogWrite(LED_PIN_BLINK_BLUE,255);
        analogWrite(LED_PIN_BLINK_GREEN,255);
        break;
      case BLINK_SLOW:
        blink_counter++;
        if (blink_counter<10) 
        {
          analogWrite(LED_PIN_BLINK_BLUE,255);
          analogWrite(LED_PIN_BLINK_GREEN,255);
        }
        if ( blink_counter >= 10 && blink_counter < 11 ) 
        {
          analogWrite(LED_PIN_BLINK_BLUE,0);
          analogWrite(LED_PIN_BLINK_GREEN,0);
        }
        if ( blink_counter >= 11 ) 
        {
          blink_counter = 0;
        }
        break;
      case BLINK_FAST:
        blink_counter++;
        if (blink_counter<5) 
        {
          analogWrite(LED_PIN_BLINK_BLUE,255);
          analogWrite(LED_PIN_BLINK_GREEN,255);
        }
        if ( blink_counter >= 5 && blink_counter < 6 ) 
        {
          analogWrite(LED_PIN_BLINK_BLUE,0);
          analogWrite(LED_PIN_BLINK_GREEN,0);
        }
        if ( blink_counter >= 6 ) 
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
          // Serial.println(512 - blink_counter*2);

        }
        if ( blink_counter > 127 && blink_counter < 255 ) 
        {
          analogWrite(LED_PIN_BLINK_BLUE,blink_counter*2);
          analogWrite(LED_PIN_BLINK_GREEN,blink_counter*2);
          // Serial.println(blink_counter*2);
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


