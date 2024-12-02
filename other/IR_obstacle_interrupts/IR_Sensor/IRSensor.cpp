// IRSensor.cpp
#include "IRSensor.h"
#include <Arduino.h>

// Function to detect object for IR sensor 1, return 1 if detected, 0 if not detected
bool detect_IR_1() {
  bool sensor1State = digitalRead(IR_SENSOR_1_PIN);
  return !sensor1State;  // Return true if an object is detected
}

// Function to detect object for IR sensor 2, return 1 if detected, 0 if not detected
bool detect_IR_2() {
  bool sensor2State = digitalRead(IR_SENSOR_2_PIN);
  return !sensor2State;  // Return true if an object is detected
}
