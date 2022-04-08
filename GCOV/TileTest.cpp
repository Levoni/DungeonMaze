#include "Tile.h"
#include "Player.h"
#include <iostream>
#include <cassert>

using namespace std;

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

   //--------------------------------------------------------------------

   //////////////////////////////////////////////////////////////////
   //Case 7: Testing GetLightLevel() and SetLightLevel()
   //////////////////////////////////////////////////////////////////
   assert(tileNone.GetLightLevel() == 0);

   tileNone.SetLightLevel(4);
   assert(tileNone.GetLightLevel() == 4);

   //////////////////////////////////////////////////////////////////
   //Case 8: Testing : tile doesn't have a power up
   //////////////////////////////////////////////////////////////////
   assert(tileNone.HasPowerUp() == false);

   //////////////////////////////////////////////////////////////////
   //Case 9: Testing seting a power up (seting it to full visibility)
   //////////////////////////////////////////////////////////////////

   tileNone.setPowerUp();
   while (tileNone.GetPowerUpType() != 1)
      tileNone.setPowerUp();
   assert(tileNone.GetPowerUpType() == 1);

   //////////////////////////////////////////////////////////////////
   //Case 10: Testing setting OppositeWall  Right + Left wall
   //////////////////////////////////////////////////////////////////
   Tile t1; 
   t1.SetRightWall(false);
   t1.setOppWall(5,5,10);
   assert(t1.HasLeftWall() == false);

   //////////////////////////////////////////////////////////////////
   //Case 11: Testing setting OppositeWall  Up + Down wall
   //////////////////////////////////////////////////////////////////
   Tile t2;
   t2.SetTopWall(false);
   t2.setOppWall(5, 5, 10);
   assert(t2.HasBottomWall() == false);

   //////////////////////////////////////////////////////////////////
   //Case 12: Testing setting OppositeWall  Left + Right wall
   //////////////////////////////////////////////////////////////////
   Tile t3;
   t3.SetLeftWall(false);
   t3.setOppWall(5, 5, 10);
   assert(t3.HasRightWall() == false);

   //////////////////////////////////////////////////////////////////
   //Case 13: Testing setting OppositeWall  Down + Up wall
   //////////////////////////////////////////////////////////////////
   Tile t4;
   t4.SetBottomWall(false);
   t4.setOppWall(5, 5, 10);
   assert(t4.HasTopWall() == false);

   //////////////////////////////////////////////////////////////////
   //Case 14: Testing checking if tile has a power up
   //////////////////////////////////////////////////////////////////
   Tile powerUp;
   assert(powerUp.HasPowerUp() == false);
   powerUp.setPowerUp();
   assert(powerUp.HasPowerUp() == true);

   //////////////////////////////////////////////////////////////////
   //Case 15: Testing checking if tile has an item
   //////////////////////////////////////////////////////////////////
   Tile item;
   assert(item.HasItem() == false);
   item.setItem(1);
   assert(item.HasItem() == true);

   //////////////////////////////////////////////////////////////////
   //Case 16: Testing checking if powerup is taken
   //////////////////////////////////////////////////////////////////
   Tile noPowerUp;
   Player* hero = new Player(10);
   noPowerUp.setPowerUp();
   noPowerUp.ExecutePowerUp(hero);
   assert(noPowerUp.HasPowerUp() == false);
   delete hero;

   //////////////////////////////////////////////////////////////////
   //Case 17: Testing checking if item is taken
   //////////////////////////////////////////////////////////////////
   Tile noItem;
   hero = new Player(10);
   noItem.setItem(1);
   noItem.ExecuteItem(hero);
   assert(noItem.HasItem() == false);

   //////////////////////////////////////////////////////////////////
   //Case 18: Testing checking the power up number
   //////////////////////////////////////////////////////////////////
   Tile powerUpType;
   powerUpType.setPowerUp();
   while (powerUpType.GetPowerUpType() != 2)
      powerUpType.setPowerUp();
   assert(powerUpType.GetPowerUpType() == 2);

   //////////////////////////////////////////////////////////////////
   //Case 19: Testing checking the item number
   //////////////////////////////////////////////////////////////////
   Tile powerUpItem;
   powerUpItem.setItem(1); // Weapon/armor,level,type
   while (powerUpItem.GetItemType() != 2)
      powerUpItem.setItem(1);
   assert(powerUpItem.GetItemType() == 2); // type 

   //////////////////////////////////////////////////////////////////
   //Case 20: Testing that tile has not been visited
   //////////////////////////////////////////////////////////////////
   Tile notVisited;// = Tile();
   assert(notVisited.GetVisited() == false);

   //////////////////////////////////////////////////////////////////
   //Case 21: Testing that tile has been visited
   //////////////////////////////////////////////////////////////////
   Tile visited;// = Tile();
   visited.SetVisited();
   assert(visited.GetVisited() == true);

   //////////////////////////////////////////////////////////////////
   //Case 22: Testing that player has not visited
   //////////////////////////////////////////////////////////////////
   notVisited;// = Tile();
   assert(notVisited.GetPlayerVisited() == false);

   //////////////////////////////////////////////////////////////////
   //Case 23: Testing that player has visited
   //////////////////////////////////////////////////////////////////
   visited;// = Tile();
   visited.SetPlayerVisited(true);
   assert(visited.GetPlayerVisited() == true);

   //////////////////////////////////////////////////////////////////
   //Case 24: Testing that tile doesnt have Item
   //////////////////////////////////////////////////////////////////
   Tile noKey = Tile();
   assert(noKey.HasItem() == NULL);

   //////////////////////////////////////////////////////////////////
   //Case 25: Testing that tile has key
   //////////////////////////////////////////////////////////////////
   Tile hasKey = Tile();
   hasKey.SetKey();
   assert(hasKey.GetItemType() == 3);

   //////////////////////////////////////////////////////////////////
   //Case 26: Testing Power Health
   //////////////////////////////////////////////////////////////////
   Tile powerHealth;
   powerHealth.setPowerUp();
   while (powerHealth.GetPowerUpType() != 3)
      powerHealth.setPowerUp();
   assert(powerHealth.GetPowerUpType() == 3);


   return 0;
}
