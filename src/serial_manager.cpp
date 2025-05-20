#define PATCHUGO_INTERNAL_USE
#include "serial_manager.h"
#undef PATCHUGO_INTERNAL_USE
#include <HardwareSerial.h>

HardwareSerial rs485Serial(PB11, PB10);

void Serial_Manager::Init(void) {
    pinMode(DE_PIN, OUTPUT);
}

void Serial_Manager::RS485_Set_Mode(RS485_Mode mode) {
    uint8_t modeInt = static_cast<uint8_t>(mode);
    digitalWrite(DE_PIN, modeInt);
    rs485Mode = mode;
}

void Serial_Manager::RS485_Set_Baud(RS485_Baud baudrate) {
    rs485Serial.end();
    uint32_t baud = static_cast<uint32_t>(baudrate);
    rs485Serial.begin(baud);
}

PatchugoStatusCode Serial_Manager::RS485_Write(uint8_t *data, uint8_t len) {

    if(rs485Mode != RS485_Mode::TX) return PatchugoStatusCode::ERROR_WRONG_MODE;

    rs485Serial.write(data, len);
    delay(1);

    return PatchugoStatusCode::OK;
}

void Serial_Manager::RS485_Set_RXCallback(RS485_RX_Callback callback) {
    rxCallback = callback;
}

void Serial_Manager::RS485_Update(void) {
     while(rs485Serial.available()) {
        uint8_t byte = rs485Serial.read();
        Serial.println(byte);

        rs485RxBuf[rs485RxCount] = byte;
        rs485RxCount++;
        delay(1);
    }

     if(rs485RxCount > 0) {
        rxCallback(rs485RxBuf,rs485RxCount);
        memset(rs485RxBuf, 0, rs485RxCount);
        rs485RxCount = 0;
    }
}