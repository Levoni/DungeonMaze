//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Program: Maze Runner game; player must escape from random labyrinths
// Purpose: Contains code used to create and manipulate instances of
//          key
//-----------------------------------------------------------------------

#ifndef __KEY_H
#define __KEY_H

#include "Items.h"

//-----------------------------------------------------------------------
// Sets main functionality for door key
//-----------------------------------------------------------------------
class DoorKey : public Items
{
public:
   DoorKey() { type = 3; }

   //--------------------------------------------------------------------
   // Makes it so player has key
   //--------------------------------------------------------------------
   void ExecuteItem(Player *hero) { hero->setKey(true); }

private:
   //--------------------------------------------------------------------
   // Returns 0, as this does not modify damage or armor.
   //--------------------------------------------------------------------
   int getModifier() { return 0; }

   //--------------------------------------------------------------------
   // Returns 0, as this item is not a weapon or armor
   //--------------------------------------------------------------------
   int getRarity() { return 0; }
};

#endif __KEY_H

