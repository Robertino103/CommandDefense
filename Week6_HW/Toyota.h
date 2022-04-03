#pragma once
#include "Car.h"
class Toyota : public Car
{
public:
	Toyota();
	float StartRace(bool&, int, int) override;
	char* GetName() override;
};