/****************************************************************************
 *  Mini Project 3
 *  FAN CONTROLLER
 *  Author: Abdelrahman Osama
 *****************************************************************************/

#include "gpio.h"
#include "Timer0.h"
#include "adc.h"
#include "DC_Motor.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include <util/delay.h>



int main (void) {

	/*To Save The Temperature Sensor Result*/
	uint8 Temp ;

	/*Reset ADC To Required Configurations By ADC_ConfigType Structure */
	ADC_ConfigType configration = {INTERNAL_2point56V , Prescaler_8 } ;

	/*Call All init Functions in Drivers*/
	ADC_init(&configration);
	LM35_init() ;
	DcMotor_Init() ;
	LCD_init() ;

	/*Clear LCD Screen At The  Beginning*/
	LCD_clearScreen();

	/*Display Welcome Massage*/
	LCD_displayStringRowColumn(0,3,"WELCOME");
	LCD_displayStringRowColumn(1,0,"Fan Control SYS");
	_delay_ms (500) ;

	/*Clear LCD Command*/
	LCD_clearScreen();

	/*Display Fan and Temp In Its Rows&column*/
	LCD_displayStringRowColumn(0,2,"FAN is ");
	LCD_displayStringRowColumn(1,2,"Temp =      C");

	while(1){

		/*Receive The Temperature sensor Result */
		Temp = LM35_getTemperature() ;

		/*Operate system By If  Condition */
		if (Temp<30)
		{
			/*If Temperature < 30, Turn OFF Fan And Display Fan State*/

			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
			DcMotor_Rotate(stop,0);
		}
		else
		{
			/*Else Temperature >30, FAN Is ON Within Range Of Speed */

			/*Display FAN State (ON)*/
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");

			if (Temp>=120)
			{
				/*Rotate In Clockwise Direction With Speed Capacity 100%*/
				DcMotor_Rotate(CW,100) ;
			}
			else if(Temp>=90)
			{
				/*Rotate In Clockwise Direction With Speed Capacity 75%*/
				DcMotor_Rotate(CW,75) ;
			}
			else if(Temp>=60)
			{
				/*Rotate In Clockwise Direction With Speed Capacity 50%*/
				DcMotor_Rotate(CW,50) ;
			}
			else if(Temp>=30)
			{
				/*Rotate In Clockwise Direction With Speed Capacity 25%*/
				DcMotor_Rotate(CW,25) ;
			}
		}




		/*Display Temperature On LCD Screen*/
		LCD_moveCursor(1,8);
		/*To Clear The Excess Term At the 100`s Number When Decrease To 10`s Number*/
		if(Temp<100)
		{
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,9);
		}
		LCD_intgerToString(Temp);



	}




}
