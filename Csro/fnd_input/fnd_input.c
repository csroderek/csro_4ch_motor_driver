#include "fnd_input.h"
#include "fnd_com.h"

void fnd_input_update_value(void)
{
    uint8_t btn_values[12];
    fnd_input_gpio_read_btns(btn_values);

    for (uint8_t i = 0; i < (INPUT_BTN_END - INPUT_BTN_START + 1); i++)
    {
        sys_regs.inputs[INPUT_BTN_START + i] = btn_values[i];
    }
}