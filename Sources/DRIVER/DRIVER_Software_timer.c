#include "../Includes/DRIVER/DRIVER_Software_timer.h"
#include <stddef.h>

/**
 * @brief Initializes the software timers
 */
void DRIVER_Software_Timer_Init(void)
{
    uint8_t i;
    for (i = 0; i < MAX_TIMERS; i++)
    {
        swTimerArray[i].Current_value = 0; /** Reset current value to 0 */
        swTimerArray[i].Load_value = 0;    /** Set the initial load value to 0  */
        swTimerArray[i].func = NULL;       /** initialize the function pointer to NULL */
        swTimerArray[i].en = false;        /** Disable the timer */
    }
    HAL_Systick_init(0xFFFFF); /** Start the Systick timer with a load value of 0xFFFFF */
}

/**
 * @brief Enable the software timer
 *
 * @param timerIndex The index of software timer to enable
 */
void DRIVER_Software_Timer_Enable(uint8_t timerIndex)
{
    if (timerIndex < MAX_TIMERS) /** Check if the timer index */
    {
        swTimerArray[timerIndex].en = true; /** Enable the software timer */
    }
    else
    {
        /** do nothing */
    }
}

/**
 * @brief Disable the software timer
 *
 * @param timerIndex The index of software timer to disable
 */
void DRIVER_Software_Timer_Disable(uint8_t timerIndex)
{
    if (timerIndex < MAX_TIMERS) /** Check if the timer index */
    {
        swTimerArray[timerIndex].en = false; /** Disable the software timer */
    }
    else
    {
        /** do nothing */
    }
}

typedef void (*DRIVER_Callback)(void);
DRIVER_Callback SystickCallback = NULL;

void DRIVER_Software_timer_set_alarm(uint8_t timerIndex, uint32 loadValue)
{
    if (timerIndex < MAX_TIMERS)
    {
        swTimerArray[timerIndex].Load_value = loadValue;
    }
}

void DRIVER_Software_timer_register_callbackUser(uint8_t timerIndex, SW_timer_callback_t user)
{
    if (timerIndex < MAX_TIMERS)
    {
        swTimerArray[timerIndex].func = user;
    }
}

void SysTick_Handler(void)
{
    uint32 i;
    for (i = 0; i < MAX_TIMERS; i++)
    {
        if (swTimerArray[i].en)
        {
            swTimerArray[i].Current_value++;
            if (swTimerArray[i].Current_value == swTimerArray[i].Load_value)
            {
                if (swTimerArray[i].func != NULL)
                {
                    swTimerArray[i].func();
                }
                swTimerArray[i].Current_value = 0;
            }
        }
    }
}
