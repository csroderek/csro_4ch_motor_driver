#include "fnd_input.h"
#include "gpio.h"

uint32_t rf_cnt = 0;

void fnd_input_remote_receive_pulse(void)
{
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == RF_SIG_Pin)
    {
        rf_cnt++;
    }
}