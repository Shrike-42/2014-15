#include "sciencestationDefine.h"
//#include <Wire.h>

void setup() {
  // initialize serial communications:
  // Wire.begin();
  Serial.begin(BAUD_RATE);
}

void loop() {
  // sendReadings(humidityReading(), phReading());
  int phValue = phReading();
  delay(TimeBetweenReadings);// delay in between reads for stability
}

