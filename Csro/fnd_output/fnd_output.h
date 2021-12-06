#ifndef FND_OUTPUT_H_
#define FND_OUTPUT_H_

#include "stm32f1xx_hal.h"

// fnd_output.c
void fnd_output_update_value(int16_t *values);

// fnd_output_gpio.c
void fnd_output_gpio_write_relays(uint8_t *values);

#endif
