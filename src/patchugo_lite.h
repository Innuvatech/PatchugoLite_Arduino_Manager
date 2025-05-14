#ifndef PATCHUGO_LITE_H
#define PATCHUGO_LITE_H

#define PATCHUGO_INTERNAL_USE
#include "io_manager.h"
#include "bt_manager.h"
#undef PATCHUGO_INTERNAL_USE

class PatchugoLite {
    private:
        IO_Manager ioManager;
        BT_Manager btManager;
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

        /**
        * @brief Initializes bluetooth peripheral.
        * This is already called inside Init so it can be omitted if Init is called
        * 
        */
        void BT_Init(void);

        /**
        * @brief Sets the Proteus-E to the given operating mode
        * 
        * @param mode Operating mode to set
        */
        void BT_Set_Mode(BTMode mode);

        /**
        * @brief Resets the Proteus-E module
        * 
        */
        void BT_Reset(void);

        /**
        * @brief Changes to Proteus-E bluetooth name to the give one
        * 
        * @param name String of the name to be set(MAX 20 characters)
        * @return PatchugoStatusCode OK if successful
        */
        PatchugoStatusCode BT_Change_Name(const char *name);

        /**
        * @brief Writes a buffer to the Bluetooth serial
        * 
        * @param data Buffer to send trough Bluetooth
        * @param len Length of the buffer to send
        * @return PatchugoStatusCode OK if successful
        */
        PatchugoStatusCode BT_Write(uint8_t *data, uint8_t len);

        /**
        * @brief Checks if Bluetooth has received anything
        * 
        */
        void BT_Update(void);

        /**
        * @brief Sets the callback function to call when an RX event occurred
        * 
        * @param callback Function that will be called on RX
        */
        void BT_Set_RXCallback(BT_RX_Callback callback);

};

#endif