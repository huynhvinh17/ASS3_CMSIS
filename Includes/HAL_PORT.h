#ifndef _HAL_PORT_H_
#define _HAL_PORT_H_

#define uint32 unsigned int /** Define uint32 for unsigned int */
#include "MKL46Z4.h"


typedef enum
{
    LED_GREEN_PIN = 5,
    LED_RED_PIN = 29,
    SW1_PIN = 3,
    SW3_PIN = 12

} pin_t;

typedef enum
{
    Pin_analog = PORT_PCR_MUX(0),
    Pin_GPIO = PORT_PCR_MUX(1)
} pin_mux_control_t;

typedef enum
{
    request_disable = 0U,
    rising_edge = PORT_PCR_IRQC(9), // Corrected to use the PORT_PCR_IRQC macro
    falling_edge = PORT_PCR_IRQC(10)
} interrupt_config_t;

typedef enum
{
    pullDown = 0U,
    pullUp = PORT_PCR_PS_MASK // Corrected to use the correct mask
} pull_select_t;

typedef enum
{
    not_enable_internal_pull_pin = 0U,
    enable_internal_pull_pin = PORT_PCR_PE_MASK
} pull_enable_t;

uint32 HAL_PORT_getInterruptFlag(PORT_Type *PORT, uint32 button_bit);

void HAL_PORT_clearInterruptFlag(PORT_Type *PORT, uint32 button_bit);

void HAL_PORT_config(PORT_Type *PORT, pin_t pin, pin_mux_control_t config);

void HAL_PORT_interrupt_config(PORT_Type *PORT, pin_t pin, interrupt_config_t config);

void HAL_PORT_pull_enable(PORT_Type *PORT, pin_t pin, pull_enable_t enable);

void HAL_PORT_pull_select(PORT_Type *PORT, pin_t pin, pull_select_t select);

#endif /** HAL_PORT_H */
