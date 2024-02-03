/******************************************************
 * file name:   dio_drv.c
 * title:       dio driver
 * autor:       DPTP System
 * date:        2024.02.03.
 * email:       don_peter[kukac]freemail[pont]hu
 * device:      STM32
 * platform:    C Code, STM32CubeIDE
 * MCU:         STM32F407ZET6
******************************************************/

#include "dio_drv.h"
#include "stm32f4xx_hal.h"

static uint16_t volatile *const dio_reg_read[DIO_PORTS_NUM] = {
    (uint16_t *)&GPIOA->IDR,
    (uint16_t *)&GPIOB->IDR,
    (uint16_t *)&GPIOC->IDR,
    (uint16_t *)&GPIOD->IDR,
    (uint16_t *)&GPIOE->IDR,
	(uint16_t *)&GPIOF->IDR,
	(uint16_t *)&GPIOG->IDR
};

static uint16_t volatile *const dio_reg_write[DIO_PORTS_NUM] = {
	(uint16_t *)&GPIOA->BSRR,
	(uint16_t *)&GPIOB->BSRR,
	(uint16_t *)&GPIOC->BSRR,
	(uint16_t *)&GPIOD->BSRR,
	(uint16_t *)&GPIOE->BSRR,
	(uint16_t *)&GPIOF->BSRR,
	(uint16_t *)&GPIOG->BSRR
};

static int16_t dio_drv_init(struct dio_drv_st *self)
{
    dio_drv_tst *dio_drv_pst = (dio_drv_tst *)self;
    volatile uint16_t     number      = 0; // Port Number
    volatile uint16_t     position    = 0; // Pin Number

    number   = dio_drv_pst->cfg_st.pin_u8 / DIO_PIN_PER_PORT_NUM;
    position = dio_drv_pst->cfg_st.pin_u8 % DIO_PIN_PER_PORT_NUM;

    switch (dio_drv_pst->cfg_st.state_u1)
    {
        case DIO_HIGH:
            switch (dio_drv_pst->cfg_st.polarity_u1)
            {
                case DIO_ACTIVE_HIGH:
                    *dio_reg_write[number] |= (1UL << (position));
                    break;
                case DIO_ACTIVE_LOW:
                    *dio_reg_write[number] &= ~(1UL << (position));
                    break;
                default:
                    break;
            }
            break;
        case DIO_LOW:
            switch (dio_drv_pst->cfg_st.polarity_u1)
            {
                case DIO_ACTIVE_HIGH:
                    *dio_reg_write[number] &= ~(1UL << (position));
                    break;
                case DIO_ACTIVE_LOW:
                    *dio_reg_write[number] |= (1UL << (position));
                    break;
                default:
                    break;
            }
        default:
            break;
    }

    return 0;
}

static void dio_drv_set(dio_if_tst *self, bool state_b)
{
    dio_drv_tst *dio_drv_pst = (dio_drv_tst *)self; // Driver structure derived from interface
    dio_drv_pst->cfg_st.state_u1 = state_b;
    volatile uint16_t number   = 0; // Port Number
    volatile uint16_t position = 0; // Pin Number

    number   = dio_drv_pst->cfg_st.pin_u8 / DIO_PIN_PER_PORT_NUM;
    position = dio_drv_pst->cfg_st.pin_u8 % DIO_PIN_PER_PORT_NUM;

    switch (dio_drv_pst->cfg_st.state_u1)
    {
        case DIO_HIGH:
            switch (dio_drv_pst->cfg_st.polarity_u1)
            {
                case DIO_ACTIVE_HIGH:
                    *dio_reg_write[number] |= (1UL << (position));
                    break;
                case DIO_ACTIVE_LOW:
                    *dio_reg_write[number] &= ~(1UL << (position));
                    break;
                default:
                    break;
            }
            break;
        case DIO_LOW:
            switch (dio_drv_pst->cfg_st.polarity_u1)
            {
                case DIO_ACTIVE_HIGH:
                    *dio_reg_write[number] &= ~(1UL << (position));
                    break;
                case DIO_ACTIVE_LOW:
                    *dio_reg_write[number] |= (1UL << (position));
                    break;
                default:
                    break;
            }
        default:
            break;
    }
}

static bool dio_drv_get(dio_if_tst *self)
{
    dio_drv_tst *dio_drv_pst = (dio_drv_tst *)self; // Driver structure derived from interface

    volatile uint8_t port_number  = dio_drv_pst->cfg_st.pin_u8 / DIO_PIN_PER_PORT_NUM; // Port Number
    volatile uint8_t pin_position = dio_drv_pst->cfg_st.pin_u8 % DIO_PIN_PER_PORT_NUM; // Pin Number

    volatile uint8_t port_state = *dio_reg_read[port_number];
    volatile uint8_t pin_mask   = (1UL << (pin_position));

    switch (dio_drv_pst->cfg_st.polarity_u1)
    {
        case DIO_ACTIVE_HIGH:
            return ((port_state & pin_mask) ? DIO_HIGH : DIO_LOW);
            break;
        case DIO_ACTIVE_LOW:
            return ((port_state & pin_mask) ? DIO_LOW : DIO_HIGH);
            break;
        default:
            return 0;
            break;
    }
}

static void dio_drv_callback(dio_if_tst *self)
{
    dio_drv_tst *dio_drv_pst = (dio_drv_tst *)self;

    volatile bool pin_state_b = dio_drv_pst->super.get(&dio_drv_pst->super);

    if (pin_state_b != self->filtered_state_b)
    {
        dio_drv_pst->cnt_u16 += dio_drv_pst->cfg_st.callback_time_ms_u16;

        if (dio_drv_pst->cnt_u16 >= dio_drv_pst->cfg_st.filter_time_ms_u16)
        {
            dio_drv_pst->cnt_u16   = 0;
            self->filtered_state_b = pin_state_b;
        }
    }
    else
    {
        dio_drv_pst->cnt_u16 = 0;
    }
}

void init_dio_drv(dio_drv_tst *self)
{
    // DIO interface initialization
    self->super.callback         = (void (*)(dio_if_tst *))dio_drv_callback;
    self->super.set              = (void (*)(dio_if_tst *, bool))dio_drv_set;
    self->super.get              = (bool (*)(dio_if_tst *))dio_drv_get;
    self->super.filtered_state_b = false;

    self->init = dio_drv_init;

    self->init(self);
}
