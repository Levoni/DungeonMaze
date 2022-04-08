//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Project: Maze Runner game; player must escape from random labyrinths
// Purpose: Handles behavior of enemy slime
//-----------------------------------------------------------------------

#ifndef __SLIMEENEMY_H
#define __SLIMEENEMY_H

#include "Enemy.h"

//-----------------------------------------------------------------------
// Sets behavior and traits of slime enemy
//-----------------------------------------------------------------------
class SlimeEnemy : public Enemy
{
public:
   //-----------------------------------------------------------------------
   // Constructor for creating a Slime Enemy
   //-----------------------------------------------------------------------
	SlimeEnemy(int mapSize, int level);
};
#endif