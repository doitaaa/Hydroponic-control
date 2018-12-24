/*
 * servo.h
 *
 * Created: 08-Dec-18 3:35:32 PM
 *  Author: mohamed
 * this library uses timer 1 to generate a pwm signal on OCR1A/B
 */ 

#ifndef SERVO_H_
#define SERVO_H_
#include "stdmacros.h"
typedef struct{
	uint8_t pin; //"A" or "B" pwm output
	uint8_t pos;
}servoHandle;

// note that each servo should be connected to a PWM output 
int init_servo(uint8_t pin, servoHandle* servo);
int move_servo(double pos, servoHandle* servo); // pos in degrees



#endif /* SERVO_H_ */