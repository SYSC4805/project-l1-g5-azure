volatile bool object1Detected = false;  // Flag to track object detection for sensor 1
volatile bool object2Detected = false;  // Flag to track object detection for sensor 2


#define IR_PIN_1 9
#define IR_PIN_2 10

void setup() {
  Serial.begin(115200);

  // Pin 3 is connected to the OUT pin of the first VMA330 sensor
  pinMode(IR_PIN_1, INPUT);  // Set Pin 3 as input to read sensor 1 output
  // Pin 4 is connected to the OUT pin of the second VMA330 sensor
  pinMode(IR_PIN_2, INPUT);  // Set Pin 4 as input to read sensor 2 output
  
  // Attach interrupt to Pin 3 (sensor 1), triggered on change (RISING or FALLING edge)
  attachInterrupt(digitalPinToInterrupt(IR_PIN_1), sensorInterruptHandler1, CHANGE);
  // Attach interrupt to Pin 4 (sensor 2), triggered on change (RISING or FALLING edge)
  attachInterrupt(digitalPinToInterrupt(IR_PIN_2), sensorInterruptHandler2, CHANGE);

  Serial.println("VMA330 Sensors Interrupt Setup Complete");
}

void loop() {
  bool obstacle_detected = IR_obstacle();
  //Serial.println(obstacle_detected);
  delay(100);  // Small delay to prevent spamming the Serial monitor
}

// Interrupt Service Routine (ISR) for sensor 1 (Pin 3)
void sensorInterruptHandler1() {
  // Read the sensor output state for sensor 1
  int sensor1State = digitalRead(IR_PIN_1);
  if (sensor1State == HIGH){
    object1Detected = true;
  }
}

//Interrupt Service Routine (ISR) for sensor 2 (Pin 4)
void sensorInterruptHandler2() {
  // Read the sensor output state for sensor 2
  int sensor2State = digitalRead(IR_PIN_2);
  if (sensor2State == HIGH){
    object2Detected = true;
  }
}

bool IR_obstacle(){
  // Check the flag and handle object detection logic for Sensor 1
  if (object1Detected) {
    Serial.println("Object 1 Detected!");
    return true;
  }
  object1Detected = false;//should be reset after function for detecting snow finished

  // Check the flag and handle object detection logic for Sensor 2
  if (object2Detected) {
    Serial.println("Object 2 Detected!");
    return true;
  }
  object2Detected = false;//should be reset after function for detecting snow finished

  return false;
}

