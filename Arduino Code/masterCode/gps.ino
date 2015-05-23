void initializeGPS()
{
    GPS.begin(9600);
}


void updateGPS()
{
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write("N" + GPS.lat);
    Udp.write("W" + GPS.lon);
    Udp.endPacket();
}
