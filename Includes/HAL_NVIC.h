#ifndef _HAL_NVIC_H_
#define _HAL_NVIC_H_

#define uint32 unsigned int /** Define uint32 for unsigned int */
#include "MKL46Z4.h"

void HAL_EnableIRQ(IRQn_Type irq_number);

#endif /** HAL_NVIC_H */
