// ultrasonic_sensors.h

#ifndef ULTRASONIC_SENSORS_H
#define ULTRASONIC_SENSORS_H

#include <Arduino.h>

// Variables to store capture counts and flags for each sensor
extern volatile uint32_t CaptureCountA, CaptureCountB;
extern volatile bool CaptureFlagA, CaptureFlagB;

// Sensor pins
#define trigPin1 2   // Sensor 1 Trigger Pin (TC0, Channel 0)
#define echoPin1 A7  // Sensor 1 Echo Pin

#define trigPin2 13  // Sensor 2 Trigger Pin (TC0, Channel 1)
#define echoPin2 A6  // Sensor 2 Echo Pin

// Function prototypes
void setup_ultrasonic();
void loop();

// Interrupt Service Routine Prototypes
void TC1_Handler();

#endif // ULTRASONIC_SENSORS_HS