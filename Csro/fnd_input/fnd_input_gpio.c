#include "fnd_input.h"
#include "gpio.h"

GPIO_TypeDef *key_port[4] = {KEY_01_GPIO_Port, KEY_02_GPIO_Port, KEY_04_GPIO_Port, KEY_04_GPIO_Port};
uint16_t key_pin[4] = {KEY_01_Pin, KEY_02_Pin, KEY_03_Pin, KEY_04_Pin};

GPIO_TypeDef *btn_port[12] = {BTN_01_GPIO_Port, BTN_02_GPIO_Port, BTN_03_GPIO_Port, BTN_04_GPIO_Port, BTN_05_GPIO_Port, BTN_06_GPIO_Port, BTN_07_GPIO_Port, BTN_08_GPIO_Port, BTN_09_GPIO_Port, BTN_10_GPIO_Port, BTN_11_GPIO_Port, BTN_12_GPIO_Port};
uint16_t btn_pin[12] = {BTN_01_Pin, BTN_02_Pin, BTN_03_Pin, BTN_04_Pin, BTN_05_Pin, BTN_06_Pin, BTN_07_Pin, BTN_08_Pin, BTN_09_Pin, BTN_10_Pin, BTN_11_Pin, BTN_12_Pin};

void fnd_input_gpio_read_keys(uint8_t *values)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        values[i] = (HAL_GPIO_ReadPin(key_port[i], key_pin[i]) == GPIO_PIN_SET) ? 1 : 0;
    }
}

void fnd_input_gpio_read_btns(uint8_t *values)
{
    for (uint8_t i = 0; i < 12; i++)
    {
        values[i] = (HAL_GPIO_ReadPin(btn_port[i], btn_pin[i]) == GPIO_PIN_SET) ? 1 : 0;
    }
}