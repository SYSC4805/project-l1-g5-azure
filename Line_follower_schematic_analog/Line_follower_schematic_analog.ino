#include "MotorControl.h"
#include "ultrasonic_sensors.h"

#define THRESHOLD 970
#define TEST 1

void setup() {
  int test = TEST;
  Serial.begin(115200);
  while (!Serial);  // Wait for Serial to connect
  setupMotors();    //MAIN SETUP IN OVERALL PROJECT
  setup_ultrasonic(); // setup ultra sonic sensor
}

void loop() { //MAIN LOOP IN OVERALL PROJECT
  // unit_test_motor();
  // delay(2000);
  int test = TEST;
  go_straight(100);
  if (detect_line(test)) {
    go_back(1000);       // Move backward for 2000ms
    turn_right_level(2); // Complete a 90-degree turn (2 levels of 45 degrees)
  }
  if (CaptureFlagA) {
        CaptureFlagA = false;
        float distanceA = 340.0 * CaptureCountA / (42000000.0) / 2 * 100;
        Serial.print("Sensor 1 Distance: ");
        Serial.print(distanceA);
        Serial.println(" cm");
    }

    if (CaptureFlagB) {
        CaptureFlagB = false;
        float distanceB = 340.0 * CaptureCountB / (42000000.0) / 2 * 100;
        Serial.print("Sensor 2 Distance: ");
        Serial.print(distanceB);
        Serial.println(" cm");
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
