cmake_minimum_required(VERSION 3.10)

# Set the project name and specify the target microcontroller
project(firmware C)

# Define the microcontroller
set(MCU atmega328p)

# Set the build type to Release for optimizations
set(CMAKE_BUILD_TYPE Release)

# Specify the compiler and linker flags
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_C_FLAGS "-mmcu=${MCU} -Os")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU}")

# Define the source files
set(SOURCES src/main.c)

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the executable
add_executable(${PROJECT_NAME}.elf ${SOURCES})

# Create the .hex file after building the .elf file
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND avr-objcopy -O ihex -R .eeprom ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.elf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex
)

# Add a custom target for flashing the microcontroller using avrdude
add_custom_target(flash
    COMMAND avrdude -c usbasp -p ${MCU} -U flash:w:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex -B 125kHz
    DEPENDS ${PROJECT_NAME}.elf
    COMMENT "Flashing the microcontroller with avrdude..."
)