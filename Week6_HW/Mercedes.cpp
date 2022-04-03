#include "Mercedes.h"
#include "Weather.h"

Mercedes::Mercedes()
{
	FuelCapacity = 50;
	FuelConsumption = 30;
	AverageSpeed[Rain] = 80;
	AverageSpeed[Sunny] = 100;
	AverageSpeed[Snow] = 64;
	CarName = (char*)"Mercedes";
}

float Mercedes::StartRace(bool& b, int w, int circuitlength)
{
	int Speed = AverageSpeed[w];
	float Distance = (FuelCapacity / FuelConsumption) * 100;
	float Time_In_Hours = Distance / AverageSpeed[w];

	b = Distance > circuitlength;

	return (Time_In_Hours * circuitlength / Distance);
}

char* Mercedes::GetName()
{
	return CarName;
}