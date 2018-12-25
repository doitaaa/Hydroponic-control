/*
 * Servo.c
 *
 * Created: 08-Dec-18 3:33:59 PM
 *  Author: mohamed
 */ 


#include "stdmacros.h"
#include "servo.h"
#include "pump.h"
#include "DHT.h"
int main(void)
{
	double temp;
	double hum;
	
	DDRD|=(1<<PD4)|(1<<PD5);
	
	servosHandle servos;
	init_servos(&servos);
	
	pump_handle pumpPh;
	init_pump(&pumpPh,'A', 0, 'A', 1);
	pump_handle pumpNutrients;
	init_pump(&pumpNutrients,'A', 2, 'A', 3);
	DHT_Setup();
    while(1)
    {
		DHT_Read(&temp, &hum);
		_delay_ms(2000);
    }
}