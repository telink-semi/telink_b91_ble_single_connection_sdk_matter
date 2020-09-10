/********************************************************************************************************
 * @file	timer_reg.h
 *
 * @brief	This is the header file for B91
 *
 * @author	Ble Group
 * @date	2019
 *
 * @par		Copyright (c) 2019, Telink Semiconductor (Shanghai) Co., Ltd.
 *			All rights reserved.
 *
 *			The information contained herein is confidential property of Telink
 *          Semiconductor (Shanghai) Co., Ltd. and is available under the terms
 *          of Commercial License Agreement between Telink Semiconductor (Shanghai)
 *          Co., Ltd. and the licensee or the terms described here-in. This heading
 *          MUST NOT be removed from this file.
 *
 *          Licensee shall not delete, modify or alter (or permit any third party to delete, modify, or  
 *          alter) any information contained herein in whole or in part except as expressly authorized  
 *          by Telink semiconductor (shanghai) Co., Ltd. Otherwise, licensee shall be solely responsible  
 *          for any claim to the extent arising out of or relating to such deletion(s), modification(s)  
 *          or alteration(s).
 *
 *          Licensees are granted free, non-transferable use of the information in this
 *          file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided.
 *
 *******************************************************************************************************/
#ifndef TIMER_REG_H
#define TIMER_REG_H
#include "../sys.h"
#include "../../../common/bit.h"
/*******************************      timer registers: 0x140140     ******************************/
#define reg_tmr_ctrl0			REG_ADDR8(0x140140)
#define reg_tmr_ctrl16			REG_ADDR16(0x140140)
#define reg_tmr_ctrl32			REG_ADDR32(0x140140)
enum{
	FLD_TMR0_MODE =				BIT_RNG(0,1),
	FLD_TMR0_EN =				BIT(2),
	FLD_TMR0_NOWRAP = 			BIT(3),
	FLD_TMR1_MODE =				BIT_RNG(4,5),
	FLD_TMR1_EN =				BIT(6),
	FLD_TMR1_NOWRAP  = 			BIT(7),
};

#define reg_tmr_ctrl2			REG_ADDR8(0x140142)

enum{
	FLD_TMR_WD_EN =				BIT(7),
};

#define reg_tmr_sta				REG_ADDR8(0x140143)
enum{
	FLD_TMR_STA_TMR0   =		BIT(0),
	FLD_TMR_STA_TMR1   =		BIT(1),
	FLD_TMR_STA_WD     =		BIT(2),
	FLD_TMR_WD_CNT_CLR =		BIT(3),

	FLD_TMR_SW_IRQ     =		BIT(7),
};

#define  reg_tmr0_capt          REG_ADDR32(0x140144)
#define  reg_tmr1_capt          REG_ADDR32(0x140148)
#define  reg_tmr_capt(i)		REG_ADDR32(0x140144 + ((i) << 2))

#define  reg_wt_target0         REG_ADDR8(0x14014c)// always is 0x00
#define  reg_wt_target1         REG_ADDR8(0x14014d)
#define  reg_wt_target2         REG_ADDR8(0x14014e)
#define  reg_wt_target3         REG_ADDR8(0x14014f)
#define  reg_wt_target          REG_ADDR32(0x14014c)


#define reg_tmr0_tick			REG_ADDR32(0X140150)
#define reg_tmr1_tick			REG_ADDR32(0X140154)
#define reg_tmr_tick(i)			REG_ADDR32(0X140150 + ((i) << 2))

/*******************************      BLE Stack Use     ******************************/
#define	    sys_tick_per_us   				16
#define		CLOCK_SYS_CLOCK_1250US			(1250 * sys_tick_per_us)

#endif
