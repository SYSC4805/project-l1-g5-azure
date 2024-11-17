#include "Motors.h"

// Initialize motor control pins
void setup() {
  Serial.begin(115200);
  while (!Serial);
  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M3_PWM, OUTPUT);
  pinMode(M4_PWM, OUTPUT);

  pinMode(M1_ENABLE, OUTPUT);
  pinMode(M2_ENABLE, OUTPUT);
  pinMode(M3_ENABLE, OUTPUT);
  pinMode(M4_ENABLE, OUTPUT);
}

// Moves robot in a straight line for a specified time
// int time, total time to go straight (in milliseconds)
void goStraight(int time) {
  analogWrite(M1_PWM, 178);
  digitalWrite(M1_ENABLE, HIGH);

  analogWrite(M2_PWM, 178);
  digitalWrite(M2_ENABLE, HIGH);

  analogWrite(M3_PWM, 70);
  digitalWrite(M3_ENABLE, HIGH);

  analogWrite(M4_PWM, 70);
  digitalWrite(M4_ENABLE, HIGH);

  delay(time);
}

// Moves robot backwards for a specified time
// int time, total time to go backwards (in milliseconds)
void goBack(int time) {
  analogWrite(M1_PWM, 90);
  digitalWrite(M1_ENABLE, HIGH);

  analogWrite(M2_PWM, 90);
  digitalWrite(M2_ENABLE, HIGH);

  analogWrite(M3_PWM, 158);
  digitalWrite(M3_ENABLE, HIGH);

  analogWrite(M4_PWM, 158);
  digitalWrite(M4_ENABLE, HIGH);

  delay(time);
}

// Turns robot right (clockwise) by 45 degrees
void rightTurnHelper() {
  int pwm_value = 196;
  int time = 650;
  analogWrite(M1_PWM, pwm_value);
  digitalWrite(M1_ENABLE, HIGH);

  analogWrite(M2_PWM, pwm_value);
  digitalWrite(M2_ENABLE, HIGH);

  analogWrite(M3_PWM, pwm_value);
  digitalWrite(M3_ENABLE, HIGH);

  analogWrite(M4_PWM, pwm_value);
  digitalWrite(M4_ENABLE, HIGH);

  delay(time);
  stop();
  delay(500);
}

// Turns robot left (counter-clockwise) by 45 degrees
void leftTurnHelper() {
  int pwm_value = 60;
  int time = 650;
  analogWrite(M1_PWM, pwm_value);
  digitalWrite(M1_ENABLE, HIGH);

  analogWrite(M2_PWM, pwm_value);
  digitalWrite(M2_ENABLE, HIGH);

  analogWrite(M3_PWM, pwm_value);
  digitalWrite(M3_ENABLE, HIGH);

  analogWrite(M4_PWM, pwm_value);
  digitalWrite(M4_ENABLE, HIGH);

  delay(time);
  stop();
  delay(500);
}

// Turns robot right (clockwise) for specified number of degrees
// int level, each level is 45 degrees (int = 8 will be 360 deg)
void rightTurn(int level) {
  for (int i = 0; i < level; i++) {
    rightTurnHelper();
  }
}

// Turns robot left (counter-clockwise) for specified number of // degrees
// int level, each level is 45 degrees (int = 8 will be 360 deg)
void leftTurn(int level) {
  for (int i = 0; i < level; i++) {
    leftTurnHelper();
  }
}

// Unit test for robot movement
void MotorsUnitTest() {
  // Test 1: Move straight for 2 seconds
  Serial.println("Test 1: Moving straight...");
  goStraight(2000);
  Serial.println("Test 1 Complete!");
  delay(1000);

  // Test 2: Move backward for 2 seconds
  Serial.println("Test 2: Moving backwards...");
  goBack(2000);
  Serial.println("Test 2 Complete!");
  delay(1000);

  // Test 3: Turn right 90 degrees
  Serial.println("Test 3: Turning right 90 degrees...");
  rightTurn(2);
  Serial.println("Test 3 Complete!");
  delay(1000);

  // Test 4: Turn left 90 degrees
  Serial.println("Test 4: Turning left 90 degrees...");
  leftTurn(2);
  Serial.println("Test 4 Complete!");
  delay(1000);

  // Test 5: Complex maneuver
  Serial.println("Test 5: Performing complex maneuver...");
  goStraight(3000);
  rightTurn(2);
  goStraight(3000);
  goBack(3000);
  leftTurn(2);
  goBack(3000);
  Serial.println("Test 5 Complete!");
  Serial.println("All Motors Unit Tests Complete!");
}

void loop {
  MotorsUnitTest();
}
