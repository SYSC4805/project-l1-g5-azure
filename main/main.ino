#include "MotorControl.h"
#include "IRSensor.h"
#include "LineDetection.h"
#include "UltrasonicSensor.h"
#include <SharpDistSensor.h>

const int IRsensorPin = A8;


#define TEST 0

void setup() {
  Serial.begin(115200);
  while (!Serial);  // Wait for Serial to connect
  setupMotors(); 

  pinMode(IR_SENSOR_1_PIN, INPUT); // Set pin 9 as input for Sensor 1
  pinMode(IR_SENSOR_2_PIN, INPUT); // Set pin 10 as input for Sensor 2
  randomSeed(analogRead(0));
}

void loop() { //MAIN LOOP IN OVERALL PROJECT
  //DETECING LINE - POLLING THROUGH LINE FOLLOWER SENSOR
  int test = TEST;
  go_straight(50);
  if (detect_line(test)) {
    go_back(1000);       // Move backward for 1000ms
    turn_right_level(random(2,5)); // Complete a 90-degree turn
  }

  //DETECTING OBSTACLES - POLLING THROUGH IR SENSOR
  int analogValue = analogRead(IRsensorPin);
  unsigned int u_distance = analogToDistance(analogValue);
  Serial.println(u_distance);
  if(detect_IR_1() || detect_IR_2() || u_distance <= 46){ //if obstacle detected
    Serial.println("obstacle detected");
    go_back(700);
    turn_right_level(1);
  }
}
