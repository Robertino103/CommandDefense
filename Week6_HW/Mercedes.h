#pragma once
#include "Car.h"
class Mercedes : public Car
{
public:
	Mercedes();
	float StartRace(bool&, int, int) override;
	char* GetName() override;
};
