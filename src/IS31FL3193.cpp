#include "IS31FL3193.h"

// Registri dal Datasheet
#define REG_SHUTDOWN 0x00
#define REG_BREATHING 0x01
#define REG_MODE 0x02
#define REG_CURRENT 0x03
#define REG_PWM_OUT1 0x04
#define REG_PWM_OUT2 0x05
#define REG_PWM_OUT3 0x06
#define REG_UPDATE 0x07

IS31FL3193::IS31FL3193(uint8_t address, TwoWire &wire) {
    _address = address;
    _wire = &wire;
}

bool IS31FL3193::begin() {
    _wire->begin();
    reset();
    return true;
}

void IS31FL3193::reset() {
    writeRegister(REG_SHUTDOWN, 0x01);  // Accende il chip
    writeRegister(REG_BREATHING, 0x00); // Disabilita effetto respiro
    writeRegister(REG_MODE, 0x00);      // Modalità PWM
    writeRegister(REG_CURRENT, 0x00);   // Imposta corrente max (42mA)
}

void IS31FL3193::setBrightness(uint8_t brightness) {
    writeRegister(REG_PWM_OUT1, brightness);
    writeRegister(REG_PWM_OUT2, brightness);
    writeRegister(REG_PWM_OUT3, brightness);
    writeRegister(REG_UPDATE, 0x00);  // Aggiorna i valori
}

void IS31FL3193::setCurrent(uint8_t current) {
    writeRegister(REG_CURRENT, current);
}

void IS31FL3193::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    writeRegister(REG_PWM_OUT1, red);
    writeRegister(REG_PWM_OUT2, green);
    writeRegister(REG_PWM_OUT3, blue);
    writeRegister(REG_UPDATE, 0x00);  // Aggiorna i valori
}

void IS31FL3193::enable() {
    writeRegister(REG_SHUTDOWN, 0x01);
}

void IS31FL3193::disable() {
    writeRegister(REG_SHUTDOWN, 0x00);
}

void IS31FL3193::writeRegister(uint8_t reg, uint8_t value) {
    _wire->beginTransmission(_address);
    _wire->write(reg);
    _wire->write(value);
    _wire->endTransmission();
}
