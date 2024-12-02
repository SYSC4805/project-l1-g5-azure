// ObstacleDetection.h
#ifndef OBSTACLEDETECTION_H
#define OBSTACLEDETECTION_H

#include <NewPing.h>

// Constants for sensor setup
#define SONAR_NUM 2         // Number of sensors
#define MAX_DISTANCE 200    // Maximum distance (in cm) to ping
#define DETECT_DISTANCE 10  // Distance to act when detected

// Pin numbers for sensors
#define TRIGGER_PIN_1 9    // Trigger pin for sensor 1 (left sensor)
#define ECHO_PIN_1 10        // Echo pin for sensor 1
#define TRIGGER_PIN_2 12     // Trigger pin for sensor 2 (right sensor)
#define ECHO_PIN_2 13       // Echo pin for sensor 2

// Initialize an array of NewPing objects (declare globally here for access in both .cpp and main)
extern NewPing sonar[SONAR_NUM];

// Function prototype
bool detect_obstacle(int sensor_num);

#endif // OBSTACLEDETECTION_H
