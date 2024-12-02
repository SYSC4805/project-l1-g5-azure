// ObstacleDetection.cpp
#include "ObstacleDetection.h"
#include <Arduino.h>

// Initialize the NewPing object array using the pin constants
NewPing sonar[SONAR_NUM] = {
    NewPing(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE), // Sensor 1: trigger pin 6, echo pin 7
    NewPing(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE)  // Sensor 2: trigger pin 9, echo pin 10
};

bool detect_obstacle(int sensor_num) {
  delay(50); // Wait 50ms between pings (about 20 pings/sec).
  Serial.print("Sensor ");
  Serial.print(sensor_num + 1);
  Serial.print(": ");

  int distance = sonar[sensor_num].ping_cm();
  Serial.print(distance);
  Serial.println("cm");

  return distance <= DETECT_DISTANCE;
}
