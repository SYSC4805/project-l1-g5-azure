// LineDetection.cpp
#include "LineDetection.h"
#include <Arduino.h>

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

void line_unit_test(){
  detect_line(1);
  Serial.println();
  detect_line(1);
  Serial.println();
  detect_line(1);
  Serial.println();
}
