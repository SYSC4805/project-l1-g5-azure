#include "IRSensor.h"

void setup() {
  pinMode(IR_SENSOR_1_PIN, INPUT); // Set pin 9 as input for Sensor 1
  pinMode(IR_SENSOR_2_PIN, INPUT); // Set pin 10 as input for Sensor 2
  Serial.begin(115200);            // Start serial communication at 115200 baud
}

void loop() {
  Serial.println("Sensor 1:");
  Serial.println(detect_IR_1());
  Serial.println("Sensor 2:");
  Serial.println(detect_IR_2());

  delay(100);  // Small delay for readability
}
