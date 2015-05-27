int phReading()
{
	double Count;
        double Voltage;
	double pH;
        // int pHint;
	Count = analogRead(pHPin);
	Voltage = Count / 1023 * 5.0;// convert from count to raw voltage
        pH = Voltage / 0.36;
	// pHint = Count * 1000 * 5 / (1023 * 36);
        Serial.print("Count:");
        Serial.println(Count);
	Serial.print("Voltage: ");
	Serial.println(Voltage);
	Serial.print("pH: ");
	Serial.println(pH);
        
	return (int) (pH * 100); //multiply by 1000 before converting to int so that all sig figs are preserved
}
