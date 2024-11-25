#include "MotorControl.h"
#include "IRSensor.h"
#include "LineDetection.h"
#include "UltrasonicSensor.h"
#include <SharpDistSensor.h>

//const byte medianFilterWindowSize = 5;
//const byte sensorPin = A8;
//SharpDistSensor sensor(sensorPin, medianFilterWindowSize);

const int IRsensorPin = A8;

int analogToDistance(int analogValue) {
    // Conversion formula depends on your specific Sharp sensor model
    // Example for GP2Y0A21YK0F (10-80 cm range):
    if (analogValue == 0) return -1; // Avoid division by zero

    float voltage = analogValue * (5.0 / 1023.0); // Convert analog value to voltage
    int distance = (27.86 / (voltage - 0.42));    // Empirical formula from datasheet

    if (distance > 80 || distance < 10) {
        return -1; // Out of range for this sensor model
    }

    return distance;
}


#define TEST 0

void setup() {
  Serial.begin(115200);
  while (!Serial);  // Wait for Serial to connect
  setupMotors();    //MAIN SETUP IN OVERALL PROJECT

  pinMode(IR_SENSOR_1_PIN, INPUT); // Set pin 9 as input for Sensor 1
  pinMode(IR_SENSOR_2_PIN, INPUT); // Set pin 10 as input for Sensor 2
  randomSeed(analogRead(0));
  setupUltrasonicSensor();
  
  //setting up sharp IR sensor
  //sensor.setModel(SharpDistSensor::GP2Y0A51SK0F_5V_DS);
  //sensor.setValMinMax(70, 500);
}

void loop() { //MAIN LOOP IN OVERALL PROJECT
  // unit_test_motor();
  // delay(2000);


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
  if(detect_IR_1() || detect_IR_2() || u_distance <= 75){
    Serial.println("obstacle detected");
    if(measurePulse1() <= 10 ){
      turn_right_level(1);
      //Serial.println("obstacle detected ultrasonic");
    }else{
      go_back(700);
      turn_right_level(1);
    }
  }
}
