#ifndef SERIAL_MANAGER_H
#define SERIAL_MANAGER_H

#ifndef PATCHUGO_INTERNAL_USE
#error "serial_manager.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif


#include "common.h"

#define PATCHUGO_SERIAL_TYPES
#include "serial_types.h"
#undef PATCHUGO_SERIAL_TYPES

class Serial_Manager {
    private:
        RS485_RX_Callback rxCallback;
        static constexpr uint8_t RS485_BUF_MAX_SIZE = 200;
        uint8_t rs485RxBuf[RS485_BUF_MAX_SIZE] = {0};
        uint8_t rs485RxCount = 0;
        static constexpr uint32_t DE_PIN = PD12;
        RS485_Mode rs485Mode;
    public:

        /**
        * @brief Initializes RS485 peripheral
        * 
        */
        void Init(void);

        /**
         * @brief Sets the RS485 serial to either TX or RX mode
         * 
         * @param mode Mode to set(TX or RX)
         */
        void RS485_Set_Mode(RS485_Mode mode);

        /**
        * @brief Sets the baudrate for RS485 serial
        * 
        * @param baudrate 
        */
        void RS485_Set_Baud(RS485_Baud baudrate);

        /**
        * @brief Writes a buffer trough RS485 serial
        * 
        * @param data Buffer to send
        * @param len Length of the buffer to send
        */
        PatchugoStatusCode RS485_Write(uint8_t *data, uint8_t len);

        /**
        * @brief Sets the callback function to call when an RX event occurred
        * 
        * @param callback Function that will be called on RX
        */
        void RS485_Set_RXCallback(RS485_RX_Callback callback);

        /**
        * @brief Checks if RS485 has received anything
        * 
        */
        void RS485_Update(void);
};

#endif