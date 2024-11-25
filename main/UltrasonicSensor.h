#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

// Pin definitions
#define TRIG_PIN1 12
#define ECHO_PIN1 A7

#define TRIG_PIN2 13
#define ECHO_PIN2 A8

// Function declarations
void setupUltrasonicSensor();
int getDistanceInCentimeters();
int measurePulse1(); // Declare measurePulse to avoid conflicts
int measurePulse2(); // Declare measurePulse to avoid conflicts

#endif // ULTRASONICSENSOR_H
