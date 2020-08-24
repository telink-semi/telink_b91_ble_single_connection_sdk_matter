/*
 * emi.c
 *
 *  Created on: Jul 13, 2020
 *      Author: telink
 */
#include "emi.h"

#define STATE0		0x1234
#define STATE1		0x5678
#define STATE2		0xabcd
#define STATE3		0xef01

#define TX_FIFO_ADDR     0x14081c
#define TX_PKT_PAYLOAD		37

static unsigned char  emi_rx_packet[128] __attribute__ ((aligned (4)));
static unsigned char  emi_ble_tx_packet [48]  __attribute__ ((aligned (4))) = {3,0,0,0,0,10};
static unsigned char  emi_zigbee_tx_packet[48]  __attribute__ ((aligned (4))) = {19,0,0,0,20,0,0};
static unsigned int   emi_rx_cnt  __attribute__ ((aligned (4))) = 0;
static unsigned int   emi_rssibuf = 0;
static signed  char   rssi = 0;
static unsigned int   state0,state1;

/**
 * @brief   This function serves to set singletone power.
 * @param   level - the power level.
 * @return  none.
 */
void rf_set_power_level_index_singletone (rf_power_level_e level)
{
	unsigned char value = 0;

	if(level&BIT(7))
	{
		write_reg8(0x140e3c, (read_reg8(0x140e3c) & 0xbf) | ((0x01)<<6));//VANT
	}
	else
	{
		write_reg8(0x140e3c, (read_reg8(0x140e3c) & 0xbf));
	}
	reg_rf_ll_ctrl0 = 0x55;  //tx_en
	delay_us(150);

	value = (unsigned char)level&0x3f;
	write_reg8(0x140f78,read_reg8(0x140f78)|BIT(6));  //TX_PA_PWR_OW  BIT6 set 1
	write_reg8(0x140f7c, (read_reg8(0x140f7c)&0x81)|(value<<1));  //TX_PA_PWR  BIT1 t0 BIT6 set value
}


/**
 * @brief   This function serves to set singletone power and channel.
 * @param   power_level - the power level.
 * @param   rf_chn - the channel.
 * @return  none.
 */
void rf_emi_single_tone(rf_power_level_e power_level,signed char rf_chn)
{
	rf_set_chn(rf_chn);//set freq
	rf_set_power_level_index_singletone(power_level);
	rf_set_txmode();
}

/**
 * @brief   This function serves to close RF
 * @param   none.
 * @return  none.
 */
void rf_emi_stop(void)
{
	write_reg8(0x140f78, 0);
	write_reg8(0x140f7c, 0);//TX_PA_PWR
	rf_set_power_level_index (0);
	rf_set_tx_rx_off();
}

/**
 * @brief   This function serves to Set the CD mode correlation register.
 * @param   none.
 * @return  none.
 */
void rf_continue_mode_setup(void)
{

	write_reg8(0x140800,0x0a);
	write_reg8(0x140808,0x00);  // access code

	write_reg8(0x140801,0x80);//kick tx controller to wait data
	state0 = STATE0;
	state1 = STATE1;
}

/**
 * @brief   This function serves to init the CD mode.
 * @param   rf_mode - mode of RF.
 * @param   power_level - power level of RF.
 * @param   rf_chn - channel of RF.
 * @param 	pkt_type - The type of data sent
 * 					   0:random data
 * 					   1:0xf0
 * 					   2:0x55
 * @return  none.
 */
void rf_emi_tx_continue_setup(rf_mode_e rf_mode,rf_power_level_e power_level,signed char rf_chn,unsigned char pkt_type)
{
	rf_drv_init(rf_mode);     // RF_MODE_BLE_1M
	rf_pn_disable();
	rf_set_chn(rf_chn);
	reg_rf_ll_ctrl0 = 0x45;   // tx_en
	rf_set_power_level_index_singletone (power_level);
	rf_continue_mode_setup();
	write_reg8(0x140808, pkt_type);  // 0:pbrs9 	1:0xf0	 2:0x55
}

