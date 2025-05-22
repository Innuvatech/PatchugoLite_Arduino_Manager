#define PATCHUGO_INTERNAL_USE
#include "flash_manager.h"
#undef PATCHUGO_INTERNAL_USE

#include <string.h>

SPIClass flashSpi(PB15,PB14,PB13);

PatchugoStatusCode Flash_Manager::Flash_Check_Status1(void) {
    uint8_t reg1 = 0;
    uint8_t reg = 0;
    uint32_t tries = 0;

    uint32_t startMillis = millis();

    do {
        spiManager.SPI_Read(FLASH_STATUS_REG_1,1,&reg1);
        reg = reg1 & 0x01;
        tries++;
        uint32_t currentMillis = millis();
        if((currentMillis - startMillis) > 20000){
            return PatchugoStatusCode::ERROR_FLASH_STATUS;
        } 
    }while(reg == 0x01);

    return PatchugoStatusCode::OK;
}

void Flash_Manager::Flash_Init(SPI_Manager manager) {
    pinMode(FLASH_CS_PIN, OUTPUT);
    spiManager = manager;
    spiManager.SPI_Init_CS(flashSpi,FLASH_CS_PIN);
}

void Flash_Manager::Flash_Write_Instruction(uint8_t cmd) {
    spiManager.SPI_Write(&cmd,1);
}

PatchugoStatusCode Flash_Manager::Flash_Reset(void) {
    Flash_Write_Instruction(FLASH_CMD_ENABLE_RESET);
    delay(2000);
    Flash_Write_Instruction(FLASH_CMD_RESET);

    return Flash_Check_Status1();
}

PatchugoStatusCode Flash_Manager::Flash_Erase_Chip(void) {

    Flash_Write_Instruction(FLASH_CMD_WRITE_ENB);
    delay(10);
    Flash_Write_Instruction(FLASH_CMD_ERASE_CHIP);

    return Flash_Check_Status1();
}

PatchugoStatusCode Flash_Manager::Flash_Erase_Sector(Flash_Sector sector) {

    uint32_t sectorAddr = static_cast<uint32_t>(sector);
    uint32_t convertedAddr = sectorAddr & 0xFFFFFF;


    Flash_Write_Instruction(FLASH_CMD_WRITE_ENB);
    delay(10);
    
    uint8_t cmdBuf[FLASH_CMD_LEN] = {0};

    cmdBuf[0] = FLASH_CMD_ERASE_SECTOR;
    cmdBuf[1] = (convertedAddr >> 16) & 0xFF;
    cmdBuf[2] = (convertedAddr >> 8) & 0xFF;
    cmdBuf[3] = convertedAddr & 0xFF;

    spiManager.SPI_Write(cmdBuf, FLASH_CMD_LEN);
    delay(10);

    return Flash_Check_Status1();
}

void Flash_Manager::Flash_Read(Flash_Sector sector, Flash_Page page, uint8_t *readData, uint32_t len) {

    uint32_t sectorAddr = static_cast<uint32_t>(sector);
    uint32_t pageAddr = static_cast<uint32_t>(page);
    uint32_t writeAddr = sectorAddr + pageAddr;
    uint32_t convertedAddr = writeAddr & 0xFFFFFF;

    uint8_t cmdBuf[FLASH_CMD_LEN] = {0};

    cmdBuf[0] = FLASH_CMD_READ_DATA;
    cmdBuf[1] = (convertedAddr >> 16) & 0xFF;
    cmdBuf[2] = (convertedAddr >> 8) & 0xFF;
    cmdBuf[3] = convertedAddr & 0xFF;

    spiManager.SPI_TransmitReceive(cmdBuf, FLASH_CMD_LEN,readData,len);
}

PatchugoStatusCode Flash_Manager::Flash_Write(Flash_Sector sector, Flash_Page page, uint8_t *writeData, uint8_t len){

  Flash_Write_Instruction(FLASH_CMD_WRITE_ENB);

  uint32_t sectorAddr = static_cast<uint32_t>(sector);
  uint32_t pageAddr = static_cast<uint32_t>(page);
  uint32_t writeAddr = sectorAddr + pageAddr;
  uint32_t convertedAddr = writeAddr & 0xFFFFFF;

  uint8_t cmdBuf[FLASH_PAGE_SIZE + FLASH_CMD_LEN] = {0};

  cmdBuf[0] = FLASH_CMD_WRITE_PAGE;
  cmdBuf[1] = (convertedAddr >> 16) & 0xFF;
  cmdBuf[2] = (convertedAddr >> 8) & 0xFF;
  cmdBuf[3] = convertedAddr & 0xFF;

  memcpy(cmdBuf+FLASH_CMD_LEN,writeData,len);

  spiManager.SPI_Write(cmdBuf, len + FLASH_CMD_LEN);

  return Flash_Check_Status1();
}

bool Flash_Manager::Flash_Is_Sector_Erased(Flash_Sector sector) {
    
    uint8_t firstByte = 0;
    Flash_Read(sector,Flash_Page::PAGE_0,&firstByte,1);
    return firstByte == 0xFF;
}