#ifndef _HAL_SIM_H_
#define _HAL_SIM_H_

#include "MKL46Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define uint32 unsigned int /** Define uint32 for unsigned int */

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enumeration for system clock control settings for various GPIO port
 *
 */
typedef enum
{
    PORTA_clockEnable = SIM_SCGC5_PORTA_MASK, /** Bit mask for enabling the clock to PORTA */
    PORTB_clockEnable = SIM_SCGC5_PORTB_MASK, /** Bit mask for enabling the clock to PORTB */
    PORTC_clockEnable = SIM_SCGC5_PORTC_MASK, /** Bit mask for enabling the clock to PORTC */
    PORTD_clockEnable = SIM_SCGC5_PORTD_MASK, /** Bit mask for enabling the clock to PORTD */
    PORTE_clockEnable = SIM_SCGC5_PORTE_MASK  /** Bit mask for enabling the clock to PORTE */
} system_clock_control_t;

/**
 * @brief Enable clock for a peripheral port
 *
 * @param portClockEnable The clock enable bit mask for peripheral port
 */
void HAL_SIM_SCGC5_EnableClock(system_clock_control_t portClockEnable);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** HAL_SIM_H */
