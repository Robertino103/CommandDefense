#include "Dacia.h"

float Dacia::Cursa(int lungime_circuit, Weather weather)
{
	if (lungime_circuit * fuelConsumption / 100 <= fuelCapacity)
		return lungime_circuit / averageSpeed[weather];
	else
		return -1;
}

char* Dacia::GetName()
{
	return name;
}
