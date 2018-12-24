/*
 * pH.h
 * this pH sensor interface follows the
 * Nernst equation: V = Voffset - slope * R * T * LN10 / F * (pH - 7)
 * Voffset = V_pH7 + V_ADC_Offset
 * to give accurate pH readings in different temperatures 
 * Created: 12-Dec-18 3:27:22 PM
 *  Author: mohamed
 */ 
#include "pH.h"
//method to calculate the ideal v/ph slope at specified temp
static double ideal_slope(double temp)
{
	return (GAS_CONSTANT * ( temp + 273 ) * lN_10 / FARADAY_CONSTANT);
}
//calculating relative slope using two samples calibration data
//ideally the first sample is of pH 7 so it will be used also as offset
static double relative_slope(double temp, double ph1, double v1, double ph2, double v2) 
{
	return ( (v1 - v2) / (ph2 - ph1) / ideal_slope(temp) );
}
//calculating the Voff (v at ph = 7)
static double compute_offset(double temp, double slope, double ph, double v)// v at ph = 7!
{
	return ( v + slope * ideal_slope( temp ) * ( ph - 7) );
}
//calculating the ph value after accounting for temp differences using the relative slope
static double compute_ph(double temp, double offset, double slope, double v)
{
	return ( 7 + (offset - v) / (slope * ideal_slope(temp)) );
}
//must be called at the start of operation and routinely to account for sensor depredation
//a method that takes two points sample readings for calibration
//ideally the first sample is of pH 7 so it will be used also as offset
void calibrate_ph(double temp, double ph1, double v1, double ph2, double v2)
{
	slope = relative_slope (temp, ph1, v1, ph2, v2);
	offset = compute_offset(temp, slope, ph1, v1);
}
//interface method that returns the PH
double get_ph(double temp, double v)
{
	return compute_ph(temp, offset, slope, v);
}