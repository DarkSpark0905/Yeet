#include "Enemy.h"
#include <ctime>
int main() {
	//Random Seed 
	srand(time(NULL)); //clock() needs #include <time.h>
	//Initialize the number of enemies, how much health the player has, and how much damage the player can do to the enemies
	int enemyNum = 15;
	int p_health = (rand() % 20) + 90;
	int p_damage = (rand() % 5) + 3;
	std::cout << "Player Health: " << p_health << std::endl;
	std::cout << "Player Damage: " << p_damage << std::endl;
	//Creating a pointer 'enemies' that points to an array of all the Enemies
	Enemy ** enemies = new Enemy *[enemyNum];
	//Set random values to Health and Damage for the enemies
	for (int i = 0; i < enemyNum; ++i) {
		enemies[i] = new Enemy((rand() % 20) + 5, (rand() % 5) + 2);
	}
	//Creates a boolean to see if all enemies are still alive, if not break out of the loop and stop
	bool enemiesAlive = true;
	//checks if player is alive and the player hasnt won already
	while (p_health > 0 && enemiesAlive) {
		//A check to see if all enemies have died
		bool e = true;
		//go through and attack each enemy until they all die or you die
		for (int i = 0; i < enemyNum; ++i) {
			//check if there is still an enemy in the ith spot of the array and if the players health is still alive
			if (enemies[i] != NULL && p_health > 0) {
				e = false;
				std::cout << "Enemies " << i << ": " << enemies[i]->health << " -> ";
				//Return a boolean to see if the enemy is alive or dead yet
				bool alive = enemies[i]->takeDamage(p_damage);
				std::cout << enemies[i]->health << std::endl;
				//If the enemy died then delete the enemy
				if (!alive) {
					std::cout << "Enemy " << i << " died!" << std::endl;
					delete enemies[i];
					enemies[i] = NULL;
				}
				// if the enemy didn't die, deal damage to the player
				else {
					std::cout << "Player " << p_health << " -> ";
					p_health -= enemies[i]->damage;
					std::cout << p_health << std::endl;
				}
				std::cout << std::endl;
			}
		}
		if (e) { enemiesAlive = false; }
	}
	//Check if player health is 0 or less than 0
	if (p_health <= 0) {
		std::cout << "You Died, Rip" << std::endl;
	}
	//else the player survived and has won the game
	else {
		std::cout << "You Didn't Die, Not Rip" << std::endl;
	}

	return 0;
}
