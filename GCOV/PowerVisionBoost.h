//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Handles vision boost
//-----------------------------------------------------------------------

#ifndef __POWERVISIONBOOST_H
#define __POWERVISIONBOOST_H

#include "PowerUp.h"

using namespace std;

class PowerVisionBoost : public PowerUp
{
public:
   PowerVisionBoost() { ; }

   //-----------------------------------------------------------------------
   // Executes vision boost
   //-----------------------------------------------------------------------
   void ExecutePowerUp(Player * hero) { hero->SetVisionBoost(true); }

   //-----------------------------------------------------------------------
   // returns type
   //-----------------------------------------------------------------------
   int getPowerUpType() { return type; }

private:
   int type = 2;
};
#endif