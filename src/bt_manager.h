#ifndef BT_MANAGER_H
#define BT_MANAGER_H

#ifndef PATCHUGO_INTERNAL_USE
#error "bt_manager.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif

#define PATCHUGO_BT_TYPES
#include "bt_types.h"
#undef PATCHUGO_BT_TYPES

#include "common.h"

class BT_Manager {
    private:
        static constexpr uint32_t BT_RESET_PIN = PD2;
        static constexpr uint32_t BT_MODE_PIN = PD6;
        static constexpr uint8_t BT_MAX_NAME_LEN = 20;
        static constexpr uint8_t BT_CMD_SOF = 0x02;
        static constexpr uint8_t BT_CMD_CHANGE_NAME = 0x11;
        static constexpr uint8_t BT_CMD_CHANGE_NAME_SINDEX = 0x02;
        static constexpr uint8_t BT_BUF_MAX_SIZE = 200;
        uint8_t btRxBuf[BT_BUF_MAX_SIZE] = {0};
        uint8_t btRxCount = 0;
        BTMode currentMode;
        BT_RX_Callback rxCallback;
    public:
        /**
        * @brief Initializes bluetooh peripheral
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