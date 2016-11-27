#ifndef STEINHART_HART_H_
#define STEINHART_HART_H_


#include <math.h>

#include "Steinhart_Hart_Coefficients.h"


/// \param	resistance	the resistance in ohms
/// \returns	the temperature, in Kelvin, for the given resistance
static inline float Get_Temperature_Kelvin(const struct Steinhart_Hart_Coefficients *shc, const float resistance)
{
	float ln_r = log(resistance);
	float inverse_temperature = shc->a + shc->b * ln_r + shc->c * (ln_r * ln_r * ln_r);
	return 1.0f / inverse_temperature;
}


/// \param	resistance	the resistance in ohms
/// \returns	the temperature, in Kelvin, for the given resistance
static inline float Get_Temperature_Celsius(const struct Steinhart_Hart_Coefficients *shc, const float resistance)
{
	return Get_Temperature_Kelvin(shc, resistance) - 273.15f;
}


#endif
