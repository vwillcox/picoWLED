<p align="center">
  <img src="/images/wled_logo_akemi.png">
  <a href="https://github.com/vwillcox/picoWLED/blob/main/LICENSE"><img src="https://img.shields.io/github/license/vwillcox/picoWLED?color=blue&style=flat-square"></a>
</p>

# picoWLED ✨

**A loving fork of [WLED](https://github.com/wled/WLED) that brings it to Raspberry Pi Pico–based LED displays, starting with the Pimoroni Cosmic Unicorn.**

WLED is a wonderful project, and picoWLED aims to stay close to it and compatible with it. You get the same web UI, JSON API, effects, segments and presets, and the WLED apps work with it. The difference is that it runs on the RP2040 / RP2350 instead of an ESP32 or ESP8266.

> picoWLED is an independent, unofficial fork. It is **not** supported by the WLED team, so please don't take picoWLED problems to WLED's issue tracker, Discord or forum. Open an issue [here](https://github.com/vwillcox/picoWLED/issues) instead.

## 🧪 Status: experimental

| Board | Build environment | Status |
|---|---|---|
| Pimoroni Cosmic Unicorn 32×32, Pico W (RP2040) | `rpipicow_cosmicunicorn` | Runs on real hardware: matrix output, WiFi, web UI and app |
| Pimoroni Cosmic Unicorn 32×32, Pico 2 W (RP2350) | `rpipico2w_cosmicunicorn` | Builds; not yet tested on hardware |

The Cosmic Unicorn's matrix is driven by a dedicated bus type (`BusPimoroniUnicornMatrix`). Its PIO program and scan logic are adapted from Pimoroni's [pimoroni-pico](https://github.com/pimoroni/pimoroni-pico) library (MIT License, © Pimoroni Ltd).

### Known limitations
- **No MQTT, ESP-NOW or infrared.** These are disabled at build time because no RP2040-compatible libraries are available for them.
- **Setting "AP opens" to "Always" does not work.** The device opens a hotspot named after your router instead of joining it, so leave this on the default ("No connection after boot").
- **Some UDP services may not start.** The arduino-pico core can only open 7 UDP sockets, which is fewer than WLED normally uses. Depending on the order things start in, DDP or the captive-portal DNS may be unavailable.
- **The firmware validation check can miss.** Browser OTA uses arduino-pico's Updater, and the compatibility check may not find the firmware metadata. If an update is rejected, tick "Ignore firmware validation" to install it.

## 🔧 Building and flashing

Requires [PlatformIO](https://platformio.org/) and Node.js.

```bash
npm ci && npm run build                      # build the web UI
pio run -e rpipicow_cosmicunicorn            # Cosmic Unicorn with Pico W (RP2040)
pio run -e rpipico2w_cosmicunicorn           # Cosmic Unicorn with Pico 2 W (RP2350)
```

1. Hold **BOOTSEL** while plugging the Pico into USB. It appears as a USB drive.
2. Copy `.pio/build/<environment>/firmware.uf2` onto that drive.
3. On first boot, connect to the `WLED-AP` hotspot (password `wled1234`) and configure WiFi, just as with WLED.

`rpipicow_cosmicunicorn_debug` builds the same firmware with serial debug logging enabled.

## ❤️ Credits

All the credit for WLED goes to [Aircoookie](https://github.com/Aircoookie) and the [WLED contributors](https://kno.wled.ge/about/contributors/). picoWLED is licensed under the same [EUPL v1.2](LICENSE) as WLED.

---

## About WLED

The rest of this README is WLED's own introduction, kept as it is. The features and documentation it describes are for upstream WLED on ESP32 or ESP8266, and not every feature is available in picoWLED yet.

# Welcome to WLED! ✨

A fast and feature-rich firmware for ESP32 microcontrollers to control addressable LEDs — from simple strips to large 2D matrices and HUB75 panels.

Originally created by [Aircoookie](https://github.com/Aircoookie), now maintained by a community of contributors.

## 🤝 Contributing

Want to help improve WLED? Awesome! Please skim [CONTRIBUTING.md](CONTRIBUTING.md) first - it covers how we like PRs and issues to look, including our take on AI-assisted contributions.
If you're an AI coding agent, [AGENTS.md](AGENTS.md) is for you - please read it before modifying any files. 😊

## ⚙️ Features

### Effects & Visuals
- [**200+ built-in effects**](https://kno.wled.ge/features/effects/) including classic animations, audio-reactive, and 2D/matrix effects
- [50+ color palettes](https://kno.wled.ge/features/palettes/) plus a built-in **custom palette editor** (PixelForge)
- [**2D LED matrix support**](https://kno.wled.ge/advanced/mapping/) with dedicated 2D effects and flexible panel mapping
- [**HUB75 RGB matrix panel support**](https://kno.wled.ge/advanced/HUB75/) (ESP32)
- [**AudioReactive**](https://kno.wled.ge/advanced/audio-reactive/) effects — included by default, responding to sound via microphone, line-in, or network audio source
- Effect blending for smooth transitions between animations
- Antialiased drawing functions for smooth graphics

### Segments & Control
- [**Segments**](https://kno.wled.ge/features/segments/) — apply different effects, colors and palettes to independent parts of your LED setup simultaneously
- Up to **250 presets** to save and recall colors, effects and segment configurations — supports [playlists](https://kno.wled.ge/features/presets/) for automated cycling
- Nightlight function with configurable dimming curve
- Configurable **Auto Brightness Limiter** (per output) for safe operation

### Hardware Support
- **ESP32** (all variants: original, S2, S3, C3)
- [**Up to 17 LED outputs**](https://kno.wled.ge/features/multi-strip/) on ESP32 using parallel I2S + RMT
- [Addressable LED support](https://kno.wled.ge/basics/compatible-led-strips/): WS2812B, WS2811, WS2815, SK6812, WS2805, TM1914, APA102, WS2801, LPD8806, and many more
- RGBW, [RGB+CCT](https://kno.wled.ge/features/cct/) and white-only strips
- PWM outputs for analog LEDs and dimmers
- [**Ethernet** support](https://kno.wled.ge/features/ethernet-lan/) for a wide range of boards (QuinLED, LILYGO, Olimex, and more)
- Filesystem-based config for easy backup and restore of presets and settings
- Full OTA firmware updates (HTTP + ArduinoOTA), password-protectable

### Connectivity & Integrations
- **WLED app** for [Android](https://play.google.com/store/apps/details?id=ca.cgagnier.wlednativeandroid) and [iOS](https://apps.apple.com/gb/app/wled-native/id6446207239)
- [JSON](https://kno.wled.ge/interfaces/json-api/) and [HTTP request](https://kno.wled.ge/interfaces/http-api/) APIs
- **Multi-WiFi** — connect to up to 3 networks with automatic AP fallback
- **ESP-NOW** wireless sync between devices (no WiFi router required)
- [**MQTT**](https://kno.wled.ge/interfaces/mqtt/) with Home Assistant discovery
- [**E1.31, Art-Net**](https://kno.wled.ge/interfaces/e1.31-dmx/), [DDP](https://kno.wled.ge/interfaces/ddp/) and [TPM2.net](https://kno.wled.ge/interfaces/udp-realtime/) for DMX/professional lighting control
- [UDP realtime sync](https://kno.wled.ge/interfaces/udp-notifier/) across multiple WLED devices
- Alexa voice control (on/off, brightness, color)
- [Philips Hue sync](https://kno.wled.ge/interfaces/philips-hue/)
- [diyHue](https://github.com/diyhue/diyHue) and [Hyperion](https://github.com/hyperion-project/hyperion.ng) integration
- [Adalight / TPM2](https://kno.wled.ge/interfaces/serial/) (PC ambilight via serial)
- [Infrared remote control](https://kno.wled.ge/interfaces/infrared/) (24-key RGB, receiver required)
- Timers and schedules (NTP time sync, full timezone and DST support)

### Developer-Friendly
- **Usermod system** — extend WLED with community or custom modules without modifying core code
- Large and active [usermod library](https://kno.wled.ge/advanced/community-usermods/) including AudioReactive, temperature sensors, rotary encoders, displays, and much more
- Well-documented [JSON API](https://kno.wled.ge/interfaces/json-api/)
- Licensed under the **EUPL v1.2**

## 📲 Quick start guide and documentation

See the [documentation at kno.wled.ge](https://kno.wled.ge)!

[Tutorials and getting-started guides](https://kno.wled.ge/basics/tutorials/) to help you get your project running quickly.

## 🖼️ User interface

<img src="/images/macbook-pro-space-gray-on-the-wooden-table.jpg" width="50%"><img src="/images/walking-with-iphone-x.jpg" width="50%">

## 💾 Compatible hardware

See the [compatible hardware list](https://kno.wled.ge/basics/compatible-hardware) on the wiki.

## ✌️ Other

Licensed under the [EUPL v1.2](https://raw.githubusercontent.com/wled-dev/WLED/main/LICENSE).  
Credits to all [contributors](https://kno.wled.ge/about/contributors/)!  
CORS proxy by [Corsfix](https://corsfix.com/).

![CodeRabbit Pull Request Reviews](https://img.shields.io/coderabbit/prs/github/wled/WLED?utm_source=oss&utm_medium=github&utm_campaign=wled%2FWLED&labelColor=171717&color=FF570A&link=https%3A%2F%2Fcoderabbit.ai&label=PR+Reviews+supported+by+CodeRabbit)

Join the Discord server to discuss everything about WLED!

<a href="https://discord.gg/QAh7wJHrRM"><img src="https://discordapp.com/api/guilds/473448917040758787/widget.png?style=banner2" width="25%"></a>

Check out the WLED [Discourse forum](https://wled.discourse.group)!

If you'd like to reach the original creator privately: [dev.aircoookie@gmail.com](mailto:dev.aircoookie@gmail.com).

If WLED brightens up your day, you can [send a gift to Aircoookie via PayPal](https://paypal.me/aircoookie).

---

*Disclaimer:*

If you are prone to photosensitive epilepsy, we recommend you do **not** use this software.  
If you still want to try, avoid strobe, lightning or noise modes and high effect speed settings.

As per the EUPL license, no liability is assumed for any damage to you or any other person or equipment.
