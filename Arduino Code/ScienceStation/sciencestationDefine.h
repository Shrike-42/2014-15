#include "Arduino.h"
#include <Servo.h>
#define BAUD_RATE 9600

Servo cameras[4];
const int TOCAMERAPINS[4] = {3,5,6,9};
const int CTRLHIGHPINS[4] = {2,4,7,8};
const int CTRLLOWPINS[4] = {10,11,12,13};

int TimeBetweenReadings = 10;
const int pHPin = A1;


