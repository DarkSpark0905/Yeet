#pragma once
#include <iostream>
#include <string>

//Creates a class called enemy
class Enemy {
//Used pubicly across any C++ thingie
public:
	//Constructs an enemy with a set health and damage
	Enemy(int h, int d);
	//values for the enemies health and damage
	int health;
	int damage;
	//If they took enough damage to die then return false else return true
	bool takeDamage(int d);
};