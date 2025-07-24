/*******************************************************************************
* File Name:   Lib_LCD.h
*
* Project:     14_Dual_Core_LCD_16_2
* Author:      Rodrigo Rodrigues (EWD)
* Email:       rodrigo@eaglewingd.com
* Date:        2025-07-XX
*
* Description:
*  Header file for 16x2 LCD interface. Provides macros for pin configuration and
*  function declarations for LCD control in 4-bit mode.
*
*******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>  // Standard types

// LCD Pin Configuration (adjust as needed)
#define RS_PORT P17_2_PORT
#define RS_PIN  P17_2_NUM
#define EN_PORT P11_0_PORT
#define EN_PIN  P11_0_NUM
#define D4_PORT P2_0_PORT
#define D4_PIN  P2_0_NUM
#define D5_PORT P2_1_PORT
#define D5_PIN  P2_1_NUM
#define D6_PORT P14_3_PORT
#define D6_PIN  P14_3_NUM
#define D7_PORT P17_1_PORT
#define D7_PIN  P17_1_NUM

// Macros for digital output control
#define LCD_SET_HIGH(port, pin) Cy_GPIO_Write(port, pin, 1)
#define LCD_SET_LOW(port, pin)  Cy_GPIO_Write(port, pin, 0)

// LCD Function Prototypes
void LCD_init(void);
void LCD_Strobe(void);
void LCD_write(uint8_t c);
void LCD_clear(void);
void LCD_OUT(uint8_t line, uint8_t pos, const char *s);
void LCD_putch(uint8_t line, uint8_t pos, uint8_t c);
void LCD_scrollDisplayLeft(void);
void LCD_scrollDisplayRight(void);
void LCD_createChar(uint8_t location, const uint8_t charmap[8]);

#endif /* LCD_H_ */
