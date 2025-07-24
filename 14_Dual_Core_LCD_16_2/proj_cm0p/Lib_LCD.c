/*******************************************************************************
* File Name:   Lib_LCD.c
*
* Project:     14_Dual_Core_LCD_16_2
* Author:      Rodrigo Rodrigues (EWD)
* Email:       rodrigo@eaglewingd.com
* Date:        2025-07-XX
*
* Description:
*  LCD interface implementation for 16x2 character display using 4-bit mode.
*  Includes initialization, character/command sending, positioning,
*  string printing, scrolling, and custom character creation.
*
*******************************************************************************/

#include "cybsp.h"
#include "Lib_LCD.h"

/*******************************************************************************
* Function Name: LCD_Strobe
********************************************************************************
* Summary:
*  Generates an enable pulse to latch data into the LCD.
*******************************************************************************/
void LCD_Strobe(void)
{
    LCD_SET_HIGH(EN_PORT, EN_PIN);
    Cy_SysLib_DelayUs(800);
    LCD_SET_LOW(EN_PORT, EN_PIN);
    Cy_SysLib_DelayUs(800);
}

/*******************************************************************************
* Function Name: LCD_write
********************************************************************************
* Summary:
*  Sends one byte to the LCD in two 4-bit transactions.
*******************************************************************************/
void LCD_write(uint8_t c)
{
    __disable_irq();

    // Send upper nibble
    (c & 0x80) ? LCD_SET_HIGH(D7_PORT, D7_PIN) : LCD_SET_LOW(D7_PORT, D7_PIN);
    (c & 0x40) ? LCD_SET_HIGH(D6_PORT, D6_PIN) : LCD_SET_LOW(D6_PORT, D6_PIN);
    (c & 0x20) ? LCD_SET_HIGH(D5_PORT, D5_PIN) : LCD_SET_LOW(D5_PORT, D5_PIN);
    (c & 0x10) ? LCD_SET_HIGH(D4_PORT, D4_PIN) : LCD_SET_LOW(D4_PORT, D4_PIN);

    __enable_irq();
    LCD_Strobe();

    __disable_irq();

    // Send lower nibble
    (c & 0x08) ? LCD_SET_HIGH(D7_PORT, D7_PIN) : LCD_SET_LOW(D7_PORT, D7_PIN);
    (c & 0x04) ? LCD_SET_HIGH(D6_PORT, D6_PIN) : LCD_SET_LOW(D6_PORT, D6_PIN);
    (c & 0x02) ? LCD_SET_HIGH(D5_PORT, D5_PIN) : LCD_SET_LOW(D5_PORT, D5_PIN);
    (c & 0x01) ? LCD_SET_HIGH(D4_PORT, D4_PIN) : LCD_SET_LOW(D4_PORT, D4_PIN);

    __enable_irq();
    LCD_Strobe();

    Cy_SysLib_Delay(1);
    Cy_SysLib_DelayUs(150);
}

/*******************************************************************************
* Function Name: LCD_init
********************************************************************************
* Summary:
*  Initializes the LCD in 4-bit mode, 2-line, 5x8 font.
*******************************************************************************/
void LCD_init(void)
{
    Cy_SysLib_Delay(1);
    LCD_SET_LOW(RS_PORT, RS_PIN);

    // Initialization sequence for 4-bit mode
    LCD_SET_HIGH(D4_PORT, D4_PIN);
    LCD_SET_HIGH(D5_PORT, D5_PIN);
    LCD_SET_LOW(D6_PORT, D6_PIN);
    LCD_SET_LOW(D7_PORT, D7_PIN);

    LCD_Strobe(); Cy_SysLib_Delay(1);
    LCD_Strobe(); Cy_SysLib_Delay(1);
    LCD_Strobe(); Cy_SysLib_Delay(1);
    LCD_SET_LOW(D4_PORT, D4_PIN); Cy_SysLib_Delay(1);
    LCD_Strobe();

    // LCD configuration commands
    LCD_write(0x28); // 4-bit, 2-line, 5x8 dots
    LCD_write(0x0C); // Display ON, cursor OFF
    LCD_write(0x06); // Auto-increment cursor
    LCD_write(0x01); // Clear display
}

/*******************************************************************************
* Function Name: LCD_clear
********************************************************************************
* Summary:
*  Clears the LCD display.
*******************************************************************************/
void LCD_clear(void)
{
    LCD_SET_LOW(RS_PORT, RS_PIN);
    LCD_write(0x01);
    Cy_SysLib_Delay(2);
}

/*******************************************************************************
* Function Name: LCD_OUT
********************************************************************************
* Summary:
*  Displays a string on specified line and column.
*******************************************************************************/
void LCD_OUT(uint8_t line, uint8_t pos, const char *s)
{
    pos -= 1;
    line -= 1;

    LCD_SET_LOW(RS_PORT, RS_PIN);
    LCD_write((line == 0) ? (0x80 + pos) : (0x80 + pos + 0x40));

    LCD_SET_HIGH(RS_PORT, RS_PIN);
    while (*s)
        LCD_write(*s++);
}

/*******************************************************************************
* Function Name: LCD_putch
********************************************************************************
* Summary:
*  Displays a single character at the specified location.
*******************************************************************************/
void LCD_putch(uint8_t line, uint8_t pos, uint8_t c)
{
    pos -= 1;
    line -= 1;

    LCD_SET_LOW(RS_PORT, RS_PIN);
    LCD_write((line == 0) ? (0x80 + pos) : (0x80 + pos + 0x40));

    LCD_SET_HIGH(RS_PORT, RS_PIN);
    LCD_write(c);
}

/*******************************************************************************
* Function Name: LCD_scrollDisplayLeft
********************************************************************************
* Summary:
*  Scrolls the entire display one character to the left.
*******************************************************************************/
void LCD_scrollDisplayLeft(void)
{
    LCD_SET_LOW(RS_PORT, RS_PIN);
    LCD_write(0x18);
}

/*******************************************************************************
* Function Name: LCD_scrollDisplayRight
********************************************************************************
* Summary:
*  Scrolls the entire display one character to the right.
*******************************************************************************/
void LCD_scrollDisplayRight(void)
{
    LCD_SET_LOW(RS_PORT, RS_PIN);
    LCD_write(0x1C);
}

/*******************************************************************************
* Function Name: LCD_createChar
********************************************************************************
* Summary:
*  Defines a custom character in CGRAM at specified location (0–7).
*******************************************************************************/
void LCD_createChar(uint8_t location, const uint8_t charmap[8])
{
    location &= 0x7;
    LCD_SET_LOW(RS_PORT, RS_PIN);
    LCD_write(0x40 | (location << 3));

    LCD_SET_HIGH(RS_PORT, RS_PIN);
    for (int i = 0; i < 8; i++)
        LCD_write(charmap[i]);

    LCD_SET_LOW(RS_PORT, RS_PIN);
    LCD_write(0x00);
    LCD_write(0x02);
}

/* [] END OF FILE */
