#define PATCHUGO_INTERNAL_USE
#include "spi_manager.h"
#undef PATCHUGO_INTERNAL_USE

void SPI_Manager::SPI_Init_CS() {
    pinMode(csPin, OUTPUT);
}

void SPI_Manager::SPI_Init(uint32_t clock, BitOrder order, SPIMode mode) {
    SPI.end();
    SPI.begin();
    settings = SPISettings(clock, order, mode);
}

void SPI_Manager::SPI_Write(uint8_t *data, uint8_t len) {
    digitalWrite(csPin, LOW);
    SPI.beginTransaction(settings);
    SPI.transfer(data, len);
    SPI.endTransaction();
    digitalWrite(csPin, HIGH);
}

void SPI_Manager::SPI_Read(uint8_t reg, uint8_t len, uint8_t *readValue) {
   
    digitalWrite(csPin, LOW);
    SPI.beginTransaction(settings);
    SPI.transfer(reg);
    for(uint8_t i = 0; i < len; i++) {
        readValue[i] = SPI.transfer(0x00);
    }
    SPI.endTransaction();
    digitalWrite(csPin, HIGH);

    
}