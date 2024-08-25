#ifndef _DRIVER_SOFTWARE_TIMER_
#define _DRIVER_SOFTWARE_TIMER_
#include "../Includes/HAL/HAL_Systick.h"
#include <stdbool.h>
#include <stdint.h>

#define uint32 unsigned int
#define MAX_TIMERS 10

typedef void (*SW_timer_callback_t)(void);

    typedef struct
{
    uint32 Current_value;
    uint32 Load_value;
    SW_timer_callback_t func;
    bool en;
} sw_timer;

sw_timer swTimerArray[MAX_TIMERS];

void DRIVER_Software_Timer_Init();

void DRIVER_Software_Timer_Enable(uint8_t timerIndex);

void DRIVER_Software_Timer_Disable(uint8_t timerIndex);

void DRIVER_Software_timer_set_alarm(uint8_t timerIndex, uint32 loadValue);

void DRIVER_Software_timer_register_callbackUser(uint8_t timerIndex, SW_timer_callback_t user);

#endif /** _DRIVER_SOFTWARE_TIMER_ */
