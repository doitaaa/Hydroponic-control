/*
 * pump.h
 * this is an interface for peristaltic liquid pump
 * it uses A4988 Stepper Motor Driver
 * which controls a stepper motor using STEP - DIR PINS
 * Created: 11-Dec-18 3:36:49 PM
 *  Author: mohamed
 */ 

#include "pump.h"
//initialize stepper and set dir and step pins to outputs
uint8_t init_pump(pump_handle* pump, uint8_t dir_port, uint8_t dir_pin, uint8_t step_port, uint8_t step_pin)
{
	pump->dir_pin = dir_pin;
	pump->dir_port = dir_port;
	pump->step_pin = step_pin;
	pump->step_port = step_port;
	//setting the direction and step pins as outputs
	switch (pump->dir_port)
	{
		case ('A'):
			SETBIT(DDRA,pump->dir_pin);
			SETBIT(PORTA,pump->dir_pin);
			break;
		case ('B'):
			SETBIT(DDRB,pump->dir_pin);
			SETBIT(PORTB,pump->dir_pin);
			break;
		case ('C'):
			SETBIT(DDRC,pump->dir_pin);
			SETBIT(PORTC,pump->dir_pin);
			break;
		case ('D'):
			SETBIT(DDRD,pump->dir_pin);
			SETBIT(PORTD,pump->dir_pin);
			break;
	}
	switch (pump->step_port)
	{
		case ('A'):
		SETBIT(DDRA,pump->step_pin);
		break;
		case ('B'):
		SETBIT(DDRB,pump->step_pin);
		break;
		case ('C'):
		SETBIT(DDRC,pump->step_pin);
		break;
		case ('D'):
		SETBIT(DDRD,pump->step_pin);
		break;
	}
	return 1;
}
//step the required number of steps while accounting for micro stepping 
static uint8_t step_stepper(pump_handle* pump, uint16_t steps)
{
	uint8_t pin = pump->step_pin;
	uint8_t port = pump->step_port;
	for (uint16_t i = 0; i < steps * MICRO_STEP; i++)
	{
		switch (port)
		{
			case ('A'):
			SETBIT(PORTA, pin);
			break;
			case ('B'):
			SETBIT(PORTB, pin);
			break;
			case ('C'):
			SETBIT(PORTC, pin);
			break;
			case ('D'):
			SETBIT(PORTD, pin);
			break;
		}
		_delay_ms(DELAY_PERIOD);
		switch (port)
		{
			case ('A'):
			CLRBIT(PORTA, pin);
			break;
			case ('B'):
			CLRBIT(PORTB, pin);
			break;
			case ('C'):
			CLRBIT(PORTC, pin);
			break;
			case ('D'):
			CLRBIT(PORTD, pin);
			break;
		}
		_delay_ms(DELAY_PERIOD);
	}
	return 1;
}
//volume in ML incriments!!!!!!
uint8_t pump(pump_handle* pump, uint16_t volume)
{
	step_stepper(pump, volume * STEP_PER_ML);
	return 1;
}
