#include "fnd_input.h"
#include "gpio.h"
#include "tim.h"

uint16_t low_dur = 0;
uint16_t high_dur = 0;

uint32_t compose_cnt = 0;
uint8_t flag = 0;
uint8_t data_index;
uint8_t data[40] = {0};
uint64_t code[20] = {0};

static void compose_remote_data(void)
{
	code[compose_cnt]= 0;
    for (uint8_t i = 0; i < 40; i++)
    {
        if (data[i] == 1)
        {
        	code[compose_cnt] = (code[compose_cnt] << 1) | 0x01;
        }
        else
        {
        	code[compose_cnt] = (code[compose_cnt] << 1) & 0xFFFFFFFFFFFFFFFE;
        }
    }
    compose_cnt=(compose_cnt+1)%20;
}

static void remote_received_high_pulse(void)
{
    static uint8_t valid = 0;
    if (high_dur > 400 && high_dur < 600)
    {
        valid = 1;
        data_index = 0;
    }
    else if (valid == 1 && high_dur > 20 && high_dur < 40)
    {
        data[data_index] = 0;
        data_index = (data_index + 1) % 40;
        if (data_index == 0)
        {
            valid = 0;
            compose_remote_data();
        }
    }
    else if (valid == 1 && high_dur > 60 && high_dur < 80)
    {
        data[data_index] = 1;
        data_index = (data_index + 1) % 40;
        if (data_index == 0)
        {
            valid = 0;
            compose_remote_data();
        }
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (HAL_GPIO_ReadPin(RF_SIG_GPIO_Port, RF_SIG_Pin) == GPIO_PIN_RESET)
    {
        HAL_TIM_Base_Stop(&htim1);
        high_dur = htim1.Instance->CNT;
        htim1.Instance->CNT = 0;
        HAL_TIM_Base_Start(&htim1);
        remote_received_high_pulse();
    }
    else
    {
        HAL_TIM_Base_Stop(&htim1);
        low_dur = htim1.Instance->CNT;
        htim1.Instance->CNT = 0;
        HAL_TIM_Base_Start(&htim1);
    }
}
