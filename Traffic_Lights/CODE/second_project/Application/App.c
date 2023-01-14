/*
 * App.c
 *
 *  Created on: Jan 9, 2023
 *      Author: Nada Karam
 */

#include "App.h"

void switch_func(void)
{
	if(Green_state==HIGH)
	{
		//both yellow leds toggle for 5 seconds then the cars green led is off and pedestrian red led is on
		yellow_led_pedestrians();
		LED_OFF(Port_A,Pin_0);
		LED_OFF(Port_B,Pin_2);
		LED_ON(Port_A,Pin_2);
		LED_ON(Port_B,Pin_0);
		//function to make a delay for 5 seconds using Timer1 overflow
		delay2();
		//cars red led is off and pedestrian green led is still on
		LED_OFF(Port_A,Pin_2);
		//both yellow leds toggle for 5 seconds
		yellow_led_pedestrians();
		//both yellow leds will be off and we will back to normal mode
		LED_OFF(Port_B,Pin_0);
		LED_OFF(Port_B,Pin_1);
		LED_OFF(Port_A,Pin_1);
		LED_ON(Port_A,Pin_0);
		LED_ON(Port_B,Pin_2);
		delay2();

	}
	else if(Yellow_state== HIGH)
	{
		//both yellow leds will stop and toggle for more 5 seconds
		LED_OFF(Port_A,Pin_1);
		LED_OFF(Port_B,Pin_1);
		yellow_led_pedestrians();
		//cars red led will be on and pedestrian green led will be on for 5 seconds
		LED_ON(Port_A,Pin_2);
		LED_ON(Port_B,Pin_0);
		LED_OFF(Port_B,Pin_2);
		//function to make a delay for 5 seconds using Timer1 overflow
		delay2();
		// both yellow will toggle again for 5 seconds then back to normal mode
		yellow_led_pedestrians();
		LED_OFF(Port_B,Pin_0);
		LED_ON(Port_B,Pin_2);
		LED_ON(Port_A,Pin_0);
		LED_OFF(Port_A,Pin_2);
		delay2();
		LED_OFF(Port_A,Pin_0);
		yellow_led_cars_toggle();
		LED_ON(Port_A,Pin_2);
		LED_ON(Port_B,Pin_0);
		delay2();
		LED_OFF(Port_A,Pin_2);
		//	Dio_read(Port_B,Pin_0,&Green_state2);
	}
	else if(Red_state==HIGH)
	{
		//cars red led on and pedestrian green on for 5 more seconds
		LED_ON(Port_B,Pin_0);
		LED_ON(Port_A,Pin_2);
		Dio_read(Port_B,Pin_0,&Green_state2);
		//function to make a delay for 5 seconds using Timer1 overflow
		delay2();
		Dio_read(Port_B,Pin_0,&Green_state2);
		//cars red led off
		LED_OFF(Port_A,Pin_2);
		Dio_read(Port_B,Pin_0,&Green_state2);
		// both yellow will toggle again for 5 seconds and pedestrian green led is off then back to normal mode
		yellow_led_pedestrians();
		LED_OFF(Port_B,Pin_0);
		//back to normal mode again
		LED_ON(Port_A,Pin_0);
		LED_ON(Port_B,Pin_2);
		delay2();
		LED_OFF(Port_A,Pin_0);
		yellow_led_cars_toggle();
		LED_OFF(Port_B,Pin_2);
		LED_ON(Port_A,Pin_2);
		LED_ON(Port_B,Pin_0);
		delay2();
		LED_OFF(Port_A,Pin_2);
	}
	else if(Red_state==HIGH && Green_state2 == HIGH)
	{
		//Do nothing
	}
	//	main();
}

ISR(INT0_vect)
{
	switch_func(); // call the function that will set the pedestrian mode

}
void INT0_Init(void)
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	PORTD |=(1<<PD2);                   //pull up resistor configuration
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}


void App_start(void)
{
	INT0_Init();                // Enable external INT0
	//initialize all cars leds
	LED_init(Port_A,Pin_0);
	LED_init(Port_A,Pin_1);
	LED_init(Port_A,Pin_2);

	//initialize all pedestrian leds
	LED_init(Port_B,Pin_0);
	LED_init(Port_B,Pin_1);
	LED_init(Port_B,Pin_2);


	while(1)
	{
		//cars green led on for and pedestrian red led on 5 seconds
		LED_ON(Port_A,Pin_0);
		LED_ON(Port_B,Pin_2);
		Button_read(Port_A,Pin_0,&Green_state);
		//function to make a delay for 5 seconds using Timer0 overflow
		delay1();
		//cars green led is off
		LED_OFF(Port_A,Pin_0);
		Button_read(Port_A,Pin_0,&Green_state);
		//cars yellow led toggle for 5 seconds then stop
		yellow_led_cars_toggle();
		//cars red led is on and pedestrian green led is on and pedestrian red led is off
		LED_ON(Port_A,Pin_2);
		LED_ON(Port_B,Pin_0);
		LED_OFF(Port_B,Pin_2);
		Button_read(Port_A,Pin_2,&Red_state);
		//function to make a delay for 5 seconds using Timer0 overflow
		delay1();
		//cars red led is off and pedestrian green led is off and pedestrian red led is on
		LED_OFF(Port_A,Pin_2);
		LED_OFF(Port_B,Pin_0);
		LED_ON(Port_B,Pin_2);
		Button_read(Port_A,Pin_2,&Red_state);
		//cars yellow led toggle for 5 seconds then stop then we restart normal mode again
		yellow_led_cars_toggle();
	}



}


