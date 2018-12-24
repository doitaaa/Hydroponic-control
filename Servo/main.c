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
	volatile double temp;
	volatile double hum;
	DDRD|=(1<<PD4)|(1<<PD5);
	servoHandle servoA;
	servoHandle servoB;
	init_servo('A',&servoA);
	init_servo('B',&servoB);
	uint8_t pos = 0;
	uint8_t pos1 = 180;
	pump_handle pump1;
	init_pump(&pump1,'A', 0, 'A', 1);
	DHT_Setup();
    while(1)
    {
		DHT_Read(&temp, &hum);
		_delay_ms(2000);
    }
}