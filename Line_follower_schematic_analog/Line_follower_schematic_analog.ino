#define threshold 720

//float threshold1 = 720;
//float threshold2 = 720;
//float threshold3 = 720;
//float threshold4 = 720;
//float threshold5 = 720;
//float threshold6 = 720;

void setup() {
  Serial.begin(115200);  // Initialize Serial communication through the Programming Port
  while (!Serial);       // Wait for Serial to connect (required for Due)
}

void loop() {
  detect_line();
  delay(500);
}

bool detect_line(){
  // Reading analog values from pins A0, A1, and A2
  int sensorValue1 = analogRead(A0);  // Read sensor 1 value from A0
  int sensorValue2 = analogRead(A1);  // Read sensor 2 value from A1
  int sensorValue3 = analogRead(A2);  // Read sensor 3 value from A2
  int sensorValue4 = analogRead(A3);  // Read sensor 1 value from A0
  int sensorValue5 = analogRead(A4);  // Read sensor 2 value from A1
  int sensorValue6 = analogRead(A5);  // Read sensor 3 value from A2

  // Convert analog readings to voltage (Due uses 3.3V reference)
  float voltage1 = sensorValue1 * (3.3 / 4095.0);
  float voltage2 = sensorValue2 * (3.3 / 4095.0);
  float voltage3 = sensorValue3 * (3.3 / 4095.0);
  float voltage4 = sensorValue4 * (3.3 / 4095.0);
  float voltage5 = sensorValue5 * (3.3 / 4095.0);
  float voltage6 = sensorValue6 * (3.3 / 4095.0);

  // Print sensor 1 data
  Serial.print("Sensor 1 (A0) - Analog value: ");
  Serial.print(sensorValue1);
  Serial.print("\tVoltage: ");
  Serial.print(voltage1);
  Serial.println(" V");

  // Print sensor 2 data
  Serial.print("Sensor 2 (A1) - Analog value: ");
  Serial.print(sensorValue2);
  Serial.print("\tVoltage: ");
  Serial.print(voltage2);
  Serial.println(" V"); 

  // Print sensor 3 data
  Serial.print("Sensor 3 (A2) - Analog value: ");
  Serial.print(sensorValue3);
  Serial.print("\tVoltage: ");
  Serial.print(voltage3);
  Serial.println(" V");

  // Print sensor 4 data
  Serial.print("Sensor 4 (A3) - Analog value: ");
  Serial.print(sensorValue4);
  Serial.print("\tVoltage: ");
  Serial.print(voltage4);
  Serial.println(" V");

  // Print sensor 2 data
  Serial.print("Sensor 5 (A4) - Analog value: ");
  Serial.print(sensorValue5);
  Serial.print("\tVoltage: ");
  Serial.print(voltage5);
  Serial.println(" V"); 

  // Print sensor 3 data
  Serial.print("Sensor 6 (A5) - Analog value: ");
  Serial.print(sensorValue6);
  Serial.print("\tVoltage: ");
  Serial.print(voltage6);
  Serial.println(" V");

  Serial.println();

  // if(sensorValue1 >= threshold){
  //   Serial.println("black line detected at sensor 1");
  // }
  // if(sensorValue2 >= threshold){
  //   Serial.println("black line detected at sensor 2");
  // }
  // if(sensorValue3 >= threshold){
  //   Serial.println("black line detected at sensor 3");
  // }


  // if(sensorValue4 >= threshold){
  //   Serial.println("black line detected at sensor 4");
  // }
  // if(sensorValue5 >= threshold){
  //   Serial.println("black line detected at sensor 5");
  // }
  // if(sensorValue6 >= threshold){
  //   Serial.println("black line detected at sensor 6   ");
  // }

  // Serial.println();


  // //serial plotter printing
  // Serial.print(voltage1);
  // Serial.print(" ");  // Space separator
  // Serial.print(voltage2);
  // Serial.print(" ");
  // Serial.print(voltage3);
  // Serial.print(" ");
  // Serial.print(voltage4);
  // Serial.print(" ");
  // Serial.print(voltage5);
  // Serial.print(" ");
  // Serial.println(voltage6);  // End the line here

}
