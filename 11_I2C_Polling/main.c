/*******************************************************************************
* File Name:   main.c
*
* Description:
* Example 11 – I2C Polling with AHT25 Sensor:
* This example demonstrates how to use the I2C peripheral in polling mode
* to communicate with the AHT25 temperature and humidity sensor.
* The data is printed to the UART terminal using retarget-io.
*
* - I2C SCL : P6.2
* - I2C SDA : P6.1
* - Data Rate: 100 kbps
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
#include <stdio.h>

#define AHT25_I2C_ADDRESS  0x38  // I2C address of AHT25 sensor

cy_stc_scb_i2c_context_t i2c_context;

// Initializes the I2C peripheral with polling mode
void init_i2c(void)
{
    Cy_SCB_I2C_Init(I2C_HW, &I2C_config, &i2c_context);
    Cy_SCB_I2C_Enable(I2C_HW);
}

// Checks if AHT25 sensor responds on the I2C bus
bool check_aht25(void)
{
    cy_en_scb_i2c_status_t status = Cy_SCB_I2C_MasterSendStart(I2C_HW, AHT25_I2C_ADDRESS,
                                                               CY_SCB_I2C_WRITE_XFER, 100, &i2c_context);
    Cy_SCB_I2C_MasterSendStop(I2C_HW, 100, &i2c_context);
    return (status == CY_SCB_I2C_SUCCESS);
}

// Reads temperature and humidity data from the AHT25 sensor
void read_aht25(float *temperature, float *humidity)
{
    uint8_t cmd[3] = {0xAC, 0x33, 0x00};  // Measurement trigger command
    uint8_t data[7] = {0};                // Buffer to hold the received data

    // Send measurement command
    Cy_SCB_I2C_MasterSendStart(I2C_HW, AHT25_I2C_ADDRESS, CY_SCB_I2C_WRITE_XFER, 100, &i2c_context);
    for (int i = 0; i < 3; i++)
    {
        Cy_SCB_I2C_MasterWriteByte(I2C_HW, cmd[i], 100, &i2c_context);
    }
    Cy_SCB_I2C_MasterSendStop(I2C_HW, 100, &i2c_context);

    Cy_SysLib_DelayUs(80);  // Wait for conversion

    // Read 7 bytes from sensor
    Cy_SCB_I2C_MasterSendStart(I2C_HW, AHT25_I2C_ADDRESS, CY_SCB_I2C_READ_XFER, 100, &i2c_context);
    for (int i = 0; i < 6; i++)
    {
        Cy_SCB_I2C_MasterReadByte(I2C_HW, CY_SCB_I2C_ACK, &data[i], 100, &i2c_context);
    }
    Cy_SCB_I2C_MasterReadByte(I2C_HW, CY_SCB_I2C_NAK, &data[6], 100, &i2c_context);
    Cy_SCB_I2C_MasterSendStop(I2C_HW, 100, &i2c_context);

    // Convert humidity
    uint32_t raw_humidity = ((uint32_t)data[1] << 12) | ((uint32_t)data[2] << 4) | (data[3] >> 4);
    if (raw_humidity > 0x100000) raw_humidity = 0x100000;
    *humidity = ((float)raw_humidity / 0x100000) * 100.0f;

    // Convert temperature
    uint32_t raw_temperature = ((uint32_t)(data[3] & 0x0F) << 16) | ((uint32_t)data[4] << 8) | data[5];
    *temperature = ((float)raw_temperature / 0x100000) * 200.0f - 50.0f;
}

int main(void)
{
    cy_rslt_t result;

    result = cybsp_init(); // Initialize board support package
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    result = cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, 115200);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    printf("\x1b[2J\x1b[;H"); // ANSI ESC: clear screen and reset cursor
    printf("===========================================\r\n");
    printf("   Traveo T2G – AHT25 I2C Polling Example   \r\n");
    printf("===========================================\r\n");
    printf(" I2C Mode : Polling\r\n");
    printf(" SDA Pin  : P6.1\r\n");
    printf(" SCL Pin  : P6.2\r\n");
    printf(" Baudrate : 100 kbps\r\n");
    printf("-------------------------------------------\r\n");
    printf(" >> Reading temperature and humidity...\r\n\r\n");


    init_i2c();

    if (!check_aht25())
    {
        printf("Error: AHT25 not detected on I2C bus!\r\n");
        return 1;
    }

    float temperature = 0.0f, humidity = 0.0f;

    for (;;)
    {
        read_aht25(&temperature, &humidity);
        printf("Temperature: %.2f °C | Humidity: %.2f %%\r\n", temperature, humidity);
        Cy_SysLib_Delay(1000); // Wait 1 seconds before next reading
    }
}
