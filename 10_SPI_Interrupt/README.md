# 📟 10_SPI_Interrupt – SPI Communication with MAX6675 (Interrupt Mode)

This example demonstrates how to communicate with the **MAX6675 thermocouple sensor** using the **SPI peripheral in interrupt mode** on the **Infineon Traveo T2G** microcontroller. The measured temperature is printed to a UART terminal using the `retarget-io` library.

---

## 🔧 Configuration

- **Sensor**: MAX6675 (K-type thermocouple digital converter)
- **SPI Settings**:
  - Clock Speed: 100 kbps
  - Mode: Master, SPI Mode 0
  - Data Width: 8 bits
  - Transfer: Full duplex (read only from slave)
  - API Mode: High-Level (`Cy_SCB_SPI_Transfer`)
- **Pinout**:
  - **SPI CLK** : P13.2
  - **SPI MISO**: P13.0
  - **SPI MOSI**: P13.1 (not used by MAX6675, but required for full config)
  - **CS (Slave Select)**: P13.6 (configured as SS3, automatically controlled)
- **UART**:
  - **TX/RX**: `CYBSP_DEBUG_UART_TX` / `CYBSP_DEBUG_UART_RX`
  - **Baud Rate**: 115200 bps
- **Interrupt**:
  - SCB3 interrupt enabled for SPI completion callback
  - Priority: 3

---

## 📟 How It Works

1. SPI is initialized in **Master mode** with **Slave Select 3 (SS3)** set to control P13.6 automatically.
2. Every 1 second:
   - A SPI transfer of 2 bytes is initiated using `Cy_SCB_SPI_Transfer()`.
   - The CS (P13.6) is toggled automatically by the hardware.
   - Upon transfer completion, an interrupt is triggered.
   - The raw data is parsed into Celsius temperature and printed via UART.
   - If the thermocouple is disconnected, an error is reported.

---

## 🛠️ Tools Required

- ModusToolbox
- Traveo T2G KIT_T2G-B-E_Lite
- MAX6675 Module with K-type thermocouple
- USB-UART Terminal (e.g., Tera Term, PuTTY, or VS Code Serial Monitor)

---

## ▶️ Usage Instructions

1. Connect the MAX6675 sensor to the board:
   - MISO → P13.0  
   - MOSI → P13.1 (dummy only)  
   - CLK  → P13.2  
   - CS   → P13.6 (configured as SS3 in Device Configurator)
2. Flash the firmware to the Traveo T2G board.
3. Open a serial terminal at **115200 baud**, 8N1.
4. Observe temperature values printed every second.

---


