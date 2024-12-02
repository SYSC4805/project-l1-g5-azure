#include "IRSensor.h"

// Simulation variables to emulate sensor states
bool simulatedIRSensor1State = false; // Change these values to simulate input
bool simulatedIRSensor2State = false;

// Mock digitalRead function for simulation
bool digitalRead(int pin) {
  if (pin == IR_SENSOR_1_PIN) {
    return simulatedIRSensor1State; // Return the simulated state for sensor 1
  } else if (pin == IR_SENSOR_2_PIN) {
    return simulatedIRSensor2State; // Return the simulated state for sensor 2
  }
  return HIGH; // Default to HIGH for other pins
}

// Functions to be tested
bool detect_IR_1() {
  bool sensor1State = digitalRead(IR_SENSOR_1_PIN);
  return !sensor1State; // Return true if an object is detected
}

bool detect_IR_2() {
  bool sensor2State = digitalRead(IR_SENSOR_2_PIN);
  return !sensor2State; // Return true if an object is detected
}

// Test setup
void setup() {
  Serial.begin(9600);

  // Test cases
  testDetectIR1();
  testDetectIR2();
}

void loop() {
  // Nothing to do here for the test
}

// Test function for detect_IR_1
void testDetectIR1() {
  Serial.println("Testing detect_IR_1...");

  // Test case 1: No object detected (HIGH state)
  simulatedIRSensor1State = HIGH;
  if (detect_IR_1() == false) {
    Serial.println("Test Case 1 Passed: No object detected.");
  } else {
    Serial.println("Test Case 1 Failed.");
  }

  // Test case 2: Object detected (LOW state)
  simulatedIRSensor1State = LOW;
  if (detect_IR_1() == true) {
    Serial.println("Test Case 2 Passed: Object detected.");
  } else {
    Serial.println("Test Case 2 Failed.");
  }
}

// Test function for detect_IR_2
void testDetectIR2() {
  Serial.println("Testing detect_IR_2...");

  // Test case 1: No object detected (HIGH state)
  simulatedIRSensor2State = HIGH;
  if (detect_IR_2() == false) {
    Serial.println("Test Case 1 Passed: No object detected.");
  } else {
    Serial.println("Test Case 1 Failed.");
  }

  // Test case 2: Object detected (LOW state)
  simulatedIRSensor2State = LOW;
  if (detect_IR_2() == true) {
    Serial.println("Test Case 2 Passed: Object detected.");
  } else {
    Serial.println("Test Case 2 Failed.");
  }


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
