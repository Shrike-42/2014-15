#include <Servo.h>

void initializeCameraServo()
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

void controlCameraDirection()
{
  for (int i = 0; i <= 3; i++)
  {
    controlHigh[i] = digitalRead(CTRLHIGHPINS[i]);
    delay(TimeBetweenReadings);
    controlLow[i] = digitalRead(CTRLLOWPINS[i]);
    delay(TimeBetweenReadings);
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
    delay(TimeBetweenReadings);
  }
} 