/**
 * @brief   This function serves to generate random number.
 * @param   the old random number.
 * @return  the new random number.
 */
unsigned int pnGen(unsigned int state)
{
	unsigned int feed = 0;
	feed = (state&0x4000) >> 1;
	state ^= feed;
	state <<= 1;
	state = (state&0xfffe) + ((state&0x8000)>>15);
	return state;
}

/**
 * @brief   This function serves to continue to send CD mode.
 * @param   none.
 * @return  none.
 */
void rf_continue_mode_run(void)
{
	if(read_reg8(0x140808) == 1){
		write_reg32(TX_FIFO_ADDR, 0x0f0f0f0f);
	}else if(read_reg8(0x140808)==2){
		write_reg32(TX_FIFO_ADDR, 0x55555555);
	}else if(read_reg8(0x140808)==3){
		write_reg32(TX_FIFO_ADDR, read_reg32(0x140809));
	}else if(read_reg8(0x140808)==4){
		write_reg32(TX_FIFO_ADDR, 0);
	}else if(read_reg8(0x140808)==5){
		write_reg32(TX_FIFO_ADDR, 0xffffffff);
	}else{
		write_reg32(TX_FIFO_ADDR, (state0<<16)+state1);
		state0 = pnGen(state0);
		state1 = pnGen(state1);
	}

	while(read_reg8(TX_FIFO_ADDR) & 0x1){
	}
}

/**
 * @brief   This function serves to set rx mode and channel.
 * @param   mode - mode of RF
 * @param   rf_chn - the rx channel.
 * @return  none.
 */
void rf_emi_rx(rf_mode_e mode,signed char rf_chn)
{
	rf_drv_init(mode);
	rf_set_rx_dma(emi_rx_packet,3,64);
	rf_pn_disable();
	rf_set_chn(rf_chn);//set freq
	if(mode != RF_MODE_ZIGBEE_250K)
		write_reg32(ACCESS_ADDR,ACCESS_CODE); 	//accesscode: 1001-0100 1000-0010 0110-1110 1000-1110   29 41 76 71
	write_reg8 (ACCLEN_ADDR, read_reg8(ACCLEN_ADDR)|0x80); //trig accesscode
	rf_set_tx_rx_off();
	rf_set_rxmode();
	delay_us(150);
	rssi = 0;
	emi_rssibuf = 0;
	emi_rx_cnt = 0;
}

/**
 * @brief   This function serves is receiving service program
 * @param   none.
 * @return  none.
 */
void rf_emi_rx_loop(void)
{
	if(read_reg8(0x140a20)&BIT(0))
	{
	   if((read_reg8(0x140840) & 0xf0) == 0)
	   {
		   emi_rssibuf += (read_reg8(0x140c5d));
		   if(emi_rx_cnt)
		   {
			   if(emi_rssibuf != 0)
			   {
				   emi_rssibuf >>= 1;
			   }
		   }
		   rssi = emi_rssibuf - 110;
		   emi_rx_cnt++;
	   }
	   write_reg8(0x140a20, 1);
	   write_reg8(0x140a00, 0x80);
	}
}

/**
 * @brief   This function serves to get the number of packets received
 * @param   none.
 * @return  the number of packets received.
 */
unsigned int rf_emi_get_rxpkt_cnt(void)
{
	return emi_rx_cnt;
}

/**
 * @brief   This function serves to get the RSSI of packets received
 * @param   none.
 * @return  the RSSI of packets received.
 */
char rf_emi_get_rssi_avg(void)
{
	return rssi;
}


/**
 * @brief   This function serves to generate random packets that need to be sent in burst mode
 * @param   *p - the address of random packets.
 * @param   n - the number of random packets.
 * @return  none.
 */
void rf_phy_test_prbs9 (unsigned char *p, int n)
{
	unsigned short x = 0x1ff;
	int i = 0;
	int j = 0;
	for ( i=0; i<n; i++)
	{
		unsigned char d = 0;
		for (j=0; j<8; j++)
		{
			if (x & 1)
			{
				d |= BIT(j);
			}
			x = (x >> 1) | (((x<<4) ^ (x<<8)) & 0x100);
		}
		*p++ = d;
	}
}

