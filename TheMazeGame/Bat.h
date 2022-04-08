//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Program: Maze Runner game; player must escape from random labyrinths
// Purpose: Contains code that creates and manages instances of Bat
//-----------------------------------------------------------------------

#ifndef __BAT_H
#define __BAT_H

#include "Enemy.h"

//-----------------------------------------------------------------------
// Sets behavior and traits of Bat enemy
//-----------------------------------------------------------------------
class Bat : public Enemy
{
public:
	//--------------------------------------------------------------------
	// Constructor for bat enemy
	//--------------------------------------------------------------------
	Bat(int mapSize, int level);
};

#endif __BAT_H
