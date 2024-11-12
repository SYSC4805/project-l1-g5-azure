#include "ObstacleDetection.h"

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  bool sensor1 = detect_obstacle(0); // Sensor 1
  bool sensor2 = detect_obstacle(1); // Sensor 2

  Serial.println();
  //Serial.println(sensor1 ? "true" : "false");
  //Serial.println(sensor2 ? "true" : "false");


  //delay(100); // Optional: adjust to control loop frequency
}
