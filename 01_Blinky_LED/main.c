/*******************************************************************************
* File Name:   main.c
*
* Description:
* Simple example to blink LED 3 using the Traveo II microcontroller
* with the KIT_T2G-B-E_Lite evaluation board.
*
* The LED is connected to pin P5_0 with pull-up logic, meaning it turns ON
* when the GPIO output is set to LOW (0V), and OFF when set to HIGH (3.3V).
*
* The LED will blink every 1 second using Cy_SysLib_Delay().
*
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
