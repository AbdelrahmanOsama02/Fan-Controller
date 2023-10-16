/******************************************************************************
 *
 * Module: Timer0
 *
 * File Name: Timer0.c
 *
 * Description: Source file for the AVR Timer0 driver
 *
 *******************************************************************************/


#include <avr/io.h>
#include "Timer0.h"
#include "gpio.h"
#include "common_macros.h"



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */
void PWM_Timer0_Start(uint8 duty_cycle_precentage)
{
	/* Set Timer Initial Value to 0*/
	TCNT0 = 0;
	/*Set Compare Value*/
	OCR0  = ( Dudy_Cycle(dudy_cycle_precentage) ) ;
	/*Configure PB3/OC0 as output pin -> pin where the PWM signal is generated */
	GPIO_setupPinDirection(PWM_Signal_Output_Port, PWM_Signal_Output_Pin, PIN_OUTPUT );

	/* Configure timer control register :
	 * 1. Fast PWM mode FOC0=0 & WGM01=1 & WGM00=1
	 * 2. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 3. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

