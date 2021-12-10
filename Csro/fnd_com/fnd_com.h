#ifndef FND_COM_H_
#define FND_COM_H_

#include "stm32f1xx_hal.h"
#include "mb_slave.h"
#include "mb_master.h"

#define INPUT_BTN_START 100
#define INPUT_BTN_END 109

#define INPUT_RLY_CTRL_START 150
#define INPUT_RLY_CTRL_END 157

extern modbus_regs sys_regs;
extern modbus_slave slaves[2];

extern int16_t relay[8];

extern uint64_t rmt_cmd[20];
extern uint8_t rmt_index;

void fnd_com_modbus_rtu_init(void);
void fnd_com_modbus_rtu_uart_idle_irq(UART_HandleTypeDef *huart);
void fnd_com_modbus_rtu_slave1_wait(void);
void fnd_com_modbus_rtu_slave2_wait(void);

#endif
