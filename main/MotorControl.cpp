#include "MotorControl.h"

// Initializes motor control pins
void setupMotors() {
  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M3_PWM, OUTPUT);
  pinMode(M4_PWM, OUTPUT);

  pinMode(M1_ENABLE, OUTPUT);
  pinMode(M2_ENABLE, OUTPUT);
  pinMode(M3_ENABLE, OUTPUT);
  pinMode(M4_ENABLE, OUTPUT);
}

// Moves the robot straight for a specified time (milliseconds)
void go_straight(int time) {
  analogWrite(M1_PWM, 178);  // Forward
  digitalWrite(M1_ENABLE, HIGH);

  analogWrite(M2_PWM, 178);  // Forward
  digitalWrite(M2_ENABLE, HIGH);

  analogWrite(M3_PWM, 70); // Forward
  digitalWrite(M3_ENABLE, HIGH);

  analogWrite(M4_PWM, 70); // Forward
  digitalWrite(M4_ENABLE, HIGH);

  delay(time);
}

// Moves the robot backward for a specified time (milliseconds)
void go_back(int time) {
  analogWrite(M1_PWM, 90); // Backward
  digitalWrite(M1_ENABLE, HIGH);

  analogWrite(M2_PWM, 90); // Backward
  digitalWrite(M2_ENABLE, HIGH);

  analogWrite(M3_PWM, 158);  // Backward
  digitalWrite(M3_ENABLE, HIGH);

  analogWrite(M4_PWM, 158);  // Backward
  digitalWrite(M4_ENABLE, HIGH);

  delay(time);
}

// Turns the robot right by 90 degrees
void turn_right() {
  int pwm_value = 196;
  int time = 650;  // Time to turn 90 degrees
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

// Turns the robot left by 90 degrees
void turn_left() {
  int pwm_value = 60;
  int time = 650;  // Time to turn 90 degrees
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

// Turns the robot right by a specified number of levels (each level is 45 degrees)
void turn_right_level(int level) {
  for (int i = 0; i < level; i++) {
    turn_right();
  }
}

// Turns the robot left by a specified number of levels (each level is 45 degrees)
void turn_left_level(int level) {
  for (int i = 0; i < level; i++) {
    turn_left();
  }
}

// Stops the robot by disabling motor outputs
void stop() {
  digitalWrite(M1_ENABLE, LOW);
  digitalWrite(M2_ENABLE, LOW);
  digitalWrite(M3_ENABLE, LOW);
  digitalWrite(M4_ENABLE, LOW);
}


void unit_test_motor(){
  go_straight(1000);
  stop();
  delay(500);
  go_back(1000);
  stop();
  delay(500);
  turn_right_level(2);
  delay(500);
  turn_left_level(2);
  delay(500);
}