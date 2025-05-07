# 💡 Example: 01_Blinky_LED - KIT_T2G-B-E_Lite

This example demonstrates how to blink LED 3 using the Traveo II microcontroller and the Infineon KIT_T2G-B-E_Lite evaluation board.

---

## 🛠️ Description

- LED 3 on the board is connected to pin **P5_0**
- The LED is toggled every 1 second using a delay created with `Cy_SysLib_Delay()`
- The project is based on the PDL (Peripheral Driver Library)
- Pin configuration is handled via **Device Configurator**
- **The entire project was developed using Visual Studio Code** with ModusToolbox toolchain integration

---

## 📦 Requirements

- Infineon KIT_T2G-B-E_Lite
- ModusToolbox (tested with version 3.x)
- Visual Studio Code configured for C development (with optional Infineon extensions)
- USB debugger connected to the board

---

## ▶️ How to Use

1. Clone this repository or copy the example folder.
2. Open the project folder in **Visual Studio Code**.
3. Open **Device Configurator** (`design.modus`) and configure pin **P5_0** as:
   - Drive Mode: `Strong Drive, Input buffer off`
   - Initial Output State: `High`
   - Assigned Symbol: `LED1`
4. Click "Generate Application" in Device Configurator.
5. Build and flash the board using: