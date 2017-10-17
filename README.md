# M200Toolchain
Toolchain updates for building Marlin for the Malyan M200 boards

These are toolchain chainges (board definitions and a minor script update) for building Marlin for the Malyan M200 boards.
Copy the variant to the STM32duino variants directory, the board json file to platformio's boards directory, and update 
your stm32duino.py with this and you should be able to build firmware for the M200 V1 (but probably not V2 yet, and definitely not delta).
