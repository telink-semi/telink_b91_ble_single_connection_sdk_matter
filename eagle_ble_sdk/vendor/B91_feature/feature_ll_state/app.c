/********************************************************************************************************
 * @file	app.c
 *
 * @brief	This is the source file for BLE SDK
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
#include "tl_common.h"
#include "drivers.h"
#include "stack/ble/ble.h"

#include "app_config.h"
#include "app.h"
#include "app_buffer.h"
#include "application/keyboard/keyboard.h"
#include "application/usbstd/usbkeycode.h"
#include "../default_att.h"

#if (FEATURE_TEST_MODE == TEST_ADVERTISING_ONLY || FEATURE_TEST_MODE == TEST_SCANNING_ONLY || FEATURE_TEST_MODE == TEST_ADVERTISING_IN_CONN_SLAVE_ROLE || \
	FEATURE_TEST_MODE == TEST_SCANNING_IN_ADV_AND_CONN_SLAVE_ROLE || FEATURE_TEST_MODE == TEST_ADVERTISING_SCANNING_IN_CONN_SLAVE_ROLE)


#define		MY_RF_POWER_INDEX					RF_POWER_INDEX_P2p79dBm



_attribute_data_retention_	int device_in_connection_state;

_attribute_data_retention_	u32 advertise_begin_tick;

_attribute_data_retention_	u32	interval_update_tick;

_attribute_data_retention_	u8	sendTerminate_before_enterDeep = 0;

_attribute_data_retention_	u32	latest_user_event_tick;






/**
 * @brief      callback function of LinkLayer Event "BLT_EV_FLAG_SUSPEND_ENTER"
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
_attribute_ram_code_ void  ble_remote_set_sleep_wakeup (u8 e, u8 *p, int n)
{
	if( blc_ll_getCurrentState() == BLS_LINK_STATE_CONN && ((u32)(bls_pm_getSystemWakeupTick() - clock_time())) > 80 * SYSTEM_TIMER_TICK_1MS){  //suspend time > 30ms.add gpio wakeup
		bls_pm_setWakeupSource(PM_WAKEUP_PAD);  //gpio pad wakeup suspend/deepsleep
	}
}







/**
 * @brief      callback function of LinkLayer Event "BLT_EV_FLAG_CONNECT"
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
void	task_connect (u8 e, u8 *p, int n)
{
	//bls_l2cap_requestConnParamUpdate (8, 8, 99, 400);  // 1 S

	latest_user_event_tick = clock_time();

	device_in_connection_state = 1;//

	interval_update_tick = clock_time() | 1; //none zero


#if (UI_LED_ENABLE)
	gpio_write(GPIO_LED_RED, LED_ON_LEVAL);  //yellow light on
#endif
}



/**
 * @brief      callback function of LinkLayer Event "BLT_EV_FLAG_TERMINATE"
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
void 	task_terminate(u8 e,u8 *p, int n) //*p is terminate reason
{
	device_in_connection_state = 0;


	if(*p == HCI_ERR_CONN_TIMEOUT){

	}
	else if(*p == HCI_ERR_REMOTE_USER_TERM_CONN){  //0x13

	}
	else if(*p == HCI_ERR_CONN_TERM_MIC_FAILURE){

	}
	else{

	}


#if (UI_LED_ENABLE)
	gpio_write(GPIO_LED_RED, !LED_ON_LEVAL);  //yellow light off
#endif

	advertise_begin_tick = clock_time();

}



/**
 * @brief      callback function of LinkLayer Event "BLT_EV_FLAG_SUSPEND_EXIT"
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
_attribute_ram_code_ void	user_set_rf_power (u8 e, u8 *p, int n)
{
	rf_set_power_level_index (MY_RF_POWER_INDEX);
}





/**
 * @brief      power management code for application
 * @param	   none
 * @return     none
 */
