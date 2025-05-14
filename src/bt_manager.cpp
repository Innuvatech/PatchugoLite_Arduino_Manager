#define PATCHUGO_INTERNAL_USE
#include "bt_manager.h"
#undef PATCHUGO_INTERNAL_USE
#include <string.h>
#include <HardwareSerial.h>

HardwareSerial btSerial(PG9,PG14);

static inline uint8_t BT_Calc_CS(uint8_t buf[], uint8_t len) {
    uint8_t cs = 0;
    for(uint8_t i = 0; i < len; i++) {
        cs ^= buf[i];
    }
    return cs;
}

void BT_Manager::BT_Init(void) {
    btSerial.begin(115200);

    pinMode(BT_RESET_PIN, OUTPUT);
    pinMode(BT_MODE_PIN, OUTPUT);
}

void BT_Manager::BT_Set_Mode(BTMode mode) {
    uint8_t modeInt = static_cast<uint8_t>(mode);
    digitalWrite(BT_Manager::BT_MODE_PIN,modeInt);
    currentMode = mode;
    delay(30);
    BT_Reset();
}

void BT_Manager::BT_Reset(void) {
    digitalWrite(BT_Manager::BT_RESET_PIN, RESET);
    delay(30);
    digitalWrite(BT_Manager::BT_RESET_PIN,SET);
}

PatchugoStatusCode BT_Manager::BT_Change_Name(const char *name) {
    if(currentMode != BTMode::COMMAND) return PatchugoStatusCode::ERROR_WRONG_MODE;
    uint32_t nameLen = strlen(name);
    if(nameLen > BT_MAX_NAME_LEN) return PatchugoStatusCode::ERROR_BT_NAME_LEN;
    

    uint8_t payloadLen = nameLen + 1;
    uint8_t cmdLen = payloadLen + 5;

    uint8_t cmd[cmdLen] = {0};

    cmd[0] = BT_CMD_SOF;
    cmd[1] = BT_CMD_CHANGE_NAME;
    cmd[2] = payloadLen;
    cmd[3] = 0x00;
    cmd[4] = BT_CMD_CHANGE_NAME_SINDEX;
    memcpy(&cmd[5],name,nameLen);

    cmd[cmdLen - 1] = BT_Calc_CS(cmd, cmdLen - 1);

    btSerial.write(cmd, cmdLen);

    return PatchugoStatusCode::OK;
}

PatchugoStatusCode BT_Manager::BT_Write(uint8_t *data, uint8_t len) {
    if(currentMode != BTMode::TRANSPARENT) return PatchugoStatusCode::ERROR_WRONG_MODE;

    btSerial.write(data, len);

    return PatchugoStatusCode::OK;
}

void BT_Manager::BT_Set_RXCallback(BT_RX_Callback callback) {
    rxCallback = callback;
}


void BT_Manager::BT_Update(void) {

    while(btSerial.available()) {
        uint8_t byte = btSerial.read();

        btRxBuf[btRxCount] = byte;
        btRxCount++;
        delay(1);
    }

    if(btRxCount > 0) {
        rxCallback(btRxBuf,btRxCount);
        memset(btRxBuf, 0, btRxCount);
        btRxCount = 0;
    }
}