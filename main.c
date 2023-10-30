/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: HP
 */

#include "adc.h"
#include"lcd.h"
#include<util/delay.h>
#include"stdtypes.h"
#include"dio.h"
#include"gie.h"
#include"EXTI0.h"
#include"EXTI1.h"
#include"EXTI2.h"
#include"AvrRegisters.h"

//volatile u16 data=0;
volatile u16 Reading[3];
volatile u16 channel=0;

#define LM_MAX  50
#define LDR_MAX 3
#define POT_MAX 2

//BUZZER OUTPUT PORTC PIN3
#define BUZZER_ID PIN3_ID

//PORTC  PIN 0 ,1 ,2 AS OUTPUT TO TRIGGER INTERRUTS
//INPUTS TO INT0,1,2
#define LM_INT PIN0_ID
#define LDR_INT PIN1_ID
#define POT_INT PIN2_ID
void ISR_ADC_chaining(void){
	ADC_voidDisable();
	Reading[channel]= ADC_u16ReadADCInMV();
//	ADC_voidStartConversion(channel);
    channel++;
    if (channel>2){
    	channel=0;
    }
}
void ISR_EXTI0_LM(void){

	LCD_GotoRowColumn(0,0);
	LCD_writeString("TEMP=");
	LCD_integertoString(Reading[0]/10);
}
void ISR_EXTI1_LDR(void){

	LCD_GotoRowColumn(1,0);
	LCD_writeString("LDR VALUE=");
	LCD_integertoString(Reading[1]/1000);
}
void ISR_EXTI2_POT(void){
	LCD_GotoRowColumn(2,0);
	LCD_writeString("POT VALUE=");
	LCD_integertoString(Reading[2]/1000);

}
int main(){

	EXT0_VID_SET_CALL_BACK(ISR_EXTI0_LM);
	EXT1_VID_SET_CALL_BACK(ISR_EXTI1_LDR);
	EXT2_VID_SET_CALL_BACK(ISR_EXTI2_POT);

	DIO_init();
	LCD_init();
	ADC_init();
//	ADC_voidEnable();
	GIE_voidEnable();
//ALL EXT INTERRUPTS INITALIZED AS FALLNG EDGE
 EXTI0_voidInit();
 EXTI0_voidEnable();
 EXTI1_voidInit();
    EXTI1_voidEnable();
    EXTI2_voidInit();
    EXTI2_voidEnable();
	ADC_voidEnableInt();
	ADC_SetCallback(ISR_ADC_chaining);
//	ADC_voidStartConversion(0);
	ADC_voidStartConversion(channel);


while(1){

 //configure pins as high at first
	DIO_SetPinValue(PORTC_ID,LM_INT,LOGIC_HIGH);
	DIO_SetPinValue(PORTC_ID,LDR_INT,LOGIC_HIGH);
	DIO_SetPinValue(PORTC_ID,POT_INT,LOGIC_HIGH);
//	_delay_ms(100);

	if((Reading[0]/10)>LM_MAX)
	{//put lm pin=0 to trigger interrupt
		DIO_SetPinValue(PORTC_ID,LM_INT,LOGIC_LOW);
		//buzzer
		DIO_SetPinValue(PORTC_ID,BUZZER_ID,LOGIC_HIGH);
		_delay_ms(50);
		DIO_SetPinValue(PORTC_ID,BUZZER_ID,LOGIC_LOW);
	}
	else
	{
		LCD_Clearrow(0);
	}
	if((Reading[1]/1000)>LDR_MAX)
	{
		DIO_SetPinValue(PORTC_ID,LDR_INT,LOGIC_LOW);
		//buzzer
		DIO_SetPinValue(PORTC_ID,BUZZER_ID,LOGIC_HIGH);
		_delay_ms(50);
		DIO_SetPinValue(PORTC_ID,BUZZER_ID,LOGIC_LOW);
	}
	else {

		LCD_Clearrow(1);

	}
	if((Reading[2]/1000)>POT_MAX)
	{
		DIO_SetPinValue(PORTC_ID,POT_INT,LOGIC_LOW);
		DIO_SetPinValue(PORTC_ID,BUZZER_ID,LOGIC_HIGH);
		_delay_ms(50);
		DIO_SetPinValue(PORTC_ID,BUZZER_ID,LOGIC_LOW);
	}
	else{

		LCD_Clearrow(2);

	}
	ADC_voidEnable();
	ADC_voidStartConversion(channel);

}
	return 0;


}

