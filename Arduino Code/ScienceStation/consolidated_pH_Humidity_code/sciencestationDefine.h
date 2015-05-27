#include "Arduino.h"
#define BAUD_RATE 9600
// const int humPin = A0;
boolean humcalibrated = true;
double humcalibratedValue = 640.0;
int TimeBetweenReadings = 500;
const int pHPin = A1;


