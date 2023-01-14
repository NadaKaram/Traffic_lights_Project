/*
 * Button.c
 *
 *  Created on: Jan 9, 2023
 *      Author: Nada Karam
 */

#ifndef BUTTON_BUTTON_C_
#define BUTTON_BUTTON_C_
#include "Button.h"

void Button_init(uint8_t PortNumber,uint8_t PinNumber)
{
	Dio_init(PortNumber,PinNumber,IN);
}
void Button_read(uint8_t PortNumber,uint8_t PinNumber,uint8_t *value)
{
  Dio_read(PortNumber,PinNumber,value);
}
void Button_write(uint8_t PortNumber,uint8_t PinNumber,uint8_t value)
{
	Dio_write(PortNumber,PinNumber,value);
}
void Button_toggle(uint8_t PortNumber,uint8_t PinNumber)
{
 Dio_toggle(PortNumber,PinNumber);
}
#endif /* BUTTON_BUTTON_C_ */
