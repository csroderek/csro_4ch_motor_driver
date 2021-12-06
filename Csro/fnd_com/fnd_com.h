#ifndef FND_COM_H_
#define FND_COM_H_

#include "stm32f1xx_hal.h"
#include "mb_slave.h"
#include "mb_master.h"

#define INPUT_BTN_START 100
#define INPUT_BTN_END 111

#define INPUT_RMT_START 120
#define INPUT_RMT_END 144

#define INPUT_RLY_CTRL_START 150
#define INPUT_RLY_CTRL_END 157

#define HOLDING_COM_START 110
#define HOLDING_COM_END 134

extern modbus_regs sys_regs;
extern modbus_slave slaves[2];

void fnd_com_modbus_rtu_init(void);
void fnd_com_modbus_rtu_uart_idle_irq(UART_HandleTypeDef *huart);
void fnd_com_modbus_rtu_slave1_wait(void);
void fnd_com_modbus_rtu_slave2_wait(void);

#endif
