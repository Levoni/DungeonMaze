#include "..\TheMazeGame\Armor.h"
#include "..\TheMazeGame\Player.h"

#include <cassert>
#include <iostream>


int main()
{


   //-----------------------------------------------------------------------
   // Case 1:  Armor is collected
   //-----------------------------------------------------------------------

   int testLevel = 1;
   int testSize = 50;

   Player * testPlayer = new Player(testSize);

   Armor testArmor(testLevel);

   testArmor.ExecuteItem(testPlayer);

   assert(testArmor.getModifier() == testPlayer->GetArmor());
   assert(testArmor.getRarity() == testPlayer->GetArmorRarity());
   assert(testArmor.getType() == 2);

   delete testPlayer;
   cout << "Test successfull\n";
   return 0;
}