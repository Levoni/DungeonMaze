#include "SlimeEnemy.h"

SlimeEnemy::SlimeEnemy(int mapSize) :Enemy(mapSize)
{
   sightRange = 3;
   curHealth = maxHealth = 10;
   imgName = "enemySlime";
   moveDistance = moveDistance / 2;
   if(moveDistance < 1)
    moveDistance = 1;
   moveMethod = 2;
   attackDamage = 2;
   pointValue = 10;
}
