#include <Arduino.h>
#include <Wire.h>
#define RGB_R 3
#define RGB_G 9
#define RGB_B 10

void receiveEvent(int);

void setup() {
    Wire.begin(8); // Join bus as slave with address 8
    Wire.onReceive(receiveEvent);
    pinMode(RGB_R,OUTPUT);
    pinMode(RGB_G,OUTPUT);
    pinMode(RGB_B,OUTPUT);
    digitalWrite(RGB_R,HIGH);
    digitalWrite(RGB_G,HIGH);
    digitalWrite(RGB_B,HIGH);
}

void loop() {
    // put your main code here, to run repeatedly:
}

void receiveEvent(int howMany) {
    if(howMany == 2)
    {
        char led = (char)Wire.read();
        uint8_t duty_cycle = (char)Wire.read();
        switch(led)
        {
            case 'r':
                analogWrite(RGB_R,duty_cycle);
                break;
            case 'g':
                analogWrite(RGB_G,duty_cycle);
                break;
            case 'b':
                analogWrite(RGB_B,duty_cycle);
                break;
            default:
                break;
        }
    }
}