// IRSensor.cpp
#include "IRSensor.h"
#include <Arduino.h>


void setup() {
  Serial.begin(9600); // Start Serial communication for debugging
  pinMode(IR_SENSOR_1_PIN, INPUT);
  pinMode(IR_SENSOR_2_PIN, INPUT);

  // Test IR sensor 1
  testDetectIR1();

  // Test IR sensor 2
  testDetectIR2();
}

void loop() {
  // Nothing to do here for the test
}

// Test function for detect_IR_1
void testDetectIR1() {
  Serial.println("Testing detect_IR_1...");

  // Simulating sensor states
  bool simulatedState = digitalRead(IR_SENSOR_1_PIN); // Reading the real pin state for testing

  if (detect_IR_1() == !simulatedState) {
    Serial.println("Test Passed for detect_IR_1");
  } else {
    Serial.println("Test Failed for detect_IR_1");
  }
}

// Test function for detect_IR_2
void testDetectIR2() {
  Serial.println("Testing detect_IR_2...");

  // Simulating sensor states
  bool simulatedState = digitalRead(IR_SENSOR_2_PIN); // Reading the real pin state for testing

  if (detect_IR_2() == !simulatedState) {
    Serial.println("Test Passed for detect_IR_2");
  } else {
    Serial.println("Test Failed for detect_IR_2");
  }
}
