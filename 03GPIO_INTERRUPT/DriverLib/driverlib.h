/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef __DRIVERLIB__H_
#define __DRIVERLIB__H_

/* Common Modules */
#include <driverlib/adc14.h>
#include <driverlib/aes256.h>
#include <driverlib/comp_e.h>
#include <driverlib/cpu.h>
#include <driverlib/crc32.h>
#include <driverlib/cs.h>
#include <driverlib/dma.h>
#include <driverlib/eusci.h>
#include <driverlib/fpu.h>
#include <driverlib/gpio.h>
#include <driverlib/i2c.h>
#include <driverlib/interrupt.h>
#include <driverlib/mpu.h>
#include <driverlib/pcm.h>
#include <driverlib/pmap.h>
#include <driverlib/pss.h>
#include <driverlib/ref_a.h>
#include <driverlib/reset.h>
#include <driverlib/rom.h>
#include <driverlib/rom_map.h>
#include <driverlib/rtc_c.h>
#include <driverlib/spi.h>
#include <driverlib/systick.h>
#include <driverlib/timer32.h>
#include <driverlib/timer_a.h>
#include <driverlib/uart.h>
#include <driverlib/wdt_a.h>

/* Device specific modules */
#if defined(__MCU_HAS_SYSCTL_A__)
#include <driverlib/sysctl_a.h>
#endif

#if defined(__MCU_HAS_SYSCTL__)
#include <driverlib/sysctl.h>
#endif

#if defined(__MCU_HAS_FLCTL_A__)
#include <driverlib/flash_a.h>
#endif

#if defined(__MCU_HAS_FLCTL__)
#include <driverlib/flash.h>
#endif

#if defined(__MCU_HAS_LCD_F__)
#include <driverlib/lcd_f.h>
#endif

/* Offset Definitions */
#define HWREG8(x)         (*((volatile uint8_t *)(x)))
#define HWREG16(x)        (*((volatile uint16_t *)(x)))
#define HWREG32(x)        (*((volatile uint32_t *)(x)))
#define HWREG(x)          (HWREG16(x))
#define HWREG8_L(x)       (*((volatile uint8_t *)((uint8_t *)&x)))
#define HWREG8_H(x)       (*((volatile uint8_t *)(((uint8_t *)&x)+1)))
#define HWREG16_L(x)      (*((volatile uint16_t *)((uint16_t *)&x)))
#define HWREG16_H(x)      (*((volatile uint16_t *)(((uint16_t *)&x)+1)))


#endif
