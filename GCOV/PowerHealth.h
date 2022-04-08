//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Handles health powerup
//-----------------------------------------------------------------------

#ifndef __POWERHEALTH_H
#define __POWERHEALTH_H
#define DEFAULT_HEAL 20

#include "PowerUp.h"

using namespace std;

class PowerHealth : public PowerUp
{
public:
   PowerHealth() { ; }

   //-----------------------------------------------------------------------
   // Executes heal powerup
   //-----------------------------------------------------------------------
   void ExecutePowerUp(Player * hero) { hero->Heal(DEFAULT_HEAL); }

   //-----------------------------------------------------------------------
   // Returns type
   //-----------------------------------------------------------------------
   int getPowerUpType() { return type; }

private:
   int type = 3;
};
#endif
