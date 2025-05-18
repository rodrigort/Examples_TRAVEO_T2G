# 🌡️ Example 11 – I2C Polling with AHT25 Sensor

This example demonstrates how to communicate with the **AHT25 temperature and humidity sensor** via **I2C** using **interrupt-based handling** with polling status checks.  
The project uses the **Infineon Traveo II (T2G)** microcontroller on the **KIT_T2G-B-E_Lite** board.

Measured values are displayed via UART using `printf()` every second.

---

## 🛠️ Description

- I2C master (SCB4) communicates with AHT25
- UART is used to print the temperature and humidity
- I2C operates in interrupt mode, but polling is used to check transaction completion
- Fully handled with **PDL (Peripheral Driver Library)**

---

## 🔧 Tools & Configuration

- **ModusToolbox** 3.x
- **Visual Studio Code** or ModusToolbox IDE
- **Device Configurator** for peripheral setup
- **UART terminal** at 115200 baud (e.g., TeraTerm, PuTTY)

---

## 📍 Pin Mapping

| Function         | Pin    | Description                |
|------------------|--------|----------------------------|
| I2C SDA          | P5.0   | Data line to AHT25         |
| I2C SCL          | P5.1   | Clock line to AHT25        |
| UART TX          | P14.0  | Retarget I/O (TX to PC)    |
| UART RX          | P14.1  | Retarget I/O (RX from PC)  |
| Power            | 3.3 V  | Sensor supply              |
| GND              | GND    | Common ground              |

> ✅ The I2C interface uses **SCB4**, and UART is configured using `cy_retarget_io_init`.

---

## 🧪 Sensor Information

- Sensor: **AHT25** (Temperature + Humidity)
- Communication: I2C (7-bit address: `0x38`)
- Protocol: Standard command sequence (`0xAC 0x33 0x00`)
- Delay: 80ms between command and read (optional)

---

## ▶️ How to Run

1. Open the project folder in **VS Code**
2. Configure pins using **Device Configurator**
3. Generate code (`design.modus → Generate Application`)
4. Build and flash the board:
