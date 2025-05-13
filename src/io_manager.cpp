#define PATCHUGO_INTERNAL_USE
#include "io_manager.h"
#undef PATCHUGO_INTERNAL_USE

/**
 * @brief Converts a member of @ref OutputPin to its corresponding integer value
 * 
 * @param pin The pin enum to convert
 * @return uint32_t Integer representation of the enum
 */
static inline uint32_t OutputPinToInt(OutputPin pin) {
    return static_cast<uint32_t>(pin);
}

/**
 * @brief Converts a member of @ref InputPin to its corresponding integer value
 * 
 * @param pin The pin enum to convert
 * @return uint32_t Integer representation of the enum
 */
static inline uint32_t InputPinToInt(InputPin pin) {
    return static_cast<uint32_t>(pin);
}

void IO_Manager::Init_IO_Pins(void) {

    //Init OUTPUT pins
    pinMode(OutputPinToInt(OutputPin::OUT_1), OUTPUT);
    pinMode(OutputPinToInt(OutputPin::OUT_2), OUTPUT);
    pinMode(OutputPinToInt(OutputPin::OUT_3), OUTPUT);
    pinMode(OutputPinToInt(OutputPin::OUT_4), OUTPUT);
    pinMode(OutputPinToInt(OutputPin::OUT_5), OUTPUT);
    pinMode(OutputPinToInt(OutputPin::OUT_6), OUTPUT);
    pinMode(OutputPinToInt(OutputPin::OUT_7), OUTPUT);
    pinMode(OutputPinToInt(OutputPin::OUT_8), OUTPUT);

    //Init INPUT pins
    pinMode(InputPinToInt(InputPin::IN_1), INPUT);
    pinMode(InputPinToInt(InputPin::IN_2), INPUT);
    pinMode(InputPinToInt(InputPin::IN_3), INPUT);
    pinMode(InputPinToInt(InputPin::IN_4), INPUT);
    pinMode(InputPinToInt(InputPin::IN_5), INPUT);
    pinMode(InputPinToInt(InputPin::IN_6), INPUT);
    pinMode(InputPinToInt(InputPin::IN_7), INPUT);
    pinMode(InputPinToInt(InputPin::IN_8), INPUT);
}

void IO_Manager::Write_Pin(OutputPin pin, FlagStatus status) {
    digitalWrite(OutputPinToInt(pin), status);
}

uint8_t IO_Manager::Read_Pin(InputPin pin) {
    return digitalRead(InputPinToInt(pin));
}