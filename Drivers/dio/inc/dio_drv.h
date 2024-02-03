/******************************************************
 * file name:   dio_drv.h
 * title:       dio driver
 * autor:       DPTP System
 * date:        2024.02.03.
 * email:       don_peter[kukac]freemail[pont]hu
 * device:      STM32
 * platform:    C Code, STM32CubeIDE
 * MCU:         STM32F407ZET6
******************************************************/

#ifndef DIO_DRV_STM32F407_H
#define	DIO_DRV_STM32F407_H

#include "dio_if.h"

typedef enum
{
    DIO_OUTPUT = 0,
    DIO_INPUT,
}dio_direction_ten;

typedef enum
{
    DIO_STATE_INACTIVE = 0,
    DIO_STATE_ACTIVE,
}dio_state_ten;

typedef enum
{
    DIO_ACTIVE_HIGH = 0,
    DIO_ACTIVE_LOW,
}dio_active_level_ten;

typedef enum
{
    DIO_MODE_NORMAL = 0,
    DIO_MODE_ANALOG,
}dio_mode_ten;

typedef enum
{
    DIO_PULLUP_DISABLE = 0,
    DIO_PULLUP_ENABLE,
}dio_pullup_ten;

typedef enum
{
    DIO_PULLDOWN_DISABLE = 0,
    DIO_PULLDOWN_ENABLE,
}dio_pulldown_ten;

typedef enum
{
    DIO_LOW = 0,
    DIO_HIGH,  
}dio_init_state_ten;

/** @brief DIO driver error codes.
 *
 */
typedef enum
{
    SUCCESS_GPIO = 0,
    WRONG_PIN_NUM,
    WRITE_INPUT_PIN,
    NOT_SUPP_PIN_MODE
} dio_err_code_tun;

/** @brief All PINs of the PORTs
 * STM32F407ZET6
 * 
 */

