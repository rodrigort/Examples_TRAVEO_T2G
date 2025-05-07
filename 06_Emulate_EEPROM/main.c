/*******************************************************************************
* File Name:   main.c
*
* Description:
* Example 06 – Emulate EEPROM with UART and Button Control
* - Increments a counter from 0 to 65535
* - BTN2 (P5.3): Saves the current value to emulated EEPROM
* - BTN1 (P17.0): Reads and prints the stored value from EEPROM
* - LED feedback optional (defined in Device Configurator)
*
* Author: Rodrigo Rodrigues
*******************************************************************************/

#include "cybsp.h"
#include "cy_retarget_io.h"
#include "cy_em_eeprom.h"
#include <stdint.h>

/*******************************************************************************
* Macros
*******************************************************************************/
#define LOGICAL_EEPROM_SIZE     (2u)    // 2 bytes for 16-bit counter
#define LOGICAL_EEPROM_START    (0u)    // EEPROM logical address offset

/*******************************************************************************
* EEPROM Configuration
*******************************************************************************/
cy_stc_eeprom_config_t Em_EEPROM_config = {
    .eepromSize          = MY_EEPROM_SIZE,
    .simpleMode          = MY_EEPROM_SIMPLEMODE,
    .blockingWrite       = MY_EEPROM_BLOCKINGMODE,
    .redundantCopy       = MY_EEPROM_REDUNDANT_COPY,
    .wearLevelingFactor  = MY_EEPROM_WEARLEVELING_FACTOR,
    .userFlashStartAddr  = CY_WFLASH_LG_SBM_BASE,
};

cy_stc_eeprom_context_t Em_EEPROM_context;
uint8_t eepromReadArray[LOGICAL_EEPROM_SIZE] = {0};
uint8_t eepromWriteArray[LOGICAL_EEPROM_SIZE] = {0};

/*******************************************************************************
* Global Variables
*******************************************************************************/
uint16_t counter = 0;       // Main counter
uint16_t stored_value = 0;  // EEPROM readback

/*******************************************************************************
* Function Name: main
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    // Initialize board and peripherals
    result = cybsp_init();
    if (result != CY_RSLT_SUCCESS) CY_ASSERT(0);

    // Initialize UART for printf output
    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);

    // Clear terminal and show banner
    printf("\x1b[2J\x1b[;H");
    printf("********** Example 06 – Emulated EEPROM **********\r\n\n");

    // Initialize EEPROM
    Cy_Em_EEPROM_Init(&Em_EEPROM_config, &Em_EEPROM_context);

    // Read previous value from EEPROM
    result = Cy_Em_EEPROM_Read(LOGICAL_EEPROM_START, eepromReadArray, LOGICAL_EEPROM_SIZE, &Em_EEPROM_context);
    stored_value = (eepromReadArray[1] << 8) | eepromReadArray[0];
    printf("[EEPROM] Stored value: %u\r\n", stored_value);
    Cy_SysLib_Delay(3000);

    __enable_irq();

    while (1)
    {
        // BTN1 (P17.0): Read value from EEPROM
        if (Cy_GPIO_Read(BT_1_PORT, BT_1_PIN) == 0)
        {
            result = Cy_Em_EEPROM_Read(LOGICAL_EEPROM_START, eepromReadArray, LOGICAL_EEPROM_SIZE, &Em_EEPROM_context);
            stored_value = (eepromReadArray[1] << 8) | eepromReadArray[0];

            printf("\x1b[2J\x1b[;H");
            printf("[BTN1] Read from EEPROM: %u\r\n", stored_value);
            Cy_SysLib_Delay(1500);
        }

        // BTN2 (P5.3): Save current counter to EEPROM
        if (Cy_GPIO_Read(BT_2_PORT, BT_2_PIN) == 0)
        {
            printf("\x1b[2J\x1b[;H");
            printf("[BTN2] Saving counter value: %u\r\n", counter);

            eepromWriteArray[0] = (counter & 0xFF);         // LSB
            eepromWriteArray[1] = (counter >> 8) & 0xFF;     // MSB

            result = Cy_Em_EEPROM_Write(LOGICAL_EEPROM_START, eepromWriteArray, LOGICAL_EEPROM_SIZE, &Em_EEPROM_context);
            if (result != CY_EM_EEPROM_SUCCESS)
            {
                printf("[ERROR] EEPROM Write Failed. Code: 0x%08lX\r\n", (unsigned long)result);
                CY_ASSERT(0);
            }

            Cy_SysLib_Delay(200);
        }

        // BTN1 + BTN2: Clear EEPROM value
        if (Cy_GPIO_Read(BT_1_PORT, BT_1_PIN) == 0 && Cy_GPIO_Read(BT_2_PORT, BT_2_PIN) == 0)
        {
            printf("\x1b[2J\x1b[;H");
            printf("[BTN1 + BTN2] Erasing EEPROM value...\r\n");

            eepromWriteArray[0] = 0;
            eepromWriteArray[1] = 0;

            result = Cy_Em_EEPROM_Write(LOGICAL_EEPROM_START, eepromWriteArray, LOGICAL_EEPROM_SIZE, &Em_EEPROM_context);
            if (result == CY_EM_EEPROM_SUCCESS)
                printf("[EEPROM] Value erased.\r\n");
            else
                printf("[ERROR] Erase Failed. Code: 0x%08lX\r\n", (unsigned long)result);

            Cy_SysLib_Delay(1000);
        }

        // Increment counter with wrap-around at 65535
        counter++;
        if (counter > 0xFFFF) counter = 0;
    }
}
/* [] END OF FILE */
