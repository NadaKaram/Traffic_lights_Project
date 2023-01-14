/*
 * Dio.h
 *
 *  Created on: Jan 6, 2023
 *      Author: lenovo
 */

#ifndef DIO_H_
#define DIO_H_
#include "../../vip_file/std_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define Pin_0 0
#define Pin_1 1
#define Pin_2 2
#define IN 0
#define OUT 1
#define HIGH 1
#define LOW 0
#define Port_A 'A'
#define Port_B 'B'
#define Port_C 'C'
#define Port_D 'D'
/*
enum day
{
	Port_A=1,Port_B,Port_C,Port_D
};
*/
void Dio_init(uint8_t PortNumber,uint8_t PinNumber,uint8_t Direction);
void Dio_read(uint8_t PortNumber,uint8_t PinNumber,uint8_t *value);
void Dio_write(uint8_t PortNumber,uint8_t PinNumber, uint8_t value);
void Dio_toggle(uint8_t PortNumber,uint8_t PinNumber);

#endif /* DIO_H_ */
