// BASE STATION PAN-TILT CODE
// HARDWARE: Arduino UNO R3, Ethernet Shield
#include "Arduino.h"
#include "megaBoardDefine.h"
#include <Adafruit_GPS.h>  // include this file in the Arduino libraries folder
#include <Servo.h>
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#define BASE_GPS_LAT
#define BASE_GPS_LON
#define UDP_PORT = 8888;

IPAddress ip(192, 168, 1, 177);
EthernetUDP Udp;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
Servo pan;

void setup()
{
    pan.attach(9);
    Ethernet.begin(mac, ip);
    Udp.begin(UDP_PORT);
}


void loop()
{
    getRoverGPS();
    adjustPan();
}


void getRoverGPS()
{
    // get UDP packet
    // parse udp packet
}


void adjustPan()
{
    // check magnetometer
    // get heading from GPS coords
    // turn Pan
}
