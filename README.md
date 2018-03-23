# M200Toolchain
Toolchain updates for building Marlin for the Malyan M200 boards

These are toolchain changes (board definitions) for building Marlin for the Malyan M200 boards.
Copy the variant to the STM32duino variants directory, the board json file to platformio's boards directory.


If you are running the most up to date Platformio Builder code, and you get a "arduino.h" not found error, this is likely due to them breaking variant board builds again.

Earlier versions of platformio should be able to build firmware for the M200 V1 and early V2s.
I do not have a late run V2 or a delta, though I suspect this should work on them as well.
