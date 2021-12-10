#include "fnd_input.h"
#include "gpio.h"
#include "tim.h"

uint16_t low_pulse = 0;
uint16_t high_pulse = 0;

uint8_t bit_data[40] = {0};

uint64_t rmt_cmd[20] = {0};
uint8_t cmd_index = 0;

static void compose_and_process_remote_command(void)
{
    for (uint8_t i = 0; i < 40; i++)
    {
        if (bit_data[i] == 1)
        {
            rmt_cmd[cmd_index] = (rmt_cmd[cmd_index] << 1) | 0x01;
        }
        else
        {
            rmt_cmd[cmd_index] = (rmt_cmd[cmd_index] << 1) & 0xFFFFFFFFFFFFFFFE;
        }
    }
    cmd_index = (cmd_index + 1) % 20;
}

static void remote_receive_high_pulse(void)
{
    static uint8_t receiving = 0;
    static uint8_t bit_index = 0;

    uint8_t valid_0 = high_pulse > 20 && high_pulse < 40;
    uint8_t valid_1 = high_pulse > 60 && high_pulse < 80;

    if (high_pulse > 400 && high_pulse < 600)
    {
        receiving = 1;
        bit_index = 0;
    }
    else if (receiving == 1 && (valid_0 || valid_1))
    {
        bit_data[bit_index] = valid_1 ? 1 : 0;
        bit_index = (bit_index + 1) % 40;
        if (bit_index == 0)
        {
            receiving = 0;
            compose_and_process_remote_command();
        }
    }
    else
    {
        receiving = 0;
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (HAL_GPIO_ReadPin(RF_SIG_GPIO_Port, RF_SIG_Pin) == GPIO_PIN_RESET)
    {
        high_pulse = __HAL_TIM_GetCounter(&htim1);
        __HAL_TIM_SetCounter(&htim1, 0);
        remote_receive_high_pulse();
    }
    else
    {
        low_pulse = __HAL_TIM_GetCounter(&htim1);
        __HAL_TIM_SetCounter(&htim1, 0);
    }
}
