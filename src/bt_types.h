#ifndef BT_TYPES_H
#define BT_TYPES_H

#include <Arduino.h>
#ifndef PATCHUGO_BT_TYPES
#error "bt_types.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif

/**
 * @brief Enum representing Proteus-E operating modes
 * 
 */
enum class BTMode {
    COMMAND = 0,
    TRANSPARENT= 1,
};

/**
 * @brief Type for Bluetooth RX callback
 * 
 */
typedef void (*BT_RX_Callback)(uint8_t* buffer, uint8_t len);

#endif