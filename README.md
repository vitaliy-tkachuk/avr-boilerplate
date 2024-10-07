# AVR Boilerplate

This repository provides a boilerplate setup for developing, building, and flashing AVR microcontroller firmware, specifically for the ATmega328P. The setup uses Docker to streamline the development process, allowing for easy compilation and flashing of firmware.

## Requirements

- **Docker**: Ensure Docker is installed and running on your system.
- **USBasp Programmer**: Used for flashing the firmware to the microcontroller.
- **Proteus**: PCB Design and Circuit Simulator Software (**Optional**)

## Setup

**Clone the Repository**:
```bash
 git clone https://github.com/vitaliy-tkachuk/avr-boilerplate.git
 cd avr-boilerplate
```

## Commands

### Build the Project

To build the firmware using Docker, run:

```bash
docker-compose run --rm avr_build
```
This builds sources and creates binary files in build folder both inside docker container and in a root folder of project.
### Flash the Firmware

To flash the compiled firmware to the microcontroller using `avrdude`, run:

```bash
docker-compose run --rm avr_flash
```

## Customizing avrdude Parameters

If you need to pass specific parameters to `avrdude` for flashing your microcontroller, you can modify the `CMakeLists.txt` file. The `avrdude` command and its parameters are defined within this file under the `flash` target.

```cmake
add_custom_target(flash
    COMMAND avrdude -c usbasp -p ${MCU} -U flash:w:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex -B 125kHz
    DEPENDS ${PROJECT_NAME}.elf
    COMMENT "Flashing the microcontroller with avrdude..."
)
```

You can adjust the `-c`, `-p`, `-U`, `-B`, or any other flags to suit your specific hardware setup or preferences.

For example, to change the clock frequency or use a different programmer, simply edit the relevant options in the `CMakeLists.txt` file.

## Example Code

`src/main.c` file contains an example code, that can be used to tests the boilerplate setup by blinking an LED connected to PB0 (pin 14 on ATmega328P). It toggles the LED every 500ms, ensuring that your toolchain and microcontroller are working correctly.

Note: 
You can also test this code with the included Proteus simulation project in `simulation` folder.
