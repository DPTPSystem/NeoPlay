/******************************************************
 * file name:   gpio.c
 * title:       gpio pin configurations
 * autor:       DPTP System
 * date:        2024.02.03.
 * email:       don_peter[kukac]freemail[pont]hu
 * device:      STM32
 * platform:    C Code, STM32CubeIDE
 * MCU:         STM32F407ZET6
******************************************************/

#include "gpio.h"

// LED0
dio_drv_tst led0_out_st= { .cfg_st = {
                                            .pin_u8             = PORTF_9,
                                            .direction_u1       = DIO_OUTPUT,
                                            .mode_u1            = DIO_MODE_NORMAL,
                                            .state_u1           = DIO_STATE_INACTIVE,
                                            .polarity_u1        = DIO_ACTIVE_HIGH
                                        }
                        };
// LED1
dio_drv_tst led1_out_st= { .cfg_st = {
                                            .pin_u8             = PORTF_10,
                                            .direction_u1       = DIO_OUTPUT,
                                            .mode_u1            = DIO_MODE_NORMAL,
                                            .state_u1           = DIO_STATE_INACTIVE,
                                            .polarity_u1        = DIO_ACTIVE_HIGH
                                        }
                        };

// LED0 and LED1
dio_if_tst *led0_out_pst;
dio_if_tst *led1_out_pst;

void gpio_init_pins(void)
{
    init_dio_drv(&led0_out_st);
    init_dio_drv(&led1_out_st);

    //Initialize output interfaces

    // LED0
    led0_out_pst = &led0_out_st.super;
    led0_out_pst->callback_time_ms_u16 = 0;
    led0_out_pst->filter_time_ms_u16 = 0;
    // LED1
    led1_out_pst = &led1_out_st.super;
	led1_out_pst->callback_time_ms_u16 = 0;
	led1_out_pst->filter_time_ms_u16 = 0;

    //Initialize input interfaces
   
}

