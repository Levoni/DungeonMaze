//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Program: Maze Runner game; player must escape from random labyrinths
// Purpose: Handles functionality for executing armor in game regarding
//          spawning and using.
//-----------------------------------------------------------------------

#ifndef __Armor_H
#define __Armor_H

#include"Items.h"

using namespace std;

//-----------------------------------------------------------------------
// Contains functions used for creating and handling armor in game
//-----------------------------------------------------------------------
class Armor : public Items
{
public:
   Armor(int lvl) { Level = lvl; rarity = (rand() % 3) + 1; defense = lvl + rarity * 2; type = 2; }

   //--------------------------------------------------------------------
   // Activates armor for player.
   //--------------------------------------------------------------------
	void ExecuteItem(Player * hero) { hero->SetArmor(defense, rarity); }

   //--------------------------------------------------------------------
   // Returns how much damage this armor will block
   //--------------------------------------------------------------------
	int getModifier() { return defense; }

   //--------------------------------------------------------------------
   // Returns rarity of this armor
   //--------------------------------------------------------------------
   int getRarity() { return rarity; }

private:
	int defense;
   int rarity;
};

#endif