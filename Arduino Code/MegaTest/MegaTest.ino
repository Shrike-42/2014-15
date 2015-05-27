#include "Arduino.h"
#define BAUD_RATE 9600
void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD_RATE*4);
  Serial2.begin(BAUD_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial2.available()) {
    char inByte = Serial2.read();
    Serial.write(inByte);
  }
}
