/**
 * @file APP.c
 * @author huynhvinh17@gmail.com
 * @brief Application layer for initializing LEDs and switches, and handling interrupts.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/APP/APP.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Initializes the green LED on PORTD
 *
 */
void Init_LED_Green(void)
{
    DRIVER_SIM_EnableClock(PORTD_clockEnable);                /** Enable the clock for PORTD */
    DRIVER_PORT_Init(PORTD, LED_GREEN_PIN, Pin_GPIO);         /** Initialize PORTD for GPIO functionaliy */
    DRIVER_GPIO_Init(GPIOD, LED_GREEN_PIN, configPinOutput);  /** Set the green LED pin as an output*/
    DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, configPinLow); /** Set the green LED pin to low (led off) */
}

/**
 * @brief Initializes the red LED on PORTE
 *
 */
void Init_LED_Red(void)
{
    DRIVER_SIM_EnableClock(PORTE_clockEnable);              /** Enable the clock for PORTE */
    DRIVER_PORT_Init(PORTE, LED_RED_PIN, Pin_GPIO);         /** Initialize PORTE for GPIO functionality */
    DRIVER_GPIO_Init(GPIOE, LED_RED_PIN, configPinOutput);  /** Set the red LED pin as an output */
    DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, configPinLow); /** Set the red LED pin to low (LED off) */
}

void DRIVER_SW_Timer_User0(void)
{
    DRIVER_Software_Timer_Enable(0);
    DRIVER_Software_timer_set_alarm(0, 2);
    DRIVER_Software_timer_register_callbackUser(0, systickInterruptCallbackUser0);
}

void DRIVER_SW_Timer_User1(void)
{
    DRIVER_Software_Timer_Enable(1);
    DRIVER_Software_timer_set_alarm(1, 7);
    DRIVER_Software_timer_register_callbackUser(1, systickInterruptCallbackUser1);
}

void systickInterruptCallbackUser0(void)
{
    DRIVER_GPIO_TogglePin(GPIOE, LED_RED_PIN); /** Toggle the RED led state */
}

void systickInterruptCallbackUser1(void)
{
    DRIVER_GPIO_TogglePin(GPIOD, LED_GREEN_PIN); /** Toggle the green LED state */
}
