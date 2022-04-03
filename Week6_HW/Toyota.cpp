#include "Toyota.h"
#include "Weather.h"

Toyota::Toyota()
{
	FuelCapacity = 50;
	FuelConsumption = 30;
	AverageSpeed[Rain] = 80;
	AverageSpeed[Sunny] = 100;
	AverageSpeed[Snow] = 64;
	CarName = (char*)"Toyota";
}

float Toyota::StartRace(bool& b, int w, int circuitlength)
{
	int Speed = AverageSpeed[w];
	float Distance = (FuelCapacity / FuelConsumption) * 100;
	float Time_In_Hours = Distance / AverageSpeed[w];

	b = Distance > circuitlength;

	return (Time_In_Hours * circuitlength / Distance);
}

char* Toyota::GetName()
{
	return CarName;
}