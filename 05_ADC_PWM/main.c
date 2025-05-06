/*******************************************************************************
* File Name:   main.c
*
* Description:
* Example 05 – ADC to PWM Mapping:
* This example demonstrates how to perform continuous analog-to-digital
* conversion using the 12-bit ADC of the TRAVEO T2G microcontroller.
*
* The ADC reads voltage from pin P6.0 and maps the result to a PWM duty cycle.
* The PWM output on P5.0 adjusts its brightness according to the analog input.
*
* - ADC Input: P6.0
* - PWM Output: P5.0 (LED fade control)
*
* Related Document: See README.md
*
********************************************************************************
* Author: Rodrigo Rodrigues
*******************************************************************************/

#include "cybsp.h"                 // Board support package: handles pin, clock and peripheral setup

/*******************************************************************************
* Global Variables
*******************************************************************************/
volatile uint16_t AdcValue = 0;     // Variable to store the latest ADC result
uint16_t duty = 0;                  // Variable to store the PWM duty cycle value

/*******************************************************************************
* Function: map
* Description: Maps a value from one numerical range to another
* Parameters:
*   x        - input value to map
*   in_min   - minimum input range
*   in_max   - maximum input range
*   out_min  - minimum output range
*   out_max  - maximum output range
* Returns:
*   mapped output value as uint32_t
*******************************************************************************/
uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*******************************************************************************
* Function Name: main
* Summary:
*   Main function that initializes peripherals, continuously reads the ADC value,
*   maps it to the PWM range, and updates the duty cycle in real-time.
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;  // Variable to store the result of initialization calls

    result = cybsp_init(); // Initialize board-level hardware and middleware
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0); // Halt program if initialization fails
    }

    Cy_SAR2_Init(ADC_HW, &ADC_config); // Initialize ADC block with configuration

    Cy_SAR2_SetReferenceBufferMode(PASS0_EPASS_MMIO, CY_SAR2_REF_BUF_MODE_OFF); // Disable ADC reference buffer if not used

    Cy_SAR2_Channel_SoftwareTrigger(ADC_HW, 0); // Start first ADC conversion on channel 0 (P6.0)

    Cy_TCPWM_PWM_Init(PWM_0_HW, PWM_0_NUM, &PWM_0_config); // Initialize PWM block
    Cy_TCPWM_PWM_Enable(PWM_0_HW, PWM_0_NUM);              // Enable PWM functionality
    Cy_TCPWM_TriggerStart_Single(PWM_0_HW, PWM_0_NUM);     // Start PWM operation

    __enable_irq(); // Enable global interrupts (not mandatory for this example)

    while (1) // Infinite application loop
    {
        AdcValue = Cy_SAR2_Channel_GetResult(ADC_HW, ADC_channel_0_IDX, NULL); // Get current ADC result from channel 0

        duty = map(AdcValue, 0, 4095, 0, 13110); // Convert 12-bit ADC value to 0-13110 range for PWM compare

        if(duty <= 5)
        {
            duty = 0; // Clamp lower boundary to avoid PWM noise
        }

        if (duty > 13100)
        {
            duty = 13111; // Clamp upper boundary to avoid overflow
        }

        Cy_TCPWM_PWM_SetCompare0(PWM_0_HW, PWM_0_NUM, duty); // Update PWM duty cycle register
    }
}

/* [] END OF FILE */
