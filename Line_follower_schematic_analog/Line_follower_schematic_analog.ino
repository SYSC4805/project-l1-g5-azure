#include "MotorControl.h"
#include "IRSensor.h"

#define THRESHOLD 970
#define TEST 1

void setup() {
  int test = TEST;
  Serial.begin(115200);
  while (!Serial);  // Wait for Serial to connect
  setupMotors();    //MAIN SETUP IN OVERALL PROJECT

  pinMode(IR_SENSOR_1_PIN, INPUT); // Set pin 9 as input for Sensor 1
  pinMode(IR_SENSOR_2_PIN, INPUT); // Set pin 10 as input for Sensor 2
}

void loop() { //MAIN LOOP IN OVERALL PROJECT
  // unit_test_motor();
  // delay(2000);


  //DETECING LINE - POLLING THROUGH LINE FOLLOWER SENSOR
  int test = TEST;
  go_straight(100);
  if (detect_line(test)) {
    go_back(1000);       // Move backward for 2000ms
    turn_right_level(2); // Complete a 90-degree turn (2 levels of 45 degrees)
  }

  //DETECTING OBSTACLES - POLLING THROUGH IR SENSOR
  if(detect_IR_1() || detect_IR_2()){
    go_back(700);
    turn_right_level(1);
  }
}

bool detect_line(int test) {
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);
  int sensorValue5 = analogRead(A4);
  int sensorValue6 = analogRead(A5);

  if (test == 1) {
    Serial.print("Sensor Values: ");
    Serial.print(sensorValue1); Serial.print(" ");
    Serial.print(sensorValue2); Serial.print(" ");
    Serial.print(sensorValue3); Serial.print(" ");
    Serial.print(sensorValue4); Serial.print(" ");
    Serial.print(sensorValue5); Serial.print(" ");
    Serial.println(sensorValue6);
  }

  return (sensorValue1 >= THRESHOLD || sensorValue2 >= THRESHOLD ||
          sensorValue3 >= THRESHOLD || sensorValue4 >= THRESHOLD ||
          sensorValue5 >= THRESHOLD || sensorValue6 >= THRESHOLD);
}
