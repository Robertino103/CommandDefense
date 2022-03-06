#include "Enemy.h"
#include <iostream>

void Enemy::Init(Point initialLocation, int initialHealth)
{
	this->health = initialHealth;
	this->location = initialLocation;
}

int Enemy::GetHealth()
{
	return this->health;
}
void Enemy::SetHealth(int hp)
{
	this->health = hp;
}

void Enemy::Move(EnemyDirection direction, int step)
{
	if (EnemyDirection::UpDirection) this->location.y -= step;
	if (EnemyDirection::DownDirection) this->location.y += step;
	if (EnemyDirection::LeftDirection) this->location.x -= step;
	if (EnemyDirection::RightDirection) this->location.x += step;
}

bool Enemy::IsDead()
{
	if (this->health <= 0) return true;
	else return false;
}

void Enemy::Shoot(int damage)
{
	this->health -= damage;
}
