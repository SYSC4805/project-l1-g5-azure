#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>  // Ensure Arduino functions are available

// Motor pin definitions
#define M1_PWM 2
#define M2_PWM 3
#define M3_PWM 4
#define M4_PWM 5

#define M1_ENABLE 46
#define M2_ENABLE 48
#define M3_ENABLE 50
#define M4_ENABLE 52

// Function prototypes
void setupMotors();
void go_straight(int time);
void go_back(int time);
void turn_right();
void turn_left();
void turn_right_level(int level);
void turn_left_level(int level);
void stop();
void unit_test_motor();

#endif
