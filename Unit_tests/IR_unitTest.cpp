#include <iostream>

#include <string>



// Simulated Arduino pins

#define IR_SENSOR_1_PIN 1

#define IR_SENSOR_2_PIN 2



// Simulated sensor states for testing

bool simulatedIRSensor1State = false;

bool simulatedIRSensor2State = false;



// Mock digitalRead function for simulation

bool digitalRead(int pin) {

  if (pin == IR_SENSOR_1_PIN) {

    return simulatedIRSensor1State; // Return the simulated state for sensor 1

  } else if (pin == IR_SENSOR_2_PIN) {

    return simulatedIRSensor2State; // Return the simulated state for sensor 2

  }

  return true; // Default to HIGH for other pins

}



// Function prototypes

void testDetectIR1();

void testDetectIR2();

bool detect_IR_1();

bool detect_IR_2();



int main() {

  std::cout << "Starting tests...\n";



  // Run tests

  testDetectIR1();

  testDetectIR2();



  std::cout << "Tests completed.\n";

  return 0;

}



// Simulated function for IR sensor 1

bool detect_IR_1() {

  bool sensor1State = digitalRead(IR_SENSOR_1_PIN);

  return !sensor1State; // Return true if an object is detected

}



// Simulated function for IR sensor 2

bool detect_IR_2() {

  bool sensor2State = digitalRead(IR_SENSOR_2_PIN);

  return !sensor2State; // Return true if an object is detected

}



// Test function for detect_IR_1

void testDetectIR1() {

  std::cout << "Testing detect_IR_1...\n";



  // Test case 1: No object detected (HIGH state)

  simulatedIRSensor1State = true; // Simulate HIGH state

  if (detect_IR_1() == false) {

    std::cout << "Test Case 1 Passed: No object detected.\n";

  } else {

    std::cout << "Test Case 1 Failed.\n";

  }



  // Test case 2: Object detected (LOW state)

  simulatedIRSensor1State = false; // Simulate LOW state

  if (detect_IR_1() == true) {

    std::cout << "Test Case 2 Passed: Object detected.\n";

  } else {

    std::cout << "Test Case 2 Failed.\n";

  }

}



// Test function for detect_IR_2

void testDetectIR2() {

  std::cout << "Testing detect_IR_2...\n";



  // Test case 1: No object detected (HIGH state)

  simulatedIRSensor2State = true; // Simulate HIGH state

  if (detect_IR_2() == false) {

    std::cout << "Test Case 1 Passed: No object detected.\n";

  } else {

    std::cout << "Test Case 1 Failed.\n";

  }



  // Test case 2: Object detected (LOW state)

  simulatedIRSensor2State = false; // Simulate LOW state

  if (detect_IR_2() == true) {

    std::cout << "Test Case 2 Passed: Object detected.\n";

  } else {

    std::cout << "Test Case 2 Failed.\n";

  }

}