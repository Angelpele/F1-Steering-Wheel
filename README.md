# 🏎️ F1 Steering Wheel

This project is a **custom-made F1-style steering wheel** designed and built entirely from scratch, featuring a **custom PCB**, advanced input/output handling, and a rigid mechanical structure optimized for sim racing or automotive-style control systems.

<p align="center">
  <img src="./media/MVIMG_20260207_000909.jpg" width="650">
</p>

---

## 🛠️ Electronics & PCB Design

The steering wheel is built around a **custom-designed PCB** using an **ESP32-C6 DevKitC-1** as the main controller, providing high performance and wireless capabilities.

<p align="center">
  <img src="PASTE_PCB_IMAGE_HERE" width="600">
</p>

### Main Electronic Features

| Component | Description |
|---------|-------------|
| **ESP32-C6 DevKitC-1** | Main microcontroller handling inputs, logic, and communication |
| **74LS154 Decoder** | 4-to-16 line decoder used to drive LED groups |
| **15 LEDs (RGB Groups)** | Divided into 3 groups of 5 LEDs (Green, Red, Blue) |
| **4-Digit 7-Segment Display** | Displays speed, gear, or system information |
| **8 Buttons (Resistor Ladder)** | All buttons read through a single ADC pin |
| **2 Potentiometers** | Center-mounted, using voltage divider for analog input |
| **External Sensor Support** | Designed for NTC temperature sensor and Hall-effect sensor |
| **Custom Buttons PCB** | Top-mounted buttons integrated into the housing |

### LED Functionality
The **15 LEDs**, controlled via the **74LS154 decoder**, provide real-time visual feedback:
- **Green LEDs** → Speed or system status  
- **Red LEDs** → Engine RPM / rev-up indication  
- **Blue LEDs** → Custom functions or gear indicators  

The decoder uses **4 control lines** to efficiently manage all LED outputs.

---

## ⚙️ Mechanical Design

The entire mechanical structure was **designed from scratch in Fusion 360**, prioritizing rigidity, modularity, and professional finish.

<p align="center">
  <img src="PASTE_INNER_STRUCTURE_IMAGE_HERE" width="600">
</p>

### Structural Overview

1. **Lower Case**
   - Houses most electronic components.
   - Rear sockets allow bolts to be inserted flush with the surface.
   - Enables clean and solid assembly.

2. **Steel Reinforcement Plate**
   - Water-jet cut steel middle plate.
   - Provides structural rigidity and torsional strength.
   - Acts as the main load-bearing core.

3. **TPU Handles**
   - Designed in **two parts per side**.
   - Bolted directly to the internal steel structure.
   - Flexible yet durable for comfortable grip.

4. **PCB Mounting**
   - Custom PCB is mounted on top of the steel plate.
   - Electrically isolated to prevent short circuits.
   - Secured using threaded inserts.

5. **Top Case & Buttons**
   - Top enclosure holds the custom-made buttons.
   - Assembled using **threaded inserts melted into the plastic**.
   - All components are bolted together for maximum durability.

---

## 🎮 User Interface & Inputs

- **8 programmable buttons** via resistor ladder  
- **2 analog potentiometers** for adjustable parameters  
- **4-digit display** for speed, gear, or telemetry  
- **RGB LED groups** for intuitive real-time feedback  

---

## 🚀 Project Goals

- Realistic **F1-style input device**
- Robust **mechanical and electrical integration**
- Modular design for future firmware expansion
- Support for additional external sensors

---

## 🔧 Future Improvements
- CAN bus or USB HID integration
- Advanced LED animations synchronized with telemetry
- Wireless configuration via ESP32-C6
- Closed-loop haptic feedback
