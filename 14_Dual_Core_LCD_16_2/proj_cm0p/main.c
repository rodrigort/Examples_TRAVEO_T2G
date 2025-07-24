/*******************************************************************************
* File Name:   main.c (CM0+ Core)
*
* Project:     14_Dual_Core_LCD_16_2
* Author:      Rodrigo Rodrigues (EWD)
* Email:       rodrigo@eaglewingd.com
* Date:        2025-07-XX
*
* Description:
*  This code runs on the CM0+ core of a Traveo II (T2G) MCU.
*  It performs the following operations:
*
*   - Initializes the board and peripherals.
*   - Initializes a 16x2 LCD via GPIO in 4-bit mode.
*   - Displays a welcome message on the LCD (first row).
*   - Blinks an LED connected to P13.1 every 500ms.
*   - Increments a counter every second and shows its value on the second row.
*   - Resets the counter after reaching 100.
*   - Starts the Cortex-M4 core from the address defined in the linker script.
*
*******************************************************************************/

#include "cybsp.h"
#include "Lib_LCD.h"
#include "stdio.h"

/*******************************************************************************
* Global Variables
********************************************************************************/
extern const char __cm4_app_address[];     // External symbol defined in the linker for CM4 start

static uint32_t sum = 0;                   // Summation counter
char buffer[16];                           // Buffer for LCD formatted string

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  Main entry point of the CM0+ core. Handles board initialization,
*  LCD setup, LED blinking, counter display, and CM4 startup.
*
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    // Initialize board support package and peripherals
    result = cybsp_init();
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0); // Halt on failure
    }

    // Initialize LCD and display welcome message
    LCD_init();
    LCD_OUT(1, 1, "TRAVEO AMR-M0");

    // Enable global interrupts
    __enable_irq();

    // Launch Cortex-M4 core using the linker-defined address
    Cy_SysEnableCM4((uint32_t)__cm4_app_address);

    // Main loop: blink LED and update LCD
    for (;;)
    {
        // Toggle LED (assumes LED is connected to P13.1 or similar)
        Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 0U); // ON
        Cy_SysLib_Delay(500);                    // 500ms

        Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 1U); // OFF
        Cy_SysLib_Delay(500);                    // 500ms

        // Update counter and display on LCD
        sum++;
        if (sum > 100)
        {
            sum = 0;
            LCD_OUT(2, 7, "   ");  // Clear previous digits
        }

        snprintf(buffer, sizeof(buffer), "Soma: %u", (unsigned int)sum);
        LCD_OUT(2, 1, buffer);     // Show updated sum on second row
    }
}

/* [] END OF FILE */
