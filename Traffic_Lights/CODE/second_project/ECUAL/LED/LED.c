/*
 * LED.c
 *
 *  Created on: Jan 9, 2023
 *      Author: Nada Karam
 */
#include"LED.h"
//#include"Timer.h"
//uint8_t tick=0;
uint8_t gb_flag=LOW;
//initialize the led
uint8_t Yellow_state;
void LED_init(uint8_t PortNumber,uint8_t PinNumber)
{
	Dio_init(PortNumber,PinNumber,OUT);

}
void LED_ON(uint8_t PortNumber,uint8_t PinNumber)
{
	Dio_write(PortNumber,PinNumber,HIGH);
}
void LED_OFF(uint8_t PortNumber,uint8_t PinNumber)
{
	Dio_write(PortNumber,PinNumber,LOW);
}
void LED_toggle(uint8_t PortNumber, uint8_t PinNumber)
{
	Dio_toggle(PortNumber,PinNumber);
}

void yellow_led_pedestrians(void)
{
	TIMER1_Init_Normal_Mode();
	TIMER1_Enable_Interrupt_Normal_Mode();
	TIMER1_Set_Normal_Mode();
	TIMER1_Set_Initial_Normal_Mode(46004);
	while((TIFR & (1<<TOV1))==0)
	{
		LED_toggle(Port_A,Pin_1);
		LED_toggle(Port_B,Pin_1);
		_delay_ms(50);
	}
	LED_OFF(Port_A,Pin_1);
	LED_OFF(Port_B,Pin_1);
	TIMER1_OVF();
	TIMER1_Stop();
}
/*
 * this function is used to toggle both yellow leds for 5 seconds
 *  and make a delay a 0.5 second between the toggle and another
 */
void yellow_led_cars_toggle(void)
{
	uint8_t count=0;
	for(uint8_t i=0;i<10;i++)
	{

		for(count = 0; count < 2; count++)
		{
			LED_toggle(Port_A,Pin_1);
			//LED_toggle(Port_B,Pin_1);
			Button_read(Port_A,Pin_1,&Yellow_state);
			Timer2_Delay(); //it's an alternative to the _delay_ms
		}
		count=0;
		//i=0;
		LED_OFF(Port_A,Pin_1);
		Button_read(Port_A,Pin_1,&Yellow_state);
	}
}
