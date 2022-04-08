#include "../TheMazeGame/DoorKey.h"
#include "../TheMazeGame/Player.h"
#include "../TheMazeGame/Character.h"

#include <cassert>
#include <iostream>

int main()
{
   DoorKey testDoorKey;
   int testMapSize = 100;
   Player* testPlayer = new Player(testMapSize);
   
   //--------------------------------------------------------------------
   // Case 1:  Door key is collected by player.
   //--------------------------------------------------------------------
   testDoorKey.ExecuteItem(testPlayer);
   assert(testPlayer->hasKey());

   delete testPlayer;

   cout << "Tests successful!" << endl;
   
   return 0;
}