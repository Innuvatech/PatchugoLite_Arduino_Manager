#include "patchugo_lite.h"

void PatchugoLite::Init(void) {

    ioManager.Init_IO_Pins();
    BT_Init();
    BT_Set_Mode(BTMode::COMMAND);
    BT_Reset();
    BT_Change_Name("PatchugoLite");
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