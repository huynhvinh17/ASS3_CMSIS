#include "HAL_NVIC.h"
#include "MKL46Z4.h"

void HAL_EnableIRQ(IRQn_Type irq_number)
{
    NVIC_EnableIRQ(irq_number);
}
