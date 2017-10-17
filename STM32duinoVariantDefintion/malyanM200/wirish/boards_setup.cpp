/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2012 LeafLabs, LLC.
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
 * @file wirish/stm32f1/boards_setup.cpp
 * @author Marti Bolivar <mbolivar@leaflabs.com>
 * @brief STM32F1 chip setup.
 *
 * This file controls how init() behaves on the STM32F1. Be very
 * careful when changing anything here. Many of these values depend
 * upon each other.
 */

#include "boards_private.h"

#include <libmaple/gpio.h>
#include <libmaple/timer.h>

#include <boards.h>
#include <usb_serial.h>

// Allow boards to provide a PLL multiplier. This is useful for
// e.g. STM32F100 value line MCUs, which use slower multipliers.
// (We're leaving the default to RCC_PLLMUL_9 for now, since that
// works for F103 performance line MCUs, which is all that LeafLabs
// currently officially supports).
#ifndef BOARD_RCC_PLLMUL
  #if F_CPU==72000000
	#define BOARD_RCC_PLLMUL RCC_PLLMUL_9
  #elif F_CPU==48000000
	#define BOARD_RCC_PLLMUL RCC_PLLMUL_6
  #endif
#endif

namespace wirish {
    namespace priv {

        static stm32f1_rcc_pll_data pll_data = {BOARD_RCC_PLLMUL};
        __weak rcc_pll_cfg w_board_pll_cfg = {RCC_PLLSRC_HSE, &pll_data};
        __weak adc_prescaler w_adc_pre = ADC_PRE_PCLK2_DIV_6;
        __weak adc_smp_rate w_adc_smp = ADC_SMPR_55_5;

        __weak void board_reset_pll(void) {
            // TODO
        }

        __weak void board_setup_clock_prescalers(void) {
            rcc_set_prescaler(RCC_PRESCALER_AHB, RCC_AHB_SYSCLK_DIV_1);
            rcc_set_prescaler(RCC_PRESCALER_APB1, RCC_APB1_HCLK_DIV_2);
            rcc_set_prescaler(RCC_PRESCALER_APB2, RCC_APB2_HCLK_DIV_1);
			rcc_clk_disable(RCC_USB);
			#if F_CPU == 72000000
			rcc_set_prescaler(RCC_PRESCALER_USB, RCC_USB_SYSCLK_DIV_1_5);
			#elif F_CPU == 48000000
			rcc_set_prescaler(RCC_PRESCALER_USB, RCC_USB_SYSCLK_DIV_1);
			#endif
        }

        __weak void board_setup_gpio(void) {
            gpio_init_all();
        }

        __weak void board_setup_usb(void) {
#ifdef SERIAL_USB

      // On the Malyan board, PB9 a transistor which pulls up USB, normally off.
      // It must be set to high long enough for the host to recognize, or USB doesn't
      // work. In theory, the usb code will do this with the discovery bit, but PB9
      // needs to be returned to high after signaling the connect. We need a task
      // that runs when not connected to toggle this every so often.
			//Reset the USB interface on generic boards - developed by Victor PV
			gpio_set_mode(PIN_MAP[PB9].gpio_device, PIN_MAP[PB9].gpio_bit, GPIO_OUTPUT_PP);
      gpio_write_bit(PIN_MAP[PB9].gpio_device, PIN_MAP[PB9].gpio_bit,1);
      for(volatile unsigned int i=0;i<1024;i++);// Leave this high long enough for the host to notice

			gpio_write_bit(PIN_MAP[PB9].gpio_device, PIN_MAP[PB9].gpio_bit,0);
			for(volatile unsigned int i=0;i<512;i++);// Only small delay seems to be needed, and USB pins will get configured in Serial.begin
      // and return to high so USB works.
      gpio_write_bit(PIN_MAP[PB9].gpio_device, PIN_MAP[PB9].gpio_bit,1);

			Serial.begin();// Roger Clark. Changed SerialUSB to Serial for Arduino sketch compatibility
#endif
		}

        __weak void series_init(void) {
            // Initialize AFIO here, too, so peripheral remaps and external
            // interrupts work out of the box.
            afio_init();
        }

    }
}
