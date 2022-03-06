#pragma once
#include <EnemiesWave.h>

class Wave;

class GlobalWave
{
public:
	short Wave_CompareMoney(Wave* wave1, Wave* wave2);
	short Wave_CompareByEnemies(Wave* wave1, Wave* wave2);
};