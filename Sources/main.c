
/**
 * @file main.c
 * @author huynhvinh17@gmail.com
 * @brief Main program file for initializing peripherals and setting up interrupt handling.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/APP/APP.h"
#include "../Includes/DRIVER/DRIVER_NVIC.h"
#include "../Includes/DRIVER/DRIVER_Software_timer.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

int main(void)
{

    Init_LED_Red();   /** Initialize the Red LED on the boardI */
    Init_LED_Green(); /** Initialize the Green LED on the board */

    DRIVER_Software_Timer_Init();
    DRIVER_SW_Timer_User0();
    DRIVER_SW_Timer_User1();

    while (1)
    {
    }

    return 0;
}
