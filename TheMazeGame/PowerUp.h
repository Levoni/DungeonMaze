//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Handles virtual declarations for powerup children
//-----------------------------------------------------------------------

#ifndef __POWERUP_H
#define __POWERUP_H

#include"Player.h"

using namespace std;

class PowerUp
{
public:
   PowerUp() { ; }

   //-----------------------------------------------------------------------
   // Virtual function
   //-----------------------------------------------------------------------
   virtual void ExecutePowerUp(Player * hero) = 0;

   //-----------------------------------------------------------------------
   // Virtual function
   //-----------------------------------------------------------------------
   virtual int getPowerUpType() = 0;
};
#endif