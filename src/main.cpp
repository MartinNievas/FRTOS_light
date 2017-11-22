#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <Wire.h>
#include <functions.h>

void TaskBlink( void *pvParameters );
void TaskReadModeButton( void *pvParameters );
void TaskReadLightSensor( void *pvParameters );

int mode = 0;
int press_duration = 0;

int press_flag = 0;

int light_sensor_read = 0;
int light_sensor_read_mapped = 0;


void setup() {
  
  Serial.begin(9600);
  
  pinMode(WHITE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(MODE_BUTTON, INPUT);

  xTaskCreate(
    TaskBlink
    ,  (const portCHAR *)"Blink"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  xTaskCreate(
    TaskReadModeButton
    ,  (const portCHAR *) "AnalogRead"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );
  xTaskCreate(
    TaskReadLightSensor
    ,  (const portCHAR *) "AnalogRead"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tareas ---------------------*/
/*--------------------------------------------------*/

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  
  pinMode(LED_BUILTIN, OUTPUT);

  for (;;) 
  {

    switch(mode)
     {
     case LIGHT_DEFAULT:
         
         analogWrite(WHITE_LED_PIN, light_sensor_read);
         break;
       case LIGHT_LOW:
         analogWrite(WHITE_LED_PIN, 100);
         break;
       case LIGHT_HIGH:
         analogWrite(WHITE_LED_PIN, 255);
         break;
       case LIGHT_BATTERY_SAVE:
         analogWrite(WHITE_LED_PIN, 20);
  
         break;
       default:
         analogWrite(WHITE_LED_PIN, 0);
  
         break;
     }

    vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
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
    // Serial.println(press_duration);
    if (press_duration == 50)
    {
      mode = LIGHT_DEFAULT;
      press_flag = 0;
      // Serial.println("default");
    }
    if(press_duration < 10)
    {
      press_flag = 1;
    }
  }
  else
  {
      if (press_flag == 1) 
      {
        if (mode <  3)
        {
          mode++;
          // Serial.println("mode++");
        }
        else
          mode = LIGHT_DEFAULT;  
      }
      press_duration = 0;
      press_flag = 0;
  }
   
    vTaskDelay(1);
  }
}
void TaskReadLightSensor(void *pvParameters) 
{
  (void) pvParameters;
  
  for (;;)
  {
    light_sensor_read = analogRead(A0);
    light_sensor_read_mapped = map(light_sensor_read, 0, 1024, 0, 255);
    // Serial.print(light_sensor_read);
    // Serial.print("\t");
    // Serial.println(light_sensor_read_mapped);

    vTaskDelay(5);
  }
}
