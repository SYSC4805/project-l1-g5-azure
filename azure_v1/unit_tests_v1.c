#include <assert.h>
#include "azzure_v1.h"

extern volatile bool object1Detected;
extern volatile bool object2Detected;

void simSensor1Detect(bool detected) {
    object1Detected = detected;
}

void simSensor2Detect(bool detected) {
    object2Detected = detected;
}

void test_scan_snow() {
    // Test 1: No objects detected
    simSensor1Detect(false);
    simSensor2Detect(false);
    bool result = scan_snow();
    assert(result == false);  // Expecting scan_snow to return false
    Serial.println("Test 1 passed: No objects detected");

    // Test 2: Object detected by sensor 1
    simSensor1Detect(true);
    simSensor2Detect(false);
    result = scan_snow();
    assert(result == true);  
    Serial.println("Test 2 passed: Object detected by sensor 1");

    // Test 3: Object detected by sensor 2
    simSensor1Detect(false);
    simSensor2Detect(true);
    result = scan_snow();
    assert(result == true);  
    Serial.println("Test 3 passed: Object detected by sensor 2");

    // Test 4: Both objects detected
    simSensor1Detect(true);
    simSensor2Detect(true);
    result = scan_snow();
    assert(result == true);  
    Serial.println("Test 4 passed: Both objects detected");

    // Test 5: Scan timeout (x > 8)
    simSensor1Detect(false);
    simSensor2Detect(false);
    int loopCounter = 9; 
    result = scan_snow();
    assert(result == false);  
    Serial.println("Test 5 passed: Scan timeout");
}

void setup() {
    Serial.begin(115200);
    Serial.println("Starting unit tests...");

    test_scan_snow();

    Serial.println("All unit tests passed!");
}

void loop() {
    
}
