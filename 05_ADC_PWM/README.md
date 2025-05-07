# 📈 Example 05 – ADC to PWM Mapping

This example demonstrates how to continuously read an analog voltage using the 12-bit ADC of the **TRAVEO T2G** microcontroller and dynamically control the PWM duty cycle of an LED on pin **P5.0**.

---

## 🛠️ Description

- The ADC continuously reads voltage from pin **P6.0**
- The value (0 to 4095) is mapped to a PWM duty cycle (0 to 13110)
- The PWM output on **P5.0** controls an LED that fades in and out
- PWM frequency: **3.82 kHz** (period = 13110)

---

## 🔧 Tools & Configuration

- **ModusToolbox** with Device Configurator
- **Visual Studio Code** or **ModusToolbox IDE**
- **Target Board**: [KIT_T2G-B-E_Lite](https://www.infineon.com/cms/en/product/evaluation-boards/kit_t2g-b-e_lite/)
- ADC resolution: 12 bits
- Peripheral Driver Library (PDL)

---

## 📍 Pin Configuration

| Symbol   | Pin   | Function     | Direction | Note                                      |
|----------|--------|--------------|-----------|-------------------------------------------|
| ADC_IN   | P6.0  | Analog Input | Input     | Connected to analog source (e.g. potentiometer) |
| LED_PWM  | P5.0  | PWM Output   | Output    | LED brightness control (fading effect)    |

> Configure **P6.0** as **"Analog Input"**, and **P5.0** as **"PWM Output - Strong Drive, input buffer off"**

---

## ▶️ How to Run

1. Open the project folder in **Visual Studio Code**
2. Use **Device Configurator** to:
   - Configure **ADC Channel 0** on **P6.0**
   - Assign **PWM_0** to **P5.0** with period set to **13110** (≈ 3.82 kHz)
3. Click **"Generate Application"**
4. Build and program the board
5. Rotate a potentiometer or vary the voltage on **P6.0** to observe the LED fading

---

## 📂 File Structure

| File         | Description                            |
|--------------|----------------------------------------|
| `main.c`     | Application code with ADC-to-PWM logic |
| `.mtb`       | ModusToolbox metadata                  |
| `cycfg_*.h`  | Auto-generated peripheral configs       |

---

## 👤 Author

**Rodrigo Rodrigues**  
Electrical Engineer & Embedded Systems Developer
