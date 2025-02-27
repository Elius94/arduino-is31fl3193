#include "IS31FL3193.h"

// Registri del IS31FL3193
#define REG_CONFIG  0x00
#define REG_SHUTDOWN 0x01
#define REG_PWM_RED  0x02
#define REG_PWM_GREEN 0x03
#define REG_PWM_BLUE 0x04
#define REG_BRIGHTNESS 0x05
#define REG_CURRENT 0x06

IS31FL3193::IS31FL3193(TwoWire &wire) {
    _wire = &wire;
}

bool IS31FL3193::begin() {
    _wire->begin();
    reset();
    return true;
}

void IS31FL3193::reset() {
    writeRegister(REG_CONFIG, 0x00);  // Reset configurazione
}

void IS31FL3193::setBrightness(uint8_t brightness) {
    writeRegister(REG_BRIGHTNESS, brightness);
}

void IS31FL3193::setCurrent(uint8_t current) {
    writeRegister(REG_CURRENT, current);
}

void IS31FL3193::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    writeRegister(REG_PWM_RED, red);
    writeRegister(REG_PWM_GREEN, green);
    writeRegister(REG_PWM_BLUE, blue);
}

void IS31FL3193::enable() {
    writeRegister(REG_SHUTDOWN, 0x01);  // Accendi il driver
}

void IS31FL3193::disable() {
    writeRegister(REG_SHUTDOWN, 0x00);  // Spegni il driver
}

void IS31FL3193::writeRegister(uint8_t reg, uint8_t value) {
    _wire->beginTransmission(IS31FL3193_I2C_ADDR);
    _wire->write(reg);
    _wire->write(value);
    _wire->endTransmission();
}