_attribute_ram_code_
void blt_pm_proc(void)
{

#if(BLE_APP_PM_ENABLE)
	#if (PM_DEEPSLEEP_RETENTION_ENABLE)
		bls_pm_setSuspendMask (SUSPEND_ADV | DEEPSLEEP_RETENTION_ADV | SUSPEND_CONN | DEEPSLEEP_RETENTION_CONN);
	#else
		bls_pm_setSuspendMask (SUSPEND_ADV | SUSPEND_CONN);
	#endif

#endif  //end of BLE_APP_PM_ENABLE
}





#if (FEATURE_TEST_MODE == TEST_SCANNING_ONLY || FEATURE_TEST_MODE == TEST_SCANNING_IN_ADV_AND_CONN_SLAVE_ROLE \
	  || FEATURE_TEST_MODE == TEST_ADVERTISING_SCANNING_IN_CONN_SLAVE_ROLE )
//////////////////////////////////////////////////////////
// event call back
//////////////////////////////////////////////////////////
#define DBG_ADV_REPORT_ON_RAM 				0
#if (DBG_ADV_REPORT_ON_RAM)  //debug adv report on ram
	#define  RAM_ADV_MAX		64
	u8 AA_advRpt[RAM_ADV_MAX][48];
	u8 AA_advRpt_index = 0;
#endif

/**
 * @brief      callback function of HCI Controller Event
 * @param[in]  h - HCI Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
int controller_event_callback (u32 h, u8 *p, int n)
{
	if (h &HCI_FLAG_EVENT_BT_STD)		//ble controller hci event
	{
		u8 evtCode = h & 0xff;

		if(evtCode == HCI_EVT_LE_META)
		{
			u8 subEvt_code = p[0];
			if (subEvt_code == HCI_SUB_EVT_LE_ADVERTISING_REPORT)	// ADV packet
			{
				//after controller is set to scan state, it will report all the adv packet it received by this event

				event_adv_report_t *pa = (event_adv_report_t *)p;
				s8 rssi = (s8)pa->data[pa->len];//rssi has already plus 110.
				printf("LE advertising report (rssi:%ddb, len:%d):\n", rssi, pa->len+11);
				array_printf(p, (pa->len + 11));

				#if (DBG_ADV_REPORT_ON_RAM)
					if(pa->len > 31){
						pa->len = 31;
					}
					memcpy( (u8 *)AA_advRpt[AA_advRpt_index++],  p, pa->len + 11);
					if(AA_advRpt_index >= RAM_ADV_MAX){
						AA_advRpt_index = 0;
					}
				#endif
			}
		}
	}
return 0;
}

#endif


/**
 * @brief		user initialization when MCU power on or wake_up from deepSleep mode
 * @param[in]	none
 * @return      none
 */
_attribute_no_inline_ void user_init_normal(void)
{
	/* random number generator must be initiated here( in the beginning of user_init_nromal).
	 * When deepSleep retention wakeUp, no need initialize again */
	random_generator_init();  //this is must



//////////////////////////// BLE stack Initialization  Begin //////////////////////////////////
	/* for 1M   Flash, flash_sector_mac_address equals to 0xFF000
	 * for 2M   Flash, flash_sector_mac_address equals to 0x1FF000*/
	u8  mac_public[6];
	u8  mac_random_static[6];
	blc_initMacAddress(flash_sector_mac_address, mac_public, mac_random_static);

	//////////// Controller Initialization  Begin /////////////////////////
	blc_ll_initBasicMCU();                      //mandatory
	blc_ll_initStandby_module(mac_public);		//mandatory

#if (FEATURE_TEST_MODE == TEST_ADVERTISING_ONLY || FEATURE_TEST_MODE == TEST_ADVERTISING_IN_CONN_SLAVE_ROLE \
	|| FEATURE_TEST_MODE == TEST_SCANNING_IN_ADV_AND_CONN_SLAVE_ROLE || FEATURE_TEST_MODE == TEST_ADVERTISING_SCANNING_IN_CONN_SLAVE_ROLE)
	blc_ll_initAdvertising_module();
#endif

