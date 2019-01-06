/*
 * pH.h
 * this pH sensor interface follows the
 * Nernst equation: V = Voffset - slope * R * T * LN10 / F * (pH - 7)
 * Voffset = V_pH7 + V_ADC_Offset
 * to give accurate pH readings in different temperatures 
 * Created: 12-Dec-18 3:27:22 PM
 *  Author: mohamed
 */ 


#ifndef PH_H_
#define PH_H_
#include "config.h"
#define GAS_CONSTANT 8.3144
#define FARADAY_CONSTANT 96485
#define lN_10 2.3026
static double slope;
static double offset;
static double ideal_slope(double temp);
static double relative_slope(double temp, double ph1, double v1, double ph2, double v2); //use for calibration
static double compute_offset(double temp, double slope, double ph, double v);// v at ph = 7!
static double compute_ph(double temp, double offset, double slope, double v);
void calibrate_ph(double temp, double ph1, double v1, double ph2, double v2);
double get_ph(double temp, double v);





#endif /* PH_H_ */