#ifndef functions_h
#define functions_h

#define WHITE_LED_PIN 9
#define RED_LED_PIN   10
#define MODE_BUTTON   11



#define PID_OUT_LIMIT 30
#define CALIBRATE_ESC 
// #define TUNNING_PID
#define SHOW_ANGLE_DATA 
//#define SHOW_ESC_OUT
#define AUTOTUNE_PID 
//#define CAPTURE_JOYSTICK
//
#define LIGHT_DEFAULT       0
#define LIGHT_LOW           1
#define LIGHT_HIGH          2
#define LIGHT_BATTERY_SAVE  3

void config_i2cData(void);

void kalman_set_initial_angle(void);

void get_IMU_data(void);

void update_time(void);

void compute_roll_pitch(void);

void check_and_fix_transition(void);


#endif
