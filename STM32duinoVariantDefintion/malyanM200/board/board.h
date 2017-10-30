/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file   wirish/boards/maple_mini/include/board/board.h
 * @author Marti Bolivar <mbolivar@leaflabs.com>
 * @brief  Maple Mini board header.
 *
 * See wirish/boards/maple/include/board/board.h for more information
 * on these definitions.
 */

#ifndef _BOARD_GENERIC_STM32F103C_H_
#define _BOARD_GENERIC_STM32F103C_H_

#undef CYCLES_PER_MICROSECOND
#define CYCLES_PER_MICROSECOND	(F_CPU / 1000000U)
#define SYSTICK_RELOAD_VAL     (F_CPU/1000) - 1 /* takes a cycle to reload */

#define BOARD_NR_USARTS           3
#define BOARD_USART1_TX_PIN       PA9
#define BOARD_USART1_RX_PIN       PA10
#define BOARD_USART2_TX_PIN       PA2
#define BOARD_USART2_RX_PIN       PA3
#define BOARD_USART3_TX_PIN       PB10
#define BOARD_USART3_RX_PIN       PB11

#define BOARD_NR_SPI              2
#define BOARD_SPI1_NSS_PIN        PA4
#define BOARD_SPI1_MOSI_PIN       PA7
#define BOARD_SPI1_MISO_PIN       PA6
#define BOARD_SPI1_SCK_PIN        PA5

#define BOARD_SPI2_NSS_PIN        PB12
#define BOARD_SPI2_MOSI_PIN       PB15
#define BOARD_SPI2_MISO_PIN       PB14
#define BOARD_SPI2_SCK_PIN        PB13

#define BOARD_NR_GPIO_PINS        35
#define BOARD_NR_PWM_PINS         12
#define BOARD_NR_ADC_PINS          9
#define BOARD_NR_USED_PINS         4


#define BOARD_JTMS_SWDIO_PIN      22
#define BOARD_JTCK_SWCLK_PIN      21
#define BOARD_JTDI_PIN            20
#define BOARD_JTDO_PIN            19
#define BOARD_NJTRST_PIN          18

// I don't currently believe there is a discovery pin
#define BOARD_USB_DISC_DEV        NULL
#define BOARD_USB_DISC_BIT        0

#define LED_BUILTIN PC13

#ifdef ENUM_PINS
// Note this needs to match with the PIN_MAP array in board.cpp
enum {
    PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13,PA14,PA15,
	PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13,PB14,PB15,
	PC13, PC14,PC15
};
#else
#define PA0   0
#define PA1   1
#define PA2   2
#define PA3   3
#define PA4   4
#define PA5   5
#define PA6   6
#define PA7   7
#define PA8   8
#define PA9   9
#define PA10 10
#define PA11 11
#define PA12 12
#define PA13 13
#define PA14 14
#define PA15 15
#define PB0  16
#define PB1  17
#define PB2  18
#define PB3  19
#define PB4  20
#define PB5  21
#define PB6  22
#define PB7  23
#define PB8  24
#define PB9  25
#define PB10 26
#define PB11 27
#define PB12 28
#define PB13 29
#define PB14 30
#define PB15 31
#define PC13 32
#define PC14 33
#define PC15 34
#endif

#endif
