/********************************************************************************************************
 * @file	app_config.h
 *
 * @brief	for TLSR chips
 *
 * @author	BLE GROUP
 * @date	2020.06
 *
 * @par     Copyright (c) 2020, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *          All rights reserved.
 *          
 *          Redistribution and use in source and binary forms, with or without
 *          modification, are permitted provided that the following conditions are met:
 *          
 *              1. Redistributions of source code must retain the above copyright
 *              notice, this list of conditions and the following disclaimer.
 *          
 *              2. Unless for usage inside a TELINK integrated circuit, redistributions 
 *              in binary form must reproduce the above copyright notice, this list of 
 *              conditions and the following disclaimer in the documentation and/or other
 *              materials provided with the distribution.
 *          
 *              3. Neither the name of TELINK, nor the names of its contributors may be 
 *              used to endorse or promote products derived from this software without 
 *              specific prior written permission.
 *          
 *              4. This software, with or without modification, must only be used with a
 *              TELINK integrated circuit. All other usages are subject to written permission
 *              from TELINK and different commercial license may apply.
 *
 *              5. Licensee shall be solely responsible for any claim to the extent arising out of or 
 *              relating to such deletion(s), modification(s) or alteration(s).
 *         
 *          THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *          ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *          WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *          DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY
 *          DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *          (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *          LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *          ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *          (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *          SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *         
 *******************************************************************************************************/
#pragma once



/////////////////// FEATURE SELECT /////////////////////////////////
/**
 *  @brief  Feature select in bLE Sample project
 */
#define BLE_APP_PM_ENABLE					1
#define PM_NO_SUSPEND_ENABLE				1
#define PM_DEEPSLEEP_RETENTION_ENABLE		1
#define TEST_CONN_CURRENT_ENABLE            0 //test connection current, disable UI to have a pure power
#define APP_SECURITY_ENABLE      			1




#if 1 //(SAMPLE_BOARD_SELECT == EVK_C1T139A30_V1P2)
	#if (TEST_CONN_CURRENT_ENABLE) //test current, disable keyboard
			#define	UI_KEYBOARD_ENABLE						0
	#else
			#define	UI_KEYBOARD_ENABLE						1
	#endif


	#if (UI_KEYBOARD_ENABLE)   // if test pure power, kyeScan GPIO setting all disabled
			//---------------  KeyMatrix PB2/PB3/PB4/PB5 -----------------------------
			#define	MATRIX_ROW_PULL					PM_PIN_PULLDOWN_100K
			#define	MATRIX_COL_PULL					PM_PIN_PULLUP_10K

			#define	KB_LINE_HIGH_VALID				0   //dirve pin output 0 when keyscan, scanpin read 0 is valid



			#define			CR_VOL_UP				0xf0  ////
			#define			CR_VOL_DN				0xf1


			/**
			 *  @brief  Normal keyboard map
			 */
			#define		KB_MAP_NORMAL	{	CR_VOL_DN,		VK_1,	 \
											CR_VOL_UP,		VK_2 }



			//////////////////// KEY CONFIG (EVK board) ///////////////////////////
			#define  KB_DRIVE_PINS  {GPIO_PC2, GPIO_PC0}
			#define  KB_SCAN_PINS   {GPIO_PC3, GPIO_PC1}

			//drive pin as gpio
			#define	PC2_FUNC				AS_GPIO
			#define	PC0_FUNC				AS_GPIO

			//drive pin need 100K pulldown
			#define	PULL_WAKEUP_SRC_PC2		MATRIX_ROW_PULL
			#define	PULL_WAKEUP_SRC_PC0		MATRIX_ROW_PULL

			//drive pin open input to read gpio wakeup level
			#define PC2_INPUT_ENABLE		1
			#define PC0_INPUT_ENABLE		1

			//scan pin as gpio
			#define	PC3_FUNC				AS_GPIO
			#define	PC1_FUNC				AS_GPIO

			//scan  pin need 10K pullup
			#define	PULL_WAKEUP_SRC_PC3		MATRIX_COL_PULL
			#define	PULL_WAKEUP_SRC_PC1		MATRIX_COL_PULL

			//scan pin open input to read gpio level
			#define PC3_INPUT_ENABLE		1
			#define PC1_INPUT_ENABLE		1



			#define		KB_MAP_NUM		KB_MAP_NORMAL
			#define		KB_MAP_FN		KB_MAP_NORMAL


	#endif
