#include "Enemy.h"

Enemy::Enemy(int h, int d) {
	damage = d;
	health = h;
}

bool Enemy::TakeDamage(int d) {
	health -= d;
	if (health > 0) {
		return true;
	}
	else {
		return false;
	}
}