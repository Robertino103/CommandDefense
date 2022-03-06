#include "GlobalFWave.h"

class Wave;
class GlobalWave;

short GlobalWave::Wave_CompareMoney(Wave* wave1, Wave* wave2)
{
	int MoneyPerEnemy_w1 = wave1->GetMoneyPerEnemy();
	int MoneyPerEnemy_w2 = wave2->GetMoneyPerEnemy();

	if (MoneyPerEnemy_w1 > MoneyPerEnemy_w2) return 1;
	else if (MoneyPerEnemy_w1 < MoneyPerEnemy_w2) return -1;
	else return 0;
}

short GlobalWave::Wave_CompareByEnemies(Wave* wave1, Wave* wave2)
{
	int NumberOfEnemies_w1 = wave1->GetEnemiesNumber();
	int NumberOfEnemies_w2 = wave2->GetEnemiesNumber();

	if (NumberOfEnemies_w1 > NumberOfEnemies_w2) return 1;
	else if (NumberOfEnemies_w1 < NumberOfEnemies_w2) return -1;
	else return 0;
}
