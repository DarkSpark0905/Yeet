#include "Enemy.h"
#include <time.h>
int main() {
	srand(clock());
	int enemyNum = 10;
	int p_health = 100;
	int p_damage = 5;
	Enemy ** enemies = new Enemy *[enemyNum];
	for (int i = 0; i < enemyNum; ++i) {
		enemies[i] = new Enemy((rand() % 20) + 5, (rand() % 5) + 1);
	}
	bool enemiesAlive = true;
	while (p_health > 0 && enemiesAlive) {
		bool e = true;
		for (int i = 0; i < enemyNum; ++i) {
			if (enemies[i] != NULL && p_health > 0) {
				e = false;
				std::cout << "Enemies " << i << ": " << enemies[i]->health << " -> ";
				bool alive = enemies[i]->takeDamage(p_damage);
				std::cout << enemies[i]->health << std::endl;
				if (!alive) {
					std::cout << "Enemy " << i << " died!" << std::endl;
					delete enemies[i];
					enemies[i] = NULL;
				}
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
	if (p_health <= 0) {
		std::cout << "You Died, Rip" << std::endl;
	}
	else {
		std::cout << "You Didn't Die, Not Rip" << std::endl;
	}

	return 0;
}
