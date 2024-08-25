#ifndef _APP_H_
#define _APP_H_

#include "MKL46Z4.h"
#include "../Includes/DRIVER/DRIVER_GPIO.h"
#include "../Includes/DRIVER/DRIVER_NVIC.h"
#include "../Includes/DRIVER/DRIVER_PORT.h"
#include "../Includes/DRIVER/DRIVER_SIM.h"
#include "../Includes/DRIVER/DRIVER_Software_timer.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LED_GREEN_PIN 5
#define LED_RED_PIN 29
#define SW1_PIN 3
#define SW3_PIN 12

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Initializes the green LED on PORTD
 *
 */
void Init_LED_Green(void);

/**
 * @brief Initializes the red LED on PORTE
 *
 */
void Init_LED_Red(void);

void DRIVER_SW_Timer_User0(void);
void DRIVER_SW_Timer_User1(void);

void systickInterruptCallbackUser0(void);
void systickInterruptCallbackUser1(void);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _APP_H_ */
