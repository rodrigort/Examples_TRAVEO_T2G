# 📈 Example 03 – ADC (Analog to Digital Conversion)

This example demonstrates how to use the 12-bit ADC of the Traveo (T2G) microcontroller to continuously read an analog voltage on pin **P6.0** and control an onboard LED based on the measured value.

---

## 🛠️ Description

- The ADC continuously reads voltage on pin **P6.0**
- If the ADC value is **greater than 2048** (midpoint of 12-bit range), the LED is **turned ON**
- If the ADC value is **less than or equal to 2048**, the LED is **turned OFF**
- The LED used is connected to **P5.0** (active-low)

---

## 🔧 Tools & Configuration

- **ModusToolbox** with Device Configurator
- **Visual Studio Code** or ModusToolbox IDE
- **Target Board**: KIT_T2G-B-E_Lite
- ADC resolution: 12 bits
- Peripheral Driver Library (PDL)

---

## 📍 Pin Configuration

| Symbol | Pin   | Function     | Direction | Note                    |
|--------|--------|--------------|-----------|-------------------------|
| ADC_IN | P6.0  | Analog Input | Input     | Connected to analog source (e.g. potentiometer) |
| LED_1  | P5.0  | Digital Out  | Output    | LED control (active-low) |

> Make sure P6.0 is configured as **"Analog Input"**, and P5.0 as **"Strong Drive, input buffer off"**

---

## ▶️ How to Run

1. Open the project folder in **Visual Studio Code**
2. Configure pins in **Device Configurator**:
   - P6.0 as ADC input
   - P5.0 as digital output (LED)
3. Click "Generate Application
4. Build and program the board