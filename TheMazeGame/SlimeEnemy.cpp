#include "SlimeEnemy.h"

SlimeEnemy::SlimeEnemy(int mapSize, int level) :Enemy(mapSize, level)
{
	sightRange = 3;
	curHealth = maxHealth = 10;
	imgName = "enemySlime";
	moveDistance = moveDistance / 2;
   if (moveDistance < 1)
      moveDistance = 1;
	moveMethod = 2;
	attackDamage = 2 + level / 3;
   pointValue = 10;
}