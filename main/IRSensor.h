// IRSensor.h
#ifndef IRSENSOR_H
#define IRSENSOR_H

#include <Arduino.h>

// Pin definitions for IR sensors
#define IR_SENSOR_1_PIN 9  // First IR sensor connected to digital pin 9
#define IR_SENSOR_2_PIN 10 // Second IR sensor connected to digital pin 10

// Function prototypes
bool detect_IR_1();
bool detect_IR_2();
int analogToDistance(int analogValue);

#endif // IRSENSOR_H
