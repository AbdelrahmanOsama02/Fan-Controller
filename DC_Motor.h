/******************************************************************************
 *
 * Module: DC_Motor
 *
 * File Name: DC_Motor.h
 *
 * Description: Header file for the DC_Motor driver
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_Motor_IN_Port PORTB_ID

#define DC_Motor_IN1_Pin PIN0_ID
#define DC_Motor_IN2_Pin PIN1_ID
#define DC_Motor_IN3_Pin PIN2_ID
#define DC_Motor_IN4_Pin PIN4_ID


#define DC_Motor_EN_Port PORTB_ID

#define DC_Motor_EN1_Pin	PIN3_ID
#define DC_Motor_EN2_Pin	PIN5_ID


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum {
	stop,CCW,CW
}DcMotor_State;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description:
 *  -The Function responsible for setup the direction for the two
 *   motor pins through the GPIO driver.
 *
 *  -Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);


/*
 * Description:
 * -The function responsible for rotate the DC Motor CW/ or A-CW or
 *  stop the motor based on the state input state value.
 *
 * -Send the required duty cycle to the PWM driver based on the
 *  required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_MOTOR_H_ */
