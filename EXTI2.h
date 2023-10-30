/*
 * EXT1.h
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#ifndef EXTI2_H_
#define EXTI2_H_

#include"stdtypes.h"
#include "EXTI_config.h"

#define NULL 0

#define  EXTI2_FALLING          0
#define  EXTI2_RISING           1

#define SENSE_MOOD EXTI2_FALLING


//init the INT with sensing mood in preprocessing stage
void EXTI2_voidInit(void);

//enable EXTI
void EXTI2_voidEnable(void);

//disable EXTI
void EXTI2_voidDisable(void);

//change the INT with sensing mood in runtime
void EXT2_voidSetSignalch(u8 SenseCpy);

//callback function
void EXT2_VID_SET_CALL_BACK(void (*ptr)(void));

void __vector_3 (void) __attribute__ ((signal,used, externally_visible)); //to avoid optmization

#endif /* EXTI2_H_ */
