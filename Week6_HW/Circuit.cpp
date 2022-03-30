#include "Circuit.h"

void Circuit::SetLength(int length)
{
	this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

bool Circuit::AddCar(Car* c)
{
	if (count < max_count)
	{
		cars[count++] = c;
		return true;
	}
	return false;
}

void Circuit::Race()
{
	for (int i = 0; i < count; i++)
	{
		timp[i] = cars[i]->Cursa(lungime_circuit, weather);
	}
}

void Circuit::ShowFinalRanks()
{

}

Circuit::Circuit()
{
	length = 0;
	count = 0;
}