#ifndef FND_INPUT_H_
#define FND_INPUT_H_

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"

// fnd_input.c
void fnd_input_update_value(void);

// fnd_input_gpio.c
void fnd_input_gpio_read_keys(uint8_t *values);

void fnd_input_gpio_read_btns(uint8_t *values);

// fnd_input_remote.c
void fnd_input_remote_receive_pulse(void);

#endif
