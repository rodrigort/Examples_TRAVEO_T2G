/*******************************************************************************
* File Name:   main.c
*
* Project:     I2C_AHT25_Reader
* Author:      Rodrigo Rodrigues (EWD)
* Email:       rodrigo@eaglewingd.com
* Date:        2025-06-XX
*
* Description:
*  This example demonstrates how to communicate with the AHT25 temperature and
*  humidity sensor using I2C in interrupt mode with the Traveo II (T2G) MCU.
*  The I2C bus is initialized with interrupt handling and configured for polling
*  using the SCB driver. The measured values are printed via UART at 1-second
*  intervals.
*
*  - I2C Interface: SCB4
*  - Sensor Address: 0x38
*  - UART Output: Retarget I/O (115200 baud)
*
* Related Document:
*  - AHT25 Datasheet
*  - PDL Documentation (SCB I2C Master, SysLib, Retarget IO)
*
*******************************************************************************/

#include "cycfg_peripherals.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "stdio.h"

/*******************************************************************************
* Defines and Constants
*******************************************************************************/
#define AHT25_ADDR         0x38       // I2C 7-bit address
#define I2C_TIMEOUT        100        // Timeout for I2C transactions [ms]
#define CMD_TO_CMD_DELAY   80         // Sensor processing delay [ms]

#define I2C_INTR_NUM       scb_4_interrupt_IRQn
#define I2C_INTR_PRIORITY  (7UL)

/*******************************************************************************
* Global Variables
*******************************************************************************/
float temperature = 0, humidity = 0;
cy_stc_scb_i2c_context_t i2c_context;  // I2C context used by SCB driver

/*******************************************************************************
* Interrupt Configuration
*******************************************************************************/
const cy_stc_sysint_t i2cIntrConfig =
{
    .intrSrc      = I2C_INTR_NUM,
    .intrPriority = I2C_INTR_PRIORITY
};

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
void I2C_Isr(void);
void init_i2c(void);
bool check_aht25(void);
void read_aht25(float *temperature, float *humidity);

/*******************************************************************************
* Interrupt Service Routine - I2C Master
*******************************************************************************/
void I2C_Isr(void)
{
    Cy_SCB_I2C_MasterInterrupt(I2C_HW, &i2c_context);
}

/*******************************************************************************
* Function Name: init_i2c
********************************************************************************
* Summary:
*  Initializes the SCB I2C block in master mode with interrupt handling.
*******************************************************************************/
void init_i2c(void)
{
    Cy_SCB_I2C_Init(I2C_HW, &I2C_config, &i2c_context);
    Cy_SysInt_Init(&i2cIntrConfig, I2C_Isr);
    NVIC_EnableIRQ((IRQn_Type)I2C_INTR_NUM);
    Cy_SCB_I2C_Enable(I2C_HW);
    __enable_irq();
}

/*******************************************************************************
* Function Name: check_aht25
********************************************************************************
* Summary:
*  Sends a start condition to verify AHT25 sensor presence.
*
* Return:
*  true  - Sensor ACKed the address
*  false - No ACK
*******************************************************************************/
bool check_aht25(void)
{
    cy_en_scb_i2c_status_t status;

    status = Cy_SCB_I2C_MasterSendStart(I2C_HW, AHT25_ADDR, CY_SCB_I2C_WRITE_XFER, I2C_TIMEOUT, &i2c_context);
    Cy_SCB_I2C_MasterSendStop(I2C_HW, I2C_TIMEOUT, &i2c_context);

    return (status == CY_SCB_I2C_SUCCESS);
}

/*******************************************************************************
* Function Name: read_aht25
********************************************************************************
* Summary:
*  Sends a measurement command to AHT25, reads 6 bytes of data,
*  and calculates temperature and humidity values.
*******************************************************************************/
void read_aht25(float *temperature, float *humidity)
{
    uint8_t cmd[3]  = { 0xAC, 0x33, 0x00 };
    uint8_t data[7] = { 0 };

    cy_stc_scb_i2c_master_xfer_config_t writeXferConfig = {
        .slaveAddress = AHT25_ADDR,
        .buffer       = cmd,
        .bufferSize   = sizeof(cmd),
        .xferPending  = true // No stop condition yet
    };

    cy_stc_scb_i2c_master_xfer_config_t readXferConfig = {
        .slaveAddress = AHT25_ADDR,
        .buffer       = data,
        .bufferSize   = sizeof(data),
        .xferPending  = false // Generate stop after read
    };

    // Start write transaction
    Cy_SCB_I2C_MasterWrite(I2C_HW, &writeXferConfig, &i2c_context);
    while (Cy_SCB_I2C_MasterGetStatus(I2C_HW, &i2c_context) & CY_SCB_I2C_MASTER_BUSY) {}

    // Delay for sensor processing (if needed)
    // Cy_SysLib_Delay(CMD_TO_CMD_DELAY);

    // Start read transaction
    Cy_SCB_I2C_MasterRead(I2C_HW, &readXferConfig, &i2c_context);
    while (Cy_SCB_I2C_MasterGetStatus(I2C_HW, &i2c_context) & CY_SCB_I2C_MASTER_BUSY) {}

    // Convert raw data to humidity
    uint32_t raw_humidity = (data[1] << 12) | (data[2] << 4) | (data[3] >> 4);
    *humidity = ((float)raw_humidity / 1048576.0f) * 100.0f;

    // Convert raw data to temperature
    uint32_t raw_temperature = ((data[3] & 0x0F) << 16) | (data[4] << 8) | data[5];
    *temperature = ((float)raw_temperature / 1048576.0f) * 200.0f - 50.0f;
}

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  Application entry point. Initializes the board, UART, I2C, and communicates
*  with the AHT25 sensor, printing temperature and humidity every second.
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    // Initialize board peripherals
    result = cybsp_init();
    if (result != CY_RSLT_SUCCESS) { CY_ASSERT(0); }

    // Initialize UART for printf debugging
    result = cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, 115200);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    // Terminal greeting (EWD standard)
    printf("\x1b[2J\x1b[;H"); // Clear terminal and move cursor to top
    printf("==============================================\r\n");
    printf("         EWD - AHT25 I2C Sensor Reader         \r\n");
    printf("           Traveo II | KIT_T2G-B-E_Lite        \r\n");
    printf("==============================================\r\n\n");
    printf("🔄 Initializing AHT25 sensor via I2C...\r\n\n");
    // Initialize I2C and check sensor

    init_i2c();

    if (!check_aht25())
    {
        printf("AHT25 not detected. Check wiring or address.\r\n");
        return 1;
    }

    // Main loop: read and print every second
    for (;;)
    {
        read_aht25(&temperature, &humidity);
        printf("Temperature: %.2f °C | Humidity: %.2f %%\r\n", temperature, humidity);
        Cy_SysLib_Delay(1000);
    }
}

/* [] END OF FILE */