typedef enum
{
    // A PORT
    PORTA_0,    // PA0 - YM RA8 OUT - ADPCM-A ADRESS
    PORTA_1,    // PA1 - YM RA9 OUT - ADPCM-A ADRESS
    PORTA_2,    // PA2 - YM RA20 OUT - ADPCM-A ADRESS
    PORTA_3,    // PA3 - YM RA21 OUT - ADPCM-A ADRESS
    PORTA_4,    // PA4 - YM RA22 OUT - ADPCM-A ADRESS
    PORTA_5,    // PA5
    PORTA_6,    // PA6
    PORTA_7,    // PA7
	PORTA_8,    // PA8  - YM IC IN RESET
	PORTA_9,    // PA9  - YM CS IN CHIP SELECT
	PORTA_10,	// PA10 - YM WR IN WRITE
	PORTA_11,	// PA11
	PORTA_12,   // PA12
	PORTA_13,   // PA13
	PORTA_14,   // PA14
	PORTA_15,   // PA15
            
    // B PORTS       
    PORTB_0,    // PB0
    PORTB_1,    // PB1
    PORTB_2,    // PB2
    PORTB_3,    // PB3
    PORTB_4,    // PB4
    PORTB_5,    // PB5
    PORTB_6,    // PB6
    PORTB_7,    // PB7
	PORTB_8,    // PB8
	PORTB_9,    // PB9
	PORTB_10,   // PB10
	PORTB_11,   // PB11
	PORTB_12,   // PB12
	PORTB_13,   // PB13
	PORTB_14,   // PB14
	PORTB_15,   // PB15
            
    // C PORTS       
    PORTC_0,    // PC0 - YM RAD0 I/O - ADPCM-A MULTIPLEXED ADDRESS/DATA
    PORTC_1,    // PC1 - YM RAD1
    PORTC_2,    // PC2 - YM RAD2
    PORTC_3,    // PC3 - YM RAD3
    PORTC_4,    // PC4 - YM RAD4
    PORTC_5,    // PC5 - YM RAD5
    PORTC_6,    // PC6 - YM RAD6
    PORTC_7,    // PC7 - YM RAD7 I/O
	PORTC_8,    // PC8
	PORTC_9,    // PC9
	PORTC_10,   // PC10
	PORTC_11,   // PC11
	PORTC_12,   // PC12
	PORTC_13,   // PC13
	PORTC_14,   // PC14
	PORTC_15,   // PC15
            
    // D PORTS       
    PORTD_0,    // PD0 - YM ROE OUT - ADPCM-A ADRESS/DATA ENABLED
    PORTD_1,    // PD1 - YM RMPX OUT - ADPCM-A ADDRESS/DATA SELECT
    PORTD_2,    // PD2
    PORTD_3,    // PD3 - YM RA23 OUT - ADPCM-A ADRESS
    PORTD_4,    // PD4
    PORTD_5,    // PD5
    PORTD_6,    // PD6
    PORTD_7,    // PD7
	PORTD_8,    // PD8
	PORTD_9,    // PD9
	PORTD_10,   // PD10
	PORTD_11,   // PD11
	PORTD_12,   // PD12
	PORTD_13,   // PD13
	PORTD_14,   // PD14
	PORTD_15,   // PD15
            
    // E PORTS       
    PORTE_0,    // PE0 - YM PAD0 I/O - ADPCM-B MULTIPLEXED ADDRESS/DATA
    PORTE_1,    // PE1 - YM PAD1
    PORTE_2,    // PE2 - YM PAD2
    PORTE_3,    // PE3 - YM PAD3
    PORTE_4,    // PE4 - YM PAD4
    PORTE_5,    // PE5 - YM PAD5
    PORTE_6,    // PE6 - YM PAD6
    PORTE_7,    // PE7 - YM PAD7 I/O
	PORTE_8,    // PE8 - YM PA8 OUT - ADPCM-B ADDRESS
	PORTE_9,    // PE9 - YM PA9 OUT - ADPCM-B ADDRESS
	PORTE_10,   // PE10 - YM PA10 OUT - ADPCM-B ADDRESS
	PORTE_11,   // PE11 - YM PA11 OUT - ADPCM-B ADDRESS
	PORTE_12,   // PE12 - YM A0 IN
	PORTE_13,   // PE13 - YM A1 IN
	PORTE_14,   // PE14 - YM POE OUT - ADPCM-B DATA OUTPUT ENABLED
	PORTE_15,   // PE15 - YM PMPX OUT - ADPCM-B ADRESS/DATA SELEC

	PORTF_0,	// PF0 - YM RD IN - READ
	PORTF_1,	// PF1 - JRC MUTE IN
	PORTF_2,	// PF2
	PORTF_3,	// PF3
	PORTF_4,	// PF4
	PORTF_5,	// PF5
	PORTF_6,	// PF6
	PORTF_7,	// PF7
	PORTF_8,	// PF8
	PORTF_9,	// PF9  - BOARD LED0
	PORTF_10,	// PF10 - BOARD LED1
	PORTF_11,	// PF11
	PORTF_12,	// PF12
	PORTF_13,	// PF13
	PORTF_14,	// PF14
	PORTF_15,	// PF15

	PORTG_0,	// PG0 - YM D0 I/O - Z80 DATA BUS
	PORTG_1,	// PG1 - YM D1
	PORTG_2,	// PG2 - YM D2
	PORTG_3,	// PG3 - YM D3
	PORTG_4,	// PG4 - YM D4
	PORTG_5,	// PG5 - YM D5
	PORTG_6,	// PG6 - YM D6
	PORTG_7,	// PG7 - YM D7 I/O
	PORTG_8,	// PG8
	PORTG_9,	// PG9
	PORTG_10,	// PG10
	PORTG_11,	// PG11
	PORTG_12,	// PG12
	PORTG_13,	// PG13
	PORTG_14,	// PG14
	PORTG_15,	// PG15
            
    DIO_PIN_NUMBER,
} dio_channel_ten;

#define DIO_PIN_PER_PORT_NUM (16)
#define DIO_PORTS_NUM ((DIO_PIN_NUMBER) / DIO_PIN_PER_PORT_NUM)

/** @brief DIO driver configuration structure
 *
 *  All port pins are defined as inputs after Device reset.
 *
 *  For setting up the driver, use the predefined values.
 *  Predefined values van be accessed by using the "DIO_" prefix or
 *  for pin selection, use the "dio_pins_tun" enumerator type.
 */
typedef struct
{
    uint8_t direction_u1    : 1,       
            polarity_u1     : 1,       
            mode_u1         : 2,      
            pullup_u1       : 1,      
            pulldown_u1     : 1,      
            state_u1        : 1;     

                                    /*   For open drain mode, if initial state set to 1, means that*/
                                    /*   the transistor wont be driven (so drain value wont be pulled down) */
    uint8_t  pin_u8;               /**< Associated GPIO pin number (select from the "dio_pins_tun" list) */
    uint16_t callback_time_ms_u16; /**< Callback function time in ms from where the DIO Callback will be called */
    uint16_t filter_time_ms_u16;   /**< Desired Filter/Debounce time in ms */
} dio_drv_cfg_tst;

/** @brief DIO driver structure
 *
 *  Use this structure to define DIO pins that you want to use in your application.
 *  After Initialization, you must only use the DIO interface methods and variables.
 */
typedef struct dio_drv_st
{
    dio_if_tst  super;  /**< DIO interface structure */
    dio_drv_cfg_tst cfg_st; /**< DIO driver config structure */

    uint16_t cnt_u16; /**< Filter time counter */
    int16_t        (*init)(struct dio_drv_st *self);
} dio_drv_tst;

void init_dio_drv(dio_drv_tst *dio_drv_pst);



#endif // DIO_DRV_STM32F407_H
