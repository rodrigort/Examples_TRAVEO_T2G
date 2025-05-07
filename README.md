# 🚀 Traveo T2G Examples

This repository contains a collection of practical examples for the **Infineon Traveo (T2G)** microcontroller family, developed using **ModusToolbox** and **Visual Studio Code**.

Each example demonstrates the use and configuration of various peripherals via the **Peripheral Driver Library (PDL)**, helping developers get started quickly with real hardware and hands-on code.

---

## 🔧 Tools Used

- [ModusToolbox](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
- Visual Studio Code (with optional Infineon extensions)
- Device Configurator
- Peripheral Driver Library (PDL)
- [KIT_T2G-B-E_Lite](https://www.infineon.com/cms/en/product/evaluation-boards/kit_t2g-b-e_lite/) (main test board)

---

## 📁 Example Categories


| Category              | Description                                           |
|-----------------------|-------------------------------------------------------|
| [`01_Blinky_LED`](https://github.com/rodrigort/Examples_TRAVEO_T2G/tree/main/01_Blinky_LED)       | Basic GPIO control: toggling LEDs                     |
| `02_Switch_GPIO`      | Reading GPIO input from switches                      |
| `03_ADC`              | Reading analog signals using the ADC                  |
| `04_PWM_Fade_LED`     | LED brightness fade using PWM on pin P5.0            |
| `05_ADC_PWM`          | Controlling PWM duty cycle with ADC input             |
| `05_ADC_PWM_2V`       | ADC to PWM with UART output via printf (retarget-io)  |
| `06_Emulate_EEPROM`   | EEPROM emulation using Flash memory                   |
| `07_UART_Polling`     | UART communication using polling                      |
| `08_UART_Interrupt`   | UART communication using interrupts                   |
| `09_SPI_Polling`      | SPI communication using polling                       |
| `10_SPI_Interrupt`    | SPI communication using interrupts                    |
| `11_I2C_Polling`      | I2C communication using polling                       |
| `12_I2C_Interrupt`    | I2C communication using interrupts                    |
| `13_DualCore`         | Inter-core communication between CM0+ and CM4 using IPC |


Each folder includes a `README.md` with step-by-step instructions, source code, and configuration details.

---

## 🧠 Project Goals

- Deliver simple, clean, and working examples for each key peripheral
- Help developers and students quickly start programming the Traveo T2G
- Encourage learning, exploration, and community contribution

---

## ✅ Getting Started

1. Clone this repository
2. Open the desired example folder in **Visual Studio Code**
3. Launch the **Device Configurator** and generate code
4. Compile and flash to the board using ModusToolbox build tools

For more details, see the individual example folders.

---

## 📬 Contributing

Feel free to open issues, submit improvements, or request new examples.  
This repository was created to support the community and improve embedded development with Infineon tools.

---

## 👨‍💼 Author

**Rodrigo Rodrigues** – Electrical Engineer & Embedded Systems Developer  

---

Made with ❤️ using real hardware and a lot of debugging!
