#ifndef FLASH_MANAGER_H
#define FLASH_MANAGER_H

#ifndef PATCHUGO_INTERNAL_USE
#error "spi_manager.h is private inside the PatchugoLite library and cannot be included in other files!"
#endif

#define PATCHUGO_FLASH_TYPES
#include "flash_types.h"
#undef PATCHUGO_FLASH_TYPES

#include "common.h"

class Flash_Manager {
    private:
        static constexpr uint8_t FLASH_CMD_ENABLE_RESET = 0x66;
        static constexpr uint8_t FLASH_CMD_RESET = 0x99;
        static constexpr uint8_t FLASH_CMD_WRITE_ENB = 0x06;
        static constexpr uint8_t FLASH_CMD_ERASE_CHIP = 0xC7;
        static constexpr uint8_t FLASH_CMD_ERASE_SECTOR = 0x20;
        static constexpr uint8_t FLASH_CMD_READ_DATA = 0x03;
        static constexpr uint8_t FLASH_CMD_WRITE_PAGE = 0x02;
        static constexpr uint8_t FLASH_STATUS_REG_1 = 0x05;
        static constexpr uint32_t FLASH_CS_PIN = PG3;
        static constexpr uint8_t FLASH_CMD_LEN = 4;
        SPI_Manager spiManager;

        /**
         * @brief Writes a single byte command to the flash
         * 
         * @param cmd Command to send to the flash
         */
        void Flash_Write_Instruction(uint8_t cmd);
        PatchugoStatusCode Flash_Check_Status1(void);

    public:
        /**
        * @brief Initializes the flash assigning the SPI manager class instance to use
        * for all flash operations
        * 
        * @param manager SPI manager instance to use for all flash operations
        */
        void Flash_Init(SPI_Manager manager);
        /**
         * @brief Resets the flash
         * 
         */
        PatchugoStatusCode Flash_Reset(void);

        PatchugoStatusCode Flash_Erase_Chip(void);

        PatchugoStatusCode Flash_Erase_Sector(Flash_Sector sector);

        bool Flash_Is_Sector_Erased(Flash_Sector sector);

        void Flash_Read(Flash_Sector sector, Flash_Page page, uint8_t *readData, uint32_t len);

        PatchugoStatusCode Flash_Write(Flash_Sector sector, Flash_Page page, uint8_t *writeData, uint8_t len);

};

#endif