#ifndef DRIVER_GPIO_H
#define DRIVER_GPIO_H

#include "MKL46Z4.h"
#include "HAL_GPIO.h"

#define uint32 unsigned int


/**
 * @brief Initialize GPIO pin(s) with the specified configuration.
 *
 * @param GPIOx     Pointer to the GPIO peripheral.
 * @param pin_mask  Mask for the pin(s) to be initialized.
 * @param state     Desired configuration state (input/output).
 */
void DRIVER_GPIO_INIT(GPIO_Type *GPIOx, uint32 pin_mask, uint32 state);

/**
 * @brief Toggle the state of the specified GPIO pin(s).
 *
 * @param GPIOx     Pointer to the GPIO peripheral.
 * @param pin_mask  Mask for the pin(s) to be toggled.
 */
void DRIVER_GPIO_TOGGLE_PIN(GPIO_Type *GPIOx, uint32 pin_mask);

/**
 * @brief Read the state of the specified GPIO pin.
 *
 * @param GPIOx     Pointer to the GPIO peripheral.
 * @param pin_mask  Mask for the pin to be read.
 * @return          The state of the pin (high/low).
 */
/* read_pin_output_t DRIVER_GPIO_ReadPinOutput(GPIO_Type *GPIOx, uint32 pin_mask);

read_pin_input_t DRIVER_GPIO_ReadPinInput(GPIO_Type *GPIOx, uint32 pin_mask);
 */
/**
 * @brief Write a state (high/low) to the specified GPIO pin(s).
 *
 * @param GPIOx     Pointer to the GPIO peripheral.
 * @param pin_mask  Mask for the pin(s) to be written.
 * @param state     The state to write to the pin(s).
 */
void DRIVER_GPIO_WritePin(GPIO_Type *GPIOx, uint32 pin_mask, pin_state_t state);

#endif // DRIVER_GPIO_H
