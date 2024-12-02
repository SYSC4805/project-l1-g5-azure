volatile uint32_t CaptureCountA, CaptureCountB;
volatile boolean CaptureFlagA = false, CaptureFlagB = false;

// Sensor 1 pins
#define trigPin1 2  // TC0, Channel 0 (Pin 2)
#define echoPin1 A7

// Sensor 2 pins
#define trigPin2 13  // TC0, Channel 1 (Pin 13)
#define echoPin2 A6

void setup() {
  Serial.begin(115200);

  // Sensor 1 Trigger Configuration (Pin 2 - TC0, Channel 0)
  PMC->PMC_PCER0 |= PMC_PCER0_PID27; // Enable TC0 Channel 0 for trigger
  PIOB->PIO_PDR |= PIO_PDR_P25;      // Disable GPIO control for PB25 (Trig Pin)
  PIOB->PIO_ABSR |= PIO_PB25B_TIOA0; // Select Peripheral B for PB25 (Trig Pin)
  TC0->TC_CHANNEL[0].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK1 | TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_ACPA_CLEAR | TC_CMR_ACPC_SET;
  TC0->TC_CHANNEL[0].TC_RC = 2520000 - 1;  // 60 ms period
  TC0->TC_CHANNEL[0].TC_RA = 420 - 1;      // 10 microsecond pulse width
  TC0->TC_CHANNEL[0].TC_CCR = TC_CCR_SWTRG | TC_CCR_CLKEN;

  // Sensor 1 Echo Configuration (Pin A7)
  PMC->PMC_PCER0 |= PMC_PCER0_PID28; // Enable TC0 Channel 1 for echo
  TC0->TC_CHANNEL[1].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK1 | TC_CMR_ABETRG | TC_CMR_LDRA_FALLING | TC_CMR_ETRGEDG_RISING;
  TC0->TC_CHANNEL[1].TC_CCR = TC_CCR_SWTRG | TC_CCR_CLKEN;
  TC0->TC_CHANNEL[1].TC_IER |= TC_IER_LDRAS; // Enable interrupt for Load RA
  NVIC_EnableIRQ(TC1_IRQn); // Enable interrupts for Timer Counter 1

  // // Sensor 2 Trigger Configuration (Pin 13 - TC0, Channel 1)
  // PIOC->PIO_PDR |= PIO_PDR_P29;      // Disable GPIO control for Pin 13 (Trig Pin)
  // PIOC->PIO_ABSR |= PIO_PC13B_TIOA1; // Select Peripheral B for PC13 (Trig Pin)
  // TC0->TC_CHANNEL[1].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK1 | TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_ACPA_CLEAR | TC_CMR_ACPC_SET;
  // TC0->TC_CHANNEL[1].TC_RC = 2520000 - 1;  // 60 ms period
  // TC0->TC_CHANNEL[1].TC_RA = 420 - 1;      // 10 microsecond pulse width
  // TC0->TC_CHANNEL[1].TC_CCR = TC_CCR_SWTRG | TC_CCR_CLKEN;

  // // Sensor 2 Echo Configuration (Pin A6)
  // PMC->PMC_PCER0 |= PMC_PCER0_PID28; // Enable TC0 Channel 2 for echo
  // TC0->TC_CHANNEL[2].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK1 | TC_CMR_ABETRG | TC_CMR_LDRA_FALLING | TC_CMR_ETRGEDG_RISING;
  // TC0->TC_CHANNEL[2].TC_CCR = TC_CCR_SWTRG | TC_CCR_CLKEN;
  // TC0->TC_CHANNEL[2].TC_IER |= TC_IER_LDRAS; // Enable interrupt for Load RA
  // NVIC_EnableIRQ(TC2_IRQn); // Enable interrupts for Timer Counter 2
}

void loop() {
  if (CaptureFlagA) {
    CaptureFlagA = false;
    float distanceA = 340.0 * CaptureCountA / (42000000.0) / 2 * 100;
    Serial.print("Sensor 1 Distance: ");
    Serial.print(distanceA);
    Serial.println(" cm");
  }

  // if (CaptureFlagB) {
  //   CaptureFlagB = false;
  //   float distanceB = 340.0 * CaptureCountB / (42000000.0) / 2 * 100;
  //   Serial.print("Sensor 2 Distance: ");
  //   Serial.print(distanceB);
  //   Serial.println(" cm");
  // }
}

// Interrupt Service Routines for Timer Counters
void TC1_Handler() {
  uint32_t status = TC0->TC_CHANNEL[1].TC_SR; // Read status register to clear interrupt
  if (status & TC_SR_LDRAS) {
    CaptureCountA = TC0->TC_CHANNEL[1].TC_RA;
    CaptureFlagA = true;
  }

  // uint32_t statusB = TC0->TC_CHANNEL[2].TC_SR; // Read status for Sensor 2
  // if (statusB & TC_SR_LDRAS) {
  //   CaptureCountB = TC0->TC_CHANNEL[2].TC_RA;
  //   CaptureFlagB = true;
  // }
}





