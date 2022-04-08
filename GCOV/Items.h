//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Sets base behavior for in game items
//-----------------------------------------------------------------------

#ifndef __Items_H
#define __Items_H

#include"Player.h"

using namespace std;

//-----------------------------------------------------------------------
// Controls in game items
//-----------------------------------------------------------------------
class Items
{
public:

	Items() { ; }

   //--------------------------------------------------------------------
   // Virtual funcition for child classes of Items
   //--------------------------------------------------------------------
	virtual void ExecuteItem(Player * hero) = 0;

   //--------------------------------------------------------------------
   // Virtual funcition for child classes of Items
   //--------------------------------------------------------------------
	virtual int getModifier() = 0;

   //--------------------------------------------------------------------
   // Returns the type of item
   //--------------------------------------------------------------------
   int getType() { return type; }

   //--------------------------------------------------------------------
   // Virtual funcition for child classes of Items
   //--------------------------------------------------------------------
   virtual int getRarity() = 0;

protected:
	int Level;
   int type;
};

#endif