#pragma once
#include <string.h>
#define Max_Chars_Name 200

class Wave
{
private:
	char Name[Max_Chars_Name];
	unsigned int EnemiesNumber;
	int StartingHealth;
	float MoneyPerEnemy;

public:
	void Init(char Name[Max_Chars_Name], int EnemiesNumber, int StartingHealth, float MoneyPerEnemy);

	void SetName(char new_name[Max_Chars_Name]);
	char* GetName();

	void SetEnemiesNumber(int value);
	int GetEnemiesNumber();

	void SetStartingHealth(int value);
	int GetStartingHealth();

	void SetMoneyPerEnemy(float sum);
	float GetMoneyPerEnemy();
};