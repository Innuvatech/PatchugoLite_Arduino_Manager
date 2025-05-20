#define PATCHUGO_INTERNAL_USE
#include "i2c_manager.h"
#undef PATCHUGO_INTERNAL_USE

void I2C_Manager::I2C_Init(uint8_t address) {
    Wire.end();
    addr = address;
    Wire.begin();
}

void I2C_Manager::I2C_Write(uint8_t *data, uint8_t len) {
    Wire.beginTransmission(addr);
    if(len == 1) {
        Wire.write(data[0]);
    }else {
        Wire.write(data, len);
    }
    Wire.endTransmission();
}

void I2C_Manager::I2C_Read(uint8_t address, uint8_t len, uint8_t *readData) {
    Wire.requestFrom(addr, len);

    uint8_t i = 0;
    while(Wire.available()) {
        readData[i] = Wire.read();
        i++;
    }
}