#if (FEATURE_TEST_MODE == TEST_SCANNING_ONLY || FEATURE_TEST_MODE == TEST_SCANNING_IN_ADV_AND_CONN_SLAVE_ROLE || FEATURE_TEST_MODE == TEST_ADVERTISING_SCANNING_IN_CONN_SLAVE_ROLE)
	blc_ll_initScanning_module();
#endif

#if(FEATURE_TEST_MODE == TEST_ADVERTISING_IN_CONN_SLAVE_ROLE || FEATURE_TEST_MODE == TEST_SCANNING_IN_ADV_AND_CONN_SLAVE_ROLE || FEATURE_TEST_MODE == TEST_ADVERTISING_SCANNING_IN_CONN_SLAVE_ROLE)
	blc_ll_initConnection_module();				//connection module  mandatory for BLE slave/master

	blc_ll_setAclConnMaxOctetsNumber(ACL_CONN_MAX_RX_OCTETS, ACL_CONN_MAX_TX_OCTETS);

	blc_ll_initAclConnTxFifo(app_acl_txfifo, ACL_TX_FIFO_SIZE, ACL_TX_FIFO_NUM);
	blc_ll_initAclConnRxFifo(app_acl_rxfifo, ACL_RX_FIFO_SIZE, ACL_RX_FIFO_NUM);
#endif



	u8 check_status = blc_controller_check_appBufferInitialization();
	if(check_status != BLE_SUCCESS){
		/* here user should set some log to know which application buffer incorrect */
		write_log32(0x88880000 | check_status);
		while(1);
	}
	//////////// Controller Initialization  End /////////////////////////




	//////////// Host Initialization  Begin /////////////////////////
#if (FEATURE_TEST_MODE == TEST_ADVERTISING_ONLY)
	/**
	 * @brief	Adv Packet data
	 */
	u8 tbl_advData[] = {
		 0x08, 0x09, 't', 'e', 's', 't', 'a', 'd', 'v',
		 0x02, 0x01, 0x05,
		};

	/**
	 * @brief	Scan Response Packet data
	 */
	u8	tbl_scanRsp [] = {
			 0x08, 0x09, 'T', 'E', 'S', 'T', 'A', 'D', 'V',	//scan name
		};
	bls_ll_setAdvData( (u8 *)tbl_advData, sizeof(tbl_advData) );
	bls_ll_setScanRspData( (u8 *)tbl_scanRsp, sizeof(tbl_scanRsp));

	u8 status = bls_ll_setAdvParam( ADV_INTERVAL_100MS, ADV_INTERVAL_100MS, \
									ADV_TYPE_NONCONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC, \
									 0,  NULL,  BLT_ENABLE_ADV_ALL, ADV_FP_NONE);


	if(status != BLE_SUCCESS){  //adv setting err
		while(1);
	}

	blc_ll_setAdvCustomedChannel(37, 38, 39);
	bls_ll_setAdvEnable(1);  //adv enable

#elif (FEATURE_TEST_MODE == TEST_SCANNING_ONLY)
	blc_hci_le_setEventMask_cmd(HCI_LE_EVT_MASK_ADVERTISING_REPORT);
	blc_hci_registerControllerEventHandler(controller_event_callback);


	////// set scan parameter and scan enable /////
	#if 1  //report all adv
		blc_ll_setScanParameter(SCAN_TYPE_PASSIVE, SCAN_INTERVAL_90MS, SCAN_INTERVAL_90MS,
							  	  OWN_ADDRESS_PUBLIC, SCAN_FP_ALLOW_ADV_ANY);
	#else //report adv only in whitelist
		ll_whiteList_reset();
		u8 test_adv[6] = {0x33, 0x33, 0x33, 0x33, 0x33, 0x33};
		ll_whiteList_add(BLE_ADDR_PUBLIC, test_adv);
		blc_ll_setScanParameter(SCAN_TYPE_PASSIVE, SCAN_INTERVAL_90MS, SCAN_INTERVAL_90MS,
							  	  OWN_ADDRESS_PUBLIC, SCAN_FP_ALLOW_ADV_WL);
	#endif

	blc_ll_setScanEnable (BLC_SCAN_ENABLE, DUP_FILTER_DISABLE);

