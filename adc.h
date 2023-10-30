/*
 * adc.h
 *
 *  Created on: Oct 23, 2023
 *      Author: HP
 */

#ifndef ADC_H_
#define ADC_H_
#include "stdtypes.h"

#define REFS1_ID   7
#define REFS0_ID   6
#define ADLAR_ID   5
#define MUX4_ID    4
#define MUX3_ID    3
#define MUX2_ID    2
#define MUX1_ID    1
#define MUX0_ID    0

#define ADEN_ID    7
#define ADSC_ID    6
#define ADATE_ID   5
#define ADIF_ID    4
#define ADIE_ID    3
#define ADPS2_ID   2
#define ADPS1_ID   1
#define ADPS0_ID   0
#define ADTS2_ID   7
#define ADTS1_ID   6
#define ADTS0_ID   5

void ADC_init();
void ADC_voidEnable();
//void ADC_voidInterrputEnable();
void ADC_voidDisable();
u16 ADC_u16ReadADC();
void ADC_voidStartConversion(u8 channel_num);
u16 ADC_u16ReadADCInMV();
void ADC_voidEnableInt();
void ADC_voidDisableInt();
void ADC_SetCallback( void (*ptr) (void) );
void __vector_16 (void) __attribute__ ((signal,used, externally_visible)); //to avoid optmization
#endif /* ADC_H_ */
