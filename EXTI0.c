/*
 * EXT1.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "EXTI0.h"
#include"stdtypes.h"
#include"bitmap.h"
#include "AvrRegisters.h"


void (*CallbackPtr0 )(void)=NULL;

//init the INT with sensing mood in preprocessing stage
void EXTI0_voidInit(void)
{
#if (SENSE_MOOD == EXTI0_LOW)
	CLEAR_BIT(MCUCR,ISC00_ID);
	CLEAR_BIT(MCUCR,ISC01_ID);
#elif(SENSE_MOOD == EXTI0_IOC)
	SET_BIT(MCUCR,ISC00_ID);
	CLEAR_BIT(MCUCR,ISC01_ID);
#elif(SENSE_MOOD == EXTI0_FALLING)
	SET_BIT(MCUCR,ISC01_ID);
	CLEAR_BIT(MCUCR,ISC00_ID);
#elif(SENSE_MOOD == EXTI0_RISING)
	SET_BIT(MCUCR,ISC00_ID);
	SET_BIT(MCUCR,ISC01_ID);
#endif
}

//enable EXTI
void EXTI0_voidEnable(void){
	SET_BIT(GICR,INT0_ID);
}

//disable EXTI
void EXTI0_voidDisable(void){
	CLEAR_BIT(GICR,INT0_ID);
}

//void EXT0_voidSetSignalch(u8 SenseCpy)
//{
//if (SenseCpy == EXTI0_LOW){
//	CLEAR_BIT(MCUCR,ISC00_ID);
//	CLEAR_BIT(MCUCR,ISC01_ID);
//}
//else if(SenseCpy== EXTI0_IOC)
//{
//	SET_BIT(MCUCR,ISC00_ID);
//	CLEAR_BIT(MCUCR,ISC01_ID);
//}
//else if(SenseCpy == EXTI0_FALLING)
//	{SET_BIT(MCUCR,ISC01_ID);
//	CLEAR_BIT(MCUCR,ISC00_ID);
//	}
//else if(SenseCpy == EXTI0_RISING)
//	{
//	SET_BIT(MCUCR,ISC00_ID);
//	SET_BIT(MCUCR,ISC01_ID);
//	}
//}

void EXT0_VID_SET_CALL_BACK(void (*ptr)(void)){
	CallbackPtr0 = ptr;
}

void __vector_1 (void){
	CallbackPtr0();
}
