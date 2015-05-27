#include "sciencestationDefine.h"

void setup() {
  // initialize serial communications:
  Serial.begin(BAUD_RATE);
  initializeCameraServo();
}

void loop() {
  controlCameraDirection();
  int pHValue = phReading();
  Serial.println(pHValue);
  delay(TimeBetweenReadings);// delay in between reads for stability
}