#define     UI_LED_ENABLE           1
#if UI_LED_ENABLE
	/**
	 *  @brief  Definition gpio for led
	 */
	#define	GPIO_LED_WHITE			GPIO_PB6
	#define	GPIO_LED_GREEN			GPIO_PB5
	#define	GPIO_LED_BLUE			GPIO_PB4
#if (HARDWARE_BOARD_SELECT == HW_C1T219A20_V1_0_64_EVB)
	#define GPIO_LED_RED			GPIO_PB7
#elif (HARDWARE_BOARD_SELECT == HW_C1T217A20_V1_0_48_EVB)
	#define GPIO_LED_RED			GPIO_PB2
#elif (HARDWARE_BOARD_SELECT == HW_C1T213A20_V1_0_80_EVB)
	#define GPIO_LED_RED			GPIO_PB7
#endif
	#define LED_ON_LEVAL 			1 		//gpio output high voltage to turn on led

	#define PB7_FUNC				AS_GPIO
	#define PB6_FUNC				AS_GPIO
	#define PB5_FUNC				AS_GPIO
	#define PB4_FUNC				AS_GPIO

	#define	PB7_OUTPUT_ENABLE		1
	#define	PB6_OUTPUT_ENABLE		1
	#define PB5_OUTPUT_ENABLE		1
	#define	PB4_OUTPUT_ENABLE		1
#endif
#elif (SAMPLE_BOARD_SELECT == DONGLE_C1T139A3_V2P0A)
	#undef  PM_DEEPSLEEP_RETENTION_ENABLE
	#define PM_DEEPSLEEP_RETENTION_ENABLE					0    //dongle demo no need deepSleepRetention

	#define	UI_BUTTON_ENABLE								1
	#define UI_LED_ENABLE									1

	#if (UI_BUTTON_ENABLE)
			//---------------  Button -------------------------------
			/**
			 *  @brief  Definition gpio for button detection
			 */
			#define	SW1_GPIO				GPIO_PD5
			#define	SW2_GPIO				GPIO_PD6
			#define PD5_FUNC				AS_GPIO
			#define PD6_FUNC				AS_GPIO
			#define PD5_INPUT_ENABLE		1
			#define PD6_INPUT_ENABLE		1
			#define PULL_WAKEUP_SRC_PD5     PM_PIN_PULLUP_10K
			#define PULL_WAKEUP_SRC_PD6     PM_PIN_PULLUP_10K
	#endif



	#if (UI_LED_ENABLE)
			/**
			 *  @brief  Definition gpio for led
			 */
			//---------------  LED ----------------------------------
			#define	GPIO_LED_RED			GPIO_PA3
			#define	GPIO_LED_WHITE			GPIO_PB1
			#define	GPIO_LED_GREEN			GPIO_PA2
			#define	GPIO_LED_BLUE			GPIO_PB0
			#define	GPIO_LED_YELLOW			GPIO_PA4

			#define PA3_FUNC				AS_GPIO
			#define PB1_FUNC				AS_GPIO
			#define PA2_FUNC				AS_GPIO
			#define PB0_FUNC				AS_GPIO
			#define PA4_FUNC				AS_GPIO

			#define	PA3_OUTPUT_ENABLE		1
			#define	PB1_OUTPUT_ENABLE		1
			#define PA2_OUTPUT_ENABLE		1
			#define	PB0_OUTPUT_ENABLE		1
			#define	PA4_OUTPUT_ENABLE		1

			#define LED_ON_LEVAL 			1 		//gpio output high voltage to turn on led
	#endif
