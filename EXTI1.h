/*
 * EXT1.h
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#ifndef EXTI1_H_
#define EXTI1_H_

#include "EXTI_config.h"
#include"stdtypes.h"
#define NULL 0

#define  EXTI1_LOW              0
#define  EXTI1_IOC              1
#define  EXTI1_FALLING          2
#define  EXTI1_RISING           3

#define SENSE_MOOD EXTI1_FALLING


//init the INT with sensing mood in preprocessing stage
void EXTI1_voidInit(void);

//enable EXTI
void EXTI1_voidEnable(void);

//disable EXTI
void EXTI1_voidDisable(void);

//change the INT with sensing mood in runtime
void EXT1_voidSetSignalch(u8 SenseCpy);

//callback function
void EXT1_VID_SET_CALL_BACK(void (*ptr)(void));

void __vector_2 (void) __attribute__ ((signal,used, externally_visible)); //to avoid optmization

#endif /* EXTI1_H_ */
