void initializeCompressor()
{
    pinMode(COMPRESSOR_CONTROL, OUTPUT);
    pinMode(COMPRESSOR_PIN, INPUT);
    Serial.println("INITIALIZED");
}


void compressorPressureCheck()
{
    int pressureValue = analogRead(COMPRESSOR_PIN) * 0.363;
    Serial.println(pressureValue);
    if(pressureValue < 125) {
        digitalWrite(COMPRESSOR_CONTROL, HIGH);
    } 
    else if(pressureValue > 165) {
        digitalWrite(COMPRESSOR_CONTROL, LOW);
    }
}

