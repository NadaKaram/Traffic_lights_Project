/*
 * Dio.c
 *
 *  Created on: Jan 6, 2023
 *      Author: Nada Karam
 */
#include "Dio.h"

void Dio_init(uint8_t PortNumber,uint8_t PinNumber,uint8_t Direction)
{

	if(Direction == IN)
	{
		switch(PortNumber)
		{
		case Port_A:
			DDRA &=~(1<<PinNumber);
			break;
		case Port_B:
			DDRB &=~(1<<PinNumber);
			break;
		case Port_C:
			DDRC &=~(1<<PinNumber);
			break;
		case Port_D:
			DDRD &=~(1<<PinNumber);
			break;
		}
	}
	else if(Direction == OUT)
	{
		switch(PortNumber)
		{
		case Port_A:
			DDRA |=(1<<PinNumber);
			break;
		case Port_B:
			DDRB |=(1<<PinNumber);
			break;
		case Port_C:
			DDRC |=(1<<PinNumber);
			break;
		case Port_D:
			DDRD |=(1<<PinNumber);
			break;
		}
	}
}
void Dio_read(uint8_t PortNumber,uint8_t PinNumber,uint8_t *value)
{
	switch(PortNumber)
	{
	case Port_A:
		*value =(PINA & (1<<PinNumber))>>PinNumber;
		break;
	case Port_B:
		*value =(PINB & (1<<PinNumber))>>PinNumber;
		break;
	case Port_C:
		*value =(PINC & (1<<PinNumber))>>PinNumber;
		break;
	case Port_D:
		*value =(PIND & (1<<PinNumber))>>PinNumber;
		break;
	}
	//	return *value;
}
void Dio_write(uint8_t PortNumber,uint8_t PinNumber, uint8_t value)
{
	switch(PortNumber)
	{
	case Port_A:
		if(value == HIGH)
			PORTA |=(1<<PinNumber);
		else if(value == LOW)
			PORTA &=~(1<<PinNumber);
		break;
	case Port_B:
		if(value == HIGH)
			PORTB |=(1<<PinNumber);
		else if(value== LOW)
			PORTB &=~(1<<PinNumber);
		break;
	case Port_C:
		if(value == HIGH)
			PORTC |=(1<<PinNumber);
		else if(value== LOW)
			PORTC &=~(1<<PinNumber);
		break;
	case Port_D:
		if(value == HIGH)
			PORTD |=(1<<PinNumber);
		else if(value == LOW)
			PORTD &=~(1<<PinNumber);
		break;
	}

}
void Dio_toggle(uint8_t PortNumber,uint8_t PinNumber)
{
	switch(PortNumber)
	{
	case Port_A:
		PORTA ^=(1<<PinNumber);
		break;
	case Port_B:
		PORTB ^=(1<<PinNumber);
		break;
	case Port_C:
		PORTC ^=(1<<PinNumber);
		break;
	case Port_D:
		PORTD ^=(1<<PinNumber);
		break;
	}

}

