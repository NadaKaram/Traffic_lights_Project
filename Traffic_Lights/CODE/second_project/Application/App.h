/*
 * App.h
 *
 *  Created on: Jan 9, 2023
 *      Author: Nada Karam
 */

#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_
#include"../ECUAL/BUTTON/Button.h"
#include"../ECUAL/LED/LED.h"
#define Pin_0 0
#define Pin_1 1
#define Pin_2 2
uint8_t Red_state,Green_state,Green_state2,Red_state2;
extern  uint8_t Yellow_state;
void switch_func(void);
void Timer0_Delay(void);
void App_start(void);

#endif /* APPLICATION_APP_H_ */
