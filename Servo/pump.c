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
	PinMode(dir_port, dir_pin, Output);
	DigitalWrite(dir_port,dir_pin,True);
	PinMode(step_port,step_pin,Output);
	return 1;
}
//step the required number of steps while accounting for micro stepping 
static uint8_t step_stepper(pump_handle* pump, uint16_t steps)
{
	uint8_t pin = pump->step_pin;
	uint8_t port = pump->step_port;
	for (uint16_t i = 0; i < steps * MICRO_STEP; i++)
	{
		DigitalWrite(step_port, step_pin, True);
		_delay_ms(DELAY_PERIOD);
		DigitalWrite(step_port, step_pin, False);
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