/**
*	@brief	  	This function serves to clear the Tx finish flag bit.
*				After all packet data are sent, corresponding Tx finish flag bit
*				will be set as 1.By reading this flag bit, it can check whether
*				packet transmission is finished. After the check, it��s needed to
*				manually clear this flag bit so as to avoid misjudgment.
*   @param      none
*	@return	 	none
*/
static inline void rf_tx_finish_clear_flag(void)
{
    write_reg8(0x140a20, read_reg8(0x140a20) | 0x02);
}

/**
*	@brief	  	This function serves to determine whether sending a packet of data is finished
*	@param[in]	none.
*	@return	 	Yes: 1, NO: 0.
*/
static inline unsigned char rf_tx_finish(void)
{
    return ((read_reg8(0x140a20) & BIT(1))==0x02);
}

/**
 * @brief   This function serves to send packets in the burst mode
 * @param   rf_mode - mode of RF.
 * @param 	pkt_type - The type of data sent
 * 					   0:random data
 * 					   1:0xf0
 * 					   2:0x55
 * @return  none.
 */
void rf_emi_tx_burst_loop(rf_mode_e rf_mode,unsigned char pkt_type)
{
	u8 rf_data_len = TX_PKT_PAYLOAD+1;
	u32 rf_tx_dma_len = RF_TX_PAKET_DMA_LEN(rf_data_len);
	write_reg8(0x140a00, 0x80); // stop SM
	if((rf_mode==RF_MODE_BLE_1M_NO_PN)||(rf_mode==RF_MODE_BLE_2M))//ble
	{
        rf_data_len = TX_PKT_PAYLOAD+2;
        rf_tx_dma_len = RF_TX_PAKET_DMA_LEN(rf_data_len);
		emi_ble_tx_packet[4]=0;
		emi_ble_tx_packet[5]=TX_PKT_PAYLOAD;
		emi_ble_tx_packet[3] = (rf_tx_dma_len >> 24)&0xff;
		emi_ble_tx_packet[2] = (rf_tx_dma_len >> 16)&0xff;
		emi_ble_tx_packet[1] = (rf_tx_dma_len >> 8)&0xff;
		emi_ble_tx_packet[0] = rf_tx_dma_len&0xff;
		rf_start_stx ((void *)emi_ble_tx_packet,1, read_reg32(0x140200) + 10);
	    while(!rf_tx_finish());
	    rf_tx_finish_clear_flag();

	    delay_ms(2);
	    if(pkt_type == 0)
	    	rf_phy_test_prbs9(&emi_ble_tx_packet[6],37);
	}
	else if(rf_mode == RF_MODE_LR_S8_125K)
	{
        rf_data_len = TX_PKT_PAYLOAD+2;
        rf_tx_dma_len = RF_TX_PAKET_DMA_LEN(rf_data_len);
		emi_ble_tx_packet[4]=0;
		emi_ble_tx_packet[5]=TX_PKT_PAYLOAD;
		emi_ble_tx_packet[3] = (rf_tx_dma_len >> 24)&0xff;
		emi_ble_tx_packet[2] = (rf_tx_dma_len >> 16)&0xff;
		emi_ble_tx_packet[1] = (rf_tx_dma_len >> 8)&0xff;
		emi_ble_tx_packet[0] = rf_tx_dma_len&0xff;
		rf_start_stx ((void *)emi_ble_tx_packet,1, read_reg32(0x140200) + 10);
	    while(!rf_tx_finish());
	    rf_tx_finish_clear_flag();

	    delay_ms(2);
	    if(pkt_type == 0)
	    	rf_phy_test_prbs9(&emi_ble_tx_packet[6],37);
	}
	else if(rf_mode == RF_MODE_LR_S2_500K)
	{
        rf_data_len = TX_PKT_PAYLOAD+2;
        rf_tx_dma_len = RF_TX_PAKET_DMA_LEN(rf_data_len);
		emi_ble_tx_packet[4]=0;
		emi_ble_tx_packet[5]=TX_PKT_PAYLOAD;
		emi_ble_tx_packet[3] = (rf_tx_dma_len >> 24)&0xff;
		emi_ble_tx_packet[2] = (rf_tx_dma_len >> 16)&0xff;
		emi_ble_tx_packet[1] = (rf_tx_dma_len >> 8)&0xff;
		emi_ble_tx_packet[0] = rf_tx_dma_len&0xff;
		rf_start_stx ((void *)emi_ble_tx_packet,1, read_reg32(0x140200) + 10);
	    while(!rf_tx_finish());
	    rf_tx_finish_clear_flag();

	    delay_ms(2);
	    if(pkt_type == 0)
	    	rf_phy_test_prbs9(&emi_ble_tx_packet[6],37);
	}
	else if(rf_mode == RF_MODE_ZIGBEE_250K)
	{
		rf_data_len = TX_PKT_PAYLOAD+1;
		rf_tx_dma_len = RF_TX_PAKET_DMA_LEN(rf_data_len);
		emi_zigbee_tx_packet[4]=TX_PKT_PAYLOAD+2;
		emi_zigbee_tx_packet[3] = (rf_tx_dma_len >> 24)&0xff;
		emi_zigbee_tx_packet[2] = (rf_tx_dma_len >> 16)&0xff;
		emi_zigbee_tx_packet[1] = (rf_tx_dma_len >> 8)&0xff;
		emi_zigbee_tx_packet[0] = rf_tx_dma_len&0xff;
		rf_start_stx ((void *)emi_zigbee_tx_packet,1, read_reg32(0x140200) + 10);
		while(!rf_tx_finish());
	    rf_tx_finish_clear_flag();

	    delay_us(625*2);
	    if(pkt_type == 0)
	    	rf_phy_test_prbs9(&emi_zigbee_tx_packet[5],37);
	}
}

