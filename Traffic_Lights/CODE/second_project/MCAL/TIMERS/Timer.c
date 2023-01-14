/*
 * TIMER.c
 *
 *  Created on: Jan 11, 2023
 *      Author: Nada Karam
 */

#include "Timer.h"
uint8_t interrupt_flag=0;
uint8_t ovf=0;
#define NUMBR_OF_TICKS_PER_FIVE_SECONDS 20
void Timer2_Delay(void)
{
	TCNT2 = 0; // Set Timer0 initial value to 0

	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR2 = (1<<FOC2) | (1<<CS22) | (1<<CS20) | (1<<CS21);

	while(!(TIFR & (1<<TOV2))); // Wait until the Timer0 Overflow occurs (wait until TOV0 = 1)

	TIFR |= (1<<TOV2); // Clear TOV0 bit by set its value

	TCCR2 = 0; // Stop Timer0 by clear the Clock bits (CS00, CS01 and CS02)
}

void TIMER0_Init_Normal_Mode(void)
{
	TCCR0=0;
	TCCR0 |= (1<<FOC0);
}
//enable global interrupt and timer overflow interrupt enable
void TIMER0_Enable_Interrupt_Normal_Mode(void)
{
	SREG|=(1<<7);
	TIMSK |= (1<<TOIE0);
}
/* Description :
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so put initial timer counter = 0  0 --> 255 (256ms per overflow)
 * so we need timer to overflow 2 times to get a 0.5 second
 */
void TIMER0_Set_Normal_Mode(void)
{
	TCCR0 = (1<<CS02) | (1<<CS00);

}
void TIMER0_Set_Initial_Normal_Mode(int initial_value)
{
	TCNT0=initial_value;
}
void TIMER0_Stop(void)
{
	TCCR0=0;

}

/////////////////delay2////////////////
void TIMER1_Init_Normal_Mode(void)
{
	TCCR1A = 0x00; // normal mode
	TCCR1B = 0x00; // normal mode
}
void TIMER1_Enable_Interrupt_Normal_Mode(void)
{
	SREG|=(1<<7);
	TIMSK |= (1<<TOIE1);
}
void TIMER1_Set_Normal_Mode(void)
{
	//prescaling 256
	TCCR1B |= (1<<CS12);
	TCCR1B = ~(1<<CS10) & ~(1<<CS11);
}
void TIMER1_Set_Initial_Normal_Mode(int initial_value)
{
	TCNT1 = initial_value;
}
void TIMER1_OVF(void)
{
	TIFR |=(1<<TOV1);
}
void TIMER1_Stop(void)
{
	TCCR1B=0;

}
void delay1(void)
{
	//set the timer
	TIMER0_Init_Normal_Mode();
//enable the timer interrupt
	TIMER0_Enable_Interrupt_Normal_Mode();
//set the prescaler
	TIMER0_Set_Normal_Mode();
//set initial value
	TIMER0_Set_Initial_Normal_Mode(11);
	//wait until overflow happens then we clear it
	while(interrupt_flag !=1);
	interrupt_flag=0;
	//stop the timer by re initialize the TCCR0
	TIMER0_Stop();

}
/*
 * the prescaler is 1MHZ /256 then 256/1MHZ is 2.56*10^-4
 *2.56*10^-4 *(65536-46004)=5 seconds
 *delay for 5 seconds using timer1
 *
 */

void delay2(void)
{
	//set the timer
	TIMER1_Init_Normal_Mode();
	//enable the timer interrupt
	TIMER1_Enable_Interrupt_Normal_Mode();
	//set the prescaler
	TIMER1_Set_Normal_Mode();
	//set initial value
	TIMER1_Set_Initial_Normal_Mode(46004);
	while((TIFR & (1<<TOV1))==0);
	TIMER1_OVF();
	TIMER1_Stop();
}
//toggle both leds for 5 seconds

ISR(TIMER0_OVF_vect)
{
	ovf++;
	if(ovf == NUMBR_OF_TICKS_PER_FIVE_SECONDS)
	{
		interrupt_flag=1; // when numbers of flows happens we will set this global flag to tell the timer to stop
		ovf=0;
	}

}

