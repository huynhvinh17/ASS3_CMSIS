#ifndef _DRIVER_PORT_H_
#define _DRIVER_PORT_H_

#include <stddef.h>
#include "MKL46Z4.h"
#include "../Includes/HAL/HAL_PORT.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define uint32 unsigned int /** Define uint32 for unsigned int */

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/** Typedef for a callback function pointer type used for PORTC and PORTD interrupts. */
typedef void (*PORTC_PORTD_callback_t)(void);

/**
 * @brief The interrupt flag status for the specific GPIO pin
 *
 * @param PORT pointer to the PORT structure
 * @param pin The pin number on the specified PORT
 * @return uint32 The interrupt flag status
 */
uint32 DRIVER_PORT_GetInterruptFlag(PORT_Type *PORT, uint32 pin);

/**
 * @brief Clears the interrupt flag for a specific GPIO pin
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specified PORT
 */
void DRIVER_PORT_ClearInterruptFlag(PORT_Type *PORT, uint32 pin);

/**
 * @brief Initializes a GPIO pin with a specific configuration
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specific PORT
 * @param config The pin configuration setting
 */
void DRIVER_PORT_Init(PORT_Type *PORT, uint32 pin, pin_mux_control_t config);

/**
 * @brief Configures the interrupt settings
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specified PORT
 * @param config The interrupt configuration settings
 */
void DRIVER_PORT_InterruptConfig(PORT_Type *PORT, uint32 pin, interrupt_config_t config);

/**
 * @brief Configures the pull-up/pull-down resistors for a specific GPIO pin
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specific PORT
 * @param enable To enable or disable the internal pulll-up/pull-down resistor
 * @param select which type of pull resistor to use:
 *                - `pullUp`: Selects the pull-up resistor.
 *                - `pullDown`: Selects the pull-down resistor.
 */
void DRIVER_PORT_PullResistor(PORT_Type *PORT, uint32 pin, pull_enable_t enable, pull_select_t select);

/**
 * @brief Register a callback function for PORTC and PORTD interrupt
 *
 * @param callback the callback function to be registered
 */
void DRIVER_PORT_RegisterCallback(PORTC_PORTD_callback_t callback);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_PORT_H_ */
