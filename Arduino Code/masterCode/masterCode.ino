// HARDWARE: Arduino MEGA 2560
#include "Arduino.h"
#include "megaBoardDefine.h"
#include <Adafruit_GPS.h>  // include this file in the Arduino libraries folder
#include <Servo.h>
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LSM303.h>

void setup()
{
    attachDriveMotors();
    attachArmMotors();
    attachHandMotors();
    initializeWireless();
    initializeGPS();
    initializeCompass();
    Wire.begin();
}

void loop()
{
    overCurrentCheck();
    timeoutCheck();
    compressorPressureCheck();    
    receiveWirelessData();
    writeToDriveMotors();
    writeToArmMotors();
    writeToHandMotors();
    updateGPS();
    updateCompass();
}

