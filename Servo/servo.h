/*
 * servo.h
 *
 * Created: 08-Dec-18 3:35:32 PM
 *  Author: mohamed
 * this library uses timer 1 to generate a pwm signal on OCR1A/B
 * it's specific to this project which uses two servo motors to submerge the sensors in the solution
 */ 

#ifndef SERVO_H_
#define SERVO_H_
#include "stdmacros.h"
typedef struct{
	uint8_t posPh;
	uint8_t posNutrients;
}servosHandle;

// note that each servo should be connected to a PWM output 
int init_servos(servosHandle* servos);
int move_servo(double pos, servosHandle* servos, uint8_t selector); // pos in degrees , selector _Ph or _Nutirents



#endif /* SERVO_H_ */