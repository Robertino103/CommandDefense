#pragma once
#include "Car.h"
class Dacia : public Car
{
public:
	Dacia();
	float Cursa(int lungime_circuit, Weather weather);
	char* GetName();
};
