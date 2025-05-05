/*******************************************************************************
 * File Name: cycfg_pins.h
 *
 * Description:
 * Pin configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.50.0
 * device-db 4.22.0.7873
 * mtb-pdl-cat1 3.16.0.40964
 *
 *******************************************************************************
 * Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined (CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_DEBUG_UART_RX (P0_0)
#define CYBSP_DEBUG_UART_TX (P0_1)
#define CYBSP_D2 (P0_2)
#define CYBSP_S2G_0_INT CYBSP_D2
#define CYBSP_D3 (P0_3)
#define CYBSP_S2G_0_PWM CYBSP_D3
#define CYBSP_D9 (P11_0)
#define CYBSP_S2G_0_RST CYBSP_D9
#define CYBSP_S2G_1_RST (P11_1)
#define CYBSP_MIKROBUS_RST (P11_2)
#define CYBSP_CAN_TX (P12_0)
#define CYBSP_CAN_RX (P12_1)
#define CYBSP_A1 (P12_2)
#define CYBSP_S2G_0_AN1 CYBSP_A1
#define CYBSP_A2 (P12_3)
#define CYBSP_S2G_0_AN2 CYBSP_A2
#define CYBSP_A3 (P12_4)
#define CYBSP_S2G_1_AN1 CYBSP_A3
#define CYBSP_SPI_MISO (P13_0)
#define CYBSP_D12 CYBSP_SPI_MISO
#define CYBSP_MIKROBUS_SPI_MISO CYBSP_SPI_MISO
#define CYBSP_S2G_0_SPI_MISO CYBSP_SPI_MISO
#define CYBSP_S2G_1_SPI_MISO CYBSP_SPI_MISO
#define CYBSP_SPI_MOSI (P13_1)
#define CYBSP_D11 CYBSP_SPI_MOSI
#define CYBSP_MIKROBUS_SPI_MOSI CYBSP_SPI_MOSI
#define CYBSP_S2G_0_SPI_MOSI CYBSP_SPI_MOSI
#define CYBSP_S2G_1_SPI_MOSI CYBSP_SPI_MOSI
#define CYBSP_SPI_CLK (P13_2)
#define CYBSP_D13 CYBSP_SPI_CLK
#define CYBSP_MIKROBUS_SPI_SCK CYBSP_SPI_CLK
#define CYBSP_S2G_0_SPI_SCLK CYBSP_SPI_CLK
#define CYBSP_S2G_1_SPI_SCLK CYBSP_SPI_CLK
#define CYBSP_S2G_0_SPI_CS (P13_3)
#define CYBSP_S2G_1_SPI_CS (P13_4)
#define CYBSP_MIKROBUS_SPI_CS (P13_5)
#define CYBSP_SPI_CS (P13_6)
#define CYBSP_D10 CYBSP_SPI_CS
#define CYBSP_A4 (P13_7)
#define CYBSP_S2G_1_AN2 CYBSP_A4
#define CYBSP_D0 (P14_0)
#define CYBSP_MIKROBUS_UART_RX CYBSP_D0
#define CYBSP_S2G_0_UART_RX CYBSP_D0
#define CYBSP_S2G_1_UART_RX CYBSP_D0
#define CYBSP_UART_RX CYBSP_D0
#define CYBSP_D1 (P14_1)
#define CYBSP_MIKROBUS_UART_TX CYBSP_D1
#define CYBSP_S2G_0_UART_TX CYBSP_D1
#define CYBSP_S2G_1_UART_TX CYBSP_D1
#define CYBSP_UART_TX CYBSP_D1
#define CYBSP_A5 (P14_2)
#define CYBSP_MIKROBUS_AN CYBSP_A5
#define CYBSP_D6 (P14_3)
#define CYBSP_MIKROBUS_PWM CYBSP_D6
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define BTN_2_ENABLED 1U
#define BTN_2_PORT GPIO_PRT17
#define BTN_2_PORT_NUM 17U
#define BTN_2_PIN 0U
#define BTN_2_NUM 0U
#define BTN_2_DRIVEMODE CY_GPIO_DM_PULLUP
#define BTN_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_17_pin_0_HSIOM
    #define ioss_0_port_17_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define BTN_2_HSIOM ioss_0_port_17_pin_0_HSIOM
#define BTN_2_IRQ ioss_interrupts_gpio_17_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define BTN_2_HAL_PORT_PIN P17_0
#define BTN_2 P17_0
#define BTN_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define BTN_2_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define BTN_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#define CYBSP_D7 (P17_1)
#define CYBSP_S2G_0_GPIO1 CYBSP_D7
#define CYBSP_D8 (P17_2)
#define CYBSP_MIKROBUS_INT CYBSP_D8
#define CYBSP_S2G_1_GPIO1 CYBSP_D8
#define CYBSP_TRACE_CLK (P18_3)
#define CYBSP_TRACE_DATA0 (P18_4)
#define CYBSP_TRACE_DATA1 (P18_5)
#define CYBSP_TRACE_DATA2 (P18_6)
#define CYBSP_TRACE_DATA3 (P18_7)
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_WCO_IN_ENABLED 1U
#define CYBSP_WCO_IN_PORT GPIO_PRT21
#define CYBSP_WCO_IN_PORT_NUM 21U
#define CYBSP_WCO_IN_PIN 0U
#define CYBSP_WCO_IN_NUM 0U
#define CYBSP_WCO_IN_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_WCO_IN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_21_pin_0_HSIOM
    #define ioss_0_port_21_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_WCO_IN_HSIOM ioss_0_port_21_pin_0_HSIOM
#define CYBSP_WCO_IN_IRQ ioss_interrupts_gpio_21_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_WCO_IN_HAL_PORT_PIN P21_0
#define CYBSP_WCO_IN P21_0
#define CYBSP_WCO_IN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_WCO_IN_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_WCO_IN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_WCO_OUT_ENABLED 1U
#define CYBSP_WCO_OUT_PORT GPIO_PRT21
#define CYBSP_WCO_OUT_PORT_NUM 21U
#define CYBSP_WCO_OUT_PIN 1U
#define CYBSP_WCO_OUT_NUM 1U
#define CYBSP_WCO_OUT_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_WCO_OUT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_21_pin_1_HSIOM
    #define ioss_0_port_21_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_WCO_OUT_HSIOM ioss_0_port_21_pin_1_HSIOM
#define CYBSP_WCO_OUT_IRQ ioss_interrupts_gpio_21_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_WCO_OUT_HAL_PORT_PIN P21_1
#define CYBSP_WCO_OUT P21_1
#define CYBSP_WCO_OUT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_WCO_OUT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_WCO_OUT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_ECO_IN_ENABLED 1U
#define CYBSP_ECO_IN_PORT GPIO_PRT21
#define CYBSP_ECO_IN_PORT_NUM 21U
#define CYBSP_ECO_IN_PIN 2U
#define CYBSP_ECO_IN_NUM 2U
#define CYBSP_ECO_IN_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_ECO_IN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_21_pin_2_HSIOM
    #define ioss_0_port_21_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_ECO_IN_HSIOM ioss_0_port_21_pin_2_HSIOM
#define CYBSP_ECO_IN_IRQ ioss_interrupts_gpio_21_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_ECO_IN_HAL_PORT_PIN P21_2
#define CYBSP_ECO_IN P21_2
#define CYBSP_ECO_IN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_ECO_IN_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_ECO_IN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_ECO_OUT_ENABLED 1U
#define CYBSP_ECO_OUT_PORT GPIO_PRT21
#define CYBSP_ECO_OUT_PORT_NUM 21U
#define CYBSP_ECO_OUT_PIN 3U
#define CYBSP_ECO_OUT_NUM 3U
#define CYBSP_ECO_OUT_DRIVEMODE CY_GPIO_DM_ANALOG
#define CYBSP_ECO_OUT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_21_pin_3_HSIOM
    #define ioss_0_port_21_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_ECO_OUT_HSIOM ioss_0_port_21_pin_3_HSIOM
#define CYBSP_ECO_OUT_IRQ ioss_interrupts_gpio_21_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_ECO_OUT_HAL_PORT_PIN P21_3
#define CYBSP_ECO_OUT P21_3
#define CYBSP_ECO_OUT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_ECO_OUT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define CYBSP_ECO_OUT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWO_ENABLED 1U
#define CYBSP_SWO_PORT GPIO_PRT23
#define CYBSP_SWO_PORT_NUM 23U
#define CYBSP_SWO_PIN 4U
#define CYBSP_SWO_NUM 4U
#define CYBSP_SWO_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CYBSP_SWO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_23_pin_4_HSIOM
    #define ioss_0_port_23_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWO_HSIOM ioss_0_port_23_pin_4_HSIOM
#define CYBSP_SWO_IRQ ioss_interrupts_gpio_23_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWO_HAL_PORT_PIN P23_4
#define CYBSP_SWO P23_4
#define CYBSP_SWO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWO_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define CYBSP_SWO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWDCK_ENABLED 1U
#define CYBSP_SWDCK_PORT GPIO_PRT23
#define CYBSP_SWDCK_PORT_NUM 23U
#define CYBSP_SWDCK_PIN 5U
#define CYBSP_SWDCK_NUM 5U
#define CYBSP_SWDCK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CYBSP_SWDCK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_23_pin_5_HSIOM
    #define ioss_0_port_23_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDCK_HSIOM ioss_0_port_23_pin_5_HSIOM
#define CYBSP_SWDCK_IRQ ioss_interrupts_gpio_23_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWDCK_HAL_PORT_PIN P23_5
#define CYBSP_SWDCK P23_5
#define CYBSP_SWDCK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDCK_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDCK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLDOWN
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWDIO_ENABLED 1U
#define CYBSP_SWDIO_PORT GPIO_PRT23
#define CYBSP_SWDIO_PORT_NUM 23U
#define CYBSP_SWDIO_PIN 6U
#define CYBSP_SWDIO_NUM 6U
#define CYBSP_SWDIO_DRIVEMODE CY_GPIO_DM_PULLUP
#define CYBSP_SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_23_pin_6_HSIOM
    #define ioss_0_port_23_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDIO_HSIOM ioss_0_port_23_pin_6_HSIOM
#define CYBSP_SWDIO_IRQ ioss_interrupts_gpio_23_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWDIO_HAL_PORT_PIN P23_6
#define CYBSP_SWDIO P23_6
#define CYBSP_SWDIO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDIO_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDIO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define CYBSP_SWDOE_ENABLED 1U
#define CYBSP_SWDOE_PORT GPIO_PRT23
#define CYBSP_SWDOE_PORT_NUM 23U
#define CYBSP_SWDOE_PIN 7U
#define CYBSP_SWDOE_NUM 7U
#define CYBSP_SWDOE_DRIVEMODE CY_GPIO_DM_PULLUP
#define CYBSP_SWDOE_INIT_DRIVESTATE 1
#ifndef ioss_0_port_23_pin_7_HSIOM
    #define ioss_0_port_23_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_SWDOE_HSIOM ioss_0_port_23_pin_7_HSIOM
#define CYBSP_SWDOE_IRQ ioss_interrupts_gpio_23_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define CYBSP_SWDOE_HAL_PORT_PIN P23_7
#define CYBSP_SWDOE P23_7
#define CYBSP_SWDOE_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_SWDOE_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define CYBSP_SWDOE_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#define CYBSP_D4 (P2_0)
#define CYBSP_S2G_1_INT CYBSP_D4
#define CYBSP_D5 (P2_1)
#define CYBSP_S2G_1_PWM CYBSP_D5
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define LED_1_ENABLED 1U
#define LED_1_PORT GPIO_PRT5
#define LED_1_PORT_NUM 5U
#define LED_1_PIN 0U
#define LED_1_NUM 0U
#define LED_1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LED_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_0_HSIOM
    #define ioss_0_port_5_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_1_HSIOM ioss_0_port_5_pin_0_HSIOM
#define LED_1_IRQ ioss_interrupts_gpio_5_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define LED_1_HAL_PORT_PIN P5_0
#define LED_1 P5_0
#define LED_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define LED_1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define LED_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define LED_2_ENABLED 1U
#define LED_2_PORT GPIO_PRT5
#define LED_2_PORT_NUM 5U
#define LED_2_PIN 1U
#define LED_2_NUM 1U
#define LED_2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LED_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_1_HSIOM
    #define ioss_0_port_5_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define LED_2_HSIOM ioss_0_port_5_pin_1_HSIOM
#define LED_2_IRQ ioss_interrupts_gpio_5_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define LED_2_HAL_PORT_PIN P5_1
#define LED_2 P5_1
#define LED_2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define LED_2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define LED_2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#define CYBSP_USER_LED3 (P5_2)
#define LED3 CYBSP_USER_LED3
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define BTN_1_ENABLED 1U
#define BTN_1_PORT GPIO_PRT5
#define BTN_1_PORT_NUM 5U
#define BTN_1_PIN 3U
#define BTN_1_NUM 3U
#define BTN_1_DRIVEMODE CY_GPIO_DM_PULLUP
#define BTN_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_3_HSIOM
    #define ioss_0_port_5_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define BTN_1_HSIOM ioss_0_port_5_pin_3_HSIOM
#define BTN_1_IRQ ioss_interrupts_gpio_5_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define BTN_1_HAL_PORT_PIN P5_3
#define BTN_1 P5_3
#define BTN_1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define BTN_1_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define BTN_1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#define CYBSP_POT (P6_0)
#define CYBSP_POT_AOUT CYBSP_POT
#define CYBSP_A0 CYBSP_POT
#define CYBSP_I2C_SDA (P6_1)
#define CYBSP_MIKROBUS_I2C_SDA CYBSP_I2C_SDA
#define CYBSP_S2G_0_I2C_SDA CYBSP_I2C_SDA
#define CYBSP_S2G_1_I2C_SDA CYBSP_I2C_SDA
#define CYBSP_I2C_SCL (P6_2)
#define CYBSP_MIKROBUS_I2C_SCL CYBSP_I2C_SCL
#define CYBSP_S2G_0_I2C_SCL CYBSP_I2C_SCL
#define CYBSP_S2G_1_I2C_SCL CYBSP_I2C_SCL
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t BTN_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t BTN_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_WCO_IN_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_WCO_IN_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_WCO_OUT_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_WCO_OUT_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_ECO_IN_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_ECO_IN_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_ECO_OUT_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_ECO_OUT_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWO_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWO_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDCK_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWDCK_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDIO_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWDIO_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t CYBSP_SWDOE_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t CYBSP_SWDOE_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t LED_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t LED_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t LED_2_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t LED_2_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t BTN_1_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t BTN_1_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void);
void reserve_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PINS_H */