#endif



#ifndef	UI_KEYBOARD_ENABLE
#define UI_KEYBOARD_ENABLE									0
#endif

#ifndef	UI_BUTTON_ENABLE
#define UI_BUTTON_ENABLE									0
#endif




/////////////////// DEEP SAVE FLG //////////////////////////////////
#define USED_DEEP_ANA_REG                   DEEP_ANA_REG1 //u8,can save 8 bit info when deep
#define CONN_DEEP_FLG	                    BIT(0) //if 1: conn deep, 0: adv deep






/////////////////// Clock  /////////////////////////////////
/**
 *  @brief  MCU system clock
 */
#define CLOCK_SYS_CLOCK_HZ  	16000000

/**
 *  @brief  Definition the number of system tick for 1s/1ms/1us
 */
enum{
	CLOCK_SYS_CLOCK_1S = CLOCK_SYS_CLOCK_HZ,
	CLOCK_SYS_CLOCK_1MS = (CLOCK_SYS_CLOCK_1S / 1000),
	CLOCK_SYS_CLOCK_1US = (CLOCK_SYS_CLOCK_1S / 1000000),
};



/////////////////// watchdog  //////////////////////////////
#define MODULE_WATCHDOG_ENABLE		0
#define WATCHDOG_INIT_TIMEOUT		500  //ms








/**
 *  @brief  Definition for gpio debug
 */
#define DEBUG_GPIO_ENABLE							0

#if(DEBUG_GPIO_ENABLE)


	#define GPIO_CHN0							GPIO_PE1
	#define GPIO_CHN1							GPIO_PE2
	#define GPIO_CHN2							GPIO_PA0
    #define GPIO_CHN3							GPIO_PA4
	#define GPIO_CHN4							GPIO_PA3
	#define GPIO_CHN5							GPIO_PB0
	#define GPIO_CHN6							GPIO_PB2
	#define GPIO_CHN7							GPIO_PE0

	#define GPIO_CHN8							GPIO_PA2
	#define GPIO_CHN9							GPIO_PA1
	#define GPIO_CHN10							GPIO_PB1
	#define GPIO_CHN11							GPIO_PB3



	#define PE1_OUTPUT_ENABLE					1
	#define PE2_OUTPUT_ENABLE					1
	#define PA0_OUTPUT_ENABLE					1
	#define PA4_OUTPUT_ENABLE					1
	#define PA3_OUTPUT_ENABLE					1
	#define PB0_OUTPUT_ENABLE					1
	#define PB2_OUTPUT_ENABLE					1
	#define PE0_OUTPUT_ENABLE					1

	#define PA2_OUTPUT_ENABLE					1
	#define PA1_OUTPUT_ENABLE					1
	#define PB1_OUTPUT_ENABLE					1
	#define PB3_OUTPUT_ENABLE					1


	#define DBG_CHN0_LOW		gpio_write(GPIO_CHN0, 0)
	#define DBG_CHN0_HIGH		gpio_write(GPIO_CHN0, 1)
	#define DBG_CHN0_TOGGLE		gpio_toggle(GPIO_CHN0)
	#define DBG_CHN1_LOW		gpio_write(GPIO_CHN1, 0)
	#define DBG_CHN1_HIGH		gpio_write(GPIO_CHN1, 1)
	#define DBG_CHN1_TOGGLE		gpio_toggle(GPIO_CHN1)
	#define DBG_CHN2_LOW		gpio_write(GPIO_CHN2, 0)
	#define DBG_CHN2_HIGH		gpio_write(GPIO_CHN2, 1)
	#define DBG_CHN2_TOGGLE		gpio_toggle(GPIO_CHN2)
	#define DBG_CHN3_LOW		gpio_write(GPIO_CHN3, 0)
	#define DBG_CHN3_HIGH		gpio_write(GPIO_CHN3, 1)
	#define DBG_CHN3_TOGGLE		gpio_toggle(GPIO_CHN3)
	#define DBG_CHN4_LOW		gpio_write(GPIO_CHN4, 0)
	#define DBG_CHN4_HIGH		gpio_write(GPIO_CHN4, 1)
	#define DBG_CHN4_TOGGLE		gpio_toggle(GPIO_CHN4)
	#define DBG_CHN5_LOW		gpio_write(GPIO_CHN5, 0)
	#define DBG_CHN5_HIGH		gpio_write(GPIO_CHN5, 1)
	#define DBG_CHN5_TOGGLE		gpio_toggle(GPIO_CHN5)
	#define DBG_CHN6_LOW		gpio_write(GPIO_CHN6, 0)
	#define DBG_CHN6_HIGH		gpio_write(GPIO_CHN6, 1)
	#define DBG_CHN6_TOGGLE		gpio_toggle(GPIO_CHN6)
	#define DBG_CHN7_LOW		gpio_write(GPIO_CHN7, 0)
	#define DBG_CHN7_HIGH		gpio_write(GPIO_CHN7, 1)
	#define DBG_CHN7_TOGGLE		gpio_toggle(GPIO_CHN7)
	#define DBG_CHN8_LOW		gpio_write(GPIO_CHN8, 0)
	#define DBG_CHN8_HIGH		gpio_write(GPIO_CHN8, 1)
	#define DBG_CHN8_TOGGLE		gpio_toggle(GPIO_CHN8)
	#define DBG_CHN9_LOW		gpio_write(GPIO_CHN9, 0)
	#define DBG_CHN9_HIGH		gpio_write(GPIO_CHN9, 1)
	#define DBG_CHN9_TOGGLE		gpio_toggle(GPIO_CHN9)
	#define DBG_CHN10_LOW		gpio_write(GPIO_CHN10, 0)
	#define DBG_CHN10_HIGH		gpio_write(GPIO_CHN10, 1)
	#define DBG_CHN10_TOGGLE	gpio_toggle(GPIO_CHN10)
	#define DBG_CHN11_LOW		gpio_write(GPIO_CHN11, 0)
	#define DBG_CHN11_HIGH		gpio_write(GPIO_CHN11, 1)
	#define DBG_CHN11_TOGGLE	gpio_toggle(GPIO_CHN11)
