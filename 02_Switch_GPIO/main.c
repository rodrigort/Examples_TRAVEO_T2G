/*******************************************************************************
* File Name:   main.c
*
* Description:
* Example 2 - Switch GPIO:
* This example demonstrates how to read two push-button inputs and control
* two LEDs on the KIT_T2G-B-E_Lite board using the Infineon Traveo II MCU.
*
* - BTN 1 (P5.3) controls LED 1 (P5.0) with a debounce delay
* - BTN 2 (P17.0) directly reflects its state to LED 2 (P5.1)
*
* Both buttons use internal pull-up configuration and are active-low.
* The LEDs are also active-low: writing 0 turns them ON.
*
* The project was created using ModusToolbox, with pin configuration handled
* via Device Configurator.
*
* Related Document: See README.md
*
*******************************************************************************/

/*******************************************************************************
* Header Files
*******************************************************************************/
#include "cybsp.h"

/*******************************************************************************
* Main Function
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    // Initialize board support package and configured peripherals
    result = cybsp_init();

    // Halt execution if initialization fails
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    // Enable global interrupts (if used)
    __enable_irq();

    // Main application loop
    for (;;)
    {
        // -------- BUTTON 1 → LED 1 --------
        if (Cy_GPIO_Read(BTN_1_PORT, BTN_1_PIN) == 0)
        {
            // If button 1 is pressed (logic LOW)
            Cy_SysLib_Delay(200);                       // Software debounce delay
            Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 0);    // Turn ON LED 1 (active-low)
        }
        else
        {
            // If button 1 is released
            Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 1);    // Turn OFF LED 1
        }

        // -------- BUTTON 2 → LED 2 --------
        // Read button 2 and mirror its state to LED 2
        // If pressed (0), LED turns ON (0); if not, LED turns OFF (1)
        Cy_GPIO_Write(LED_2_PORT, LED_2_PIN,
                      (Cy_GPIO_Read(BTN_2_PORT, BTN_2_PIN) == 0) ? 0 : 1);

        // Apply debounce only when button 2 is pressed
        Cy_SysLib_Delay((Cy_GPIO_Read(BTN_2_PORT, BTN_2_PIN) == 0) ? 200 : 0);
    }
}

/* [] END OF FILE */
