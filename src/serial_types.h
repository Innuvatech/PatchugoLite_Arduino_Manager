#ifndef SERIAL_TYPES_H
#define SERIAL_TYPES_H

#include <stdint.h>
#include <Arduino.h>
#ifndef PATCHUGO_SERIAL_TYPES
#error "bt_types.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif

/**
 * @brief Baud rate values for RS485 serial
 * 
 */
enum class RS485_Baud {
    BAUD_9600 = 9600,
    BAUD_19200 = 19200,
    BAUD_38400 = 38400,
    BAUD_57600 = 57600,
    BAUD_115200 = 115200,
};

/**
 * @brief Mode for RS485 serial(RX or TX)
 * 
 */
enum class RS485_Mode{
    RX = 0,
    TX = 1,
};

/**
 * @brief Type for RS485 RX callback
 * 
 */
typedef void (*RS485_RX_Callback)(uint8_t* buffer, uint8_t len);

#endif