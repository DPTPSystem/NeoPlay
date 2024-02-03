/******************************************************
 * file name:   gpio.h
 * title:       gpio pin, dio driver init, variables and prototypes
 * autor:       DPTP System
 * date:        2024.02.03.
 * email:       don_peter[kukac]freemail[pont]hu
 * device:      STM32
 * platform:    C Code, STM32CubeIDE
 * MCU:         STM32F407ZET6
******************************************************/
#ifndef GPIO_H
#define	GPIO_H

#include "dio_drv.h"

extern dio_if_tst *led0_out_pst;
extern dio_if_tst *led1_out_pst;

void gpio_init_pins(void);
void gpio_callback(void);

#endif	/* GPIO_H */

