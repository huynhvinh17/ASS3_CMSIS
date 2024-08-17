#ifndef _DRIVER_PORT_H_
#define _DRIVER_PORT_H_

#include "HAL_PORT.h"
#include "MKL46Z4.h"

#define uint32 unsigned int /** Define uint32 for unsigned int */


uint32 DRIVER_PORT_getInterruptFlag(PORT_Type *PORT, uint32 button_bit);

void DRIVER_PORT_clearInterruptFlag(PORT_Type *PORT, uint32 button_bit);

void DRIVER_PORT_INIT(PORT_Type *PORT, pin_t pin, pin_mux_control_t config);

void DRIVER_PORT_interrupt_config(PORT_Type *PORT, pin_t pin, interrupt_config_t config);

void DRIVER_PORT_pull_resistor(PORT_Type *PORT, pin_t pin, pull_enable_t enable, pull_select_t select);

#endif  /** _DRIVER_PORT_H_ */
