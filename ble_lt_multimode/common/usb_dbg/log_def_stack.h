/********************************************************************************************************
 * @file	log_def_stack.h
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
#ifndef	_LOG_DEF_STACK_H_
#define _LOG_DEF_STACK_H_

//	event: 0 for time stamp; 1 reserved; eid2 - eid31
#define			SLEV_timestamp				0
#define			SLEV_reserved				1
#define			SLEV_slot					2
#define			SLEV_btrx					3
#define			SLEV_set_clkn_fcnt   		4
#define			SLEV_rx_lmp   				5
#define			SLEV_rx_acl   				6
#define			SLEV_tx_tgl					7
#define			SLEV_host_conn_req			8
#define			SLEV_set_em					9
#define			SLEV_rx_end					10
#define			SLEV_tx_lmp					11
#define			SLEV_tx_acl					12
#define			SLEV_tx_lmp_full			13
#define			SLEV_tx_acl_full			14
#define			SLEV_tx_hci_full			15
#define			SLEV_sniff_slot_start		16
#define			SLEV_sniff_sub_slot_update	17
#define			SLEV_sniff_sub_start		18
#define			SLEV_sniff_transition		19
#define			SLEV_name_req				20
#define			SLEV_inq_timeout			21
#define			SLEV_page_timeout			22
#define			SLEV_pageresp_timeout		23
#define			SLEV_newconnect_timeout		24

// 1-bit data: 0/1 for hardware signal: PA4/PB1; bid2 - bid31
#define			SL01_TX_PA4					0
#define			SL01_RXSYNC_PB1				1
#define			SL01_ac_inq					2
#define			SL01_ac_inq_scan			3
#define			SL01_ac_page				4
#define			SL01_ac_page_scan			5
#define			SL01_ac_m_connect			6
#define			SL01_ac_s_connect			7

#define			SL01_task_system_tick   	8
#define			SL01_task_rx   				9
#define			SL01_tx_tgl_level   		10
#define			SL01_task_bt_ll_main   		11
#define			SL01_task_test   			12
#define			SL01_detach_timeout			13
// 8-bit data: cid0 - cid63
#define			SL08_ac_state				0
#define			SL08_state_pending_slot		1
#define			SL08_rx_lmp_code			2
#define			SL08_rx_poll_fcnt			3
#define			SL08_rx_poll_offset			4
#define			SL08_rx_poll_rxbit			5
#define			SL08_lmp_esc4				6
#define			SL08_acl_tx_type    		7

#define			SL08_hci_wptr    			8
#define			SL08_hci_rptr    			9
#define			SL08_valid_range			10
// 16-bit data: sid0 - sid63
#define			SL16_CLKN					0
#define			SL16_FCNT					1
#define			SL16_MCLK					2
#define			SL16_MCLKP					3
#define			SL16_RXBIT					4
#define			SL16_RxStat					5
#define			SL16_LNKCNTL				6
#define			SL16_acl_tx_size			7
#define			SL16_rx_acl_cid				8
#define			SL16_sniff_slot				9
#define			SL16_sniff_win				10
#define			SL16_sub_instant			11
#endif
