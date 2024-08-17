#include "DRIVER_SIM.h"

#define uint32 unsigned int /** Define uint32 for unsigned int */


void DRIVER_SIM_enableClock(system_clock_control_t portClockEnable)
{
    HAL_SIM_enableClock(portClockEnable);
}
