#ifndef IO_TYPES_H
#define IO_TYPES_H

#include <Arduino.h>

#ifndef PATCHUGO_IO_TYPES
#error "io_types.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif

/**
 * @brief Enum class representing all 8 digital INPUT pins of the board
 * 
 */
enum class InputPin {
    IN_1 = PF7,
    IN_2 = PF1,
    IN_3 = PF0,
    IN_4 = PE6,
    IN_5 = PE5,
    IN_6 = PE4,
    IN_7 = PE3,
    IN_8 = PE2,
};

/**
 * @brief Enum class representing all 8 digital OUTPUT pins of the board
 * 
 */
enum class OutputPin {
    OUT_1 = PC3_C,
    OUT_2 = PC1,
    OUT_3 = PF8,
    OUT_4 = PF6,
    OUT_5 = PF5,
    OUT_6 = PF4,
    OUT_7 = PF3,
    OUT_8 = PF2
};

#endif