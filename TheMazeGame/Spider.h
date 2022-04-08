//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Program: Maze Runner game; player must escape from random labyrinths
// Purpose: Contains code that creates and manages instances of Bat
//-----------------------------------------------------------------------

#ifndef __SPIDER_H
#define __SPIDER_H

#include "Enemy.h"

//-----------------------------------------------------------------------
// Sets behavior and traits of Spider enemy
//-----------------------------------------------------------------------
class Spider : public Enemy
{
public:
	//--------------------------------------------------------------------
	// Constructor for creating spider enemy
	//--------------------------------------------------------------------
   Spider(int mapSize, int level);
};

#endif __SPIDER_H