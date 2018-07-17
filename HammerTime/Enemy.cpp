#include "Enemy.h"
/**
Defining the constructor function
Setting the health and damage values given as arguements to the enemies health and damage
*/
Enemy::Enemy(int h, int d) {
	damage = d;
	health = h;
}
/**
d is the damage being taken by the enemy
minus the health of the enemy by the damage taken
if the health is below zero return false meaning they are dead
if the health is above zero return true meaning they are alive
*/

bool Enemy::takeDamage(int d) {
	health -= d;
	if (health > 0) {
		return true;
	}
	else {
		return false;
	}
}