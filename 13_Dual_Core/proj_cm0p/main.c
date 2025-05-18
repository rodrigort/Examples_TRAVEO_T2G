/*******************************************************************************
* File Name:   main.c (CM0+ Core)
*
* Project:     12_IPC_ADC
* Author:      Rodrigo Rodrigues (EWD)
* Email:       rodrigo@eaglewingd.com
* Date:        2025-06-XX
*
* Description:
*  This code runs on the CM0+ core of a Traveo II (T2G) MCU. It receives
*  a 12-bit ADC value via IPC channel 7 from the CM4 core, and activates
*  one of the 3 LEDs (P5.0, P5.1, P5.2) based on the ADC range.
*
*  ADC Value Range (0–4095) → LED Mapping:
*   - 0000–0099  : All OFF
*   - 0100–1363  : LED 1 ON (P5.0)
*   - 1364–2726  : LED 2 ON (P5.1)
*   - 2727–3899  : LED 3 ON (P5.2)
*   - 3900–4095  : All OFF
*
*******************************************************************************/

#include "cybsp.h" // Board support package for initialization

/*******************************************************************************
* Macros
*******************************************************************************/
#define USED_IPC_CHANNEL         7  // IPC channel used for communication
#define IPC_NOTIFY_INT_NUMBER    7  // Interrupt number used to notify CM0+
#define IPC_RELEASE_INT_NUMBER   6  // Interrupt number used to notify CM4

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
void IpcNotifyInt_ISR(void); // IPC interrupt service routine

/*******************************************************************************
* Interrupt Configuration Structure
*******************************************************************************/
static cy_stc_sysint_t stcSysIntIpcNotifyInt =
{
    .intrSrc      = (IRQn_Type) NvicMux3_IRQn, // NVIC multiplexer interrupt source
    .cm0pSrc      = (cy_en_intr_t)(cpuss_interrupts_ipc_0_IRQn + USED_IPC_CHANNEL), // CM0+ source
    .intrPriority = 2UL // Interrupt priority
};

extern const char __cm4_app_address[]; // Address of the CM4 application

/*******************************************************************************
* Function Name: main
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    // Initialize board and peripherals
    result = cybsp_init();
    if (result != CY_RSLT_SUCCESS) { CY_ASSERT(0); }

    // Enable global interrupts
    __enable_irq();

    // Start CM4 core application
    Cy_SysEnableCM4((uint32_t)__cm4_app_address);

    // Setup IPC interrupt from CM4
    Cy_SysInt_Init(&stcSysIntIpcNotifyInt, IpcNotifyInt_ISR);
    NVIC_EnableIRQ(NvicMux3_IRQn);

    // Enable interrupt masking for IPC channel
    Cy_IPC_Drv_SetInterruptMask(
        Cy_IPC_Drv_GetIntrBaseAddr(IPC_NOTIFY_INT_NUMBER),
        CY_IPC_NO_NOTIFICATION,
        (1uL << USED_IPC_CHANNEL)
    );

    // Loop does nothing, all work in ISR
    for (;;)
    {
        __WFI(); // Wait for interrupt to save power
    }
}

/*******************************************************************************
* Function Name: IpcNotifyInt_ISR
* Summary:
*  IPC interrupt handler. Receives ADC value from CM4 and controls LEDs.
*******************************************************************************/
void IpcNotifyInt_ISR(void)
{
    uint32_t adc_value = 0; // Variable to hold received ADC value

    // Get masked pending interrupts
    uint32_t intr = Cy_IPC_Drv_GetInterruptStatusMasked(
        Cy_IPC_Drv_GetIntrBaseAddr(IPC_NOTIFY_INT_NUMBER));
    uint32_t interruptMasked = Cy_IPC_Drv_ExtractAcquireMask(intr);

    // If interrupt is from expected IPC channel
    if (interruptMasked == (1uL << USED_IPC_CHANNEL))
    {
        // Clear interrupt
        Cy_IPC_Drv_ClearInterrupt(
            Cy_IPC_Drv_GetIntrBaseAddr(IPC_NOTIFY_INT_NUMBER),
            CY_IPC_NO_NOTIFICATION,
            interruptMasked
        );

        // Read ADC value sent by CM4 core
        if (CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_ReadMsgWord(
            Cy_IPC_Drv_GetIpcBaseAddress(USED_IPC_CHANNEL),
            &adc_value))
        {
            // Control LEDs based on ADC range
            if (adc_value <= 99)
            {
                Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 1);
                Cy_GPIO_Write(LED_2_PORT, LED_2_PIN, 1);
                Cy_GPIO_Write(LED_3_PORT, LED_3_PIN, 1);
            }
            else if (adc_value <= 1363)
            {
                Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 0);
                Cy_GPIO_Write(LED_2_PORT, LED_2_PIN, 1);
                Cy_GPIO_Write(LED_3_PORT, LED_3_PIN, 1);
            }
            else if (adc_value <= 2726)
            {
                Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 1);
                Cy_GPIO_Write(LED_2_PORT, LED_2_PIN, 0);
                Cy_GPIO_Write(LED_3_PORT, LED_3_PIN, 1);
            }
            else if (adc_value <= 3899)
            {
                Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 1);
                Cy_GPIO_Write(LED_2_PORT, LED_2_PIN, 1);
                Cy_GPIO_Write(LED_3_PORT, LED_3_PIN, 0);
            }
            else // 3900–4095
            {
                Cy_GPIO_Write(LED_1_PORT, LED_1_PIN, 1);
                Cy_GPIO_Write(LED_2_PORT, LED_2_PIN, 1);
                Cy_GPIO_Write(LED_3_PORT, LED_3_PIN, 1);
            }
        }

        // Release IPC channel so CM4 can send next value
        Cy_IPC_Drv_ReleaseNotify(
            Cy_IPC_Drv_GetIpcBaseAddress(USED_IPC_CHANNEL),
            (1u << IPC_RELEASE_INT_NUMBER)
        );
    }
}

/* [] END OF FILE */