/**
 * @brief   This function serves to init the burst mode.
 * @param   rf_mode - mode of RF.
 * @param   power_level - power level of RF.
 * @param   rf_chn - channel of RF.
 * @param 	pkt_type - The type of data sent
 * 					   0:random data
 * 					   1:0xf0
 * 					   2:0x55
 * @return  none.
 */
void rf_emi_tx_burst_setup(rf_mode_e rf_mode,rf_power_level_e power_level,signed char rf_chn,unsigned char pkt_type)
{
	unsigned char i = 0;
	unsigned char tx_data = 0;
	write_reg8(0x10083c,0x10); // print buffer size set
	rf_set_tx_dma(2,2);
	rf_set_chn(rf_chn);
	rf_drv_init(rf_mode);
	if(rf_mode != RF_MODE_ZIGBEE_250K)
		write_reg32(ACCESS_ADDR,ACCESS_CODE); 	//accesscode: 1001-0100 1000-0010 0110-1110 1000-1110   29 41 76 71
	write_reg8 (ACCLEN_ADDR, read_reg8(ACCLEN_ADDR)|0x80); //trig accesscode

	rf_pn_disable();
	rf_set_power_level (power_level);
	if(pkt_type == 1)
	{
		tx_data = 0x0f;
	}
	else if(pkt_type == 2)
	{
		tx_data = 0x55;
	}

	switch(rf_mode)
	{
	    case RF_MODE_LR_S2_500K:
	    case RF_MODE_LR_S8_125K:
	    case RF_MODE_BLE_1M_NO_PN:
	    case RF_MODE_BLE_2M:
			emi_ble_tx_packet[4] = pkt_type;//type
	    	for(i = 0;i < 37;i++)
	    	{
				emi_ble_tx_packet[6+i]=tx_data;
	    	}
	    	break;
	    case RF_MODE_ZIGBEE_250K:
	    	emi_zigbee_tx_packet[5] = pkt_type; // type
	    	for(i = 0;i < 37;i++)
	    	{
	    		emi_zigbee_tx_packet[5 + i] = tx_data;
	    	}
	    	break;

	    default:
	    	break;
	}

}