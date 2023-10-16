/******************************************************************************
 *
 * Module: DC_Motor
 *
 * File Name: DC_Motor.c
 *
 * Description: Source file for the DC_Motor driver
 *
 *******************************************************************************/

#include "Timer0.h"
#include "gpio.h"
#include "DC_Motor.h"


 void DcMotor_Init(void){

	/* Configure Pin PC0 And PC1 As Output Pins For IN1&IN2 For H-Bridge */
	GPIO_setupPinDirection(DC_Motor_EN_Port, DC_Motor_EN1_Pin, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_Motor_IN_Port, DC_Motor_IN1_Pin, PIN_OUTPUT );
	GPIO_setupPinDirection(DC_Motor_IN_Port, DC_Motor_IN2_Pin, PIN_OUTPUT );

	/* Motor is Stop At The Beginning By Put Logic Low For IN1&IN2 */
	GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN1_Pin, LOGIC_LOW) ;
	GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN2_Pin, LOGIC_LOW) ;

 }

 void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	 /*Call PWM signal starter with speed 0->100 as a duty cycle*/
	 PWM_Timer0_Start(speed);

	 /*Choose The State of Motor*/
	 switch (state){

	 	 case stop : /*IN1=LOW & IN2=LOW*/
	 		 	 	 GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN1_Pin, LOGIC_LOW) ;
	 	 	 	 	 GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN2_Pin, LOGIC_LOW) ;
	 	 	 	 	 GPIO_writePin(DC_Motor_EN_Port, DC_Motor_EN1_Pin, LOGIC_LOW);
	 	 	 	 	 break;

	 	 case CW : /*IN1=LOW & IN2=HIGH*/
	 		 	   GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN1_Pin, LOGIC_HIGH) ;
	 	 	 	   GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN2_Pin, LOGIC_LOW) ;
	 	 	 	   break;

	 	 case CCW : /*IN1=HIGH & IN2=LOW*/
	 		 	    GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN1_Pin, LOGIC_LOW) ;
	 	 	 	 	GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN2_Pin, LOGIC_HIGH) ;
	 	 	 	 	break;

	 	 default : /*The Motor is Stop As A Default */
	 		 	   GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN1_Pin, LOGIC_LOW) ;
	 	 	 	   GPIO_writePin(DC_Motor_IN_Port, DC_Motor_IN2_Pin, LOGIC_LOW) ;
	 	 	 	   break;
	 }


 }
