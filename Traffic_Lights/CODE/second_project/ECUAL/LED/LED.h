/*
 * LED.h
 *
 *  Created on: Jan 9, 2023
 *      Author: Nada Karam
 */

#ifndef LED_LED_H_
#define LED_LED_H_
#include "../../MCAL/DIO/Dio.h"

void LED_init(uint8_t PortNumber,uint8_t PinNumber);
void LED_ON(uint8_t PortNumber,uint8_t PinNumber);
void LED_OFF(uint8_t PortNumber,uint8_t PinNumber);
void LED_toggle(uint8_t PortNumber, uint8_t PinNumber);
void Normal_mode_Delay(void);
#endif /* LED_LED_H_ */
