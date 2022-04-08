//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  This class holds information for a map tile
//-----------------------------------------------------------------------

#ifndef __TILE_H
#define __TILE_H
//#define __TESTING_TILE
#ifdef  __TESTING_TILE
#include <iostream>
#endif 
#include "PowerUp.h"
#include "Player.h"
#include "PowerFullVisibility.h"
#include "PowerVisionBoost.h"
#include "PowerHealth.h"
#include "Items.h"
#include "Armor.h"
#include "Weapon.h"
#include "DoorKey.h"

using namespace std;

//-----------------------------------------------------------------------
//This class holds information for a map tile
//-----------------------------------------------------------------------
class Tile {

public:
	//--------------------------------------------------------------------
	//Constructor: ititializes tile with all walls in place
	//--------------------------------------------------------------------
   Tile();
	

   ~Tile()
   {
      delete power;
      delete Item;
   }

	//--------------------------------------------------------------------
	//Constructor: ititializes tile with all 4 walls specified as existing
	//             or not.
	//--------------------------------------------------------------------
   Tile(bool top, bool bottom, bool left, bool right);

   

	//--------------------------------------------------------------------
	// Returns true if Tile has leftWall, false otherwise
	//--------------------------------------------------------------------
	bool HasLeftWall() { return leftWall; }

	//--------------------------------------------------------------------
	// Returns true if Tile has rightWall, false otherwise
	//--------------------------------------------------------------------
	bool HasRightWall() { return rightWall; }

	//--------------------------------------------------------------------
	// Returns true if Tile has topWall, false otherwise
	//--------------------------------------------------------------------
	bool HasTopWall() { return topWall; }

	//--------------------------------------------------------------------
	// Returns true if Tile has bottomWall, false otherwise
	//--------------------------------------------------------------------
	bool HasBottomWall() { return bottomWall; }

	//--------------------------------------------------------------------
	// Sets bottomWall to bot
	//--------------------------------------------------------------------
	void SetBottomWall(bool bot) { bottomWall = bot; }

	//--------------------------------------------------------------------
	// Sets topWall to top
	//--------------------------------------------------------------------
	void SetTopWall(bool top) { topWall = top; }

	//--------------------------------------------------------------------
	// Sets rightWall to right
	//--------------------------------------------------------------------
	void SetRightWall(bool right) { rightWall = right; }

	//--------------------------------------------------------------------
	// Sets leftWall to left
	//--------------------------------------------------------------------
	void SetLeftWall(bool left) { leftWall = left; }

	//--------------------------------------------------------------------
   // Returns lightLevel
   //--------------------------------------------------------------------
   int GetLightLevel() { return lightLevel; }

   //--------------------------------------------------------------------
   // Sets lightLevel to x
   //--------------------------------------------------------------------
	void SetLightLevel(int x) { lightLevel = x; }

   //--------------------------------------------------------------------
   // Returns true if visited, false otherwise
   //--------------------------------------------------------------------
   bool GetVisited() { return visited; }

   //--------------------------------------------------------------------
   // Sets visited to true
   //--------------------------------------------------------------------
	void SetVisited() { visited = true; }

   //--------------------------------------------------------------------
   //Sets whether or not the player has visited the tile
   //--------------------------------------------------------------------
   void SetPlayerVisited(bool pVisit) { playerVisited = pVisit; }

   //--------------------------------------------------------------------
   //Returns whether or not the player has visited the tile
   //--------------------------------------------------------------------
   bool GetPlayerVisited() { return playerVisited; }

   //--------------------------------------------------------------------
   // Returns wheter tile has powerup or not
   //--------------------------------------------------------------------
   bool HasPowerUp() { return power != NULL; }

   //--------------------------------------------------------------------
   // Returns whether tile has item or not
   //--------------------------------------------------------------------
   bool HasItem() { return Item != NULL; }

   //--------------------------------------------------------------------
   // Executes powerup on hero
   //--------------------------------------------------------------------
   void ExecutePowerUp(Player * hero);

   //--------------------------------------------------------------------
   // Executes item on hero
   //--------------------------------------------------------------------
   void ExecuteItem(Player * hero);

   //--------------------------------------------------------------------
   // Sets a powerup on tile
   //--------------------------------------------------------------------
   void setPowerUp();

   //--------------------------------------------------------------------
   // Sets item on tile
   //--------------------------------------------------------------------
   void setItem(int level);

   //--------------------------------------------------------------------
   // Sets Key on tile
   //--------------------------------------------------------------------
   void SetKey() { Item = new DoorKey(); };

   //--------------------------------------------------------------------
   // Returns type of powerup on tile
   //--------------------------------------------------------------------
   int GetPowerUpType() { return power->getPowerUpType(); }

   //--------------------------------------------------------------------
   // Returns type of item on tile
   //--------------------------------------------------------------------
   int GetItemType() { return Item->getType(); }
   
   //--------------------------------------------------------------------
   // Returns rarity of item on tile
   //--------------------------------------------------------------------
   int GetItemRarity() { return Item->getRarity(); }

   //--------------------------------------------------------------------
   //Sets the opposite wall to false for dead ends
   //--------------------------------------------------------------------
   void setOppWall(int x, int y, int size);

private:
   //--------------------------------------------------------------------
   // Determines whether or not two tiles are equal
   //--------------------------------------------------------------------
   Tile& operator=(Tile & m);
   PowerUp * power;
   Items * Item;
   bool topWall;
   bool leftWall;
   bool bottomWall;
   bool rightWall;
   bool visited;
   bool playerVisited;
   int lightLevel;
};
#endif