#ifndef IS31FL3193_H
#define IS31FL3193_H

#include <Arduino.h>
#include <Wire.h>

#define IS31FL3193_I2C_ADDR 0x64  // Indirizzo I2C predefinito

class IS31FL3193 {
public:
    IS31FL3193(uint8_t address, TwoWire &wire = Wire);

    bool begin();
    void reset();
    void setBrightness(uint8_t brightness);
    void setCurrent(uint8_t current);
    void setColor(uint8_t red, uint8_t green, uint8_t blue);
    void enable();
    void disable();

private:
    uint8_t _address;
    TwoWire *_wire;
    void writeRegister(uint8_t reg, uint8_t value);
};

#endif
