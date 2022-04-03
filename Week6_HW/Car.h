#pragma once

class Car
{
protected:
	int FuelCapacity;
	float FuelConsumption;
	int AverageSpeed[3];
	char* CarName;
public:
	virtual float StartRace(bool&, int, int) = 0;
	virtual char* GetName() = 0;
};