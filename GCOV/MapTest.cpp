#include "Map.h"
#include <cassert>
#include <iterator>
#include <iostream>
#include <map>

using namespace std;

const int DEFAULT_PANEL_SIZE = 440;

int main()
{
   /*
   typedef std::pair<int, int> Key;
   Map* map = new Map(440, 10, 10);
   Map* testconsturctor = new Map(500, 10, 10);
   Key temp = map->GetGeneratorPostion();
   enum{R, U, L, D};
   set<int> initialDirections = map->CheckSurroundings();

   //---------------------------------------------------------------------
   // CheckSurroundings
   //---------------------------------------------------------------------
   initialDirections.clear();
   assert(initialDirections.empty());
   std::cout << "initialDirections is empty\n";

   initialDirections.insert(0);
   assert(!initialDirections.empty());
   std::cout << "\ninitialDirections is not empty\n";

   //---------------------------------------------------------------------
   // RandomMove
   //---------------------------------------------------------------------
   assert(initialDirections.find(map->RandomMove(initialDirections)) != initialDirections.end());
   std::cout << "\nThere is a random direction to go in\n";

   initialDirections.clear();
   assert(initialDirections.size() == 0);
   std::cout << "\nThere is no random direction to go in\n";

   //---------------------------------------------------------------------
   // GoForward
   //---------------------------------------------------------------------
   temp = map->GetGeneratorPostion();
   map->GoForward(1);
   assert(temp.first != map->GetGeneratorPostion().first || temp.second != map->GetGeneratorPostion().second);
   std::cout << "\nmapGenerator moved forward\n";

   //---------------------------------------------------------------------
   // GoBack
   //---------------------------------------------------------------------
   temp = map->GetGeneratorPostion();
   map->GoBack();
   assert(temp.first != map->GetGeneratorPostion().first || temp.second != map->GetGeneratorPostion().second);
   std::cout << "\nmapGenerator moved backward\n";

   delete map;


   //---------------------------------------------------------------------
   // Checking if coordinites are in the same position
   //---------------------------------------------------------------------
   pair<int, int> one = make_pair(5, 5);
   pair<int, int> two = make_pair(5, 5);
   assert(map->CheckForSamePosition(one, two) == true);


   Map* genTestOne = new Map(500, 10, 10);
   Map* genTestTwo = new Map(500, 10, 10);
   genTestOne->GenerateMap(Key(0, 0));
   genTestTwo->GenerateMap(Key(0, 0));
   genTestOne->GenerateCollectables();
   genTestTwo->GenerateCollectables();
   //---------------------------------------------------------------------
   // Checking if generating PowerUps is random
   //---------------------------------------------------------------------
   bool powerUpCreated = false;
   for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
         if (genTestOne->GetTile(i, j)->HasPowerUp() || genTestTwo->GetTile(i, j)->HasPowerUp())
            powerUpCreated = true;
   assert(powerUpCreated == true);

   //---------------------------------------------------------------------
   // Checking if generating PowerUps is random
   //---------------------------------------------------------------------
   bool samePowerUp = true;
   for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
         if (genTestOne->GetTile(i, j)->HasPowerUp() != genTestTwo->GetTile(i, j)->HasPowerUp())
            samePowerUp = false;
   assert(samePowerUp == false);

   //---------------------------------------------------------------------
   // Checking if generating Items is random
   //---------------------------------------------------------------------
   bool itemUpCreated = false;
   for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
         if (genTestOne->GetTile(i, j)->HasItem() || genTestTwo->GetTile(i, j)->HasItem())
            itemUpCreated = true;
   assert(itemUpCreated == true);

   //---------------------------------------------------------------------
   // Checking if generating Items is random
   //---------------------------------------------------------------------
   bool sameItem = true;
   for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
         if (genTestOne->GetTile(i, j)->HasPowerUp() != genTestTwo->GetTile(i, j)->HasPowerUp())
            sameItem = false;
   assert(sameItem == false);

   //---------------------------------------------------------------------
   // Checking if Key is generaed
   //---------------------------------------------------------------------
   bool hasKey = true;
   for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
         if (genTestOne->GetTile(i, j)->GetItemType() == 3)
            hasKey = true;
   assert(hasKey == true);

   map = new Map(500, 10, 10);
   map->GenerateMap(map->GetGeneratorPostion());
   map->MakePaths();
   map->addExtraPaths();


   //---------------------------------------------------------------------
   // Making sure needs paths is true.
   //---------------------------------------------------------------------
   assert(map->PathsNeeded() == true);

   //---------------------------------------------------------------------
   // Making sure needs paths if false
   //---------------------------------------------------------------------
   assert(map->PathsNeeded() == false);


   int numTilesInRow = 12;
   int tileWidth = DEFAULT_PANEL_SIZE / numTilesInRow;

   map = new Map(440);
   Player* hero = new Player(map->GetMapSize());
   map->MakeMapFromFile("visibility_test_map_1.txt");
   //map->Tutorial(true);
   //map->MakePaths();

   std::map<pair<int, int>, Tile*>* tileMap = map->GetTileMap();

   int locX1 = 0;
   int locX2 = 0;
   int locY1 = 0;
   int locY2 = 0;


   //---------------------------------------------------------------------
   // Testing that operator= works
   //---------------------------------------------------------------------
   Map* m = new Map(10);
   m->GenerateMap(Key(5,5));
   Map mCopy = *m;
   Map* mNotCopy = new Map(10);
   mNotCopy->GenerateMap(Key(0, 0));
   Map* mAlsoNotCopy = new Map(11);
   mAlsoNotCopy->GenerateMap(Key(1, 1));

   assert(m->IsEqualTo(&mCopy));
   assert(!m->IsEqualTo(mNotCopy));
   assert(!m->IsEqualTo(mAlsoNotCopy));

   delete m;
   delete mNotCopy;
   delete mAlsoNotCopy;


   //---------------------------------------------------------------------
   // Testing that update mapsize works
   //---------------------------------------------------------------------
   Map mixing = Map(100);
   Map mapNewSize = mixing;

   mapNewSize.updateMapSize(1000, 1);

   assert(mapNewSize.GetMapSize() == 11);
   assert(!mapNewSize.IsEqualTo(&mixing));

   //---------------------------------------------------------------------
   // Testing that update dead end ratio and get dead end ratio work
   //---------------------------------------------------------------------
   int i = m->GetDeadEndRatio();
   m->updateDeadEndRatio(1);
   int j = m->GetDeadEndRatio();
   assert(j == (i + 1));

   //---------------------------------------------------------------------
   // Testing that update item ratio works
   //---------------------------------------------------------------------
   i = m->GetItemRatio();
   m->updateItemRatio(1);
   j = m->GetItemRatio();
   assert(j == (i + 1));

   //---------------------------------------------------------------------
   // Testing that update power ratio works
   //---------------------------------------------------------------------
   float k = m->GetPowerRatio();
   m->updatePowerRatio(1);
   float l = m->GetPowerRatio();
   assert(j == (i + 1));
   */

   //--------------------------------------------------------------------
   // Case x:  Check if a wall exists to the right of a character (Uses WallCheckRight())
   //--------------------------------------------------------------------
   int testPanelSize = 440;
   int testMapSize = 10;
   int testLevel = 1;
   int charHeight = 40;
   Map* testMap = new Map(testPanelSize, testMapSize, testLevel);

   testMap->GenerateMap(Key(0, 0));
   Key charPoint = testMap->GetStartPoint();
   Key finishPoint = testMap->GetFinishPoint();
   


   //--------------------------------------------------------------------
   // Case x:  Start and finish points are swapped (Uses GetStartPoint(), GetFinishPoint(), SwapPoints())
   //--------------------------------------------------------------------
   testPanelSize = 440;
   testMapSize = 10;
   testLevel = 1;
   testMap = new Map(testPanelSize, testMapSize, testLevel);

   testMap->GenerateMap(Key(0, 0));

   Key startPoint = testMap->GetStartPoint();
   finishPoint = testMap->GetFinishPoint();

   testMap->SwapPoints();

   assert(startPoint == testMap->GetFinishPoint());
   assert(finishPoint == testMap->GetStartPoint());

   delete testMap;

   //--------------------------------------------------------------------
   // Case x:  Door is unlocked (Uses IsUnlocked(), TryUnlock(), DoorJustUnlocked())
   //--------------------------------------------------------------------
   testMap = new Map(testPanelSize, testMapSize, testLevel);

   testMap->GenerateMap(Key(0, 0));

   assert(!testMap->isUnlocked());

   testMap->tryUnlock(true);

   assert(testMap->isUnlocked());
   assert(testMap->DoorJustUnlocked());

   assert(!testMap->DoorJustUnlocked());

   delete testMap;

   //Cases x - x
   //---------------------------------------------------------------------
   // Case x:  Character is moving up and changes/doesn't change tile (Uses ChangedTile())
   //---------------------------------------------------------------------
   int up = 5;
   int down = 2;
   int left = 1;
   int right = 3;
   pair<int, int>* testLocation1 = new pair<int, int>(0, 5);
   pair<int, int>* testLocation2 = new pair<int, int>(0, 6);
   pair<int, int>* testLocation3 = new pair<int, int>(0, 40);
   pair<int, int>* testLocation4 = new pair<int, int>(0, 39);
   pair<int, int>* testLocation5 = new pair<int, int>(5, 0);
   pair<int, int>* testLocation6 = new pair<int, int>(6, 0);
   pair<int, int>* testLocation7 = new pair<int, int>(40, 0);
   pair<int, int>* testLocation8 = new pair<int, int>(39, 0);
   int testCharacterHeight = 42;
   int testCharacterWidth = 42;
   testMap = new Map(testPanelSize, testMapSize, testLevel);

   testMap->GenerateMap(Key(0, 0));

   assert(testMap->ChangedTile(up, testLocation1, testCharacterHeight, testCharacterWidth));
   assert(!testMap->ChangedTile(up, testLocation2, testCharacterHeight, testCharacterWidth));

   //--------------------------------------------------------------------
   // Case x:  Character is moving down and changes/doesn't change tile (Uses ChangedTile())
   //--------------------------------------------------------------------
   assert(testMap->ChangedTile(down, testLocation3, testCharacterHeight, testCharacterWidth));
   assert(!testMap->ChangedTile(down, testLocation4, testCharacterHeight, testCharacterWidth));

   //--------------------------------------------------------------------
   // Case x:  Character is moving left and changes/doesn't change tile (Uses ChangedTile())
   //--------------------------------------------------------------------
   assert(testMap->ChangedTile(left, testLocation5, testCharacterHeight, testCharacterWidth));
   assert(!testMap->ChangedTile(left, testLocation6, testCharacterHeight, testCharacterWidth));

   //--------------------------------------------------------------------
   // Case x:  Character is moving right and changes/doesn't change tile (Uses ChangedTile())
   //--------------------------------------------------------------------
   assert(testMap->ChangedTile(right, testLocation7, testCharacterHeight, testCharacterWidth));
   assert(!testMap->ChangedTile(right, testLocation8, testCharacterHeight, testCharacterWidth));

   delete testMap;
   delete testLocation1;
   delete testLocation2;
   delete testLocation3;
   delete testLocation4;
   delete testLocation5;
   delete testLocation6;
   delete testLocation7;
   delete testLocation8;
   //--------------------------------------------------------------------

   //--------------------------------------------------------------------
   // Case x:  
   //--------------------------------------------------------------------

   //Map testMap(5);

   //---------------------------------------------------------------------
   // Case x:  Check to see if two maps are equivalent (Uses IsEqualTo())
   //---------------------------------------------------------------------




































   //Powerup functinality has been moved to GameManager
   /*

   //-------------------------------------------------------------------
   //Case 1: Player has "See Everything" power-up
   //-------------------------------------------------------------------
   hero->SetFullVisibility(true); //Add method

   map->SetLineOfSightHelper();

   for (int i = 0; i < numTilesInRow; i++)
      for (int j = 0; j < numTilesInRow; j++)
         assert(tileMap->operator[](Key(i, j)).GetLightLevel() == 4);

   for (int i = 0; i < MAX_VISIBILITY_TIMER; i++) //Let Full Visibility power-up expire
      map->coolDownTick();

   //-------------------------------------------------------------------
   //Case 2: Player has "Vision Boost" power-up
   //-------------------------------------------------------------------

   map->MakeMapFromFile("visibility_test_map_2.txt");
   tileMap = map->GetTileMap();

   map->hero->SetLocation(pair<int, int>(tileWidth * 6, tileWidth * 7)); //(6, 7)

   map->hero->SetVisionBoost(true); //Add method
   map->SetLineOfSightHelper();

   pair<int, int>* location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);

   assert(tileMap->operator[](Key(locX1, locY1 - 1)).GetLightLevel() == 3);

   assert(tileMap->operator[](Key(locX1, locY1 - 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 - 1, locY1 - 1)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 - 1, locY1 - 1)).GetLightLevel() == 2);

   assert(tileMap->operator[](Key(locX1, locY1 - 3)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 + 1, locY1 - 2)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 - 1, locY1 - 2)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 - 2, locY1 - 1)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 + 2, locY1 - 1)).GetLightLevel() == 1);

   assert(tileMap->operator[](Key(locX1, locY1 - 4)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 + 2, locY1 - 2)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 - 2, locY1 - 2)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 - 1, locY1 - 3)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 - 3, locY1 - 1)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 + 3, locY1 - 1)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 - 1, locY1 + 1)).GetLightLevel() == 0);

   for (int i = 0; i < MAX_VISION_BOOST_TIMER; i++) //Let vision boost power-up expire
      map->coolDownTick();

   //-------------------------------------------------------------------
   //Case 3: Player is horizontally in single tile and no walls oppose
   //        upward vision
   //-------------------------------------------------------------------
   map->MakeMapFromFile("visibility_test_map_1.txt");
   tileMap = map->GetTileMap();

   map->hero->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 5)); //(5, 5)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1, locY1 - 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1, locY1 - 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1, locY1 - 3)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1, locY1 - 4)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1, locY1 - 5)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 4: Player is horizontally in single tile and a wall opposes
   //        upward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 3)); //(5, 3)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1, locY1 - 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1, locY1 - 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1, locY1 - 3)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 5: Player is horizontally in two tiles and no walls oppose
   //        upward vision
   //-------------------------------------------------------------------
   map->hero->SetLocation(pair<int, int>((tileWidth * 6) - 10, tileWidth * 5)); //(5/6, 5)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locX2 = (location->first + map->hero->GetWidth()) / ((DEFAULT_PANEL_SIZE) / numTilesInRow);

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1, locY1 - 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1, locY1 - 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1, locY1 - 3)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1, locY1 - 4)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1, locY1 - 5)).GetLightLevel() == 0);

   assert(tileMap->operator[](Key(locX2, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX2, locY1 - 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX2, locY1 - 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX2, locY1 - 3)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX2, locY1 - 4)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX2, locY1 - 5)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 6: Player is horizontally in two tiles and a wall opposes
   //        upward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>((tileWidth * 6) - 10, tileWidth * 3)); //(5/6, 3)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locX2 = (location->first + map->hero->GetWidth()) / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1, locY1 - 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1, locY1 - 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1, locY1 - 3)).GetLightLevel() == 0);

   assert(tileMap->operator[](Key(locX2, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX2, locY1 - 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX2, locY1 - 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX2, locY1 - 3)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 7: Player is horizontally in single tile and no walls oppose
   //        downward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 6)); //(5, 6)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1, locY1 + 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1, locY1 + 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1, locY1 + 3)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1, locY1 + 4)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1, locY1 + 5)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 8: Player is horizontally in single tile and a wall opposes
   //        downward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 8)); //(5, 8)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1, locY1 + 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1, locY1 + 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1, locY1 + 3)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 9: Player is horizontally in two tiles and no walls oppose
   //        downward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>((tileWidth * 6) - 10, tileWidth * 6)); //(5/6, 6)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locX2 = (location->first + map->hero->GetWidth()) / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1, locY1 + 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1, locY1 + 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1, locY1 + 3)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1, locY1 + 4)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1, locY1 + 5)).GetLightLevel() == 0);

   assert(tileMap->operator[](Key(locX2, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX2, locY1 + 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX2, locY1 + 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX2, locY1 + 3)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX2, locY1 + 4)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX2, locY1 + 5)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 10: Player is horizontally in two tiles and a wall opposes
   //         downward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>((tileWidth * 6) - 10, tileWidth * 8)); //(5/6, 8)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locX2 = (location->first + map->hero->GetWidth()) / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1, locY1 + 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1, locY1 + 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1, locY1 + 3)).GetLightLevel() == 0);

   assert(tileMap->operator[](Key(locX2, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX2, locY1 + 1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX2, locY1 + 2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX2, locY1 + 3)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 11: Player is vertically in single tile and no walls oppose
   //         leftward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 5)); //(5, 5)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 - 1, locY1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 - 2, locY1)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 - 3, locY1)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 - 4, locY1)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 - 5, locY1)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 12: Player is vertically in single tile and a wall opposes
   //         leftward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 3, tileWidth * 5)); //(3, 5)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 - 1, locY1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 - 2, locY1)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 - 3, locY1)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 13: Player is vertically in two tiles and no walls oppose
   //         leftward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 5, (tileWidth * 6) - 10)); //(5, 5/6)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locY2 = (location->second + map->hero->GetHeight()) / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 - 1, locY1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 - 2, locY1)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 - 3, locY1)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 - 4, locY1)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 - 5, locY1)).GetLightLevel() == 0);

   assert(tileMap->operator[](Key(locX1, locY2)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 - 1, locY2)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 - 2, locY2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 - 3, locY2)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 - 4, locY2)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 - 5, locY2)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 14: Player is vertically in two tiles and a wall opposes
   //         leftward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 3, (tileWidth * 6) - 10)); //(3, 5/6)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locY2 = (location->second + map->hero->GetHeight()) / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 - 1, locY1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 - 2, locY1)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 - 3, locY1)).GetLightLevel() == 0);

   assert(tileMap->operator[](Key(locX1, locY2)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 - 1, locY2)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 - 2, locY2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 - 3, locY2)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 15: Player is vertically in single tile and no walls oppose
   //         rightward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 6, tileWidth * 5)); //(6, 5)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 + 1, locY1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 + 2, locY1)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 + 3, locY1)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 + 4, locY1)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 + 5, locY1)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 16: Player is vertically in single tile and a wall opposes
   //         rightward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 8, tileWidth * 5)); //(8, 5)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 + 1, locY1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 + 2, locY1)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 + 3, locY1)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 17: Player is vertically in two tiles and no walls oppose
   //         rightward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 6, (tileWidth * 6) - 10)); //(6, 5/6)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locY2 = (location->second + map->hero->GetHeight()) / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 + 1, locY1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 + 2, locY1)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 + 3, locY1)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 + 4, locY1)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 + 5, locY1)).GetLightLevel() == 0);

   assert(tileMap->operator[](Key(locX1, locY2)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 + 1, locY2)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 + 2, locY2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 + 3, locY2)).GetLightLevel() == 1);
   assert(tileMap->operator[](Key(locX1 + 4, locY2)).GetLightLevel() == 0);
   assert(tileMap->operator[](Key(locX1 + 5, locY2)).GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 18: Player is vertically in two tiles and a wall opposes
   //         rightward vision
   //-------------------------------------------------------------------

   map->hero->SetLocation(pair<int, int>(tileWidth * 8, (tileWidth * 6) - 10)); //(8, 5/6)
   location = map->hero->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locY2 = (location->second + map->hero->GetHeight()) / tileWidth;

   map->SetLineOfSightHelper();

   assert(tileMap->operator[](Key(locX1, locY1)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 + 1, locY1)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 + 2, locY1)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 + 3, locY1)).GetLightLevel() == 0);

   assert(tileMap->operator[](Key(locX1, locY2)).GetLightLevel() == 4);
   assert(tileMap->operator[](Key(locX1 + 1, locY2)).GetLightLevel() == 3);
   assert(tileMap->operator[](Key(locX1 + 2, locY2)).GetLightLevel() == 2);
   assert(tileMap->operator[](Key(locX1 + 3, locY2)).GetLightLevel() == 0);
   */

   cout << "Test Successful!" << endl;
   return 0;
}
