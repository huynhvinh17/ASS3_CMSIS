#ifndef _DRIVER_GPIO_H_
#define _DRIVER_GPIO_H_

#include "MKL46Z4.h"
#include "../Includes/HAL/HAL_GPIO.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define uint32 unsigned int

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Initializes a GPIO pin with a specified state
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin The pin number on the GPIO port
 * @param pinState State of the pin
 */
void DRIVER_GPIO_Init(GPIO_Type *GPIOx, uint32 pin, pin_state_t pinState);

/**
 * @brief Tonggle the state of a GPIO pin
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin The pin number on the GPIO port
 */
void DRIVER_GPIO_TogglePin(GPIO_Type *GPIOx, uint32 pin);

/**
 * @brief Writes a specified state to a GPIO pin
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin The pin number on the GPIO port
 * @param pinState The state of pin
 *                 - `configPinHigh`: Sets the pin state to high (logic level 1).
 *                 - `configPinLow`: Sets the pin state to low (logic level 0).
 */
void DRIVER_GPIO_WritePin(GPIO_Type *GPIOx, uint32 pin, pin_state_t pinState);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_GPIO_H_ */
