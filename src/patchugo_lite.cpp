#include "patchugo_lite.h"

void PatchugoLite::Init(void) {

    ioManager.Init_IO_Pins();
}

void PatchugoLite::IO_Write(OutputPin pin, FlagStatus status) {
    return ioManager.Write_Pin(pin, status);
}

uint8_t PatchugoLite::IO_Read(InputPin pin) {
    return ioManager.Read_Pin(pin);
}