int phReading()
{
	float Count;
	// float Voltage;
	int pH;
	Count = analogRead(pHPin);
	// Voltage = Count / 1023 * 5.0;// convert from count to raw voltage
	pH = Count * 1000 / 1023 * 5.0 * 0.36;
//	Serial.print("Voltage: ");
//	Serial.println(Voltage);
//	Serial.print("pH: ");
//	Serial.println(pH);
	return pH; //multiply by 1000 before converting to int so that all sig figs are preserved
}
