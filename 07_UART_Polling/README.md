# 📟 07_UART_Polling – UART Echo Example

This example demonstrates a simple **UART echo application** using **polling mode** on the Infineon **Traveo T2G** microcontroller.

It reads a single character received over UART and sends it back immediately, providing a clear and minimal implementation for serial communication without interrupts.

---

## 🔧 Configuration

- **SCB Used**: SCB0
- **RX Pin**: P0.0
- **TX Pin**: P0.1
- **Baud Rate**: 115200 bps
- **Mode**: 8 data bits, no parity, 1 stop bit (8N1)

---

## 📟 How it Works

1. The terminal is cleared with an ANSI command (`\x1b[2J\x1b[;H`)
2. A header message is printed with UART configuration info
3. The program enters an infinite loop:
   - Checks if data is available in the RX FIFO
   - Reads the byte
   - Sends the same byte back (echo)

---

## 🛠️ Required Tools

- ModusToolbox
- Visual Studio Code (or Eclipse-based IDE)
- USB-UART bridge or onboard debugger with UART support
- Serial terminal software like:
  - **Tera Term**, **PuTTY**, or
  - ✅ **Built-in Serial Monitor in Visual Studio Code**  
    You can install the "Serial Monitor" extension from Microsoft to use a serial terminal directly inside VS Code.  
    After flashing the project, just open the Serial Monitor, select the correct COM port and baud rate (115200), and you’re ready to test.

---

## ▶️ Usage Instructions

1. Connect the UART interface (P0.0 and P0.1) to a serial terminal
2. Set the terminal to 115200 baud, 8 data bits, no parity, 1 stop bit (8N1)
3. Flash the program to your Traveo T2G board
4. Open the terminal and observe the welcome message
5. Type any character – it will be echoed back instantly