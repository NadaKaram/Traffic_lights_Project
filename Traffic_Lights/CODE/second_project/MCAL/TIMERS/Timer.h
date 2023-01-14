/*
 * Timer.h
 *
 *  Created on: Jan 11, 2023
 *      Author: Nada Karam
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "../DIO/Dio.h"
#include "../../ECUAL/BUTTON/Button.h"
#include "../../ECUAL/LED/LED.h"
void Timer0_Delay(void);
void delay1(void);
void delay2(void);
void yellow_blink(void);
void yellow_led_cars_toggle(void);
void yellow_led_pedestrians(void);
/*
void TIMER0_Init_Normal_Mode(void);
void TIMER0_Enable_Interrupt_Normal_Mode(void);
void TIMER0_Set_Normal_Mode(void);
void TIMER0_Set_Initial_Normal_Mode(int initial_value);
void TIMER0_Stop(void);
void Timer2_Delay(void);
void Timer2_Init_Normal_Mode(void);
void Timer2_Enable_Interrupt_Normal_Mode(void);
void Timer2_Set_Normal_Mode(void);
void Timer2_Set_Initial_Normal_Mode(void);
void Timer2_Stop_Normal_Mode(void);
*/
#endif /* TIMER_H_ */
