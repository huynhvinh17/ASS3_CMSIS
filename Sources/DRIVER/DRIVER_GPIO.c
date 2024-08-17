#include "DRIVER_GPIO.h"
#define uint32 unsigned int /** Define uint32 for unsigned int */

void DRIVER_GPIO_INIT(GPIO_Type *GPIOx, uint32 pin_mask, uint32 state)
{
    HAL_GPIO_INIT(GPIOx, pin_mask, state);
}

void DRIVER_GPIO_TOGGLE_PIN(GPIO_Type *GPIOx, uint32 pin_mask)
{
    HAL_GPIO_TOGGLE_PIN(GPIOx, pin_mask);
}

/* read_pin_output_t DRIVER_GPIO_ReadPinOutput(GPIO_Type *GPIOx, uint32 pin_mask)
{
    if (PinOutPutHigh == HAL_GPIO_ReadPinOutput(GPIOx, pin_mask))
    {
        return PinOutPutHigh;
    }
    else
    {
        return PinOutPutLow;
    }
}

read_pin_input_t DRIVER_GPIO_ReadPinInput(GPIO_Type *GPIOx, uint32 pin_mask)
{
    if (PinInputHigh == HAL_GPIO_ReadPinInPut(GPIOx, pin_mask))
    {
        return PinInputHigh;
    }
    else
    {
        return PinInputLow;
    }
}
 */

void DRIVER_GPIO_WritePin(GPIO_Type *GPIOx, uint32 pin_mask, pin_state_t state)
{
    HAL_GPIO_WritePin(GPIOx, pin_mask, state);
}
