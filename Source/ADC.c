/*
 * ADC.c
 *
 * Created: 08-Jul-18 2:46:47 PM
 *  Author: mohamed
 */ 
#include "ADC.h"
void init_ADC(){
	
	ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); // enables the ADC and sets the sampling prescaler to 128
	ADMUX = _BV(REFS0); // reference set to AVCC
	
}

uint16_t readAnalog(uint8_t pin){
	ADMUX &= 0b11111000; // clear the last 3 bits
	ADMUX |= pin;
	BitSet(ADCSRA,ADSC); // starts conversion
	while(!BitCheck(ADCSRA,ADIF)); //wait till conversion finishes
	BitSet(ADCSRA,ADIF);// clear interrupt flag
	return ADCL + (ADCH << 8) ;
}
// this method takes 10 sample values sorts them then takes the average of the 6 center values
uint16_t readAnalog_Average(uint8_t pin)
{
	uint16_t temp = 0;
	uint16_t average = 0;
	//takes 10 readings with 10ms delay
	for(int i = 0; i < 10; i++)
	{
		buff[i] = readAnalog(pin);
		_delay_ms(10);
	}
	//sort the analog values from small to large
	for(int i=0;i<9;i++)        
	{
		for(int j=i+1;j<10;j++)
		{
			if(buff[i]>buff[j])
			{
				temp=buff[i];
				buff[i]=buff[j];
				buff[j]=temp;
			}
		}
	}
	//calculate the average of the 6 mid samples
	for(int i = 2; i < 8; i++)
	{
		average += buff[i];
	}
	return average/6;
	
}

double  readVoltage(uint8_t pin)
{
	return (double)readAnalog(pin)*5.0/ADC_resolution;
}
double  readVoltage_Average(uint8_t pin)
{
	return (double)readAnalog_Average(pin)*5.0/ADC_resolution;
}