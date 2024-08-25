#ifndef _DRIVER_SIM_H_
#define _DRIVER_SIM_H_

#include "MKL46Z4.h"
#include "../Includes/HAL/HAL_SIM.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enable clock for a peripheral port
 *
 * @param portClockEnable The clock enable bit mask for peripheral port
 */
void DRIVER_SIM_EnableClock(system_clock_control_t portClockEnable);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_SIM_H_ */
