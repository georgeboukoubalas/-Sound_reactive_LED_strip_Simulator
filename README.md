# Sound-Reactive LED Strip Simulator & Web-Serial Controller

A browser-based simulator and real-time hardware controller for a **WS2812B individually addressable LED strip** driven by an **ESP32 microcontroller**. 

What started as a tool to prototype color-changing logic visually has evolved into a complete, standalone control suite. The web app uses your laptop's microphone to perform real-time Fast Fourier Transform (FFT) audio analysis, and streams the resulting color data directly to the physical LED strip via the **Web Serial API**.

---

## 🧠 System Architecture: How It Works

This project uses a "Smart Brain / Dumb Monitor" architecture:

1. **The Brain (Web Browser):** Uses the `Web Audio API` to listen to your laptop's microphone, performs the heavy math to map frequency bands to colors, and uses the `Web Serial API` to queue and stream a highly-optimized byte array down the USB cable.
2. **The Monitor (ESP32):** Runs a lightweight C++ script. It simply waits for a serial packet starting with the secret header (`LED`), reads the next 180 bytes of color data, and blasts it to the WS2812B strip using the `FastLED` library.

---

## 🔌 Hardware Setup

| Component | Spec |
|---|---|
| Microcontroller | ESP32 (e.g., DOIT DevKit V1) |
| LED strip | SEZO WS2812B — 60 LEDs/m, 1 m |
| Protocol | Single-wire NZR (800 kHz) |
| Data pin | GPIO 5 (Requires 330Ω series resistor) |
| Power | External 5V DC Power Supply (Shared GND with ESP32 required) |
| PC Connection | USB Data Cable (Must support data transfer, not power-only) |

---

## ✨ Features

- **Live Hardware Syncing:** Click a button in the browser, and the physical LED strip responds instantly.
- **Microphone Spectrum Visualizer:** Real-time, logarithmic audio visualizer (20 Hz &rarr; 20 kHz) that maps audio power to a heatmap color scale (Blue &rarr; Green &rarr; Yellow &rarr; Red).
- **Smooth Animations:** Custom queue & throttle system prevents USB serial buffer overflows, keeping the hardware strip running smoothly at ~30 FPS without dropping frames.
- **No Local Server Required:** Because it uses the Web Serial API, the HTML file can be opened directly from your file explorer—no Python, Node.js, or local servers required.

---

## 🚀 Getting Started

### Part 1: Flashing the ESP32

1. Open `esp32_firmware/esp32_firmware.ino` in the Arduino IDE.
2. Install the **FastLED** library via the Library Manager.
3. Select your ESP32 board (e.g., `DOIT ESP32 DEVKIT V1`) and COM port.
4. Upload the code to your board. *(Note: Close the Arduino IDE after uploading so it releases the COM port).*

### Part 2: Running the Web Controller

*⚠️ Note: You must use **Google Chrome** or **Microsoft Edge**. Safari and Firefox do not currently support the Web Serial API.*

```bash
# Clone the repository
git clone [https://github.com/georgeboukoubalas/-Sound_reactive_LED_strip_Simulator.git](https://github.com/georgeboukoubalas/-Sound_reactive_LED_strip_Simulator.git)

# Navigate into the project folder
cd Sound_reactive_LED_strip_Simulator

# Open the controller
open main_app.html        # macOS
start main_app.html       # Windows
xdg-open main_app.html    # Linux

#Steps
Click the purple 🔌 Connect ESP32 button.

Select your ESP32's COM port from the browser popup.

Click Start mic or any of the color modes, and watch your physical strip react instantly!

---
### Part 3: File format
Sound_reactive_LED_strip_Simulator/
├── index.html                 # Full simulator & controller — self-contained UI
├── esp32_firmware.ino         # The FastLED Serial listening script for the ESP32
└── README.md                  # This file

---


### Part 4: Roadmap Progress
[x] Audio input simulation (microphone amplitude → brightness)

[x] Frequency band visualisation (bass / mid / treble mapped to colour zones)

[x] Web-to-Hardware serial communication (Web Serial API)

[x] ESP32 Arduino source code implementation

[x] Traffic throttling / Queue system to prevent serial buffer crashes

[ ] Adjustable brightness sliders for physical strip

[ ] Beat detection pulse animation

---

### Part 5: 🛠️ Tech Stack
Frontend: HTML5, CSS3, Vanilla JavaScript

Web APIs: Web Audio API (AnalyserNode), Web Serial API

Embedded: C++, Arduino Core for ESP32, FastLED Library

No heavy web frameworks. No build tools. No local backend servers.

---

### Part 6: 📄 License
MIT — free to use, modify, and distribute.
