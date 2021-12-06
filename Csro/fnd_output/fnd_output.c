#include "fnd_output.h"
#include "fnd_com.h"

void fnd_output_update_value(int16_t *values)
{
    uint8_t relay_out_values[8];
    for (uint8_t i = 0; i < (INPUT_RLY_CTRL_END - INPUT_RLY_CTRL_START + 1); i++)
    {
        sys_regs.inputs[INPUT_RLY_CTRL_START + i] = values[i];
        relay_out_values[i] = (uint8_t)sys_regs.inputs[INPUT_RLY_CTRL_START + i];
    }
    fnd_output_gpio_write_relays(relay_out_values);

    for (uint8_t i = 0; i < (HOLDING_COM_END - HOLDING_COM_START + 1); i++)
    {
        sys_regs.holdings[HOLDING_COM_START + i] = 0;
    }
}