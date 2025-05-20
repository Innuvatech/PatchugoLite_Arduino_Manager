#ifndef SPI_MANAGER_H
#define SPI_MANAGER_H

#ifndef PATCHUGO_INTERNAL_USE
#error "spi_manager.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif

#define PATCHUGO_SPI_TYPES
#include "spi_types.h"
#undef PATCHUGO_SPI_TYPES

#include "common.h"

class SPI_Manager {
    private:
        SPISettings settings;
        uint32_t csPin = PA15;
    public:
        /**
         * @brief Initializes the CS pin as a digital OUTPUT pin
         * 
         */
        void SPI_Init_CS();
        /**
        * @brief Sets the SPI parameters of communication and reinitializes the SPI
        * peripheral
        * 
        * @param clock Clock value of the SPI in hz
        * @param order Byte order of data
        * @param mode Mode of operation of SPI
        */
        void SPI_Init(uint32_t clock, BitOrder order, SPIMode mode);

        /**
        * @brief Writes a buffer trough SPI peripheral
        * 
        * @param data Buffer to write trough SPI
        * @param len Length of the buffer to write
        */
        void SPI_Write(uint8_t *data, uint8_t len);

        /**
        * @brief Reads data from the SPI peripheral
        * 
        * @param reg Register address to read(0x00 if there is not any)
        * @param len Length of the data to read
        * @param readValue Pointer where data will be stored
        */
        void SPI_Read(uint8_t reg, uint8_t len, uint8_t *readValue);
};


#endif