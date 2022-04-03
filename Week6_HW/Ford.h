#pragma once
#include "Car.h"
class Ford : public Car
{
public:
	Ford();
	float StartRace(bool&, int, int) override;
	char* GetName() override;
};


