## 📡 Example 05_V2 – ADC to PWM with UART Debug

This example expands on the original ADC-to-PWM application by printing real-time debug data (ADC and PWM values) over UART using the `retarget-io` library.  
It's ideal for debugging, monitoring analog signals, and learning how to integrate `printf()` in embedded applications.

---

### 🛠️ Description

- Reads analog voltage from **P6.0** using the 12-b ADC.
- Maps ADC value to a PWM duty cycle in the range **0–13110**.
- Drives an LED on **P5.0** with brightness proportional to the analog input.
- Sends formatted values to the serial terminal via `printf()` using `retarget-io`.

---

### 🔧 Tools & Configuration

- **ModusToolbox 3.x** with Device Configurator
- **Visual Studio Code** or ModusToolbox IDE
- **Target Board**: [KIT_T2G-B-E_Lite](https://www.infineon.com/cms/en/product/evaluation-boards/kit_t2g-b-e_lite/)
- **PWM Frequency**: 3.82 kHz (Top = 13110)
- **UART Baudrate**: 115200
- Uses `cy_retarget_io.h` for serial debug output

---

### 📍 Pin Configuration

| Symbol       | Pin   | Function     | Direction | Description                          |
|--------------|--------|--------------|-----------|--------------------------------------|
| `ADC_IN`     | P6.0  | Analog Input | Input     | Connected to analog source           |
| `LED_PWM`    | P5.0  | PWM Output   | Output    | LED brightness control               |
| `UART_TX`    | P0.1  | UART Output  | Output    | Connected to USB-to-Serial TX (PC)   |
| `UART_RX`    | P0.0  | UART Input   | Input     | Connected to USB-to-Serial RX (PC)   |

> Ensure pins are properly configured in **Device Configurator**.

---

### ▶️ How to Run

1. Open the project folder in **Visual Studio Code** or **ModusToolbox IDE**
2. Use Device Configurator to configure:
   - `ADC` on **P6.0**
   - `PWM_0` on **P5.0** (Top = 13110)
   - `UART` on **P0.1 (TX)** and **P0.0 (RX)**
3. Enable the middleware `cy_retarget_io`
4. Click **"Generate Application"**
5. Build and flash the board
6. Open a serial terminal (e.g., PuTTY, Tera Term) with:
   - Baudrate: **115200**
   - Newline: CR+LF
7. You will see:

---

#### 📂 File Structure

| File                  | Description                              |
|-----------------------|------------------------------------------|
| `main.c`              | Main logic: ADC + PWM + UART logging     |
| `.mtb`                | ModusToolbox metadata                    |
| `cycfg_peripherals.*` | Auto-generated peripheral configurations |

---

### 👤 Author

**Rodrigo Rodrigues**  
Embedded Systems Developer & Creator of T2G Examples Repository