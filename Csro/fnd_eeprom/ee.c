#include "ee.h"
#include <string.h>

#define PAGE 0
#define SECTOR 1
#define PAGE_NUM 2

#define _EE_SIZE 1024
#define _EE_ADDR_INUSE (((uint32_t)0x08000000) | (_EE_SIZE * _EE_USE_FLASH_PAGE_OR_SECTOR))
#define _EE_FLASH_BANK FLASH_BANK_1
#define _EE_PAGE_OR_SECTOR PAGE

uint8_t ee_ram[_EE_USE_RAM_BYTE];

bool ee_init(void)
{
    bool result = ee_read(0, _EE_USE_RAM_BYTE, NULL);
    if (result == false)
    {
        return false;
    }
    else if (ee_ram[100] != 1)
    {
        ee_ram[0] = 2 / 256;
        ee_ram[1] = 2 % 256;
        ee_ram[2] = 100 / 256;
        ee_ram[3] = 100 % 256;
        ee_ram[4] = 6000 / 256;
        ee_ram[5] = 6000 % 256;
        ee_ram[6] = 20 / 256;
        ee_ram[7] = 20 % 256;
        ee_ram[8] = 50 / 256;
        ee_ram[9] = 50 % 256;
        ee_ram[100] = 1;
        return ee_commit();
    }
    return true;
}

bool ee_format(bool keepRamData)
{
    uint32_t error;
    HAL_FLASH_Unlock();
    FLASH_EraseInitTypeDef flashErase;

    flashErase.NbPages = 1;
    flashErase.PageAddress = _EE_ADDR_INUSE;
    flashErase.TypeErase = FLASH_TYPEERASE_PAGES;
    flashErase.Banks = _EE_FLASH_BANK;
    if (HAL_FLASHEx_Erase(&flashErase, &error) == HAL_OK)
    {
        HAL_FLASH_Lock();
        if (error != 0xFFFFFFFF)
            return false;
        else
        {
            if (keepRamData == false)
            {
                memset(ee_ram, 0xFF, _EE_USE_RAM_BYTE);
            }
            return true;
        }
    }
    HAL_FLASH_Lock();
    return false;
}

bool ee_read(uint32_t startVirtualAddress, uint32_t len, uint8_t *data)
{
    if ((startVirtualAddress + len) > _EE_SIZE)
    {
        return false;
    }
    for (uint32_t i = startVirtualAddress; i < len + startVirtualAddress; i++)
    {
        if (data != NULL)
        {
            *data = (*(__IO uint8_t *)(i + _EE_ADDR_INUSE));
            data++;
        }
        if (i < _EE_USE_RAM_BYTE)
            ee_ram[i] = (*(__IO uint8_t *)(i + _EE_ADDR_INUSE));
    }
    return true;
}

bool ee_write(uint32_t startVirtualAddress, uint32_t len, uint8_t *data)
{
    if ((startVirtualAddress + len) > _EE_SIZE)
    {
        return false;
    }
    if (data == NULL)
    {
        return false;
    }
    HAL_FLASH_Unlock();
    for (uint32_t i = 0; i < len; i += 2)
    {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, ((i + startVirtualAddress)) + _EE_ADDR_INUSE, (uint64_t)(data[i] | (data[i + 1] << 8))) != HAL_OK)
        {
            HAL_FLASH_Lock();
            return false;
        }
    }
    HAL_FLASH_Lock();
    return true;
}

bool ee_writeToRam(uint32_t startVirtualAddress, uint32_t len, uint8_t *data)
{
    if ((startVirtualAddress + len) > _EE_USE_RAM_BYTE)
    {
        return false;
    }
    if (data == NULL)
    {
        return false;
    }
    memcpy(&ee_ram[startVirtualAddress], data, len);
    return true;
}

bool ee_commit(void)
{
    if (ee_format(true) == false)
    {
        return false;
    }
    return ee_write(0, _EE_USE_RAM_BYTE, ee_ram);
}
