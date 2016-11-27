#include "Steinhart_Hart.h"
#include "Test/Test.h"


int main(int argc, char **argv)
{
	// Get Steinhart-Hart coefficients based on known resistance/temperature pairs
	// for an NTC thermistor.
	struct Steinhart_Hart_Coefficients coefficients = Get_Coefficients(
		25415, 5 + 273.15f, 
		10021, 25 + 273.15f, 
		6545, 35 + 273.15f);

	// Compare the calculated coefficients with known coefficients.
	Test_Range_Float("A", coefficients.a, 0.00113840f, 0.001f);
	Test_Range_Float("B", coefficients.b, 0.00023245f, 0.0001f);
	Test_Range_Float("C", coefficients.c, 0.00000009489f, 0.00000001f);

	// Calculate the temperature at the resistances used to calculate the coefficients.
	// The temperature should match within a small amount.
	Test_Range_Float("T1 Kelvin", Get_Temperature_Kelvin(&coefficients, 25415), 5 + 273.15f, 0.1f);
	Test_Range_Float("T2 Kelvin", Get_Temperature_Kelvin(&coefficients, 10021), 25 + 273.15f, 0.1f);
	Test_Range_Float("T3 Kelvin", Get_Temperature_Kelvin(&coefficients, 6545), 35 + 273.15f, 0.1f);

	Test_Range_Float("T1 Celsius", Get_Temperature_Celsius(&coefficients, 25415), 5, 0.1f);
	Test_Range_Float("T2 Celsius", Get_Temperature_Celsius(&coefficients, 10021), 25, 0.1f);
	Test_Range_Float("T3 Celsius", Get_Temperature_Celsius(&coefficients, 6545), 35, 0.1f);

	return 0;
}
