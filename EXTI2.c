/*
 * EXT1.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "EXTI2.h"
#include"stdtypes.h"
#include "AvrRegisters.h"
#include "bitmap.h"

void (*CallbackPtr2 )(void)=NULL;

//init the INT with sensing mood in preprocessing stage
void EXTI2_voidInit(void)
{
#if(SENSE_MOOD == EXTI2_FALLING)
	CLEAR_BIT(MCUCSR,ISC2_ID);
#elif(SENSE_MOOD == EXTI2_RISING)
	SET_BIT(MCUCSR,ISC2_ID);
#endif
}

//enable EXTI
void EXTI2_voidEnable(void){
	SET_BIT(GICR,INT2_ID);
}

//disable EXTI
void EXTI2_voidDisable(void){
	CLEAR_BIT(GICR,INT2_ID);
}

void EXT2_voidSetSignalch(u8 SenseCpy){
if(SenseCpy == EXTI2_FALLING)
	CLEAR_BIT(MCUCSR,ISC2_ID);
else if(SenseCpy == EXTI2_RISING)
	SET_BIT(MCUCSR,ISC2_ID);
}

void EXT2_VID_SET_CALL_BACK(void (*ptr)(void)){
	CallbackPtr2 = ptr;
}

void __vector_3 (void){
	CallbackPtr2();
}
