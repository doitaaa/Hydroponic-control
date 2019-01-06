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
#include "IO_Macros.h"
#include "config.h"


typedef struct{
	uint8_t posPh;
	uint8_t posNutrients;
}servosHandle;

typedef enum{
	Ph,
	ECT
}servos_identifier;

// note that each servo should be connected to a PWM output 
int init_servos(servosHandle* servos);
int move_servo(double pos, servosHandle* servos, servos_identifier x); // pos in degrees , selector _Ph or _EC



#endif /* SERVO_H_ */