/*******************************************************************************
* File Name:   main.c
*
* Description:
* Example 10 – SPI Interrupt with MAX6675 Thermocouple Sensor:
* This example demonstrates how to read temperature data from the MAX6675
* thermocouple sensor using SPI in interrupt mode. The temperature is printed
* to the UART terminal via retarget-io.
*
* - SPI CLK : P13.2
* - SPI MISO: P13.0
* - SPI MOSI: P13.1 (not used by MAX6675, dummy only)
* - CS      : P13.6 (configured as SS3 in Device Configurator)
* - UART TX : CYBSP_DEBUG_UART_TX
* - UART RX : CYBSP_DEBUG_UART_RX
*
* Related Document: See README.md
*
********************************************************************************
* Author: Rodrigo Teixeira
*******************************************************************************/


#include "cybsp.h"
#include "cy_retarget_io.h"

#define SPI_INTR_NUM        ((IRQn_Type) scb_3_interrupt_IRQn)
#define SPI_INTR_PRIORITY   (3U)

cy_stc_scb_spi_context_t spiContext;
volatile bool spiTransferComplete = false;

// Interrupt configuration
const cy_stc_sysint_t spiIntrConfig = {
    .intrSrc = SPI_INTR_NUM,
    .intrPriority = SPI_INTR_PRIORITY,
};

// SPI interrupt handler
void SPI_Isr(void)
{
    Cy_SCB_SPI_Interrupt(SPI_HW, &spiContext);
}

// SPI transfer event callback
void SPI_EventHandler(uint32_t event)
{
    if (event & CY_SCB_SPI_TRANSFER_CMPLT_EVENT)
    {
        spiTransferComplete = true;
    }

    if (event & CY_SCB_SPI_TRANSFER_ERR_EVENT)
    {
        printf("SPI Transfer Error!\r\n");
    }
}

// Initialize SPI and CS GPIO
void max6675_init(void)
{
    Cy_SCB_SPI_Init(SPI_HW, &SPI_config, &spiContext);
    Cy_SCB_SPI_RegisterCallback(SPI_HW, SPI_EventHandler, &spiContext);

    Cy_SCB_SPI_SetActiveSlaveSelect(SPI_HW, CY_SCB_SPI_SLAVE_SELECT3);

    Cy_SysInt_Init(&spiIntrConfig, &SPI_Isr);
    NVIC_EnableIRQ(SPI_INTR_NUM);

    Cy_SCB_SPI_Enable(SPI_HW);
}

// Perform SPI transfer using interrupt
float max6675_read_temperature(void)
{
    uint8_t txBuffer[2] = {0xFF, 0xFF};  // Dummy data
    uint8_t rxBuffer[2] = {0};

    spiTransferComplete = false;

    Cy_SCB_SPI_Transfer(SPI_HW, txBuffer, rxBuffer, 2, &spiContext);

    // Wait for interrupt to signal completion
    while (!spiTransferComplete);

    uint16_t rawData = (rxBuffer[0] << 8) | rxBuffer[1];

    if (rawData & 0x04)
        return -1.0f;

    return ((rawData >> 3) & 0x0FFF) * 0.25f;
}

// Main program
int main(void)
{
    cy_rslt_t result;

    result = cybsp_init();
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    result = cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, 115200);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    printf("\x1b[2J\x1b[;H");
    printf("============================================\r\n");
    printf("   Traveo T2G – MAX6675 SPI Interrupt Demo   \r\n");
    printf("============================================\r\n");

    max6675_init();

    __enable_irq();

    for (;;)
    {
        float temperature = max6675_read_temperature();

        if (temperature < 0)
        {
            printf("Sensor Error or Disconnected!\r\n");
        }
        else
        {
            printf("Temperature: %.2f °C\r\n", temperature);
        }

        Cy_SysLib_Delay(1000);
    }
}
/*******************************************************************************
* End of File
*******************************************************************************/
