#pragma once
#include "Weather.h"

class Car
{
protected:
	int fuelCapacity;
	int fuelConsumption;
	int averageSpeed[3];
	char* name;
public:
	virtual float Cursa(int lungime_circuit, Weather weather) = 0;
};

