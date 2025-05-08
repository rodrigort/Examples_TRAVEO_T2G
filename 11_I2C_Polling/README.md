# 📟 11_I2C_Polling – AHT25 Sensor via I2C (Polling Mode)

This example demonstrates how to communicate with the **AHT25 temperature and humidity sensor** using the **I2C peripheral in polling mode** on the **Infineon Traveo T2G** microcontroller. Sensor readings are printed to a UART terminal using the `retarget-io` library.

---

## 🔧 Configuration

- **Sensor**: AHT25 (Temperature & Humidity Sensor)
- **I2C Settings**:
  - Mode: Master (Polling)
  - Clock Speed: 100 kbps
  - Data Width: 8 bits
- **Pinout**:
  - **SDA**: P6.1
  - **SCL**: P6.2
- **UART**:
  - **TX/RX**: `CYBSP_DEBUG_UART_TX` / `CYBSP_DEBUG_UART_RX`
  - **Baud Rate**: 115200 bps

---

## 📟 How It Works

1. The I2C peripheral is initialized in **master mode** with **polling**.
2. The program checks for the presence of the AHT25 on the I2C bus.
3. If found, a measurement command is sent to the sensor.
4. After a short delay, 7 bytes are read from the sensor:
   - Humidity is extracted from the first part of the data
   - Temperature is extracted from the second part
5. The values are converted to float and printed over UART every 2 seconds.

---

## 🛠️ Tools Required

- ModusToolbox
- Traveo T2G KIT_T2G-B-E_Lite
- AHT25 Sensor Module
- USB-UART Terminal (e.g., Tera Term, PuTTY, VS Code Serial Monitor)

---

## ▶️ Usage Instructions

1. Connect the AHT25 sensor to the board:
   - SDA → P6.1  
   - SCL → P6.2  
2. Flash the firmware to the Traveo T2G board.
3. Open a serial terminal at **115200 baud**, 8N1.
4. Observe the temperature and humidity readings printed every 2 seconds.


