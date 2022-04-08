//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  This class holds information for an instance of weapon
//-----------------------------------------------------------------------

#ifndef __Weapon_H
#define __Weapon_H

#include"Items.h"

using namespace std;

//-----------------------------------------------------------------------
// Manages an instance of weapon
//-----------------------------------------------------------------------
class Weapon : public Items
{
public:
	Weapon(int lvl) { Level = lvl; rarity = (rand() % 3) + 1; damage = lvl + rarity * 5; type = 1;}

   //--------------------------------------------------------------------
   // Executes weapon
   //--------------------------------------------------------------------
	void ExecuteItem(Player * hero) { hero->SetDamage(damage,rarity); }

   //--------------------------------------------------------------------
   // Returns damage
   //--------------------------------------------------------------------
	int getModifier() { return damage; }

   //--------------------------------------------------------------------
   // Returns rarity
   //--------------------------------------------------------------------
	int getRarity() { return rarity; }

private:
	int damage;
   int rarity;
};
#endif
