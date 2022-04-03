#pragma once
#include "Car.h"
#include "Dacia.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "Ford.h"

class Circuit
{
private:
	int CircuitLength;
	Car* car[20];
	float TimeToFinish[20];
	bool Finished[20];
	int NrOfCars;
	int weather;
public:
	Circuit();
	void AddCar(Car* c);
	void SetLength(int newlength);
	void SetWeather(int);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};