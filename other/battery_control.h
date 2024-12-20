//Arkash Sundralingam 101115738

void battery() {
  float variableBattery = readBatteryVoltage(); 
  int batteryPercentage = calculateBatteryPercentage(variableBattery);
  delay(10000); }

float readBatteryVoltage() {
  int rawValue = analogRead(batteryPin) ; // v(in)
  float voltage = rawValue * (4200.0/ 1024);
  return voltage;
}

int calculateBatteryPercentage(float voltage) {
  float minVoltage = 10800; // Minimum voltage
  float maxVoltage = 12600; // Maximum voltage
  int batteryPercentage = map(voltage, minVoltage, maxVoltage, 0, 100) ;
  batteryPercentage = constrain(batteryPercentage, 0, 100); // Limit to 0-100
  return batteryPercentage;
}
