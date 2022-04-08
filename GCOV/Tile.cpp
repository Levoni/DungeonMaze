//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Levon Swenson, Zachary Lee, Phillip patakos
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  This class holds information for a map tile
//-----------------------------------------------------------------------

#include "Tile.h"
Tile::Tile()
{
   topWall = true;
   bottomWall = true;
   leftWall = true;
   rightWall = true;
   visited = false;
   lightLevel = 0;
   playerVisited = false;
   power = NULL;
   Item = NULL;
}

Tile::Tile(bool top, bool bottom, bool left, bool right)
{
   topWall = top;
   bottomWall = bottom;
   leftWall = left;
   rightWall = right;
   visited = false;
   lightLevel = 0;
   playerVisited = false;
   power = NULL;
   Item = NULL;
}

void Tile::setPowerUp()
{
   int type = rand() % 3;
   if (type == 0)
      power = new PowerFullVisibility();
   if (type == 1)
      power = new PowerVisionBoost();
   if (type == 2)
      power = new PowerHealth();
}
void Tile::setItem(int level)
{
   int type = rand() % 2 + 1;
	if (type == 1)
		Item = new Weapon(level);
	if (type == 2)
		Item = new Armor(level);

}
void Tile::setOppWall(int x, int y, int size)
{

	if (topWall == false && y != size - 1)
		bottomWall = false;
	else if (bottomWall == false && y != 0)
		topWall = false;
	else if (rightWall == false && x != 0)
		leftWall = false;
	else if (leftWall == false && x != size -1)
		rightWall = false;
}

void Tile::ExecutePowerUp(Player * hero)
{
   power->ExecutePowerUp(hero); 
   delete power; 
   power = NULL;
}

void Tile::ExecuteItem(Player * hero)
{
	Item->ExecuteItem(hero);
	delete Item;
	Item = NULL;
}

#ifdef __TESTING_TILE
int main()
{
   Tile tileNone = Tile(false, false, false, false);
   Tile tileAll = Tile();

   //////////////////////////////////////////////////////////////////
   //Case 1: testing has<side>Wall methods where all are false
   //////////////////////////////////////////////////////////////////
   cout << "Testing tile without walls." << endl;
   if (!tileNone.HasTopWall() &&
      !tileNone.HasBottomWall() &&
      !tileNone.HasLeftWall() &&
      !tileNone.HasRightWall())
   {
      cout << "PASS, no walls detected." << endl << endl;
   }
   else
   {
      cout << "FAIL, walls were detected." << endl << endl;
   }

   //////////////////////////////////////////////////////////////////
   //Case 2: testing has<side>Wall methods where all are true
   //////////////////////////////////////////////////////////////////
   cout << "Testing tile with all walls." << endl;
   if (tileAll.HasTopWall() &&
      tileAll.HasBottomWall() &&
      tileAll.HasLeftWall() &&
      tileAll.HasRightWall())
   {
      cout << "PASS, all walls detected." << endl << endl;
   }
   else
   {
      cout << "FAIL, not all walls detected." << endl << endl;
   }

   //////////////////////////////////////////////////////////////////
   //Case 3: testing setTopWall method
   //////////////////////////////////////////////////////////////////
   cout << "Testing wall setter methods on tile without walls." << endl;
   cout << "Setting top wall to true:    ";
   tileNone.SetTopWall(true);
   if (tileNone.HasTopWall())
      cout << "PASS, top wall detected." << endl;
   else
      cout << "FAIL, top wall not detected." << endl;

   //////////////////////////////////////////////////////////////////
   //Case 4: testing setBottomWall method
   //////////////////////////////////////////////////////////////////
   cout << "Setting bottom wall to true: ";
   tileNone.SetBottomWall(true);
   if (tileNone.HasBottomWall())
      cout << "PASS, bottom wall detected." << endl;
   else
      cout << "FAIL, bottom wall not detected." << endl;

   //////////////////////////////////////////////////////////////////
   //Case 5: testing setLeftWall method
   //////////////////////////////////////////////////////////////////
   cout << "Setting left wall to true:   ";
   tileNone.SetLeftWall(true);
   if (tileNone.HasLeftWall())
      cout << "PASS, left wall detected." << endl;
   else
      cout << "FAIL, left wall not detected." << endl;

   //////////////////////////////////////////////////////////////////
   //Case 6: testing setRightWall method
   //////////////////////////////////////////////////////////////////
   cout << "Setting right wall to true:  ";
   tileNone.SetRightWall(true);
   if (tileNone.HasRightWall())
      cout << "PASS, right wall detected." << endl;
   else
      cout << "FAIL, right wall not detected." << endl;
}
#endif