#else
	#define DBG_CHN0_LOW
	#define DBG_CHN0_HIGH
	#define DBG_CHN0_TOGGLE
	#define DBG_CHN1_LOW
	#define DBG_CHN1_HIGH
	#define DBG_CHN1_TOGGLE
	#define DBG_CHN2_LOW
	#define DBG_CHN2_HIGH
	#define DBG_CHN2_TOGGLE
	#define DBG_CHN3_LOW
	#define DBG_CHN3_HIGH
	#define DBG_CHN3_TOGGLE
	#define DBG_CHN4_LOW
	#define DBG_CHN4_HIGH
	#define DBG_CHN4_TOGGLE
	#define DBG_CHN5_LOW
	#define DBG_CHN5_HIGH
	#define DBG_CHN5_TOGGLE
	#define DBG_CHN6_LOW
	#define DBG_CHN6_HIGH
	#define DBG_CHN6_TOGGLE
	#define DBG_CHN7_LOW
	#define DBG_CHN7_HIGH
	#define DBG_CHN7_TOGGLE
	#define DBG_CHN8_LOW
	#define DBG_CHN8_HIGH
	#define DBG_CHN8_TOGGLE
	#define DBG_CHN9_LOW
	#define DBG_CHN9_HIGH
	#define DBG_CHN9_TOGGLE
	#define DBG_CHN10_LOW
	#define DBG_CHN10_HIGH
	#define DBG_CHN10_TOGGLE
	#define DBG_CHN11_LOW
	#define DBG_CHN11_HIGH
	#define DBG_CHN11_TOGGLE
#endif  //end of DEBUG_GPIO_ENABLE



#include "../common/default_config.h"