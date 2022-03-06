#include "EnemiesWave.h"
#include <string.h>

void Wave::Init(char Name[Max_Chars_Name], int EnemiesNumber, int StartingHealth, float MoneyPerEnemey)
{
	strcpy(this->Name, Name);
	this->EnemiesNumber = EnemiesNumber;
	this->StartingHealth = StartingHealth;
	this->MoneyPerEnemy = MoneyPerEnemy;
}

void Wave::SetName(char new_name[Max_Chars_Name])
{
	strcpy(this->Name, new_name);
}

char* Wave::GetName()
{
	return this->Name;
}

void Wave::SetEnemiesNumber(int value)
{
	this->EnemiesNumber = value;
}
int Wave::GetEnemiesNumber()
{
	return this->EnemiesNumber;
}

void Wave::SetStartingHealth(int value)
{
	this->StartingHealth = value;
}
int Wave::GetStartingHealth()
{
	return this->StartingHealth;
}

void Wave::SetMoneyPerEnemy(float sum)
{
	this->MoneyPerEnemy = sum;
}
float Wave::GetMoneyPerEnemy()
{
	return this->MoneyPerEnemy;
}