#elif (FEATURE_TEST_MODE == TEST_ADVERTISING_IN_CONN_SLAVE_ROLE)
	////// Host Initialization  //////////
	blc_gap_peripheral_init();    //gap initialization
	extern void my_att_init ();
	my_att_init (); //gatt initialization
	blc_l2cap_register_handler (blc_l2cap_packet_receive);  	//l2cap initialization
	blc_smp_peripheral_init();									//smp initialization

///////////////////// USER application initialization ///////////////////
	/**
	 * @brief	Adv Packet data
	 */
	u8 tbl_advData[] = {
		 0x09, 0x09, 's', 'l', 'a', 'v', 'e', 'a', 'd', 'v',
		 0x02, 0x01, 0x05,
		};

	/**
	 * @brief	Scan Response Packet data
	 */
	u8	tbl_scanRsp [] = {
			 0x09, 0x09, 'S', 'L', 'A', 'V', 'E', 'A', 'D', 'V',
		};
	bls_ll_setAdvData( (u8 *)tbl_advData, sizeof(tbl_advData) );
	bls_ll_setScanRspData( (u8 *)tbl_scanRsp, sizeof(tbl_scanRsp));

	u8 status = bls_ll_setAdvParam( ADV_INTERVAL_30MS, ADV_INTERVAL_30MS, \
									 ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC, \
									 0,  NULL,  BLT_ENABLE_ADV_37, ADV_FP_NONE);
	if(status != BLE_SUCCESS){  //adv setting err
		while(1);
	}


	bls_ll_setAdvEnable(1);  //adv enable


	//add advertising in connection slave role
	/**
	 * @brief	Adv test Packet data
	 */
	u8 tbl_advData_test[] = {
		 0x09, 0x09, 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
		 0x02, 0x01, 0x05,
		};

	/**
	 * @brief	Scan Response test Packet data
	 */
	u8	tbl_scanRsp_test [] = {
			 0x09, 0x09, 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
		};
	blc_ll_addAdvertisingInConnSlaveRole();  //adv in conn slave role
	blc_ll_setAdvParamInConnSlaveRole(  (u8 *)tbl_advData_test, sizeof(tbl_advData_test), \
										(u8 *)tbl_scanRsp_test, sizeof(tbl_scanRsp_test), \
										ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC, BLT_ENABLE_ADV_ALL, ADV_FP_NONE);

	//ble event call back
	bls_app_registerEventCallback (BLT_EV_FLAG_CONNECT, &task_connect);
	bls_app_registerEventCallback (BLT_EV_FLAG_TERMINATE, &task_terminate);

#elif (FEATURE_TEST_MODE == TEST_SCANNING_IN_ADV_AND_CONN_SLAVE_ROLE)
	////// Host Initialization  //////////
	blc_gap_peripheral_init();    //gap initialization
	extern void my_att_init ();
	my_att_init (); //gatt initialization
	blc_l2cap_register_handler (blc_l2cap_packet_receive);  	//l2cap initialization
	blc_smp_peripheral_init();									//smp initialization

