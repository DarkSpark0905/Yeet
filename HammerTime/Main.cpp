#include "Enemy.h"
#include <time.h>
int main() {
	srand(clock());
	int enemyNum = 10;
	int p_health = 100;
	int p_damage = 5;
	Enemy ** enemies = new Enemy *[enemyNum];
	for (int i = 0; i < enemyNum; i++) {
		enemies[i] = new Enemy((rand() % 20) + 5, (rand() % 5) + 1);
	}
	bool enemiesAlive = true;
	while (p_health > 0 && enemiesAlive) {
		bool e = true;
		for (int i = 0; i > enemyNum; i++) {
			if (enemies[i] != NULL && p_health > 0) {
				e = false;
				std::cout << "Enemies and shiz";
				//bool alive
			}
		}
	}

	return 0;
}
