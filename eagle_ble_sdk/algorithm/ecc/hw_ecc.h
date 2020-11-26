/********************************************************************************************************
 * @file	hw_ecc.h
 *
 * @brief	This is the source file for BLE SDK
 *
 * @author	BLE GROUP
 * @date	2020.06
 *
 * @par		Copyright (c) 2020, Telink Semiconductor (Shanghai) Co., Ltd.
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

#ifndef HW_ECC_H_
#define HW_ECC_H_

#include "algorithm/ecc/hw_ecc.h"


#define			hECC_BYTES			32




/* hECC_RNG_Function type
The RNG function should fill 'size' random bytes into 'dest'. It should return 1 if
'dest' was filled with random data, or 0 if the random data could not be generated.
The filled-in values should be either truly random, or from a cryptographically-secure PRNG.
A correctly functioning RNG function must be set (using hECC_set_rng()) before calling
hECC_make_key(). */

typedef int (*hECC_rng_func)(unsigned char *dest, unsigned size);


/**
 * @brief		The function that will be used to generate random bytes.
 * @param[in]	resister predefined TRNG function
 * @return		none
 */
void			hwECC_set_rng(hECC_rng_func rng_func);


/**
 * @brief		get ECCP key pair(the key pair could be used in ECDH).
 * @param[out]	public_key	- public key, little-endian.
 * @param[out]	private_key	- private key, little-endian.
 * @return		PKE_SUCCESS(success), other(error).
 */
unsigned char 	hwECC_make_key(unsigned char public_key[hECC_BYTES*2], unsigned char private_key[hECC_BYTES]);


/**
 * @brief		ECDH compute key.
 * @param[in]	local_prikey	- local private key, little-endian.
 * @param[in]	public_key		- peer public key, little-endian.
 * @param[out]	dhkey			- output dhkey, little-endian..
 * @Return		0(success); other(error).
 */
unsigned char hwECC_shared_secret(const unsigned char public_key[hECC_BYTES*2],
								  const unsigned char private_key[hECC_BYTES],
		                          unsigned char secret[hECC_BYTES]);




#endif /* HW_ECC_H_ */



