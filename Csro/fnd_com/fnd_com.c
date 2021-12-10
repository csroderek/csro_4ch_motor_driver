#include "fnd_com.h"
#include "usart.h"
#include "gpio.h"

modbus_port port[2] = {
    {&huart1,
     RS485_EN1_GPIO_Port,
     RS485_EN1_Pin},
    {&huart2,
     RS485_EN2_GPIO_Port,
     RS485_EN2_Pin},
};
modbus_regs sys_regs;
modbus_slave slaves[2];

int16_t relay[8];

uint64_t rmt_cmd[20];
uint8_t rmt_index;

void fnd_com_modbus_rtu_init(void)
{
    slave_init(&slaves[0], &port[0], 1, &sys_regs);
    slave_init(&slaves[1], &port[1], 2, &sys_regs);
}
void fnd_com_modbus_rtu_uart_idle_irq(UART_HandleTypeDef *huart)
{
    if (huart == slaves[0].uart_port->uart)
    {
        slave_uart_idle(&slaves[0]);
    }
    else if (huart == slaves[1].uart_port->uart)
    {
        slave_uart_idle(&slaves[1]);
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == slaves[0].uart_port->uart)
    {
        slave_set_tx_rx(&slaves[0], rx);
    }
    else if (huart == slaves[1].uart_port->uart)
    {
        slave_set_tx_rx(&slaves[1], rx);
    }
}

void fnd_com_modbus_rtu_slave1_wait(void)
{
    slave_wait_request(&slaves[0]);
}
void fnd_com_modbus_rtu_slave2_wait(void)
{
    slave_wait_request(&slaves[1]);
}
