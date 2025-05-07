/*******************************************************************************
* File Name:   main.c
*
* Description:
* Example 01 – Blinky LED:
* This example toggles the onboard LED (connected to P5.0) every 1 second
* using the Cy_SysLib_Delay() function. The LED uses active-low logic.
*
* - LED Output: P5.0
* - Logic: ON = LOW, OFF = HIGH
*
* Related Document: See README.md
*
********************************************************************************
* Author: Rodrigo Teixeira
*******************************************************************************/


/*******************************************************************************
* Header Files
*******************************************************************************/
#if defined (CY_USING_HAL)
#include "cyhal.h"
#endif
#include "cybsp.h"

/*******************************************************************************
* Function Definitions
*******************************************************************************/

int main(void)
{
    cy_rslt_t result;

    // Initialize the board and all configured peripherals
    result = cybsp_init();

    // If initialization fails, halt the system
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    // Enable global interrupts
    __enable_irq();

    // Main loop: toggle LED every 500ms
    for (;;)
    {
        Cy_GPIO_Write(LED1_PORT, LED1_PIN, 0U); // Write LOW to turn ON the LED
        Cy_SysLib_Delay(500);

        Cy_GPIO_Write(LED1_PORT, LED1_PIN, 1U); // Write HIGH to turn OFF the LED
        Cy_SysLib_Delay(500);
    }
}

/* [] END OF FILE */
