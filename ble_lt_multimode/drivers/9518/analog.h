/*******************************      analog control registers: 0xb8      ******************************/
/**	@page ANALOG
 *
 *	Introduction
 *	===============
 *	TLSR9518 analog support dma and normal mode, in each mode, support byte/halfword/word/buffer write and read. 
 *
 *	API Reference
 *	===============
 *	Header File: analog.h
 */
#pragma once

#include "../../common/types.h"
#include "dma.h"
#include "compiler.h"
#include "reg_include/register_9518.h"

/**********************************************************************************************************************
 *                                         global constants                                                           *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *                                           global macro                                                             *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *                                         global data type                                                           *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *                                     global variable declaration                                                    *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *                                      global function prototype                                                     *
 *********************************************************************************************************************/

/**
 * @brief      This function serves to analog register read by byte.
 * @param[in]  addr - address need to be read.
 * @return     the result of read.
 */
_attribute_ram_code_sec_noinline_ unsigned char analog_read_reg8(unsigned char addr);

/**
 * @brief      This function serves to analog register write by byte.
 * @param[in]  addr - address need to be write.
 * @param[in]  data - the value need to be write.
 * @return     none.
 */
_attribute_ram_code_sec_noinline_ void analog_write_reg8(unsigned char addr, unsigned char data);

/**
 * @brief      This function serves to analog register read by halfword.
 * @param[in]  addr - address need to be read.
 * @return     the result of read.
 */
unsigned short analog_read_reg16(unsigned char addr);

/**
 * @brief      This function serves to analog register write by halfword.
 * @param[in]  addr - address need to be write.
 * @param[in]  data - the value need to be write.
 * @return     none.
 */
void analog_write_reg16(unsigned char addr, unsigned short data);

/**
 * @brief      This function serves to analog register read by word.
 * @param[in]  addr - address need to be read.
 * @return     the result of read.
 */
 unsigned int analog_read_reg32(unsigned char addr);

 /**
  * @brief      This function serves to analog register write by word.
  * @param[in]  addr - address need to be write.
  * @param[in]  data - the value need to be write.
  * @return     none.
  */
void analog_write_reg32(unsigned char addr, unsigned int data);
/**
 * @brief      This function serves to analog register read.
 * @param[in]  addr - address need to be read.
 * @param[in]  *buff - the value need to be read.
 * @param[in]  len - the length of read value.
 * @return     none.
 */
_attribute_ram_code_sec_noinline_ void analog_read_buff(unsigned char addr, unsigned char *buff, int len);

/**
 * @brief      This function serves to analog register write.
 * @param[in]  addr - address need to be write.
 * @param[in]  *buff - the value need to be write.
 * @param[in]  len - the length of write value.
 * @return     none.
 */
_attribute_ram_code_sec_noinline_ void analog_write_buff(unsigned char addr, unsigned char *buff, int len);


/**
 * @brief      This function serves to analog register write by word using dma.
 * @param[in]  chn - the dma channel.
 * @param[in]  addr - address need to be write.
 * @param[in]  pdat - the value addr need to be write.
 * @return     none.
 */
void analog_write_reg32_dma(dma_chn_e chn, unsigned char addr, void *pdat);

/**
 * @brief      This function serves to analog register write by word using dma.
 * @param[in]  chn - the dma channel.
 * @param[in]  addr - address need to be write.
 * @param[in]  pdat - the value need to be write.
 * @return     none.
 */
void analog_read_reg32_dma(dma_chn_e chn, unsigned char addr,void *pdat);

/**
 * @brief      This function write buffer to analog register by dma channel.
 * @param[in]  chn - the dma channel.
 * @param[in]  addr - address need to be write.
 * @param[in]  *pdat - the buffer need to be write.
 * @param[in]  len - the length of buffer.
 * @return     none.
 */
void analog_write_buff_dma(dma_chn_e chn, unsigned char addr, unsigned char *pdat, unsigned int len);

/**
 * @brief      This function write buffer to analog register by dma channel.
 * @param[in]  chn - the dma channel.
 * @param[in]  addr - address need to be read from.
 * @param[in]  *pdat - the buffer need to be put data.
 * 			   note: The size of array pdat must be a multiple of 4.
 * 			  	 	For example, if you just need read 5 byte by dma, you should
 * 			  	 	define the size of array pdat to be greater than 8 other than 5.
 * 			  	 	Because the dma would return 4 byte data every time, 5 byte is
 * 			  	 	not enough to store them.
 * @param[in]  len - the length of read data.
 * @return     none.
 */
void analog_read_buff_dma(dma_chn_e chn, unsigned char addr, unsigned char *pdat, unsigned int len);

/**
 * @brief      This function write buffer to analog register by dma channel.
 * @param[in]  chn - the dma channel.
 * @param[in]  pdat - the buffer need to be put data,
 * @par
 * @code
 * 			 	The array pdat should look like this,
 * 						------------------
 * 						| 	pdat  	 	 |
 * 						|----------------|
 * 				pdat[0] | address 	0x3a |
 * 				pdat[1] | data     	0x11 |
 * 				pdat[2] | address 	0x3b |
 *				pdat[3] | data    	0x22 |
 *						| ...... 		 |
 * 						------------------
 * 				It means write data 0x11 to address 0x3a,
 * 						 write data 0x22 to address 0x3b,
 * 						 ......
 * @endcode
 * @param[in]  len - the length of read data.
 * @return     none.
 */
void analog_write_addr_data_dma(dma_chn_e chn, void *pdat, int len);
