# 📟 09\_SPI\_MAX6675 – SPI Thermocouple Temperature Sensor

This example demonstrates how to use the SPI peripheral of the Infineon **Traveo T2G** microcontroller to interface with a **MAX6675 thermocouple temperature sensor**. The measured temperature is displayed via UART using the `retarget-io` library.

---

## 🔧 Configuration

* **Sensor**: MAX6675 K-Type Thermocouple Interface
* **SPI Settings**:

  * Clock Speed: 100 kbps
  * SPI Mode: 0
  * Data Frame: 16 bits (read only)
* **Pinout**:

  * **SPI MISO**: P13.0
  * **SPI MOSI**: P13.1 (not used by MAX6675 but required for config)
  * **SPI CLK**:  P13.2
  * **CS (Chip Select)**: P13.6 (manually controlled as GPIO)
* **UART**:

  * TX/RX used for terminal output via `retarget-io`
  * Baud Rate: 115200

---

## 📟 How It Works

1. SPI and UART are initialized.
2. CS (chip select) is set low to begin SPI communication.
3. Two bytes (16 bits) are read from the MAX6675 sensor.
4. The result is converted to temperature in Celsius and printed to the UART terminal.
5. If the thermocouple is disconnected, an error is reported.
6. The process repeats every second.

---

## 🛠️ Tools Required

* ModusToolbox
* Traveo T2G KIT\_T2G-B-E\_Lite
* MAX6675 sensor module
* Thermocouple probe
* USB-UART terminal (e.g., Tera Term, PuTTY, or VS Code Serial Monitor)

---

## ▶️ Usage Instructions

1. Connect the MAX6675 sensor to the board:

   * MISO → P13.0
   * MOSI → P13.1 (dummy, not used)
   * CLK  → P13.2
   * CS   → P13.6 (configured as GPIO)
2. Flash the firmware to the Traveo T2G board.
3. Open a serial terminal at **115200 baud**, 8N1.
4. Observe temperature readings printed every second.

---

## 📁 File Structure
