#include "EnemyController.h"
#include "Enemy.h" // to actualy use the field Enemy declared in the header by forward declaration, we use the field here
#include <iostream>

void EnemyController::Init(int maximumEnemies, int step, Point initialLocation)
{
	enemies = new Enemy[maximumEnemies];
	this->SpawnedEnemies = 0;
	for (int i = 0; i < sizeof(enemies); ++i)
	{
		enemies[i].Init(initialLocation, ENEMY_HEALTH);
		this->stepSize = step;
	}
}

void EnemyController::Uninit()
{
	delete[] enemies;
}

void EnemyController::Move(EnemyDirection direction)
{
	for (int i = 0; i < SpawnedEnemies; ++i)
	{
		enemies[i].Move(direction, this->stepSize);
	}
}

void EnemyController::DamageAll()
{
	for (int i = 0; i < SpawnedEnemies; ++i)
	{
		enemies[i].Shoot(i + 1);
	}
}

int EnemyController::CountKilledEnemies()
{
	unsigned int dead_enemies_count = 0;
	for (int i = 0; i < SpawnedEnemies; ++i)
	{
		if (enemies[i].IsDead()) dead_enemies_count++;
	}
	return dead_enemies_count;
}

bool EnemyController::SpawnEnemy()
{
	if (SpawnedEnemies >= sizeof(enemies)) return false;
	else return true;
}