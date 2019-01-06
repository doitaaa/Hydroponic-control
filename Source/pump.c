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
uint8_t init_pumps()
{	
	//setting the direction and step pins as outputs
	PinMode(pumpPhPlus_StepPin, Output);
	PinMode(pumpPhMinus_StepPin, Output);
	PinMode(pumpNutrients_StepPin, Output);
	return 1;
}
//step the required number of steps while accounting for micro stepping 
static uint8_t step_stepper(pump_identifier x, uint16_t steps)
{
	switch (x)
	{
	case PH_Plus: 
		for (uint16_t i = 0; i < steps * MICRO_STEP; i++)
		{
			DigitalWrite(pumpPhPlus_StepPin, True);
			_delay_ms(DELAY_PERIOD);
			DigitalWrite(pumpPhPlus_StepPin, False);
			_delay_ms(DELAY_PERIOD);
		}
		break;
		
	case PH_Minus:
		for (uint16_t i = 0; i < steps * MICRO_STEP; i++)
		{
			DigitalWrite(pumpNutrients_StepPin, True);
			_delay_ms(DELAY_PERIOD);
			DigitalWrite(pumpNutrients_StepPin, False);
			_delay_ms(DELAY_PERIOD);
		}
		break;
	case Nutrients:
		for (uint16_t i = 0; i < steps * MICRO_STEP; i++)
		{
			DigitalWrite(pumpPhMinus_StepPin, True);
			_delay_ms(DELAY_PERIOD);
			DigitalWrite(pumpPhMinus_StepPin, False);
			_delay_ms(DELAY_PERIOD);
		}
		break;
	}
	
	return 1;
}
//volume in ML incriments!!!!!!
uint8_t pump_volume(pump_identifier x, uint16_t volume)
{
	step_stepper(x, volume * STEP_PER_ML);
	return 1;
}
