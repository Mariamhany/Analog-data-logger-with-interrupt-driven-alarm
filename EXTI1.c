/*
 * EXT1.c
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#include "EXTI1.h"
#include"bitmap.h"
#include "AvrRegisters.h"
#include"stdtypes.h"

void (*CallbackPtr1 )(void)=NULL;

//init the INT with sensing mood in preprocessing stage
void EXTI1_voidInit(void)
{
#if (SENSE_MOOD == EXTI1_LOW)
	CLEAR_BIT(MCUCR,ISC10_ID);
	CLEAR_BIT(MCUCR,ISC11_ID);
#elif(SENSE_MOOD == EXTI1_IOC)
	SET_BIT(MCUCR,ISC10_ID);
	CLEAR_BIT(MCUCR,ISC11_ID);
#elif(SENSE_MOOD == EXTI1_FALLING)
	SET_BIT(MCUCR,ISC11_ID);
	CLEAR_BIT(MCUCR,ISC10_ID);
#elif(SENSE_MOOD == EXTI1_RISING)
	SET_BIT(MCUCR,ISC10_ID);
	SET_BIT(MCUCR,ISC11_ID);
#endif
}

//enable EXTI
void EXTI1_voidEnable(void){
	SET_BIT(GICR,INT1_ID);
}

//disable EXTI
void EXTI1_voidDisable(void){
	CLEAR_BIT(GICR,INT1_ID);
}

void EXT1_voidSetSignalch(u8 SenseCpy)
{

	if (SenseCpy == EXTI1_LOW){
		CLEAR_BIT(MCUCR,ISC10_ID);
		CLEAR_BIT(MCUCR,ISC11_ID);
	}
	else if(SenseCpy == EXTI1_IOC)
	{
		SET_BIT(MCUCR,ISC10_ID);
		CLEAR_BIT(MCUCR,ISC11_ID);
	}
	else if(SenseCpy == EXTI1_FALLING)
	{	SET_BIT(MCUCR,ISC11_ID);
	CLEAR_BIT(MCUCR,ISC10_ID);
	}
	else if(SenseCpy == EXTI1_RISING)
	{
		SET_BIT(MCUCR,ISC10_ID);
		SET_BIT(MCUCR,ISC11_ID);
	}
}

void EXT1_VID_SET_CALL_BACK(void (*ptr)(void)){
	CallbackPtr1 = ptr;
}

void __vector_2 (void){
	CallbackPtr1();
}
