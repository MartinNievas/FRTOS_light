#include <Arduino.h>
#include <configurations.h>

extern int intensity_mode;

void check_battery_level(int battery_level){

  if (battery_level <= BATTERY_LOW) 
  {
    digitalWrite(LED_PIN_BATTERY_RED, 1);
    digitalWrite(LED_PIN_BATTERY_YELLOW, 0);
    digitalWrite(LED_PIN_BATTERY_GREEN, 0);
  }

  if (battery_level > BATTERY_LOW && battery_level <= BATTERY_MEDIUM) 
  {
    digitalWrite(LED_PIN_BATTERY_RED, 0);
    digitalWrite(LED_PIN_BATTERY_YELLOW, 1);
    digitalWrite(LED_PIN_BATTERY_GREEN, 0);
  }

  if (battery_level > BATTERY_MEDIUM ) 
  {
    digitalWrite(LED_PIN_BATTERY_RED, 0);
    digitalWrite(LED_PIN_BATTERY_YELLOW, 0);
    digitalWrite(LED_PIN_BATTERY_GREEN, 1);
  }

}

void check_brightness_level(int brightness_level){

if (intensity_mode == MODO_INTENSIDAD_CERCA)
    {
      if (brightness_level <= INTENSIDAD_NORMAL_H)   
        intensity_mode = MODO_INTENSIDAD_NORMAL;
      if (brightness_level > INTENSIDAD_CERCA_L ) 
        intensity_mode = MODO_INTENSIDAD_CERCA;
    }
    else if (intensity_mode == MODO_INTENSIDAD_NORMAL)
    {
      if (brightness_level <= INTENSIDAD_LEJOS_H)   
        intensity_mode = MODO_INTENSIDAD_LEJOS;
      if (brightness_level > INTENSIDAD_CERCA_L ) 
        intensity_mode = MODO_INTENSIDAD_CERCA;
    }
    else if (intensity_mode == MODO_INTENSIDAD_LEJOS)
    {
      if (brightness_level <= INTENSIDAD_LEJOS_H)   
        intensity_mode = MODO_INTENSIDAD_LEJOS;
      if (brightness_level > INTENSIDAD_NORMAL_L ) 
        intensity_mode = MODO_INTENSIDAD_NORMAL;
    }


}
