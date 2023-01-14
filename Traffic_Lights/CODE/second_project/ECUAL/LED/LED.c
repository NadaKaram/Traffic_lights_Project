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

