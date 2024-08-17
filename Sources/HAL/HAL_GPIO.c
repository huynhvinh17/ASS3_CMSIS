#include "HAL_GPIO.h"
#include "MKL46Z4.h"

void HAL_GPIO_INIT(GPIO_Type *GPIOx, uint32 pin_mask, config_pin_t state)
{
    if (state == configPinOutput)
    {
        GPIOx->PDDR |= pin_mask;
    }
    else if (state == configPinInput)
    {
        GPIOx->PDDR &= ~pin_mask;
    }
}

void HAL_GPIO_TOGGLE_PIN(GPIO_Type *GPIOx, uint32 pin_mask)
{
    GPIOx->PTOR |= pin_mask;
}

/* read_pin_output_t HAL_GPIO_ReadPinOutput(GPIO_Type *GPIOx, uint32 pin_mask)
{
    if (GPIOx->PDOR |= pin_mask)
    {
        return PinOutPutHigh;
    }
    else if (GPIOx->PDOR &= ~pin_mask)
    {
        return PinOutPutLow;
    }
    else
    {
    }
}

read_pin_input_t HAL_GPIO_ReadPinInPut(GPIO_Type *GPIOx, uint32 pin_mask)
{
    if ((GPIOx->PDIR) |= pin_mask)
    {
        return PinInputHigh;
    }
    else
    {
        return PinInputLow;
    }
}
 */

void HAL_GPIO_WritePin(GPIO_Type *GPIOx, uint32 pin_mask, pin_state_t state)
{
    if (state == configPinHigh)
    {
        GPIOx->PDOR &= ~pin_mask;
    }
    else if (state == configPinLow)
    {
        GPIOx->PDOR |= pin_mask;
    }
}
