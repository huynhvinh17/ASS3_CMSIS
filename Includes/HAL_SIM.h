#ifndef _HAL_SIM_H_
#define _HAL_SIM_H_

#define uint32 unsigned int /** Define uint32 for unsigned int */
#include "MKL46Z4.h"

typedef enum
{
    PORTA_clockEnable = SIM_SCGC5_PORTA_MASK,
    PORTB_clockEnable = SIM_SCGC5_PORTB_MASK,
    PORTC_clockEnable = SIM_SCGC5_PORTC_MASK,
    PORTD_clockEnable = SIM_SCGC5_PORTD_MASK,
    PORTE_clockEnable = SIM_SCGC5_PORTE_MASK
} system_clock_control_t;

void HAL_SIM_enableClock(system_clock_control_t portClockEnable);

#endif /** HAL_SIM_H */
