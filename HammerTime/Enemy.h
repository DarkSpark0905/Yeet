#pragma once
#include <iostream>
#include <string>
class Enemy {
public:
	Enemy(int h, int d);
	int health;
	int damage;
	bool takeDamage(int d);
};