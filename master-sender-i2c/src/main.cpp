#include <Arduino.h>
#include <Wire.h>

void setup() {
    Serial.begin(9600);
    Wire.begin();
    Wire.setClock(400000);
}

void loop() {
    
}

void serialEvent()
{
    while(Serial.available()>0)
    {
        char led = (char)Serial.read();
        int duty_cycle = (int)Serial.parseInt();

        Wire.beginTransmission(8);
        Wire.write(led);
        Wire.write((uint8_t)duty_cycle);
        Wire.endTransmission();
        delay(10);
    }
}