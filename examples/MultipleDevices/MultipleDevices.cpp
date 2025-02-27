#include <Wire.h>
#include "IS31FL3193.h"

IS31FL3193 led1(0x68);  // AD → GND
IS31FL3193 led2(0x69);  // AD → SCL
IS31FL3193 led3(0x6A);  // AD → SDA

void setup() {
    Wire.begin();
    led1.begin();
    led2.begin();
    led3.begin();

    led1.enable();
    led2.enable();
    led3.enable();
}

void loop() {
    led1.setColor(255, 0, 0);  // Rosso
    delay(500);
    led2.setColor(0, 255, 0);  // Verde
    delay(500);
    led3.setColor(0, 0, 255);  // Blu
    delay(500);
}
