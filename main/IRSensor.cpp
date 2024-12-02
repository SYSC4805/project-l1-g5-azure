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

int analogToDistance(int analogValue) {
    if (analogValue == 0) return -1; // Avoid division by zero

    float voltage = analogValue * (5.0 / 1023.0); // Convert analog value to voltage
    int distance = (27.86 / (voltage - 0.42));    // Empirical formula from datasheet

    if (distance > 80 || distance < 10) {
        return -1; // Out of range for this sensor model
    }

    return distance;
}
