/*
 * pump.h
 * this is an interface for peristaltic liquid pump
 * it uses A4988 Stepper Motor Driver
 * which controls a stepper motor using STEP - DIR PINS
 * Created: 11-Dec-18 3:36:49 PM
 *  Author: mohamed
 */ 


#ifndef PUMP_H_
#define PUMP_H_

#include "IO_Macros.h"
#include "config.h"

#define STEP_ANGLE 1.8
#define ANGLE_PER_ML 1890
#define STEP_PER_ML (ANGLE_PER_ML/STEP_ANGLE)
#define MAX_FREQ 1 // 1 turn per second
#define MICRO_STEP 16
#define DELAY_PERIOD (0.5 * 1000/(MAX_FREQ * 180 * MICRO_STEP / STEP_ANGLE)) // in milli seconds

typedef enum
{
	PH_Plus,
	PH_Minus,
	Nutrients
	
} pump_identifier;
uint8_t init_pumps();
uint8_t pump_volume(pump_identifier, uint16_t volume);

#endif /* PUMP_H_ */