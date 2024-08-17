#include "DRIVER_PORT.h"

#define uint32 unsigned int /** Define uint32 for unsigned int */

uint32 DRIVER_PORT_getInterruptFlag(PORT_Type *PORT, uint32 button_bit)
{
    return HAL_PORT_getInterruptFlag(PORT,button_bit);
}

void DRIVER_PORT_clearInterruptFlag(PORT_Type *PORT, uint32 button_bit)
{
    HAL_PORT_clearInterruptFlag(PORT,button_bit);
}

void DRIVER_PORT_INIT(PORT_Type *PORT, pin_t pin, pin_mux_control_t config)
{
    HAL_PORT_config(PORT,pin,config);
}

void DRIVER_PORT_interrupt_config(PORT_Type *PORT, pin_t pin, interrupt_config_t config)
{
    HAL_PORT_interrupt_config(PORT,pin,config);
}

void DRIVER_PORT_pull_resistor(PORT_Type *PORT, pin_t pin, pull_enable_t enable, pull_select_t select)
{
    HAL_PORT_pull_enable(PORT,pin,enable);
    HAL_PORT_pull_select(PORT,pin,select);
}

