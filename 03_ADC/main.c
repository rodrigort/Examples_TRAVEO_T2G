/*******************************************************************************
* File Name:   main.c
*
* Description:
* Example 03 – ADC:
* This example demonstrates how to perform continuous analog-to-digital
* conversion using the 12-bit ADC of the Traveo II microcontroller.
*
* The ADC reads voltage from pin P6.0. If the value is greater than 2048
* (midpoint of 12-bit range), LED 1 (P5.0) is turned ON. Otherwise, it remains OFF.
*
* - ADC Input: P6.0
* - LED Output: P5.0 (active-low)
*
* This example uses polling and software comparison to control the LED.
*
* Related Document: See README.md
*
********************************************************************************
* Copyright 2021-2024, Cypress Semiconductor Corporation (an Infineon company)
* or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
*
* This software is protected by international law and licensed for use only
* with Infineon microcontroller products, under the terms of the accompanying EULA.
*******************************************************************************/

/*******************************************************************************
* Header Files
*******************************************************************************/
#include "cybsp.h" // Board support package (includes GPIO and peripheral init)

/*******************************************************************************
* Global Variables
*******************************************************************************/
volatile uint16_t AdcValue = 0; // Stores the latest ADC result

/*******************************************************************************
* Function Definitions
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    // Initialize board peripherals and pins (based on design.modus configuration)
    result = cybsp_init();

    // Halt if board initialization failed
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    // Initialize the SAR2 ADC hardware with generated config
    Cy_SAR2_Init(ADC_HW, &ADC_config);

    // Disable internal reference buffer (optional based on your setup)
    Cy_SAR2_SetReferenceBufferMode(PASS0_EPASS_MMIO, CY_SAR2_REF_BUF_MODE_OFF);

    // Trigger the first ADC conversion on channel 0 (P6.0)
    Cy_SAR2_Channel_SoftwareTrigger(ADC_HW, 0);

    // Enable global interrupts (if needed for other parts of the system)
    __enable_irq();

    // Main application loop
    for (;;)
    {
        // Read the ADC result from channel 0 (P6.0)
        AdcValue = Cy_SAR2_Channel_GetResult(ADC_HW, 0, NULL);

        // Compare ADC value to midpoint (2048 = 50% of 12-bit range)
        if (AdcValue >= 2048)
        {
            // If above threshold, turn ON LED 1 (active-low: write 0)
            Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 0);
        }
        else
        {
            // If below threshold, turn OFF LED 1 (write 1)
            Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 1);
        }
    }
}

/* [] END OF FILE */
