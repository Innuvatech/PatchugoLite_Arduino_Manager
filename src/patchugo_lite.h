#ifndef PATCHUGO_LITE.H
#define PATCHUGO_LITE_H

#define PATCHUGO_INTERNAL_USE
#include "io_types.h"
#include "io_manager.h"
#undef PATCHUGO_INTERNAL_USE

class PatchugoLite {
    private:
        IO_Manager ioManager;
    public:
        //Number of 24V IN and OUT pins on the board
        static constexpr uint8_t N_OUT_PINS = 8;
        static constexpr uint8_t N_IN_PINS = 8;
        OutputPin outputPinsList[N_OUT_PINS] = {
            OutputPin::OUT_1,
            OutputPin::OUT_2,
            OutputPin::OUT_3,
            OutputPin::OUT_4,
            OutputPin::OUT_5,
            OutputPin::OUT_6,
            OutputPin::OUT_7,
            OutputPin::OUT_8,
        };

        InputPin inputPinsList[N_IN_PINS] = {
            InputPin::IN_1,
            InputPin::IN_2,
            InputPin::IN_3,
            InputPin::IN_4,
            InputPin::IN_5,
            InputPin::IN_6,
            InputPin::IN_7,
            InputPin::IN_8,
        };

        /**
         * @brief Initializes all board peripherals
         * 
         */
        void Init(void);
        /**
         * @brief Writes to one of the 8 24V digital OUTPUT pins
         * 
         * @param pin Enum of the pin to write
         * @param status Status to write to the pin
         */
        void IO_Write(OutputPin pin, FlagStatus status);

        /**
         * @brief Reads one of the 8 24V digital INPUT pins
         * 
         * @param pin Enum of the pin to read
         * @return uint8_t Value read from the pin
         */
        uint8_t IO_Read(InputPin pin);

};

#endif