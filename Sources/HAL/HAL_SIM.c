#include "MKL46Z4.h"
#include "HAL_SIM.h"

void HAL_SIM_enableClock(system_clock_control_t portClockEnable)
{
    SIM->SCGC5 |= portClockEnable;
}
