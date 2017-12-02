#ifndef configurations_h
#define configurations_h

#define FALSE 0
#define TRUE  1

/* Constatntes para determinar cuanto tiempo se presionó 
 * el botón de cambio de modo */
#define PRESS_DURATION_LONG   50
#define PRESS_DURATION_SHORT  10

/* Pines de la placa y sus funciones */
#define LED_PIN_BATTERY_RED       2
#define LED_PIN_BATTERY_YELLOW    3
#define LED_PIN_BATTERY_GREEN     13
#define LED_PIN_BLINK_BLUE    5
#define LED_PIN_BLINK_GREEN   6
#define LED_PIN_FOCUS  9
#define LED_PIN_WIDE   10
#define MODE_BUTTON    11

/* Umbrales de la maquina de estado 
 * para el control de la intensidad de la luz */
#define INTENSIDAD_LEJOS_H    70
#define INTENSIDAD_NORMAL_L   80
#define INTENSIDAD_NORMAL_H   140
#define INTENSIDAD_CERCA_L    400
#define INTENSIDAD_CERCA_H    1024


/* Estados de la maquina de estado para el control de la intensidad de luz */
#define MODO_INTENSIDAD_CERCA     0
#define MODO_INTENSIDAD_NORMAL    1
#define MODO_INTENSIDAD_LEJOS     2

/* Cantidad de modos de la linterna */
#define CONT_MODE_LIGHT     5

/* Estados para controlar los modos de la linterna */
#define LIGHT_OFF                 0
#define LIGHT_ADAPTABLE           1
#define LIGHT_WIDE                2
#define LIGHT_FOCUS               3
#define LIGHT_WIDE_AND_FOCUS      4
#define LIGHT_BATTERY_SAVE        5

/* Umbrales del ADC para identificar el nivel de la batería 
 * La medición del nivel se realiza mediante A1*/
#define BATTERY_LOW     500
#define BATTERY_MEDIUM  800
#define BATTERY_HIGH    1000

/* Estados para controlar el modo de parpadeo del led RGB */
#define BLINK_OFF   0
#define BLINK_SLOW  1
#define BLINK_FAST  2
#define BLINK_BREATH  3

/* Intensidades de los LED principales*/
#define PWM_CERCA   30
#define PWM_NORMAL  100                
#define PWM_LEJOS   200
#define PWM_MAXIMO  255
#define PWM_APAGADO 0

/* Intensidad de los led para el parpadeo 
 * Los LED son ánodo común, por eso los valores están invertidos*/
#define PWM_BLINK_OFF   0
#define PWM_BLINK_ON    255

/* Duración de los parpadeos del LED RGB */
#define BLINK_DURATION_SLOW 10
#define BLINK_DURATION_FAST 5





#endif
