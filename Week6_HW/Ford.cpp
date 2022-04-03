#include "Ford.h"
#include "Weather.h"

Ford::Ford()
{
	FuelCapacity = 55;
	FuelConsumption = 18;
	AverageSpeed[Rain] = 60;
	AverageSpeed[Sunny] = 77;
	AverageSpeed[Snow] = 52;
	CarName = (char*)"Ford";
}

float Ford::StartRace(bool& b, int w, int circuitlength)
{
	int Speed = AverageSpeed[w];
	float Distance = (FuelCapacity / FuelConsumption) * 100;
	float Time_In_Hours = Distance / AverageSpeed[w];

	b = Distance > circuitlength;

	return (Time_In_Hours * circuitlength / Distance);
}

char* Ford::GetName()
{
	return CarName;
}