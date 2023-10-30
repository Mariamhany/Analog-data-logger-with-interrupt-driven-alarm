#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H

#define NULL 0

#define AREF 0
#define AVCC 1
#define INTERNAL 2

#define RIGHT_ADJUSTMENT 0
#define LEFT_ADJUSTMENT 1

#define DIO_U8_PIN_0 0
#define DIO_U8_PIN_1 1
#define DIO_U8_PIN_2 2
#define DIO_U8_PIN_3 3
#define DIO_U8_PIN_4 4
#define DIO_U8_PIN_5 5
#define DIO_U8_PIN_6 6
#define DIO_U8_PIN_7 7

#define AUTO_TRIGGER_ENABLE 1

#define FREE_RUNNING_MODE 0
#define ANALOG_COMP       1
#define EXTERNAL_INT      2
#define TIMER0_COMP       3
#define TIMER0_OVERFLOW   4
#define TIMER1_COMP       5
#define TIMER1_OVERFLOW   6
#define TIMER1_CAPTURE    7

#define DIVID_BY_2    0
#define DIVID_BY_4    1
#define DIVID_BY_8    2
#define DIVID_BY_16   3
#define DIVID_BY_32   4
#define DIVID_BY_64   5
#define DIVID_BY_128  6
/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AREF 				*/
/*						    				AVCC 				*/
/*							    			INTERNAL			*/
/****************************************************************/

#define VOLTAGE_REFERENCE			AVCC



/****************************************************************/
/** !comment : Please Enter the ADJUSTMENT						*/
/** 		   ADJUSTMENT can be : 								*/
/*					    					RIGHT_ADJUSTMENT	*/
/*							    			LEFT_ADJUSTMENT		*/
/****************************************************************/
/****************************************************************/
/** NOTE	 : The preferred adjustment for a 8 bits Resolution	*/
/*				is LEFT_ADJUSTMENT and for a 10 bits Resolution	*/
/*				is RIGHT_ADJUSTMENT								*/
/****************************************************************/

#define ADJUSTMENT				LEFT_ADJUSTMENT


/****************************************************************/
/** !comment : Please Enter the ADC PIN : 						*/
/*			        FROM PIN  0-->7
 *                                                   			*/
/****************************************************************/

//#define ADC_CHANNEL_NUMBER		DIO_U8_PIN_0

/****************************************************************/
/** configure auto trigger mode    */
/****************************************************************/

#define ADC_AUTO_TRIGGER_SOURCE		FREE_RUNNING_MODE

/****************************************************************/
/** configure prescaler			*/
/****************************************************************/

#define ADC_PRESCALLER				DIVID_BY_2




#endif
