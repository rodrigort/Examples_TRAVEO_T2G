/*******************************************************************************
* File Name:   main.c (CM4 Core)
*
* Project:     12_IPC_ADC
* Author:      Rodrigo Rodrigues (EWD)
* Email:       rodrigo@eaglewingd.com
* Date:        2025-06-XX
*
* Description:
*  This code runs on the CM4 core of a Traveo II (T2G) MCU. It performs
*  continuous 12-bit ADC conversion on pin P6.0 and sends each result to
*  the CM0+ core via IPC (channel 7). It also prints values via UART.
*******************************************************************************/

#include "cy_retarget_io.h"      // UART retarget for printf
#include "cybsp.h"               // Board support package

/*******************************************************************************
* Macros
*******************************************************************************/
#define USED_IPC_CHANNEL        7   // IPC channel used for CM4 to CM0+ communication
#define IPC_NOTIFY_INT_NUMBER   7   // Interrupt used to notify CM0+ core

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  - Initializes the system peripherals, ADC, and UART.
*  - Waits until the IPC server (CM0+) is ready.
*  - Continuously performs ADC readings and sends the value to CM0+.
*  - Also prints the value via UART for debugging.
*******************************************************************************/
int main(void)
{
    uint32_t adc_value = 0;         // Variable to hold the ADC result
    cy_rslt_t result;

    // Initialize device and board peripherals
    result = cybsp_init();
    if (result != CY_RSLT_SUCCESS) { CY_ASSERT(0); }

    // Enable global interrupts
    __enable_irq();

    // Ensure the IPC channel is not locked before starting
    (void)Cy_IPC_Drv_LockRelease(
        Cy_IPC_Drv_GetIpcBaseAddress(USED_IPC_CHANNEL),
        CY_IPC_NO_NOTIFICATION
    );

    // Wait until CM0+ IPC server has enabled the interrupt mask
    while ((1uL << USED_IPC_CHANNEL) !=
           Cy_IPC_Drv_ExtractAcquireMask(
               Cy_IPC_Drv_GetInterruptMask(
                   Cy_IPC_Drv_GetIntrBaseAddr(USED_IPC_CHANNEL)))) {}

    // Initialize SAR ADC peripheral with config from Device Configurator
    Cy_SAR2_Init(ADC_HW, &ADC_config);
    Cy_SAR2_SetReferenceBufferMode(PASS0_EPASS_MMIO, CY_SAR2_REF_BUF_MODE_OFF);
    Cy_SAR2_Channel_SoftwareTrigger(ADC_HW, 0); // Trigger first ADC conversion

    // Initialize UART for terminal debug output
    result = cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, 115200);
    if (result != CY_RSLT_SUCCESS) { CY_ASSERT(0); }

    // Clear terminal and show initial message (EWD standard)
    printf("\x1b[2J\x1b[;H");
    printf("========================================\r\n");
    printf("   EWD - CM4 Core | IPC + ADC Example   \r\n");
    printf("========================================\r\n");

    Cy_SysLib_Delay(2000); // Wait for 1 second

    for (;;)
    {
        // Send latest ADC value to CM0+ core via IPC
        Cy_IPC_Drv_SendMsgWord(
            Cy_IPC_Drv_GetIpcBaseAddress(USED_IPC_CHANNEL),
            (1u << IPC_NOTIFY_INT_NUMBER),
            adc_value
        );

        // Wait until CM0+ reads and releases the IPC lock
        bool status = true;
        do {
            status = Cy_IPC_Drv_IsLockAcquired(
                Cy_IPC_Drv_GetIpcBaseAddress(USED_IPC_CHANNEL));
        } while (status);

        // Read the new ADC value
        adc_value = Cy_SAR2_Channel_GetResult(ADC_HW, 0, NULL);
        Cy_SAR2_Channel_SoftwareTrigger(ADC_HW, 0); // Trigger next conversion

        // Print the value to UART console
        printf("📥 ADC Value = %u\r\n", adc_value);
    }
}

/* [] END OF FILE */
