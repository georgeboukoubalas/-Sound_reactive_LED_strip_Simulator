# Sound-Reactive LED Strip Simulator

A browser-based simulator for a **WS2812B individually addressable LED strip** driven by an **ESP32 dual-core microcontroller**. Built to prototype and validate color-changing logic before flashing code to physical hardware.

---

## Overview

This project is the first stage of a sound-reactive lighting system. The simulator lets you visually test LED color modes in any browser — no hardware, no IDE, no dependencies required. Each button maps directly to a FastLED command you will later run on the ESP32.

---

## Hardware Target

| Component | Spec |
|---|---|
| Microcontroller | ESP32 (dual-core, 240 MHz) |
| LED strip | SEZO WS2812B — 60 LEDs/m, 1 m |
| Protocol | Single-wire NZR (800 kHz) |
| Audio input | Physical microphone (analog) |
| Data pin | GPIO 5 |

---

## Simulator Features

- **60 individual pixel elements** rendered in a row, matching the physical strip layout
- **4 color mode buttons** — Red, Green, Blue, Rainbow
- **Off button** — clears all pixels, equivalent to `FastLED.clear()`
- **Live status bar** — shows the active mode, RGB values, and a real-time FPS counter during animation
- **Animated rainbow mode** — smooth HSV hue-wheel cycle using `requestAnimationFrame`, matching the algorithm FastLED uses internally for `fill_rainbow()`
- **FastLED command reference panel** embedded in the page for quick copy-paste to Arduino IDE

---

## Getting Started

No installation needed. Just open the file in a browser.

```bash
# Clone the repository
git clone https://github.com/georgeboukoubalas/-Sound_reactive_LED_strip_Simulator.git

# Navigate into the project folder
cd Sound_reactive_LED_strip_Simulator

# Open the simulator
open main_app.html        # macOS
start main_app.html       # Windows
xdg-open main_app.html    # Linux
```

Or simply double-click `main_app.html` in your file explorer.

---

## Color Mode → FastLED Mapping

| Simulator button | FastLED command |
|---|---|
| Red | `fill_solid(leds, NUM_LEDS, CRGB::Red);` |
| Green | `fill_solid(leds, NUM_LEDS, CRGB::Green);` |
| Blue | `fill_solid(leds, NUM_LEDS, CRGB::Blue);` |
| Rainbow | `fill_rainbow(leds, NUM_LEDS, gHue++, 4);` |
| Off | `FastLED.clear();` |

---

## Project Structure

```
Sound_reactive_LED_strip_Simulator/
├── main_app.html   # Full simulator — single self-contained file
└── README.md       # This file
```

---

## Roadmap

- [ ] Audio input simulation (microphone amplitude → brightness)
- [ ] Frequency band visualisation (bass / mid / treble mapped to colour zones)
- [ ] Beat detection pulse animation
- [ ] Adjustable brightness and speed sliders
- [ ] ESP32 MicroPython / Arduino source code

---

## Tech Stack

- **HTML5** — structure and layout
- **CSS3** — pixel rendering, dark theme, button styling
- **Vanilla JavaScript** — HSV→RGB conversion, `requestAnimationFrame` animation loop, DOM manipulation

No frameworks. No build tools. No dependencies.

---

## License

MIT — free to use, modify, and distribute.
