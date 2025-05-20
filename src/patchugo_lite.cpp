#include "patchugo_lite.h"

void PatchugoLite::Init(void) {

    ioManager.Init_IO_Pins();
    RS485_Set_Baudrate(RS485_Baud::BAUD_115200);
    BT_Init();
    BT_Set_Mode(BTMode::COMMAND);
    BT_Reset();
    BT_Change_Name("PatchugoLite");
    RS485_Init();
    spiManager.SPI_Init_CS();
}

void PatchugoLite::IO_Write(OutputPin pin, FlagStatus status) {
    return ioManager.Write_Pin(pin, status);
}

uint8_t PatchugoLite::IO_Read(InputPin pin) {
    return ioManager.Read_Pin(pin);
}

void PatchugoLite::BT_Init(void) {
    btManager.BT_Init();
}

void PatchugoLite::BT_Set_Mode(BTMode mode) {
    btManager.BT_Set_Mode(mode);
}

void PatchugoLite::BT_Reset(void) {
    btManager.BT_Reset();
}

PatchugoStatusCode PatchugoLite::BT_Change_Name(const char *name) {
    return btManager.BT_Change_Name(name);
}

PatchugoStatusCode PatchugoLite::BT_Write(uint8_t *data, uint8_t len) {
    return btManager.BT_Write(data, len);
}

void PatchugoLite::BT_Update(void) {
    btManager.BT_Update();
}

void PatchugoLite::BT_Set_RXCallback(BT_RX_Callback callback){
    btManager.BT_Set_RXCallback(callback);
}

void PatchugoLite::RS485_Init(void) {
    serialManager.Init();
}

void PatchugoLite::RS485_Set_Mode(RS485_Mode mode) {
    serialManager.RS485_Set_Mode(mode);
}

void PatchugoLite::RS485_Set_Baudrate(RS485_Baud baudrate) {
    serialManager.RS485_Set_Baud(baudrate);
}

void PatchugoLite::RS485_Write(uint8_t *data, uint8_t len) {
    serialManager.RS485_Write(data, len);
}

void PatchugoLite::RS485_Update(void) {
    serialManager.RS485_Update();
}

void PatchugoLite::RS485_Set_RXCallback(RS485_RX_Callback callback) {
    serialManager.RS485_Set_RXCallback(callback);
}

void PatchugoLite::SPI_Init(uint32_t clock, BitOrder order, SPIMode mode) {
    spiManager.SPI_Init(clock,order,mode);
}

void PatchugoLite::SPI_Write(uint8_t *data, uint8_t len) {
    spiManager.SPI_Write(data, len);
}

void PatchugoLite::SPI_Read(uint8_t reg, uint8_t len, uint8_t *readValue) {
    spiManager.SPI_Read(reg, len, readValue);
}