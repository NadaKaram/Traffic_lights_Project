/*
 * Button.h
 *
 *  Created on: Jan 9, 2023
 *      Author: Nada Karam
 */

#ifndef BUTTON_BUTTON_H_
#define BUTTON_BUTTON_H_
#include "../../MCAL/DIO/Dio.h"
#include"../../MCAL/TIMERS/Timer.h"
#include"../../MCAL/DIO/dio.h"
void Button_init(uint8_t PortNumber,uint8_t PinNumber);
void Button_read(uint8_t PortNumber,uint8_t PinNumber,uint8_t *value);
void Button_write(uint8_t PortNumber,uint8_t PinNumber,uint8_t value);
void Button_toggle(uint8_t PortNumber,uint8_t PinNumber);

#endif /* BUTTON_BUTTON_H_ */
