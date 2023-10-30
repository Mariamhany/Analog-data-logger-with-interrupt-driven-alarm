/*
 * gie.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "AvrRegisters.h"
#include "dio.h"
#include "bitmap.h"

void GIE_voidEnable(void){

	SET_BIT(SREG,PIN7_ID);
}

void GIE_voidDisable(void){

	CLEAR_BIT(SREG,PIN7_ID);
}
