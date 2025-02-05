#include "Dacia.h"
#include "Weather.h"

Dacia::Dacia()
{
	FuelCapacity = 50;
	FuelConsumption = 10;
	AverageSpeed[Rain] = 50;
	AverageSpeed[Sunny] = 75;
	AverageSpeed[Snow] = 40;
	CarName = (char*)"Dacia";
}

float Dacia::StartRace(bool& b, int w, int circuitlength)
{
	int Speed = AverageSpeed[w];
	float Distance = (FuelCapacity / FuelConsumption) * 100;
	float Time_In_Hours = Distance / AverageSpeed[w];

	b = Distance > circuitlength;
	
	return (Time_In_Hours * circuitlength / Distance);
}

char* Dacia::GetName()
{
	return CarName;
}