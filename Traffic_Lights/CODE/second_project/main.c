/*
 * main.c
 *
 *  Created on: Jan 11, 2023
 *      Author: Nada Karam
 */

#include "Application/App.h"
uint8_t high=1;
int main(void)
{
	App_start();
	/* testing the timers
	LED_ON(Port_A,Pin_0);
	delay1();
	LED_OFF(Port_A,Pin_0);
	delay2();
	LED_ON(Port_A,Pin_0);
	*/

	/* testing the other drivers
	Dio_init(Port_A,Pin_0,1);
	Dio_write(Port_A,Pin_0,1);
	_delay_ms(3000);
	 Button_init(Port_C,Pin_1);
   Button_read(Port_C,Pin_1,&high);
   if(high==0)
   {
	   Dio_write(Port_A,Pin_0,0);
	   LED_ON(Port_B,Pin_2);
   }
   */
}
