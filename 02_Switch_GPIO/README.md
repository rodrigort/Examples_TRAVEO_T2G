# 🔘 Example 2 – Switch GPIO (KIT_T2G-B-E_Lite)

This example demonstrates how to read push-button inputs and control two onboard LEDs using the **Infineon Traveo II (T2G)** microcontroller with the **KIT_T2G-B-E_Lite** evaluation board.

---

## 🛠️ Description

- **Button 1 (BTN_1 – P5.3)** controls **LED 1 (P5.0)** with a software debounce
- **Button 2 (BTN_2 – P17.0)** directly mirrors its state to **LED 2 (P5.1)**

> Buttons are configured as **inputs with internal pull-up** resistors, meaning:
> - Pressed = logic **LOW (0)**
> - Released = logic **HIGH (1)**  
>
> LEDs are **active-low**: writing `0` turns them **ON**, writing `1` turns them **OFF**

---

## 🔧 Tools & Configuration

- **ModusToolbox** (with Device Configurator)
- **Visual Studio Code** or ModusToolbox IDE
- **Target board**: `KIT_T2G-B-E_Lite`
- **Peripheral Driver Library (PDL)** APIs

---

## 📍 Pin Configuration (via Device Configurator)

| Symbol | Pin    | Direction | Drive Mode          | Input Buffer | Initial State |
|--------|--------|-----------|---------------------|---------------|----------------|
| LED_1  | P5.0   | Output    | Strong Drive        | Off           | High (OFF)     |
| LED_2  | P5.1   | Output    | Strong Drive        | Off           | High (OFF)     |
| BTN_1  | P5.3   | Input     | Resistive Pull-up   | **On**        | N/A            |
| BTN_2  | P17.0  | Input     | Resistive Pull-up   | **On**        | N/A            |

> ✅ **Important:** Be sure to enable the **input buffer** for both BTN_1 and BTN_2 in Device Configurator.

---

## ▶️ How to Run

1. Clone this repository or copy the example folder.
2. Open the project in **Visual Studio Code**.
3. Open **Device Configurator** (`design.modus`) and confirm pin settings.
4. Click **Generate Application**.
5. Build and flash the board:
