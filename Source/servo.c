/*
 * servo.c
 *
 * Created: 08-Dec-18 3:35:09 PM
 *  Author: mohamed
 */ 
#include "servo.h"
int init_servos(servosHandle* servos)
{
	PinMode(servoPh_pin, Output);
	PinMode(servoEC_pin, Output);
	TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
	//now the frequency is 50 hz with periodic time of 20ms that gives us a resolution of 1000
	//for 0 pos we need a 1ms pulse that is 20,000/20 = 1000 _ 90 degree = 1500 _ 180 = 2000 
	
	OCR1A =  1000;
	OCR1B =  1000;
	
	TCCR1A = 0b10100010; //sets top to ICR1 and N to 8 and mode to fast PWM
	TCCR1B = 0b00011010;
	ICR1 = 20000;
	servos->posPh = 0;
	servos->posNutrients = 0;
	return 1;
}
int move_servo(double pos, servosHandle* servos, servos_identifier x)
{
	volatile uint16_t temp =999+(pos/180*1000);
	if(pos >= 0 && pos <= 180)
	{
		
		if(x == Ph)
		{
			servos->posPh = pos;
			TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
			TCNT1 = 0;
			OCR1A = temp;
			TCCR1B |= (1 << CS11);
			
		}else
		{
			servos->posNutrients = pos;
			TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
			TCNT1 = 0;
			OCR1B = temp;
			TCCR1B |= (1 << CS11);
		}
		return 1;
	}
	return 0;
}
