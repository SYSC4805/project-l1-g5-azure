#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

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
void setup();
void goStraight(int time);
void goBack(int time);
void rightTurnHelper() 
void leftTurnHelper() 
void rightTurn(int level);
void leftTurn(int level);
void MotorsUnitTest();

#endif
