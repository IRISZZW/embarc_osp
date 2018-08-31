/* ------------------------------------------
 * Copyright (c) 2018, Synopsys, Inc. All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:

 * 1) Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.

 * 2) Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.

 * 3) Neither the name of the Synopsys, Inc., nor the names of its contributors may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
--------------------------------------------- */
#ifndef _MUX_H_
#define _MUX_H_

#include "embARC_toolchain.h"

#define MUX_SEL0_OFFSET		(0)
#define MUX_SEL1_OFFSET		(4)
#define MUX_SEL2_OFFSET		(8)
#define MUX_SEL3_OFFSET		(12)
#define MUX_SEL4_OFFSET		(16)
#define MUX_SEL5_OFFSET		(20)
#define MUX_SEL6_OFFSET		(24)
#define MUX_SEL7_OFFSET		(28)

#define MUX_SEL0_MASK		(0xf << MUX_SEL0_OFFSET)
#define MUX_SEL1_MASK		(0xf << MUX_SEL1_OFFSET)
#define MUX_SEL2_MASK		(0xf << MUX_SEL2_OFFSET)
#define MUX_SEL3_MASK		(0xf << MUX_SEL3_OFFSET)
#define MUX_SEL4_MASK		(0xf << MUX_SEL4_OFFSET)
#define MUX_SEL5_MASK		(0xf << MUX_SEL5_OFFSET)
#define MUX_SEL6_MASK		(0xf << MUX_SEL6_OFFSET)
#define MUX_SEL7_MASK		(0xf << MUX_SEL7_OFFSET)

/**
 * Default pin muxer settings
 */
#define PMOD_MUX_CTRL_DEFAULT		(0)		/*!< all pins are configured as GPIO inputs */
#define ARDUINO_MUX_CTRL_DEFAULT	(0)		/*!< normal Arduino mode */
#define GENERIC_MUX_CTRL_DEFAULT	(0)		/*!< Default generic mux mode */

/**
 * PMOD A Multiplexor
 */
#define PM_A_CFG1_GPIO		((0)<< MUX_SEL0_OFFSET)
#define PM_A_CFG1_I2C		((1)<< MUX_SEL0_OFFSET)
#define PM_A_CFG1_SPI		((2)<< MUX_SEL0_OFFSET)
#define PM_A_CFG1_UART1a	((3)<< MUX_SEL0_OFFSET)
#define PM_A_CFG1_UART1b	((4)<< MUX_SEL0_OFFSET)
#define PM_A_CFG1_PWM1		((5)<< MUX_SEL0_OFFSET)
#define PM_A_CFG1_PWM2		((6)<< MUX_SEL0_OFFSET)

#define PM_A_CFG2_GPIO		((0)<< MUX_SEL1_OFFSET)


/**
 * PMOD B Multiplexor
 */
#define PM_B_CFG1_GPIO		((0)<< MUX_SEL2_OFFSET)
#define PM_B_CFG1_I2C		((1)<< MUX_SEL2_OFFSET)
#define PM_B_CFG1_SPI		((2)<< MUX_SEL2_OFFSET)
#define PM_B_CFG1_UART2a	((3)<< MUX_SEL2_OFFSET)
#define PM_B_CFG1_UART2b	((4)<< MUX_SEL2_OFFSET)
#define PM_B_CFG1_PWM1		((5)<< MUX_SEL2_OFFSET)
#define PM_B_CFG1_PWM2		((6)<< MUX_SEL2_OFFSET)

#define PM_B_CFG2_GPIO		((0)<< MUX_SEL3_OFFSET)


/**
 * PMOD C Multiplexor
 */
#define PM_C_CFG1_GPIO		((0)<< MUX_SEL4_OFFSET)
#define PM_C_CFG1_I2C		((1)<< MUX_SEL4_OFFSET)
#define PM_C_CFG1_SPI		((2)<< MUX_SEL4_OFFSET)
#define PM_C_CFG1_UART3a	((3)<< MUX_SEL4_OFFSET)
#define PM_C_CFG1_UART3b	((4)<< MUX_SEL4_OFFSET)
#define PM_C_CFG1_PWM1		((5)<< MUX_SEL4_OFFSET)
#define PM_C_CFG1_PWM2		((6)<< MUX_SEL4_OFFSET)

#define PM_C_CFG2_GPIO		((0)<< MUX_SEL5_OFFSET)


typedef volatile uint32_t MUX_REG;

#ifdef __cplusplus
extern "C" {
#endif

extern void set_pmod_mux(uint32_t val);
extern uint32_t get_pmod_mux(void);
extern void set_arduino_mux(uint32_t val);
extern uint32_t get_arduino_mux(void);
extern void set_generic_mux(uint32_t val);
extern uint32_t get_generic_mux(void);

#ifdef __cplusplus
}
#endif

#endif /* _MUX_H_ */
