## 📈 Example 04 – PWM Fade LED

This example demonstrates how to use the **PWM** peripheral of the **TRAVEO T2G** microcontroller to create a smooth fade effect on an onboard LED using pin **P5.0**.

🔗 [Back to Main Repository](https://github.com/rodrigort/Examples_TRAVEO_T2G)

---

### 🛠️ Description

- PWM output is configured at 10 MHz
- Duty cycle is dynamically changed to produce a fade-in and fade-out effect
- LED connected to **P5.0** fades up and down continuously

---

### 🛠️ Tools & Configuration

- **ModusToolbox 3.x** with **Device Configurator**
- **Visual Studio Code** or **ModusToolbox IDE**
- **Target Board**: [KIT_T2G-B-E_Lite](https://www.infineon.com/cms/en/product/evaluation-boards/kit_t2g-b-e_lite/)
- **PWM Top Value**: 13110 (for 10 MHz clock)
- **Fade Step**: 50
- **Delay Between Steps**: 5 ms

---

### 📍 Pin Configuration

| Symbol     | Pin   | Function   | Direction | Note                         |
|------------|-------|------------|-----------|------------------------------|
|PWM_Fade_LED| P5.0  | PWM Output | Output    | On-board LED (fade effect)  |

Make sure P5.0 is configured as **PWM Output**, Strong Drive, Input buffer OFF.

---

### ▶️ How to Run

1. Open the project folder in Visual Studio Code or ModusToolbox IDE
2. Use Device Configurator to:
   - Assign **PWM_0** to **P5.0**
   - Set period to **13110** (for 10 MHz)
   - Enable Compare0 swapping for dynamic control
3. Click **"Generate Application"**
4. Build and program the board
5. Observe the onboard LED fading in and out

---

### 📂 File Structure

| File                  | Description                              |
|-----------------------|------------------------------------------|
| `main.c`              | Core application logic with PWM fade     |
| `.mtb`                | ModusToolbox metadata                    |
| `cycfg_peripherals.*` | Auto-generated peripheral configs        |

---

### 👤 Author

**Rodrigo Rodrigues**  
Embedded Systems Developer & Creator of T2G Examples Repository
