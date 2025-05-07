# 📟 08_UART_Interrupt – UART Interrupt-based Reception Example

This example demonstrates **UART communication using interrupts** on the **Infineon Traveo T2G** microcontroller.

It uses **asynchronous reception** to receive a fixed number of bytes (`RX_BUFFER_SIZE = 5`) and then echoes them back through UART. An onboard LED briefly lights up to indicate a successful reception.

---

## 🔧 Configuration

- **SCB Used**: SCB0  
- **RX Pin**: P18.0  
- **TX Pin**: P18.1  
- **Baud Rate**: 115200 bps  
- **Mode**: 8 data bits, no parity, 1 stop bit (8N1)  
- **Reception**: Interrupt-based, 5 bytes per message

---

## 📟 How it Works

1. The terminal is cleared using an ANSI sequence, and a welcome message is printed.
2. UART is configured to **receive 5 bytes asynchronously**.
3. Once all 5 bytes are received, an interrupt is triggered:
   - The data is copied into a buffer
   - The message is echoed back with the prefix `"Received bytes: "`
   - The onboard LED lights up briefly to indicate activity
   - The RX FIFO is cleared and reception restarts
4. The process repeats continuously.

---

## 🛠️ Required Tools

- ModusToolbox  
- Visual Studio Code (with Infineon extensions, optional)  
- USB-UART bridge or onboard debugger with UART capability  
- Serial terminal software such as:
  - Tera Term, PuTTY, etc.  
  - ✅ Or use the built-in Serial Monitor extension in **Visual Studio Code**

---

## ▶️ Usage Instructions

1. Open the project folder in **VS Code** or **ModusToolbox IDE**.  
2. Connect the RX/TX pins (P18.0 / P18.1) to your USB-UART converter.  
3. Open a serial terminal and configure:
   - **Baud Rate**: 115200  
   - **Data Bits**: 8  
   - **Parity**: None  
   - **Stop Bits**: 1  
4. Flash the firmware to the board.  
5. Send exactly 5 characters — they will be echoed back with the `"Received bytes: "` label.

---



