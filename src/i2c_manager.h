#ifndef I2C_MANAGER_H
#define I2C_MANAGER_H

#ifndef PATCHUGO_INTERNAL_USE
#error "i2c_manager.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif

#define PATCHUGO_I2C_TYPES
#include "i2c_types.h"
#undef PATCHUGO_I2C_TYPES

class I2C_Manager {
    private:
        uint8_t addr;
    public:
        void I2C_Init(uint8_t address);
        void I2C_Write(uint8_t *data, uint8_t len);
        void I2C_Read(uint8_t address, uint8_t len, uint8_t *readData);
};

#endif