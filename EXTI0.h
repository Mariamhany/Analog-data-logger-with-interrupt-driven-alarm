/*
 * EXT1.h
 *
 *  Created on: Oct 22, 2023
 *      Author: HP
 */

#ifndef EXTI0_H_
#define EXTI0_H_

#include "EXTI_config.h"


#define NULL 0

#define  EXTI0_LOW              0
#define  EXTI0_IOC              1
#define  EXTI0_FALLING          2
#define  EXTI0_RISING           3

#define SENSE_MOOD EXTI0_FALLING


//init the INT with sensing mood in preprocessing stage
void EXTI0_voidInit(void);

//enable EXTI
void EXTI0_voidEnable(void);

//disable EXTI
void EXTI0_voidDisable(void);

//change the INT with sensing mood in runtime
//void EXT0_voidSetSignalch(u8 SenseCpy);

//callback function
void EXT0_VID_SET_CALL_BACK(void (*ptr)(void));

void __vector_1 (void) __attribute__ ((signal,used, externally_visible)); //to avoid optmization

#endif /* EXTI0_H_ */
