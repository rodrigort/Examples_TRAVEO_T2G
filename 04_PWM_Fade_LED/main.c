/*******************************************************************************
* File Name: main.c
*
* Description:
*   This example demonstrates how to configure and use the PWM peripheral 
*   of the TRAVEO T2G microcontroller to create a "fade" effect on an LED.
*   The brightness of the LED gradually increases and decreases by varying the
*   PWM duty cycle from 0 to 100% and back, using a timer clocked at 10 MHz.
*
* Hardware Used:
*   - KIT_T2G-B-E_Lite
*   - On-board LED connected to pin P5.0 (configured as PWM output)
*
* Related Document:
*   See the README.md in the project root for setup and build instructions.
*
* Tool Used:
*   - ModusToolbox 3.X
*   - Visual Studio Code or Eclipse IDE
*
* Author:
*   Rodrigo Rodrigues
*
*******************************************************************************/

#include "cybsp.h"                         // Board Support Package

/******************************************************************************
* Macros
*******************************************************************************/
#define PWM_MAX_COMPARE 13110             // Maximum compare value for 10 MHz PWM signal
#define FADE_STEP       50                // Step size for PWM duty cycle increment/decrement
#define FADE_DELAY_MS   5                 // Delay in milliseconds between steps

/*******************************************************************************
* Function Definitions
*******************************************************************************/

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*   Main function that initializes the board, configures PWM, and runs a fade effect.
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;                     // Variable to store the result of function calls
    uint16_t duty = 0;                    // Current PWM duty cycle
    bool increasing = true;              // Flag to indicate direction of fade (up/down)

    result = cybsp_init();               // Initialize board support package
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);                    // Halt execution if BSP init fails
    }

    /* Initialize, enable, and start the configured PWM block */
    Cy_TCPWM_PWM_Init(PWM_0_HW, PWM_0_NUM, &PWM_0_config);      // Initialize PWM with config
    Cy_TCPWM_PWM_Enable(PWM_0_HW, PWM_0_NUM);                   // Enable the PWM
    Cy_TCPWM_TriggerStart_Single(PWM_0_HW, PWM_0_NUM);          // Start the PWM counter

    __enable_irq();                     // Enable global interrupts

    /* Main loop: adjust duty cycle up and down to create fade effect */
    while (1)
    {
        Cy_TCPWM_PWM_SetCompare0(PWM_0_HW, PWM_0_NUM, duty); // Set PWM compare value
        Cy_SysLib_Delay(FADE_DELAY_MS);                      // Delay between steps

        if (increasing)                                      // If fading up
        {
            duty += FADE_STEP;                               // Increase duty
            if (duty >= PWM_MAX_COMPARE)                     // Check upper limit
            {
                duty = PWM_MAX_COMPARE;                      // Clamp to max
                increasing = false;                          // Switch direction
            }
        }
        else                                                  // If fading down
        {
            if (duty > FADE_STEP)
                duty -= FADE_STEP;                           // Decrease duty
            else
                duty = 0;                                    // Clamp to 0

            if (duty == 0)                                   // If reached minimum
            {
                increasing = true;                           // Switch direction
            }
        }
    }
}

/* [] END OF FILE */
