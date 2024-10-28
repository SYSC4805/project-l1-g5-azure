volatile bool object1Detected = false;  // Flag to track object detection for sensor 1
volatile bool object2Detected = false;  // Flag to track object detection for sensor 2
bool setupComplete = false;

#define M1_PWM 2
#define M2_PWM 3
#define M3_PWM 4
#define M4_PWM 5

#define M1_ENABLE 46
#define M2_ENABLE 48
#define M3_ENABLE 50
#define M4_ENABLE 52

void setup() {
  Serial.begin(115200);

  // Pin 3 is connected to the OUT pin of the first VMA330 sensor
  pinMode(12, INPUT);  // Set Pin 3 as input to read sensor 1 output
  // Pin 4 is connected to the OUT pin of the second VMA330 sensor
  pinMode(13, INPUT);  // Set Pin 4 as input to read sensor 2 output
  
  // Attach interrupt to Pin 3 (sensor 1), triggered on change (RISING or FALLING edge)
  attachInterrupt(digitalPinToInterrupt(8), sensorInterruptHandler1, CHANGE);
  // Attach interrupt to Pin 4 (sensor 2), triggered on change (RISING or FALLING edge)
  attachInterrupt(digitalPinToInterrupt(13), sensorInterruptHandler2, CHANGE);

  Serial.println("VMA330 Sensors Interrupt Setup Complete");
  //Motor
  pinMode(M1_PWM,OUTPUT);
  pinMode(M2_PWM,OUTPUT);
  pinMode(M3_PWM,OUTPUT); //FRONT-RIGHT
  pinMode(M4_PWM,OUTPUT); //BACK-RIGHT
  
  pinMode(M1_ENABLE, OUTPUT);//high or low
  pinMode(M2_ENABLE, OUTPUT);//high or low
  pinMode(M3_ENABLE, OUTPUT);//high or low
  pinMode(M4_ENABLE, OUTPUT);//high or low

  setupComplete = true;

}

void loop() {
  if (!setupComplete) return;
  
  if (scan_snow()){
    Serial.println("detected");
    //go grab the snow
    //push_snow();
  }
  /*
  if(!scan_obstacle){
    go_straight(5);
  }
  */
}

void go_straight(int time){
  // put your main code here, to run repeatedly:
  analogWrite(M1_PWM,90); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M1_ENABLE, HIGH); //on or off

  analogWrite(M2_PWM,90); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M2_ENABLE, HIGH); //on or off

  analogWrite(M3_PWM,158); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M3_ENABLE, HIGH); //on or off

  analogWrite(M4_PWM,158); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M4_ENABLE, HIGH); //on or off

  delay(time);
}

void go_back(int time){
  // put your main code here, to run repeatedly:
  analogWrite(M1_PWM,158); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M1_ENABLE, HIGH); //on or off

  analogWrite(M2_PWM,158); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M2_ENABLE, HIGH); //on or off

  analogWrite(M3_PWM,90); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M3_ENABLE, HIGH); //on or off

  analogWrite(M4_PWM,90); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M4_ENABLE, HIGH); //on or off

  delay(time);
}

void turn_left(){
  //time to turn 90 = 2 seconds
  int pwm_value = 196;
  int time = 442;
  analogWrite(M1_PWM,pwm_value); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M1_ENABLE, HIGH); //on or off

  analogWrite(M2_PWM,pwm_value); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M2_ENABLE, HIGH); //on or off

  analogWrite(M3_PWM,pwm_value); //more than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M3_ENABLE, HIGH); //on or off

  analogWrite(M4_PWM,pwm_value); //more than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M4_ENABLE, HIGH); //on or off
  delay(time);//time to turn 45 degrees
  stop();
  delay(500);
}

void turn_right(){
  //time to turn 90 = 2 seconds
  int pwm_value = 60;
  int time = 442;
  analogWrite(M1_PWM,pwm_value); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M1_ENABLE, HIGH); //on or off

  analogWrite(M2_PWM,pwm_value); //less than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M2_ENABLE, HIGH); //on or off

  analogWrite(M3_PWM,pwm_value); //more than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M3_ENABLE, HIGH); //on or off

  analogWrite(M4_PWM,pwm_value); //more than 128 -> forward, more than 128->backward, 128 == stop
  digitalWrite(M4_ENABLE, HIGH); //on or off
  delay(time);//time to turn 45 degrees
  stop();
  delay(500);
}

void turn_right_level(int level){ //level 1-16, 1= 22.5 degrees, 16 = 360 degrees
  int i = 0;
  while(i<level){
    turn_right();
    i++;
  }
}

void turn_left_level(int level){ //level 1-16, 1= 22.5 degrees, 16 = 360 degrees
  int i = 0;
  while(i<level){
    turn_left();
    i++;
  }
}


void stop(){
  digitalWrite(M1_ENABLE, LOW); //on or off
  digitalWrite(M2_ENABLE, LOW); //on or off
  digitalWrite(M3_ENABLE, LOW); //on or off
  digitalWrite(M4_ENABLE, LOW); //on or off
}

bool scan_snow(){
  int x = 0;
  while(!object1Detected && !object2Detected){
      Serial.println(object1Detected);
      Serial.println(object2Detected);
      if(x > 8){
        break;
      }
      turn_right_level(1);
      x++;
  }
  if(object1Detected || object2Detected){
    return true;
  }
  return false;
}

// Interrupt Service Routine (ISR) for sensor 1 (Pin 3)
void sensorInterruptHandler1() {
  // Read the sensor output state for sensor 1
  int sensor1State = digitalRead(8);
  if (sensor1State == 0){//a value of 0 means that an object is detected
    object1Detected = true;
  }
}

// Interrupt Service Routine (ISR) for sensor 2 (Pin 4)
void sensorInterruptHandler2() {
  // Read the sensor output state for sensor 2
  int sensor2State = digitalRead(13);
  if (sensor2State == 0){ //a value of 0 means that an object is detected
    object2Detected = true;
  }
}
/*
bool scan_obstacle(){
  int x = 0;
  //turn until we find obstacle
  while(!obstacle){
    if(X > 8){
        break;
      }
      turn_right_level(1)
  }
  if(obstacle){
    turn_right_level(1);
    go_straight(2);
    return true;
  }
  return false;
} 

void push_snow(){
  while(!obstacle || !black_line){
    go_straight(1);
  }
  if(obstacle){
    while(obstacle){
      turn_right)level(1);
    }
    push_snow();
  }
}
*/

