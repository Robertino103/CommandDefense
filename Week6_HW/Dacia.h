#pragma once
#include "Car.h"
class Dacia : public Car
{
public:
	Dacia();
	float StartRace(bool&, int, int) override;
	char* GetName() override;
};
