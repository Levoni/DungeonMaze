//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Handles full visibility powerup
//-----------------------------------------------------------------------

#ifndef __POWERFULLVISIVILITY_H
#define __POWERFULLVISIVILITY_H

#include "PowerUp.h"

using namespace std;

class PowerFullVisibility: public PowerUp
{
public:
   PowerFullVisibility() { ; }

   //--------------------------------------------------------------------
   // Executes full visiblity powerup
   //--------------------------------------------------------------------
   void ExecutePowerUp(Player * hero) { hero->SetFullVisibility(true); }

   //--------------------------------------------------------------------
   // Returns type
   //--------------------------------------------------------------------
   int getPowerUpType() { return type; }

private:
   int type = 1;

};
#endif