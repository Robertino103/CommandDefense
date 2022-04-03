#include "Mazda.h"
#include "Weather.h"

Mazda::Mazda()
{
	FuelCapacity = 60;
	FuelConsumption = 15;
	AverageSpeed[Rain] = 60;
	AverageSpeed[Sunny] = 80;
	AverageSpeed[Snow] = 45;
	CarName = (char*)"Mazda";
}

float Mazda::StartRace(bool& b, int w, int circuitlength)
{
	int Speed = AverageSpeed[w];
	float Distance = (FuelCapacity / FuelConsumption) * 100;
	float Time_In_Hours = Distance / AverageSpeed[w];

	b = Distance > circuitlength;

	return (Time_In_Hours * circuitlength / Distance);
}

char* Mazda::GetName()
{
	return CarName;
}