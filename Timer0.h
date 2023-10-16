 /******************************************************************************
 *
 * Module: Timer0
 *
 * File Name: Timer0.h
 *
 * Description: Header file for the AVR Timer0 driver
 *
 *******************************************************************************/


#ifndef TIMER0_H_
#define TIMER0_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_Signal_Output_Pin PIN3_ID
#define PWM_Signal_Output_Port PORTB_ID


#define Timer0_MaxCount 255

#define Dudy_Cycle(dudy_cycle_precentage) ((((uint16)duty_cycle_precentage*Timer0_MaxCount)/100))

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK, F_CPU_CLOCK, F_CPU_8, F_CPU_64,F_CPU_265 ,F_CPU_1024,External_clk_Falling_edge, External_clk_Rising_edge
}Timer_Prescaler;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Generate A PWM Signal With Specified Frequency And Duty Cycle By Timer0
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* TIMER0_H_ */
