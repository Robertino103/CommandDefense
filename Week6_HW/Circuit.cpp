#include "Circuit.h"
#include "Car.h"
#include "Weather.h"
#include <iostream>
#include <string>


Circuit::Circuit()
{
	NrOfCars = 0;
	CircuitLength = 0;
	Finished[19] = { 0 };
	TimeToFinish[19] = { 0 };
	weather = -1;
	car[0] = 0;
}

void Circuit::AddCar(Car* c)
{
	car[NrOfCars++] = c;
}

void Circuit::SetLength(int newlength)
{
	this->CircuitLength = newlength;
}

void Circuit::SetWeather(int w)
{
	this->weather = w;
}

void Circuit::Race()
{
	for (int i = 0; i < NrOfCars; i++)
	{
		bool b = false;
		TimeToFinish[i] = car[i]->StartRace(b, weather, CircuitLength);
		Finished[i] = b;
	}
}

void Circuit::ShowFinalRanks()
{
	int inv;
	do {
		inv = 0;
		for (int i = 0; i < NrOfCars-1; i++)
		{
			if ((Finished[i]) && (TimeToFinish[i] > TimeToFinish[i + 1]))
			{
				std::swap(car[i], car[i+1]);
				std::swap(TimeToFinish[i], TimeToFinish[i+1]);
				inv = 1;
			}
		}
	} while (inv != 0);

	int cntrank = 1;

	for (int i = 0; i < NrOfCars; i++)
	{
		if (Finished[i])
		{
			std::cout << cntrank++ << " ) ";
			std::cout << car[i]->GetName() << " --> " << TimeToFinish[i] << std::endl;
		}
	}
	std::cout << std::endl;
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < NrOfCars; i++)
	{
		if (!Finished[i])
		{
			std::cout << car[i]->GetName() << " --> " << " DNF" << std::endl;
		}
	}
	std::cout << std::endl;
}


