#ifndef _HAL_GPIO_H_
#define _HAL_GPIO_H_

#include "MKL46Z4.h"
#define uint32 unsigned int /** Define uint32 for unsigned int */

typedef enum
{
    configPinInput = 0U,
    configPinOutput = 1U
} config_pin_t;

typedef enum
{
    PinOutPutLow = 0U,
    PinOutPutHigh = 1U
} read_pin_output_t;

typedef enum
{
    PinInputLow = 0U,
    PinInputHigh = 1U
} read_pin_input_t;

typedef enum
{
    configPinLow = 0U,
    configPinHigh = 1U
} pin_state_t;

void HAL_GPIO_INIT(GPIO_Type *GPIOx, uint32 pin_mask, config_pin_t state);
void HAL_GPIO_TOGGLE_PIN(GPIO_Type *GPIOx, uint32 pin_mask);
/* read_pin_output_t HAL_GPIO_ReadPinOutput(GPIO_Type *GPIOx, uint32 pin_mask);
read_pin_input_t HAL_GPIO_ReadPinInPut(GPIO_Type *GPIOx, uint32 pin_mask); */
void HAL_GPIO_WritePin(GPIO_Type *GPIOx, uint32 pin_mask, pin_state_t state);

#endif /** _HAL_GPIO_H_ */
