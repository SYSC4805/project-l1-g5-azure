#include "MotorControl.h"
#include "IRSensor.h"
#include "LineDetection.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "UltrasonicSensor.h"

#define TEST 0

void setup() {
  Serial.begin(115200);
  while (!Serial);  // Wait for Serial to connect
  setupMotors();    //MAIN SETUP IN OVERALL PROJECT

  pinMode(IR_SENSOR_1_PIN, INPUT); // Set pin 9 as input for Sensor 1
  pinMode(IR_SENSOR_2_PIN, INPUT); // Set pin 10 as input for Sensor 2
  randomSeed(analogRead(0));
  setupUltrasonicSensor();
}

void loop() { //MAIN LOOP IN OVERALL PROJECT
  // unit_test_motor();
  // delay(2000);


  //DETECING LINE - POLLING THROUGH LINE FOLLOWER SENSOR
  int test = TEST;
  go_straight(100);
  if (detect_line(test)) {
    go_back(1000);       // Move backward for 1000ms
    turn_right_level(random(2, 5)); // Complete a turn between 90 and 180 degrees
  }

  //DETECTING OBSTACLES - POLLING THROUGH IR SENSOR
  if(detect_IR_1() || detect_IR_2() || measurePulse2() <= 10){
    if(measurePulse1() <= 10 ){
      turn_right_level(1);
      //Serial.println("obstacle detected ultrasonic");
    }else{
      go_back(700);
      turn_right_level(1);
    }
  }

  //DETECTING OBSTACLES - POLLING THROUGH IR SENSOR


}
