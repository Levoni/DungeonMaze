#include "Bat.h"

Bat::Bat(int mapSize) :Enemy(mapSize)
{
   sightRange = 3;
   curHealth = maxHealth = 10;
   imgName = "enemyBat";
   moveDistance = 2 * moveDistance / 3;
   if(moveDistance < 1)
      moveDistance = 1;
   moveMethod = 0;
   attackDamage = 2;
   pointValue = 25;
}
