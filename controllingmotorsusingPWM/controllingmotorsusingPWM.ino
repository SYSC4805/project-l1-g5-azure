#define M1_PWM 2
#define M2_PWM 3
#define M3_PWM 4
#define M4_PWM 5

#define M1_ENABLE 46
#define M2_ENABLE 48
#define M3_ENABLE 50
#define M4_ENABLE 52

void setup() {
  // put your setup code here, to run once:
  pinMode(M1_PWM,OUTPUT);
  pinMode(M2_PWM,OUTPUT);
  pinMode(M3_PWM,OUTPUT); //FRONT-RIGHT
  pinMode(M4_PWM,OUTPUT); //BACK-RIGHT
  
  pinMode(M1_ENABLE, OUTPUT);//high or low
  pinMode(M2_ENABLE, OUTPUT);//high or low
  pinMode(M3_ENABLE, OUTPUT);//high or low
  pinMode(M4_ENABLE, OUTPUT);//high or low


}

void loop() {
  delay(2000);
  turn_right_level(8);
  stop();
  delay(2000);
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

void turn_right(){
  //time to turn 90 = 2 seconds
  int pwm_value = 60;
  int time = 885;
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


void turn_left(){
  //time to turn 90 = 2 seconds
  int pwm_value = 196;
  int time = 885;
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

void turn_right_level(int level){ //level 1-8, 1= 45 degrees, 8 = 360 degrees
  int i = 0;
  while(i<level){
    turn_right();
    i++;
  }
}

void turn_left_level(int level){ //level 1-8, 1= 45 degrees, 8 = 360 degrees
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
