
#include "MKL46Z4.h"
#include "DRIVER_GPIO.h"
#include "DRIVER_NVIC.h"
#include "DRIVER_PORT.h"
#include "DRIVER_SIM.h"

#define LED_GREEN_BIT (1 << 5)
#define LED_RED_BIT (1 << 29)
#define SW1_BIT (1 << 3)
#define SW3_BIT (1 << 12)

void LED_GREEN_INIT(void)
{
    DRIVER_SIM_enableClock(PORTD_clockEnable);
    DRIVER_PORT_INIT(PORTD, LED_GREEN_PIN, Pin_GPIO);
    DRIVER_GPIO_INIT(GPIOD, LED_GREEN_BIT, configPinOutput);
    DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_BIT, configPinLow);
}

void LED_RED_INIT(void)
{
    DRIVER_SIM_enableClock(PORTE_clockEnable);
    DRIVER_PORT_INIT(PORTE, LED_RED_PIN, Pin_GPIO);
    DRIVER_GPIO_INIT(GPIOE, LED_RED_BIT, configPinOutput);
    DRIVER_GPIO_WritePin(GPIOE, LED_RED_BIT, configPinLow);
}

void Button_SW1_SW3_INIT(void)
{
    DRIVER_SIM_enableClock(PORTC_clockEnable);
    DRIVER_PORT_INIT(PORTC, SW1_PIN, Pin_GPIO);
    DRIVER_PORT_INIT(PORTC, SW3_PIN, Pin_GPIO);
    DRIVER_GPIO_INIT(GPIOC, SW1_BIT, configPinInput);
    DRIVER_GPIO_INIT(GPIOC, SW3_BIT, configPinInput);
    DRIVER_PORT_interrupt_config(PORTC,SW1_PIN,falling_edge);
    DRIVER_PORT_interrupt_config(PORTC,SW3_PIN,falling_edge);
    DRIVER_PORT_pull_resistor(PORTC,SW1_PIN,enable_internal_pull_pin,pullUp);
    DRIVER_PORT_pull_resistor(PORTC,SW3_PIN,enable_internal_pull_pin,pullUp);
    DRIVER_NVIC_enableIRQ(PORTC_PORTD_IRQn);
}

void PORTC_PORTD_IRQHandler(void)
{
    if (DRIVER_PORT_getInterruptFlag(PORTC, SW1_BIT))
    {
        DRIVER_GPIO_TOGGLE_PIN(GPIOE, LED_RED_BIT);
        DRIVER_PORT_clearInterruptFlag(PORTC,SW1_BIT);
    }
    if (DRIVER_PORT_getInterruptFlag(PORTC, SW3_BIT))
    {
        DRIVER_GPIO_TOGGLE_PIN(GPIOD, LED_GREEN_BIT);
        DRIVER_PORT_clearInterruptFlag(PORTC,SW3_BIT);
    }
}

int main(void)
{
    LED_RED_INIT();
    LED_GREEN_INIT();
    Button_SW1_SW3_INIT();
    while (1)
    {
    }

    return 0;
}
