#ifndef STEINHART_HART_COEFFICIENTS_H_
#define STEINHART_HART_COEFFICIENTS_H_


#include <math.h>

#include "Matrix/Matrix_3x3.h"


struct Steinhart_Hart_Coefficients {
	float a;
	float b;
	float c;
};


/// Calculate the coefficients based on three sets of temperature and resistance.
/// Use Cramer's Rule to solve the three linear equations.
/// The three pairs should be the lowest temperature you need to read,
/// the highest temperature you need to read, and a temperature in the middle.
/// \param	r1	the resistance in ohms
/// \param	t1	the temperature in Kelvin
/// \returns	the set of coefficients generated by the given temperatures and resistances
struct Steinhart_Hart_Coefficients Get_Coefficients(
		const float r1, const float t1, 
		const float r2, const float t2, 
		const float r3, const float t3);


#endif