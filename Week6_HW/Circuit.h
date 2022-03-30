#pragma once
#include "Weather.h"
#include "Car.h"
class Circuit
{
	int length;
	Weather weather;
	Car* cars[10];
	int count;
	int max_count = 10;
	float timp[10];

public:
	Circuit();
	void SetLength(int length);
	void SetWeather(Weather weather);
	bool AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
};

