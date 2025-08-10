<h1 align="center">In the name of GOD</h1>

# GAGHL_AVR_BUTTON_HANDLER

**A Simple external interrupt button handler for AVR microcontrollers**

GAGHL_AVR_BUTTON_HANDLER is a simple and efficient button state manager designed for AVR microcontrollers.
It uses external interrupts to detect button presses, holds, and releases with minimal CPU overhead, making it ideal for low-power or responsive applications.



## 📦 Features

- ✅ External interrupt (EXTI) based button event detection
- ✅ Detects Pressed, Hold, and Released states
- ✅ Supports multiple buttons (up to 8)
- ✅ Non-blocking event polling for smooth main loop operation
- ✅ Small memory footprint and simple API


## 📚 API Overview

| Function                     | Parameters | Description                                                                                |
| ---------------------------- | ---------- | ------------------------------------------------------------------------------------------ |
| `button_handler_init()`      | *(void)*   | Configures pins and enables external interrupts for buttons                                |
| `button_handler()`           | *(void)*   | Checks button events and calls the corresponding user functions (place in while(1))        |
| `button'0..7'_pressed()`     | *(void)*   | Called when button '0..7' is pressed (weak, can be overridden by user)                     |
| `button'0..7'_hold()`        | *(void)*   | Called when button '0..7' is held down (weak, can be overridden)                           |
| `button'0..7'_released()`    | *(void)*   | Called when button '0..7' is released (weak, can be overridden)                            |



## 🚀 Getting Started

### Add the files to your project

Copy these files into your AVR project:

- `GAGHL_AVR_BUTTON_HANDLER.c`
- `GAGHL_AVR_BUTTON_HANDLER.h`
- `GAGHL_AVR_BUTTON_HANDLER_Pins.h`

## 🔧 Requirements

- AVR microcontroller
- AVR-GCC or any compatible C toolchain

## 🛠️ TODO

- [ ] Add support for pin-change interrupts (PCINT)
- [ ] Configurable active-low / active-high button modes
- [ ] Optional software filtering for noisy environments
- [ ] Add unit tests or Proteus simulation examples


## 🤝 Contributing

Contributions are welcome!  
Whether it's bug fixes, feature suggestions, or improvements — your help is appreciated.

- Fork the repository
- Create a new branch (`git checkout -b feature/my-feature`)
- Commit your changes (`git commit -am 'Add new feature'`)
- Push to the branch (`git push origin feature/my-feature`)
- Open a Pull Request

If you’re using this library in your project, feel free to let me know — I’d love to check it out!

## License

This project is licensed under the Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0).

You are free to:
- Share — copy and redistribute the material in any medium or format
- Adapt — remix, transform, and build upon the material

Under the following terms:
- **Attribution** — You must give appropriate credit to the author (GAGHL).
- **NonCommercial** — You may not use the material for commercial purposes without explicit permission.

For more information, see the full license: [https://creativecommons.org/licenses/by-nc/4.0/](https://creativecommons.org/licenses/by-nc/4.0/)

© 2025 GAGHL. All rights reserved.

## Author

Developed by [GAGHL](https://github.com/GAGHL)
