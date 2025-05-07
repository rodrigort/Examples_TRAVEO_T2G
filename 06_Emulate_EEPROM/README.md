# 💾 Example 06 – Emulate EEPROM with UART and Button Control

This example demonstrates how to use **Emulated EEPROM** in the **TRAVEO T2G** microcontroller to store and retrieve data using push buttons.  
It includes UART debug output via `retarget-io` and basic counter logic with write, read, and erase operations.

---

## 🛠️ Description

- A counter runs from 0 to 65535 continuously.
- **BTN2 (P17.0)** saves the current counter value to the emulated EEPROM.
- **BTN1 (P5.3)** reads and prints the value stored in the EEPROM.
- **BTN1 + BTN2 pressed together** will erase the stored value (set to 0).
- All actions are printed to a serial terminal using `printf()` and `retarget-io`.

---

### 🔧 Tools & Configuration

- **ModusToolbox 3.x** with Device Configurator
- **Visual Studio Code** or ModusToolbox IDE
- **Target Board**: [KIT_T2G-B-E_Lite](https://www.infineon.com/cms/en/product/evaluation-boards/kit_t2g-b-e_lite/)
- UART Baudrate: **115200**
- EEPROM Logical Size: 2 bytes (16 bits)
- EEPROM Storage: Flash emulation using `cy_em_eeprom.h`

---

### 📍 Pin Configuration

| Symbol    | Pin    | Function     | Direction | Description                                |
|-----------|--------|--------------|-----------|--------------------------------------------|
| `BTN1`    | P5.3   | Digital In   | Input     | Read stored EEPROM value                   |
| `BTN2`    | P17.0  | Digital In   | Input     | Save current counter value to EEPROM       |
| `LED_1`   | P5.0   | Digital Out  | Output    | Optional LED for status feedback           |
| `LED_2`   | P5.1   | Digital Out  | Output    | Optional LED for status feedback           |
| `LED_3`   | P5.2   | Digital Out  | Output    | Optional LED for status feedback           |
| `UART_TX` | P0.1   | UART Output  | Output    | UART TX for printf() via retarget-io       |
| `UART_RX` | P0.0   | UART Input   | Input     | UART RX (not used in this example)         |

---

### ▶️ How to Run

1. Open the project in **VS Code** or **ModusToolbox IDE**
2. In **Device Configurator**, configure:
   - `BTN1` as Digital Input on **P5.3**
   - `BTN2` as Digital Input on **P17.0**
   - UART TX on **P0.1** and RX on **P0.0**
   - (Optional) Configure P5.0–P5.2 as Digital Output for LED feedback
3. Enable middleware `cy_retarget_io` for UART debug
4. Click **"Generate Application"**
5. Build and flash the board
6. Open a serial terminal (e.g., Tera Term, PuTTY):
   - Baudrate: **115200**
   - Newline: CR+LF
7. Observe messages such as:
