# 🔀 12_IPC_ADC – ADC Reading on CM4 + LED Control on CM0+

This example demonstrates inter-core communication between the **CM4** and **CM0+** cores of the **Infineon Traveo II (T2G)** MCU, using **12-bit ADC** and **IPC**.

📌 The **CM4** core continuously reads an analog value via ADC and sends it via IPC (channel 7) to **CM0+**, which processes the value and controls three green LEDs connected to GPIOs.

---

## 📋 Functionality

- **CM4** reads analog input from **pin P6.0** using a 12-bit ADC.
- Each value is sent via IPC to **CM0+**.
- **CM0+** receives the value and controls three **green LEDs** based on this range:

| ADC Value Range | LED Behavior                      |
|------------------|-----------------------------------|
| 0000–0099        | 🔘 All LEDs OFF                   |
| 0100–1363        | 🟢 LED 1 ON (P5.0)                |
| 1364–2726        | 🟢 LED 2 ON (P5.1)                |
| 2727–3899        | 🟢 LED 3 ON (P5.2)                |
| 3900–4095        | 🔘 All LEDs OFF                   |

ℹ️ **Note:** All LEDs are green. Each one is used to represent a value range independently.

---

## ⚙️ Tools Used

- ✅ ModusToolbox 3.x  
- ✅ Visual Studio Code  
- ✅ Device Configurator  
- ✅ Peripheral Driver Library (PDL)  
- ✅ KIT_T2G-B-E_Lite

---

## 🔌 Pin Mapping

| Signal Name | Core  | Function          | Pin   |
|-------------|-------|-------------------|--------|
| LED 1       | CM0+  | Green LED Output  | P5.0   |
| LED 2       | CM0+  | Green LED Output  | P5.1   |
| LED 3       | CM0+  | Green LED Output  | P5.2   |
| ADC Input   | CM4   | Analog Input      | P6.0   |
| UART TX/RX  | CM4   | Debug Serial Port | P5.0 / P5.1 (default BSP) |

---