#ifndef IO_MANAGER_H
#define IO_MANAGER_H

#ifndef PATCHUGO_INTERNAL_USE
#error "io_manager.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif

#define PATCHUGO_IO_TYPES
#include "io_types.h"
#undef PATCHUGO_IO_TYPES


/**
 * @brief "private" library class to manage digital INPUT and OUTPUT pins
 * of the board
 * 
 */
class IO_Manager {
    public:
        /**
         * @brief Initializes all 16 24V digital pins to their respective modes
         * 
         */
        void Init_IO_Pins(void);

        /**
         * @brief Writes to one of the 8 24V digital OUTPUT pins
         * 
         * @param pin Enum of the pin to write
         * @param status Status to write to the pin
         */
        void Write_Pin(OutputPin pin, FlagStatus status);
        
        /**
         * @brief Reads one of the 8 24V digital INPUT pins
         * 
         * @param pin Enum of the pin to read
         * @return uint8_t Value read from the pin
         */
        uint8_t Read_Pin(InputPin pin);
};

#endif