///////////////////// USER application initialization ///////////////////
	/**
	 * @brief	Adv Packet data
	 */
	u8 tbl_advData[] = {
		 0x0A, 0x09, 's', 'l', 'a', 'v', 'e', 's', 'c', 'a', 'n',
		 0x02, 0x01, 0x05,
		};

	/**
	 * @brief	Scan Response Packet data
	 */
	u8	tbl_scanRsp [] = {
			 0x0A, 0x09, 'S', 'L', 'A', 'V', 'E', 'S', 'C', 'A','N'
		};
	bls_ll_setAdvData( (u8 *)tbl_advData, sizeof(tbl_advData) );
	bls_ll_setScanRspData( (u8 *)tbl_scanRsp, sizeof(tbl_scanRsp));

	u8 status = bls_ll_setAdvParam( ADV_INTERVAL_30MS, ADV_INTERVAL_30MS, \
									 ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC, \
									 0,  NULL,  BLT_ENABLE_ADV_37, ADV_FP_NONE);
	if(status != BLE_SUCCESS){  //adv setting err
		while(1);
	}


	bls_ll_setAdvEnable(1);  //adv enable



	//scan setting
	blc_ll_initScanning_module();
	blc_hci_le_setEventMask_cmd(HCI_LE_EVT_MASK_ADVERTISING_REPORT);
	blc_hci_registerControllerEventHandler(controller_event_callback);

	#if 1  //report all adv
		blc_ll_setScanParameter(SCAN_TYPE_PASSIVE, SCAN_INTERVAL_100MS, SCAN_INTERVAL_100MS,
								  OWN_ADDRESS_PUBLIC, SCAN_FP_ALLOW_ADV_ANY);
	#else //report adv only in whitelist
		ll_whiteList_reset();
		u8 test_adv[6] = {0x33, 0x33, 0x33, 0x33, 0x33, 0x33};
		ll_whiteList_add(BLE_ADDR_PUBLIC, test_adv);
		blc_ll_setScanParameter(SCAN_TYPE_PASSIVE, SCAN_INTERVAL_100MS, SCAN_INTERVAL_100MS,
								  OWN_ADDRESS_PUBLIC, SCAN_FP_ALLOW_ADV_WL);

	#endif

	blc_ll_addScanningInAdvState();  //add scan in adv state
	blc_ll_addScanningInConnSlaveRole();  //add scan in conn slave role




	//ble event call back
	bls_app_registerEventCallback (BLT_EV_FLAG_CONNECT, &task_connect);
	bls_app_registerEventCallback (BLT_EV_FLAG_TERMINATE, &task_terminate);


#elif (FEATURE_TEST_MODE == TEST_ADVERTISING_SCANNING_IN_CONN_SLAVE_ROLE)
	////// Host Initialization  //////////
	blc_gap_peripheral_init();    //gap initialization
	extern void my_att_init ();
	my_att_init (); //gatt initialization
	blc_l2cap_register_handler (blc_l2cap_packet_receive);  	//l2cap initialization
	blc_smp_peripheral_init();									//smp initialization

///////////////////// USER application initialization ///////////////////
	/**
	 * @brief	Adv Packet data
	 */
	u8	tbl_advData[] = {
		 0x05, 0x09, 'f', 'h', 'i', 'd',
		 0x02, 0x01, 0x05,
		 0x03, 0x19, 0x80, 0x01,
		 0x05, 0x02, 0x12, 0x18, 0x0F, 0x18,
	};

	/**
	 * @brief	Scan Response Packet data
	 */
	u8	tbl_scanRsp [] = {
			 0x08, 0x09, 'f', 'e', 'a', 't', 'u', 'r', 'e',
		};

	bls_ll_setAdvData( (u8 *)tbl_advData, sizeof(tbl_advData) );
	bls_ll_setScanRspData( (u8 *)tbl_scanRsp, sizeof(tbl_scanRsp));

	u8 status = bls_ll_setAdvParam( ADV_INTERVAL_30MS, ADV_INTERVAL_35MS, \
									 ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC, \
									 0,  NULL,  BLT_ENABLE_ADV_ALL, ADV_FP_NONE);
	if(status != BLE_SUCCESS){  //adv setting err
		while(1);
	}


	bls_ll_setAdvEnable(1);  //adv enable



	//add advertising in connection slave role
	/**
	 * @brief	Adv test Packet data
	 */
	u8 tbl_advData_test[] = {
			 0x09, 0x09, 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
			 0x02, 0x01, 0x05,
			};

	/**
	 * @brief	Scan Response Packet data
	 */
	u8	tbl_scanRsp_test [] = {
			 0x09, 0x09, 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
		};
	blc_ll_addAdvertisingInConnSlaveRole();  //adv in conn slave role
	blc_ll_setAdvParamInConnSlaveRole(  (u8 *)tbl_advData_test, sizeof(tbl_advData_test), \
										(u8 *)tbl_scanRsp_test, sizeof(tbl_scanRsp_test), \
										ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC, BLT_ENABLE_ADV_ALL, ADV_FP_NONE);



	//scan setting
	blc_ll_initScanning_module();
	blc_hci_le_setEventMask_cmd(HCI_LE_EVT_MASK_ADVERTISING_REPORT);
	blc_hci_registerControllerEventHandler(controller_event_callback);

	#if  1  //report all adv
		blc_ll_setScanParameter(SCAN_TYPE_PASSIVE, SCAN_INTERVAL_100MS, SCAN_INTERVAL_100MS,
								  OWN_ADDRESS_PUBLIC, SCAN_FP_ALLOW_ADV_ANY);
	#else //report adv only in whitelist
		ll_whiteList_reset();
		u8 test_adv[6] = {0x33, 0x33, 0x33, 0x33, 0x33, 0x33};
		ll_whiteList_add(BLE_ADDR_PUBLIC, test_adv);
		blc_ll_setScanParameter(SCAN_TYPE_PASSIVE, SCAN_INTERVAL_100MS, SCAN_INTERVAL_100MS,
								  OWN_ADDRESS_PUBLIC, SCAN_FP_ALLOW_ADV_WL);
	#endif

	blc_ll_addScanningInConnSlaveRole();  //add scan in conn slave role




	//ble event call back
	bls_app_registerEventCallback (BLT_EV_FLAG_CONNECT, &task_connect);
	bls_app_registerEventCallback (BLT_EV_FLAG_TERMINATE, &task_terminate);
