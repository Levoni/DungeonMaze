#include "Bat.h"

Bat::Bat(int mapSize, int level) :Enemy(mapSize, level)
{
   sightRange = 3;
   curHealth = maxHealth = 10;
   imgName = "enemyBat";
   moveDistance = 2 * moveDistance / 3;
   if (moveDistance < 1)
      moveDistance = 1;
   moveMethod = 0;
   attackDamage = 2 +  level / 3;
   pointValue = 25;
}