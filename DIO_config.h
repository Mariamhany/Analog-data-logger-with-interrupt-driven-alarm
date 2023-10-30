/*
 * DIO_config.h
 *
 *  Created on: Oct 17, 2023
 *      Author: HP
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "DIO.h"

//#define output 1
//#define input 0



#define PORTA_PIN0 PIN_INPUT  //lm
#define PORTA_PIN1 PIN_INPUT //ldr
#define PORTA_PIN2 PIN_INPUT //potentiometer       // ENABLE (kit)
#define PORTA_PIN3 PIN_OUTPUT // RS
#define PORTA_PIN4 PIN_OUTPUT // ENABLE (proteus)
#define PORTA_PIN5 PIN_OUTPUT
#define PORTA_PIN6 PIN_OUTPUT
#define PORTA_PIN7 PIN_OUTPUT

#define PORTB_PIN0 PIN_OUTPUT //D4
#define PORTB_PIN1 PIN_OUTPUT //D5
#define PORTB_PIN2 PIN_INPUT //INT2          //d6 in kit
#define PORTB_PIN3 PIN_OUTPUT //d6 for lcd in proteus
#define PORTB_PIN4 PIN_OUTPUT //D7
#define PORTB_PIN5 PIN_INPUT
#define PORTB_PIN6 PIN_INPUT
#define PORTB_PIN7 PIN_OUTPUT

#define PORTC_PIN0 PIN_OUTPUT //buzzer
#define PORTC_PIN1 PIN_OUTPUT //to trigger int0 (LM)
#define PORTC_PIN2 PIN_OUTPUT //to trigger int1 (LDR)
#define PORTC_PIN3 PIN_OUTPUT //to trigger int2 (pot)
#define PORTC_PIN4 PIN_INPUT
#define PORTC_PIN5 PIN_OUTPUT
#define PORTC_PIN6 PIN_OUTPUT
#define PORTC_PIN7 PIN_INPUT

#define PORTD_PIN0 PIN_INPUT
#define PORTD_PIN1 PIN_INPUT
#define PORTD_PIN2 PIN_INPUT // int0
#define PORTD_PIN3 PIN_INPUT // int1
#define PORTD_PIN4 PIN_INPUT
#define PORTD_PIN5 PIN_OUTPUT
#define PORTD_PIN6 PIN_OUTPUT
#define PORTD_PIN7 PIN_OUTPUT


#endif /* DIO_CONFIG_H_ */
