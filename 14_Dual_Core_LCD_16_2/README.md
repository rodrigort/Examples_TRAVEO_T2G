# Project: 14_Dual_Core_LCD_16_2

## Author
**Rodrigo Rodrigues (EWD)**  
📧 rodrigo@eaglewingd.com

---

## 🧠 Description

This example demonstrates a basic dual-core application running on the **Infineon Traveo II (T2G)** microcontroller using a **16x2 LCD Keypad Shield** (Arduino-compatible) controlled by the **CM0+** core.

- The **CM0+** core handles all system logic, including LCD control and LED blinking.
- The **CM4** core is enabled but not used in this example.

---

## ✅ Functionality

- Displays a welcome message `"TRAVEO AMR-M0"` on the LCD's first line.
- Starts an incrementing counter from `0` to `100` on the second LCD line.
- Once the counter reaches `100`, it resets to `0`.
- A user LED connected to **P5.0** blinks every 500ms.

---

## 🧰 Tools Used

- ✅ ModusToolbox 3.x  
- ✅ Visual Studio Code  
- ✅ Device Configurator  
- ✅ Peripheral Driver Library (PDL)  
- ✅ KIT_T2G-B-E_Lite or KIT_T2G-B-H_Lite

---

## 🔌 LCD Keypad Shield Pin Mapping

This project is compatible with a standard Arduino **LCD Keypad Shield**. The LCD uses **4-bit parallel mode** and is connected via the Arduino-style headers.

| LCD Signal | Arduino Pin | Traveo T2G Pin |
|------------|--------------|----------------|
| RS         | D8           | `P17.2`        |
| EN         | D9           | `P11.0`        |
| D4         | D4           | `P2.0`         |
| D5         | D5           | `P2.1`         |
| D6         | D6           | `P14.3`        |
| D7         | D7           | `P17.1`        |
| RW         | GND          | GND            |
| VSS/VDD    | GND / +5V    | GND / VDD      |
| VO         | Potentiometer | LCD Contrast |
| Backlight A/K | —         | +5V / GND      |

> 🛑 Note: The onboard buttons are **not used** in this project.

---

## 🧩 GPIO Mapping

| Signal       | Core  | Function             | Pin     |
|--------------|-------|----------------------|----------|
| LED          | CM0+  | Blinking LED         | `P5.0`   |
| LCD RS       | CM0+  | LCD Register Select  | `P17.2`  |
| LCD EN       | CM0+  | LCD Enable           | `P11.0`  |
| LCD D4       | CM0+  | LCD Data Bit 4       | `P2.0`   |
| LCD D5       | CM0+  | LCD Data Bit 5       | `P2.1`   |
| LCD D6       | CM0+  | LCD Data Bit 6       | `P14.3`  |
| LCD D7       | CM0+  | LCD Data Bit 7       | `P17.1`  |

---

## 📁 Project Structure

- `main.c` → CM0+ core logic (LCD, LED, counter)
- `main_cm4.c` → Empty stub (CM4 is only enabled)
- `Lib_LCD.c / Lib_LCD.h` → Custom driver for 16x2 LCD in 4-bit mode
- `README.md` → Project documentation

---

## ⚙️ How to Build

- Build and flash the project via **ModusToolbox**.
- Ensure that CM0+ is the primary application.
- CM4 is enabled with `Cy_SysEnableCM4()` but does not run any logic.

---

## 🔎 Notes

- The counter resets at `100` to keep the LCD clean.
- LED blink and LCD update timing results in ~1 second per cycle.
- Designed for compatibility with standard **Arduino LCD Keypad Shields**.

---

## License

Distributed under the standard Cypress/Infineon license.
