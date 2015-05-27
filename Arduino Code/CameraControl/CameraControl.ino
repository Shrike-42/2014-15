#include <Servo.h>

const int TOCAMERAPINS[4] = {3,5,6,9};
const int CTRLHIGHPINS[4] = {2,4,7,8};
const int CTRLLOWPINS[4] = {10,11,12,13};

Servo cameras[4];

void setup()
{
  for (int i = 0; i <= 3; i++)
  {
    pinMode(TOCAMERAPINS[i], OUTPUT);
    pinMode(CTRLHIGHPINS[i], INPUT);
    pinMode(CTRLLOWPINS[i], INPUT);
    cameras[i].attach(TOCAMERAPINS[i]);
  }
}

boolean controlHigh[4];
boolean controlLow[4];

void loop()
{
  for (int i = 0; i <= 3; i++)
  {
    controlHigh[i] = digitalRead(CTRLHIGHPINS[i]);
    controlLow[i] = digitalRead(CTRLLOWPINS[i]);
  }
  for (int i = 0; i <= 3; i++)
  {
    if (controlHigh[i] == 1 && controlLow[i] == 0)
    {
      cameras[i].write(10); // Move upward
    }
    else if (controlHigh[i] == 1 && controlLow[i] == 0)
    {
      cameras[i].write(-10); // Move downward
    }
    else if (controlHigh[i] == 1 && controlLow[i] == 1)
    {
      cameras[i].write(0); // Stay put
    }
  }
} 
