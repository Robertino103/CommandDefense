#pragma once
#include "Car.h"
class Mazda : public Car
{
public:
	Mazda();
	float StartRace(bool&, int, int) override;
	char* GetName() override;
};

