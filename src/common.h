#ifndef COMMON_H
#define COMMON_H

/**
 * @brief Status codes for all board related
 * operations
 * 
 */
enum class PatchugoStatusCode {
    OK,
    ERROR_BT_NAME_LEN,
    ERROR_WRONG_MODE,
    ERROR_FLASH_STATUS,
};

#endif