#endif


	///////////////////// Power Management initialization///////////////////
#if(BLE_APP_PM_ENABLE)
	blc_ll_initPowerManagement_module();

	#if (PM_DEEPSLEEP_RETENTION_ENABLE)
		bls_pm_setSuspendMask (SUSPEND_ADV | DEEPSLEEP_RETENTION_ADV | SUSPEND_CONN | DEEPSLEEP_RETENTION_CONN);
		blc_pm_setDeepsleepRetentionThreshold(95, 95);
		blc_pm_setDeepsleepRetentionEarlyWakeupTiming(240);
		//blc_pm_setDeepsleepRetentionType(DEEPSLEEP_MODE_RET_SRAM_LOW64K); //default use 32k deep retention
	#else
		bls_pm_setSuspendMask (SUSPEND_ADV | SUSPEND_CONN);
	#endif

	bls_app_registerEventCallback (BLT_EV_FLAG_SUSPEND_ENTER, &ble_remote_set_sleep_wakeup);
#else
	bls_pm_setSuspendMask (SUSPEND_DISABLE);
#endif


//	advertise_begin_tick = clock_time();




#if (APP_DUMP_EN)
	myudb_usb_init (0x120,&uart_txfifo);		//0x120: usb sub-id
	usb_set_pin_en ();
#endif

}



/**
 * @brief		user initialization when MCU wake_up from deepSleep_retention mode
 * @param[in]	none
 * @return      none
 */
_attribute_ram_code_ void user_init_deepRetn(void)
{
#if (PM_DEEPSLEEP_RETENTION_ENABLE)

	blc_ll_initBasicMCU();   //mandatory
	rf_set_power_level_index (MY_RF_POWER_INDEX);
	blc_ll_recoverDeepRetention();

	DBG_CHN0_HIGH;    //debug
	irq_enable();

#endif
}


/////////////////////////////////////////////////////////////////////s
// main loop flow
/////////////////////////////////////////////////////////////////////




/**
 * @brief		This is main_loop function
 * @param[in]	none
 * @return      none
 */
_attribute_no_inline_ void main_loop (void)
{
	////////////////////////////////////// BLE entry /////////////////////////////////
	blt_sdk_main_loop();


	////////////////////////////////////// PM Process /////////////////////////////////
	blt_pm_proc();



#if (APP_DUMP_EN)
	myudb_usb_handle_irq ();
#endif
}





#endif  //end of (FEATURE_TEST_MODE == ...)