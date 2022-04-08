#include "Spider.h"

Spider::Spider(int mapSize, int level) :Enemy(mapSize, level)
{
   sightRange = 5;
   curHealth = maxHealth = 15;
   imgName = "enemySpider";
   moveDistance = moveDistance / 2;
   if (moveDistance < 1)
      moveDistance = 1;
   moveMethod = 3;
   attackDamage = 5;
   pointValue = 50;
}