/*
 * LED.h
 *
 *  Created on: Jan 9, 2023
 *      Author: Nada Karam
 */

#ifndef LED_LED_H_
#define LED_LED_H_
#include "../../MCAL/DIO/Dio.h"
#include"../../MCAL/TIMERS/Timer.h"
#include"../../MCAL/DIO/dio.h"
#include <util/delay.h>
void LED_init(uint8_t PortNumber,uint8_t PinNumber);
void LED_ON(uint8_t PortNumber,uint8_t PinNumber);
void LED_OFF(uint8_t PortNumber,uint8_t PinNumber);
void LED_toggle(uint8_t PortNumber, uint8_t PinNumber);
void yellow_blink(void);
void yellow_led_cars_toggle(void);
void yellow_led_pedestrians(void);
#endif /* LED_LED_H_ */
