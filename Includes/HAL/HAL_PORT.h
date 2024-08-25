#ifndef _HAL_PORT_H_
#define _HAL_PORT_H_

#define uint32 unsigned int /** Define uint32 for unsigned int */
#include "MKL46Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enumeration for pin multiplexing control options
 *
 */
typedef enum
{
    Pin_analog = PORT_PCR_MUX(0), /** Configures the pin for analog functions */
    Pin_GPIO = PORT_PCR_MUX(1)    /** Configures the pin for general-purpose I/O */
} pin_mux_control_t;

/** Enumeration for interrupt configuration option */
typedef enum
{
    request_disable = 0U,            /** Disable interrupt request */
    rising_edge = PORT_PCR_IRQC(9),  /** Configures the interrupt to trigger on a rising */
    falling_edge = PORT_PCR_IRQC(10) /** Configures the interrupt to trigger on a falling */
} interrupt_config_t;

/** Enumeration for pull resistor selection */
typedef enum
{
    pullDown = 0U,            /** Selects a pull-down resistor */
    pullUp = PORT_PCR_PS_MASK /** Selects a pull up resistor */
} pull_select_t;

typedef enum
{
    disable_internal_pull_pin = 0U,
    enable_internal_pull_pin = PORT_PCR_PE_MASK
} pull_enable_t;

/**
 * @brief check if an interrupt has been triggered
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @return uint32 non-zero value if a interrupt has been triggered
 */
uint32 HAL_PORT_GetInterruptFlag(PORT_Type *PORT, uint32 pin);

/**
 * @brief Clear flag after an interrupt is triggered
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 */
void HAL_PORT_ClearInterruptFlag(PORT_Type *PORT, uint32 pin);

/**
 * @brief Initialize the pin mux configuration
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @param config The pin mux configuration value to set for the pin
 */
void HAL_PORT_Init(PORT_Type *PORT, uint32 pin, pin_mux_control_t config);

/**
 * @brief Configures the interrupt setting
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @param config The interrupt configuration value to be set
 */
void HAL_PORT_InterruptConfig(PORT_Type *PORT, uint32 pin, interrupt_config_t config);

/**
 * @brief Configure the internal pull up or pull down resistor
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @param enable Specifies whether to enable or disble the internal pull resistor
 */
void HAL_PORT_PullEnable(PORT_Type *PORT, uint32 pin, pull_enable_t enable);

/**
 * @brief Selects the type of internal pull resistor
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @param select Specifies whether to select a pull up or pull down resistor
 */
void HAL_PORT_PullSelect(PORT_Type *PORT, uint32 pin, pull_select_t select);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** HAL_PORT_H */
