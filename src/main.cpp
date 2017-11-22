#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <Wire.h>
#include <Kalman.h> 
#include <functions.h>

void TaskBlink( void *pvParameters );
void TaskReadModeButton( void *pvParameters );
void TaskReadLightSensor( void *pvParameters );

Kalman kalmanX; // Create the Kalman instances
Kalman kalmanY;

int mode = 0;
uint32_t timer;
int press_duration = 0;
uint8_t i2cData[14]; 
int press_flag = 0;

int light_sensor_read = 0;
int light_sensor_read_mapped = 0;

double accX, accY, accZ;
double gyroX, gyroY, gyroZ;
int16_t tempRaw;

double kalAngleX, kalAngleY; 



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
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  // initialize digital LED_BUILTIN on pin 13 as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {

    switch(mode)
     {
     case LIGHT_DEFAULT:
         // white_led_mapped = map(kalAngleX, -45, 45, 0, 255);
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

    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
}

void TaskReadModeButton(void *pvParameters)  // This is a task.
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
      Serial.println("default");
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
          Serial.println("mode++");
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
void TaskReadLightSensor(void *pvParameters)  // This is a task.
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
