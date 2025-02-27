#include <Wire.h>
#include <IS31FL3193.h>

IS31FL3193 ledDriver;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    
    if (!ledDriver.begin()) {
        Serial.println("IS31FL3193 non trovato!");
        while (1);
    }

    ledDriver.enable();
    ledDriver.setBrightness(255);
    ledDriver.setCurrent(10);
    ledDriver.setColor(255, 0, 0); // LED rosso
}

void loop() {
    delay(1000);
}
