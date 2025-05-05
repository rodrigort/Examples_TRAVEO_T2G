# 🚀 Traveo T2G Examples

This repository contains a collection of hands-on examples for the **Infineon Traveo II (T2G)** microcontroller family, developed using **Visual Studio Code** and **ModusToolbox**.

Each project is designed to demonstrate the configuration and usage of various peripheral drivers using the **Peripheral Driver Library (PDL)**, helping developers quickly get started with embedded systems based on Traveo T2G.

---

## 🔧 Tools Used

- [ModusToolbox](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
- Visual Studio Code (with optional Infineon extensions)
- Device Configurator
- Peripheral Driver Library (PDL)
- KIT_T2G-B-E_Lite (primary test board)

---

## 📁 Example Categories

| Category         | Description                                |
|------------------|--------------------------------------------|
| `01_Blinky_LED`  | Basic GPIO examples (LEDs, buttons)        |
| `02_Switch_GPIO` | Basic Read GPIOs                           |
| `03_ADC`         | Analog reading via ADC                     |
| `04_UART`        | UART Tx/Rx using polling and interrupts    |
| `05_PWM`         | LED dimming,                               |
| `06_I2C`         | I2C communication with sensors/EEPROM      |
| `07_SPI`         | SPI communication                          |
| `08_DualCore`    | IPC and shared memory between CM0+ and CM4 |
| `09_Advanced`    | Power modes, bootloader, protocols         |

Each folder contains a `README.md` with step-by-step instructions, source code, and configuration notes.

---

## 🧠 Project Goals

- Provide clear and minimal working examples for every peripheral
- Help new users get started quickly with Traveo II development
- Encourage community contributions and learning

---

## ✅ Getting Started

1. Clone this repository
2. Open the desired project in Visual Studio Code
3. Launch Device Configurator and generate code
4. Build and flash using `make build` and `make program`

For more details, see the individual example folders.

---

## 📬 Contributing

Feel free to open issues, submit improvements, or request new examples.  
This repository was created to support the community and improve embedded development with Infineon tools.

---

## 👨‍💻 Author

**Rodrigo Teixeira** – Electrical Engineer & Embedded Systems Developer  

---

Made with ❤️ using real hardware and a lot of debugging!
