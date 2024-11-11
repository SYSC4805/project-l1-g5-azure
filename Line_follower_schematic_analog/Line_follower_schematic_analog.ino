#include "MotorControl.h"
#include "LineDetection.h"

#define TEST 1

void setup() {
  Serial.begin(115200);
  while (!Serial);  // Wait for Serial to connect
  setupMotors();    // Initialize motors
}

void loop() {
  int test = TEST;
  go_straight(100);
  if (detect_line(test)) {
    go_back(1000);       // Move backward for 1000ms
    turn_right_level(2); // Complete a 90-degree turn
  }
}
