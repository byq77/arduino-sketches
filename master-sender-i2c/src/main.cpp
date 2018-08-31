#include <Arduino.h>
#define LED 5

void setup() {
    DDRB |= 1<<LED;
}

void loop() {
    PORTB ^= 1<<LED;
    delay(500);
}