#include "HAL_PORT.h"
#include "MKL46Z4.h"

uint32 HAL_PORT_getInterruptFlag(PORT_Type *PORT, uint32 button_bit)
{
    return PORT -> ISFR & button_bit;
}

void HAL_PORT_clearInterruptFlag(PORT_Type *PORT, uint32 button_bit)
{
    PORT->ISFR |= button_bit;
}

void HAL_PORT_config(PORT_Type *PORT, pin_t pin, pin_mux_control_t config)
{
    PORT->PCR[pin] &= ~PORT_PCR_MUX_MASK;
    PORT->PCR[pin] |= config;
}

void HAL_PORT_interrupt_config(PORT_Type *PORT, pin_t pin, interrupt_config_t config)
{
    PORT->PCR[pin] &= ~PORT_PCR_IRQC_MASK; // Clear the IRQC field
    PORT->PCR[pin] |= config;              // Set the new interrupt configuration
}

void HAL_PORT_pull_enable(PORT_Type *PORT, pin_t pin, pull_enable_t enable)
{
    if (enable == enable_internal_pull_pin)
    {
        PORT->PCR[pin] |= PORT_PCR_PE_MASK; // Enable internal pull-up or pull-down resistor
    }
    else
    {
        PORT->PCR[pin] &= ~PORT_PCR_PE_MASK; // Disable internal pull-up or pull-down resistor
    }
}

void HAL_PORT_pull_select(PORT_Type *PORT, pin_t pin, pull_select_t select)
{
    if (select == pullUp)
    {
        PORT->PCR[pin] |= PORT_PCR_PS_MASK; // Select pull-up resistor
    }
    else
    {
        PORT->PCR[pin] &= ~PORT_PCR_PS_MASK; // Select pull-down resistor
    }
}
