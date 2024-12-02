#include <Arduino.h>
#include "Motors.h"

// Define pins
#define IR_SENSOR_1_PIN 1
#define IR_SENSOR_2_PIN 2
#define LINE_SENSOR_1_PIN 6
#define LINE_SENSOR_2_PIN 7
#define SMALL_BLOCK_HANDLER_PIN 8
#define MOTOR1_PIN 2
#define MOTOR2_PIN 3

// Battery Management Variables
char state;
int batteryLevel;

// Function Prototypes
int battery(); // Simulates retrieving battery level
void battery_management(int batteryLevel);
bool detect_IR_1();
bool detect_IR_2();
void executeMovement();

// Simulated Sensor States
bool simulatedIRSensor1State = false;
bool simulatedIRSensor2State = false;

// Mock digitalRead for simulation
bool digitalRead(int pin) {
  if (pin == IR_SENSOR_1_PIN) {
    return simulatedIRSensor1State;
  } else if (pin == IR_SENSOR_2_PIN) {
    return simulatedIRSensor2State;
  }
  return true; // Default HIGH
}

// IR Sensor Functions
bool detect_IR_1() { return !digitalRead(IR_SENSOR_1_PIN); }
bool detect_IR_2() { return !digitalRead(IR_SENSOR_2_PIN); }

// Battery Management Function
void battery_management(int x) {
  state = 'z'; // Default state

  if (x >= 60) {
    state = 'H';
    // Keep all sensors and components on
    pinMode(LINE_SENSOR_1_PIN, HIGH);
    pinMode(LINE_SENSOR_2_PIN, HIGH);
    pinMode(SMALL_BLOCK_HANDLER_PIN, HIGH);
    pinMode(MOTOR1_PIN, HIGH);
    pinMode(MOTOR2_PIN, HIGH);
  } else if (x >= 20 && x < 60) {
    state = 'S';
    // Enable only line sensors and small block handlers
    pinMode(LINE_SENSOR_1_PIN, HIGH);
    pinMode(LINE_SENSOR_2_PIN, HIGH);
    pinMode(SMALL_BLOCK_HANDLER_PIN, HIGH);
    pinMode(MOTOR1_PIN, LOW);
    pinMode(MOTOR2_PIN, LOW);
  } else {
    state = 'L';
    // Only line sensors are on
    pinMode(LINE_SENSOR_1_PIN, HIGH);
    pinMode(LINE_SENSOR_2_PIN, HIGH);
    pinMode(MOTOR1_PIN, LOW);
    pinMode(MOTOR2_PIN, LOW);
    pinMode(SMALL_BLOCK_HANDLER_PIN, LOW);
  }
}

// Robot Functions
void executeMovement() {
  Serial.println("Starting Movement Sequence...");
  goStraight(2000);
  if (detect_IR_1() || detect_IR_2()) {
    Serial.println("Obstacle detected, reversing...");
    goBack(1000);
    rightTurn(2);
  }
  leftTurn(2);
  goStraight(3000);
  Serial.println("Movement Sequence Complete.");
}

int battery() {
  // Simulate battery level retrieval
  return random(0, 101); // Random value between 0-100
}

void setup() {
  Serial.begin(115200);
  setupMotors();
  Serial.println("System Initialized.");
}

void loop() {
  batteryLevel = battery();
  battery_management(batteryLevel);
  Serial.printf("Battery Level: %d%%, State: %c\n", batteryLevel, state);

  if (state != 'L') { // Avoid movement if in low battery mode
    executeMovement();
  } else {
    Serial.println("Low battery, limiting operations.");
  }

  delay(5000); // Wait before restarting the loop
}
