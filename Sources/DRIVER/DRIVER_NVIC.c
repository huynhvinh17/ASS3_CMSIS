#include "DRIVER_NVIC.h"

void DRIVER_NVIC_enableIRQ(IRQn_Type irq_number)
{
    HAL_EnableIRQ(irq_number);
}
