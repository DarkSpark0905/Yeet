#include "Enemy.h"

Enemy::Enemy(int h, int d) {
	damage = d;
	health = h;
}

bool Enemy::takeDamage(int d) {
	health -= d;
	if (health > 0) {
		return true;
	}
	else {
		return false;
	}
}