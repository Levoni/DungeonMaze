//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Contain information of the map, creates the tutorial level 
//          and displays graphics to screen.
//-----------------------------------------------------------------------
#include "Map.h"

Map::Map(int pnlSize)
{
   visitedStack = NULL;
   deadEnds = NULL;
   for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
         tileMap[make_pair(i, j)] = new Tile();
}

Map::Map(int pnlSize, int s, int Level)
{
   size = s;
   for (int y = 0; y < size; y++)
      for (int x = 0; x < size; x++)
      {
         tileMap[Key(x, y)] = new Tile();
      }
   isStart = true;
   noDoor = false;
   visitedStack = new std::stack<Key>();
   possibleDir = std::set<int>();
   deadEnds = new std::set<Key>();
   generatorPosition = Key(0, 0);
   visitedStack->push(generatorPosition);
   srand(std::time(0));
   tileHeight = pnlSize / size;
   tileWidth = tileHeight;
   createPaths = false;
   bufferZone = tileWidth / 10;
   isTutorial = false;

   powerUpRatio = 0.0;
   itemRatio = 0.0;
   deadEndRatio = 1;
   level = Level;

   doorJustUnlocked = false;
}

Map & Map::operator= (Map & m)
{
   if (this != &m)
   {


      //tileMap = m.tileMap;
      for (int i = 0; i < m.size; i++)
         for (int j = 0; j < m.size; j++)
            tileMap[Key(i, j)] = m.tileMap[Key(i, j)];

      possibleDir = m.possibleDir;

      if (visitedStack != NULL)
         delete visitedStack;
      visitedStack = new stack<Key>();
      *visitedStack = *(m.visitedStack);

      if (deadEnds != NULL)
         delete deadEnds;
      deadEnds = new set<Key>();
      *deadEnds = *(m.deadEnds);

      generatorPosition = m.generatorPosition;

      finishPoint = m.finishPoint;

      startPoint = m.startPoint;

      isTutorial = m.isTutorial;

      isStart = m.isStart;

      size = m.size;

      tileWidth = m.tileWidth;

      tileHeight = m.tileHeight;

      bufferZone = m.bufferZone;

      powerUpRatio = m.powerUpRatio;

      itemRatio = m.itemRatio;

      deadEndRatio = m.deadEndRatio;

      noDoor = m.noDoor;

      level = m.level;
   }
   return *this;
}

void Map::GenerateMap(Key initialPos)
{
   if (isStart)
   {
      startPoint = generatorPosition;
      isStart = false;
   }

   if (CheckEnd())
      deadEnds->insert(generatorPosition);

   tileMap[generatorPosition]->SetVisited();

   if (!visitedStack->empty())
   {
      possibleDir = CheckSurroundings();

      if (possibleDir.empty())
         GoBack();
      else
         GoForward(RandomMove(possibleDir));

      GenerateMap(generatorPosition);
   }
   else //End of generation
   {
      int size = deadEnds->size();
      int finish = rand() % deadEnds->size();
      set<Key>::const_iterator it = deadEnds->begin();

      for (int i = 0; i < finish; i++)
      {
         it++;
         int x = it->first;
         int y = it->second;
      }
      finishPoint = *it;
      deadEnds->erase(it); //Remove the finish
      GenerateCollectables();
   }
}

void Map::addExtraPaths()
{
   set<Key>::const_iterator it;
   for (it = deadEnds->begin();it != deadEnds->end();it++)
   {
      int temp = rand() % (1 + deadEndRatio);
      if (temp == 0)
      {
         tileMap[*it]->setOppWall(it->first, it->second, size);
      }
   }
   MakePaths();
}

void Map::GoBack()
{
   generatorPosition = visitedStack->top();
   visitedStack->pop();
}

void Map::GoForward(int move)
{
   visitedStack->push(generatorPosition);

   if (move == R)
   {
      tileMap[generatorPosition]->SetRightWall(false);
      generatorPosition = Key(generatorPosition.first + 1, generatorPosition.second);
   }
   if (move == U)
   {
      tileMap[generatorPosition]->SetTopWall(false);
      generatorPosition = Key(generatorPosition.first, generatorPosition.second - 1);
   }
   if (move == L)
   {
      tileMap[generatorPosition]->SetLeftWall(false);
      generatorPosition = Key(generatorPosition.first - 1, generatorPosition.second);
   }
   if (move == D)
   {
      tileMap[generatorPosition]->SetBottomWall(false);
      generatorPosition = Key(generatorPosition.first, generatorPosition.second + 1);
   }
}

set<int> Map::CheckSurroundings()
{
   possibleDir.clear();

   //Check Right
   if (generatorPosition.first < size - 1)
      if (!tileMap[Key(generatorPosition.first + 1, generatorPosition.second)]->GetVisited())
         possibleDir.insert(0);
   //Check Up
   if (generatorPosition.second > 0)
      if (!tileMap[Key(generatorPosition.first, generatorPosition.second - 1)]->GetVisited())
         possibleDir.insert(1);
   //Check Left
   if (generatorPosition.first > 0)
      if (!tileMap[Key(generatorPosition.first - 1, generatorPosition.second)]->GetVisited())
         possibleDir.insert(2);

   //Check Down
   if (generatorPosition.second < size - 1)
      if (!tileMap[Key(generatorPosition.first, generatorPosition.second + 1)]->GetVisited())
         possibleDir.insert(3);

   return possibleDir;
}

int Map::RandomMove(set<int> s)
{
   int index = rand() % s.size();
   set<int>::const_iterator it = s.begin();
   for (int i = 0; i < index;i++)
      it++;
   return *it;
}

void Map::MakePaths()
{
   for (int y = 0; y < size; y++)
      for (int x = 0; x < size; x++)
      {
         if (!tileMap[Key(x, y)]->HasLeftWall())
            if (x - 1 >= 0)
               tileMap[Key(x - 1, y)]->SetRightWall(false);
         if (!tileMap[Key(x, y)]->HasTopWall())
            if (y - 1 >= 0)
               tileMap[Key(x, y - 1)]->SetBottomWall(false);
         if (!tileMap[Key(x, y)]->HasRightWall())
            if (x + 1 < size)
               tileMap[Key(x + 1, y)]->SetLeftWall(false);
         if (!tileMap[Key(x, y)]->HasBottomWall())
            if (y + 1 < size)
               tileMap[Key(x, y + 1)]->SetTopWall(false);
      }
}

void Map::MakeMapFromFile(string filename)
{
   int mapSize, initX, initY, goalX, goalY, inCharAsInt;
   char inChar;
   bool testBit;
   std::ifstream is(filename);
   is >> mapSize >> initX >> initY >> goalX >> goalY;

   startPoint = make_pair(initX, initY);
   finishPoint = make_pair(goalX, goalY);

   size = mapSize;
   level = 1;

   for (int y = 0; y < mapSize; y++)
      for (int x = 0; x < mapSize; x++)
      {
         is >> inChar;
         if (inChar >= '0' && inChar <= '9')
            inCharAsInt = inChar - '0';
         else
            inCharAsInt = 10 + inChar - 'A';



         testBit = ((inCharAsInt & 1) == 1);
         tileMap[Key(x, y)]->SetRightWall(testBit);
         testBit = ((inCharAsInt & 2) == 2);
         tileMap[Key(x, y)]->SetTopWall(testBit);
         testBit = ((inCharAsInt & 4) == 4);
         tileMap[Key(x, y)]->SetLeftWall(testBit);
         testBit = ((inCharAsInt & 8) == 8);
         tileMap[Key(x, y)]->SetBottomWall(testBit);
      }
}

bool Map::CheckForSamePosition(pair<int, int> one, pair<int, int> two)
{
   return (one.first == two.first && one.second == two.second);
}

bool Map::PathsNeeded()
{
   if (createPaths)
   {
      createPaths = false;
      return true;
   }
   return false;
}

void Map::GenerateCollectables()
{
   GeneratePowerUps();
   GenerateItems();
   GenerateKey();
}

void Map::GeneratePowerUps()
{
   int getsItem = 0;
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         //getsItem = rand() % 2;
         getsItem = rand() % (BASE_GENERATION_RATE + (int)(BASE_GENERATION_RATE * powerUpRatio));
         if (getsItem == 0 && !(startPoint.first == i && startPoint.second == j) && !(finishPoint.first == i && finishPoint.second == j))
         {
            tileMap[Key(i, j)]->setPowerUp();
         }
      }
   }
}

void Map::GenerateKey() {
	Key tempK;
	do {
		int randX = rand() % (size - 1);
		int randY = rand() % (size - 1);
		tempK = Key(randX, randY);
	} while ((tempK == startPoint || tempK == finishPoint) || tileMap[tempK]->HasItem() || tileMap[tempK]->HasPowerUp());

   tileMap[tempK]->SetKey();
}
void Map::GenerateItems()
{
   int getsItem = 0;
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         //getsItem = 0;
         getsItem = rand() % (BASE_GENERATION_RATE + (int)(BASE_GENERATION_RATE * itemRatio));
         if (getsItem == 0 && !tileMap[Key(i, j)]->HasPowerUp() && !(startPoint.first == i && startPoint.second == j) && !(finishPoint.first == i && finishPoint.second == j))
         {
            tileMap[Key(i, j)]->setItem(level); // change second one to Current level player is on
         }
      }
   }
}

bool Map::WallCheckDown(pair<int, int>* characterLocation,
   int characterHeight, int characterWidth)
{
   Tile* currentOne = tileMap[make_pair(characterLocation->first / tileWidth, characterLocation->second / tileHeight)];
   Tile* currentTwo = tileMap[make_pair((characterLocation->first + characterWidth) / tileWidth, characterLocation->second / tileHeight)];

   int currentTileY = characterLocation->second / tileHeight;

   if ((characterLocation->second + characterHeight + bufferZone) / tileHeight > currentTileY)
   {
      if (!currentOne->HasBottomWall() && !currentTwo->HasBottomWall())
      {
         Tile* newOne = tileMap[make_pair(characterLocation->second / tileWidth, (characterLocation->second / tileHeight) + 1)];
         Tile* newTwo = tileMap[make_pair((characterLocation->first + characterWidth) / tileWidth, (characterLocation->second / tileHeight) + 1)];

         if (characterLocation->first / tileWidth != (characterLocation->first + characterWidth) / tileWidth)
            return (!(newOne->HasRightWall() || newTwo->HasLeftWall()));
         else
            return true;
      }
      return false;
   }
   return true;
}

bool Map::WallCheckUp(pair<int, int>* characterLocation,
   int characterHeight, int characterWidth)
{
   Tile* currentOne = tileMap[make_pair(characterLocation->first / tileWidth, characterLocation->second / tileHeight)];
   Tile* currentTwo = tileMap[make_pair((characterLocation->first + characterWidth) / tileWidth, characterLocation->second / tileHeight)];

   int currentTileY = characterLocation->second / tileHeight;

   if ((characterLocation->second - bufferZone) / tileHeight < currentTileY || characterLocation->second - bufferZone < 0)
   {
      if (!currentOne->HasTopWall() && !currentTwo->HasTopWall())
      {
         Tile* newOne = tileMap[make_pair(characterLocation->first / tileWidth, (characterLocation->second / tileHeight) - 1)];
         Tile* newTwo = tileMap[make_pair((characterLocation->first + characterWidth) / tileWidth, (characterLocation->second / tileHeight) - 1)];

         if (characterLocation->first / tileWidth != (characterLocation->first + characterWidth) / tileWidth)
            return (!(newOne->HasBottomWall() || newTwo->HasBottomWall() || newOne->HasRightWall() || newTwo->HasLeftWall()));
         else
            return (!newOne->HasBottomWall());
      }
      return false;
   }
   return true;
}

bool Map::WallCheckLeft(pair<int, int>* characterLocation,
   int characterHeight, int characterWidth)
{
   Tile* currentOne = tileMap[make_pair(characterLocation->first / tileWidth, characterLocation->second / tileHeight)];
   Tile* currentTwo = tileMap[make_pair(characterLocation->first / tileWidth, (characterLocation->second + characterHeight) / tileHeight)];

   int currentTileX = characterLocation->first / tileWidth;

   if ((characterLocation->first - bufferZone) / tileWidth < currentTileX || characterLocation->first - bufferZone < 0)
   {
      if (!currentOne->HasLeftWall() && !currentTwo->HasLeftWall())
      {
         Tile* newOne = tileMap[make_pair((characterLocation->first / tileWidth) - 1, characterLocation->second / tileHeight)];
         Tile* newTwo = tileMap[make_pair((characterLocation->first / tileWidth) - 1, (characterLocation->second + characterHeight) / tileHeight)];

         if (characterLocation->second / tileHeight != (characterLocation->second + characterHeight) / tileHeight)
            return (!(newOne->HasRightWall() || newTwo->HasRightWall() || newOne->HasBottomWall() || newTwo->HasTopWall()));
         else
            return (!newOne->HasRightWall());
      }
      return false;
   }
   return true;
}

bool Map::WallCheckRight(pair<int, int>* characterLocation,
   int characterHeight, int characterWidth)
{
   Tile* currentOne = tileMap[make_pair(characterLocation->first / tileWidth, characterLocation->second / tileHeight)];
   Tile* currentTwo = tileMap[make_pair(characterLocation->first / tileWidth, (characterLocation->second + characterHeight) / tileHeight)];

   int currentTileX = characterLocation->first / tileWidth;

   if ((characterLocation->first + characterWidth + bufferZone) / tileWidth > currentTileX)
   {
      if (!currentOne->HasRightWall() && !currentTwo->HasRightWall())
      {
         Tile* newOne = tileMap[make_pair((characterLocation->first / tileWidth) + 1, characterLocation->second / tileHeight)];
         Tile* newTwo = tileMap[make_pair((characterLocation->first / tileWidth) + 1, (characterLocation->second + characterHeight) / tileHeight)];

         if (characterLocation->second / tileHeight != (characterLocation->second + characterHeight) / tileHeight)
            return (!(newOne->HasLeftWall() || newTwo->HasLeftWall() || newOne->HasBottomWall() || newTwo->HasTopWall()));
         else
            return (!newOne->HasLeftWall());
      }
      return false;
   }
   return true;
}

bool Map::CheckEnd()
{
   int x = generatorPosition.first;
   int y = generatorPosition.second;
   bool temp = tileMap[generatorPosition]->GetVisited();
   if (!tileMap[generatorPosition]->GetVisited())
   {
      possibleDir = CheckSurroundings();
      if (possibleDir.empty())
         return true;
   }
   return false;
}

void Map::Restart()
{
   noDoor = false;
   deadEnds->clear();
   tileMap.clear();
   for (int y = 0; y < size; y++)
   {
      for (int x = 0; x < size; x++)
      {
         tileMap[Key(x, y)] = new Tile();
      }
   }
   generatorPosition = startPoint;
   isStart = true;
   visitedStack->push(startPoint);
   level++;
}

void Map::SwapPoints()
{
   Key temp = startPoint;
   startPoint = finishPoint;
   finishPoint = temp;
}

void Map::tryUnlock(bool open)
{
   //change to Player has Key
   if (!noDoor)
   {
      noDoor = open;
      if (open)
         doorJustUnlocked = true;
   }

}

bool Map::DoorJustUnlocked()
{
   if (doorJustUnlocked)
   {
      doorJustUnlocked = false;
      return true;
   }
   return false;
}

bool Map::ChangedTile(int direction, pair<int, int>* characterLocation, int characterHeight, int characterWidth)
{
   int curTileX1 = characterLocation->first / tileWidth;
   int curTileY1 = characterLocation->second / tileHeight;
   int curTileX2 = (characterLocation->first + characterWidth) / tileWidth;
   int curTileY2 = (characterLocation->second + characterHeight) / tileHeight;

   switch (direction)
   {
   case 5:
      if ((characterLocation->second + characterHeight - bufferZone) / tileHeight < curTileY2)
         return true;
      return false;
      break;
   case 2:
      if ((characterLocation->second + bufferZone) / tileHeight > curTileY1)
         return true;
      return false;
      break;
   case 1:
      if ((characterLocation->first + characterWidth - bufferZone) / tileWidth < curTileX2)
         return true;
      return false;
      break;
   default:
      if ((characterLocation->first + bufferZone) / tileWidth > curTileX1)
         return true;
      return false;
   }
}

bool Map::updatePowerRatio(float update) //Left bool just incase you wanted it only to go to a certain amount
{
   powerUpRatio += update;
   return true;
}

bool Map::updateItemRatio(float update)
{
   itemRatio += update;
   return true;
}

bool Map::updateDeadEndRatio(int update)
{
   deadEndRatio += update;
   return true;
}

bool Map::updateMapSize(int pnlSize,int incSize)
{
   size += incSize;
   tileHeight = tileWidth = pnlSize / size;
   bufferZone = tileHeight / 10;
   return true;
}

bool Map::IsEqualTo(Map * map)
{  
   bool equal = true;
   
   if (size != map->size)
      return false;
   
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
         if (tileMap[make_pair(i, j)] != map->tileMap[make_pair(i, j)])
            return false;
      }
   }
   
   if (possibleDir != map->possibleDir
      || *visitedStack != *map->visitedStack
      || *deadEnds != *map->deadEnds
      || generatorPosition != map->generatorPosition
      || finishPoint != map->finishPoint
      || startPoint != map->startPoint
      || noDoor != map->noDoor
      || isTutorial != map->isTutorial
      || isStart != map->isStart
      || tileWidth != map->tileWidth
      || tileHeight != map->tileHeight
      || bufferZone != map->bufferZone
      || powerUpRatio != map->powerUpRatio
      || itemRatio != map->itemRatio
      || deadEndRatio != map->deadEndRatio
      || level != map->level)
      return false;

   return equal;
}

#ifdef TESTING_MAP
int main()
{

   Map *map = new Map(15);

   enum { L = 1, D, R, U = 5 }; //Maybe just change to 0-3



   //////////////////////////////////////////////////////////////////////
   //Case 1: Player Movement (Initial)
   //Get the location of the player and display to console
   //////////////////////////////////////////////////////////////////////
   Point p = map->getLocation();
   string str = marshal_as<string>(p.ToString());
   cout << "Case 1: Initial position of player\n" <<
      "Current location of player: " << str << endl;
   if (str == "{X=3,Y=3}")
      cout << "{PASS}--Player is in the correct position(strarting)\n\n";
   else
      cout << "{FAIL}--Player is NOT in correct position\n\n";

   //////////////////////////////////////////////////////////////////////
   //Case 2: Player Movement (Right)
   //Get the location of the player and display to console
   //////////////////////////////////////////////////////////////////////
   map->hero->Move(R); //Movement 
   p = map->GetLocation();
   str = marshal_as<string>(p.ToString());
   cout << "Case 2: Position of player after move right\n" <<
      "Current location of player: " << str << endl;
   if (str == "{X=5,Y=3}")
      cout << "{PASS}--Player is in the correct position\n\n";
   else
      cout << "{FAIL}--Player is NOT in correct position\n\n";

   //////////////////////////////////////////////////////////////////////
   //Case 3: Player Movement (Left)
   //Get the location of the player and display to console
   //////////////////////////////////////////////////////////////////////
   map->hero->Move(L); //Movement 
   p = map->GetLocation();
   str = marshal_as<string>(p.ToString());
   cout << "Case 3: Position of player after move left\n" <<
      "Current location of player: " << str << endl;
   if (str == "{X=3,Y=3}")
      cout << "{PASS}Player is in the correct position\n\n";
   else
      cout << "{FAIL}--Player is NOT in correct position\n\n";

   //////////////////////////////////////////////////////////////////////
   //Case 4: Player Movement (Up)
   //Get the location of the player and display to console
   //////////////////////////////////////////////////////////////////////
   map->hero->Move(U); //Movement 
   p = map->GetLocation();
   str = marshal_as<string>(p.ToString());
   cout << "Case 4: Position of player after move up\n" <<
      "Current location of player: " << str << endl;
   if (str == "{X=3,Y=1}")
      cout << "{PASS}--Player is in the correct position\n\n";
   else
      cout << "{FAIL}--Player is NOT in correct position\n\n";

   //////////////////////////////////////////////////////////////////////
   //Case 5: Player Movement (Down)
   //Get the location of the player and display to console
   //////////////////////////////////////////////////////////////////////
   map->hero->Move(D); //Movement 
   p = map->GetLocation();
   str = marshal_as<string>(p.ToString());
   cout << "Case 2: Position of player after move Down\n" <<
      "Current location of player: " << str << endl;
   if (str == "{X=3,Y=3}")
      cout << "{PASS}--Player is in the correct position\n\n";
   else
      cout << "{FAIL}--Player is NOT in correct position\n\n";


   //////////////////////////////////////////////////////////////////////
   //Case 6: Getting Map size when tutorial is not set up
   //Get the size of the map
   //////////////////////////////////////////////////////////////////////
   int s = map->GetMapSize();
   cout << "Case 6: The Size of the map\n" <<
      "Current map Size: " << s << endl;
   if (s == 15)
      cout << "{PASS}--Map size is correct\n\n";
   else
      cout << "{FAIL}--Map size is not correct";

   //////////////////////////////////////////////////////////////////////
   //Case 7: Getting tutorial status when tutorial is not turned on
   //////////////////////////////////////////////////////////////////////
   cout << "Case 7: Tutorial level status\n";
   if (!map->Tutorial(false))
      cout << "{PASS}--Tutorial is not active\n\n";
   else
      cout << "{FAIL}--Tutorial is active but should not be\n\n";

   //////////////////////////////////////////////////////////////////////
   //Case 8: Getting tutorial status when tutorial is active
   //////////////////////////////////////////////////////////////////////
   cout << "Case 8: Tutorial level status\n";
   if (map->Tutorial(true))
      cout << "{PASS}--Tutorial is active\n\n";
   else
      cout << "{FAIL}--Tutorial is not active but should be\n\n";

   //////////////////////////////////////////////////////////////////////
   //Case 9: Getting map size when tutorial is set up
   //Get the size of the map
   //////////////////////////////////////////////////////////////////////
   s = map->GetMapSize();
   cout << "Case 9: Map size when the tutorial is created\n" <<
      "Current map size: " << s << endl;
   if (s == 10)
      cout << "{PASS}--Map size is correct\n\n";
   else
      cout << "{FAIL}--Map size is not correct\n\n";
   delete map;

   ////////////////////////////////////////////////////////////////////
   //Case 9: Wall checking when up movement contained in single tile
   ////////////////////////////////////////////////////////////////////
   map = new Map(10);
   map->Tutorial(true);
   map->MakePaths();

   if (map->WallCheckUp(Point(10, 10), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves UP when contained in single "
      << "tile" << endl;
   else
      cout << "(FAIL) Character moves UP when contained in single "
      << "tile" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 10: Wall checking when up movement enters new tile pair
   //unrestricted
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckUp(Point(130, 48), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves UP when horizontally in two "
      << "tiles and no walls block path" << endl;
   else
      cout << "(FAIL) Character moves UP when horizontally in two "
      << "tiles and no walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 11: Wall checking when up movement enters new tile pair
   //with vertical wall restricted movement
   ////////////////////////////////////////////////////////////////////
   if (!map->WallCheckUp(Point(130, 182), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character doesn't move UP when horizontally "
      << "in two tiles and vertical walls block path" << endl;
   else
      cout << "(FAIL) Character doesn't move UP when horizontally in "
      << "two tiles and vertical walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 12: Wall checking when up movement enters new tile 
   //unrestricted
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckUp(Point(60, 48), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves UP when horizontally in one "
      << "tile and no walls block path" << endl;
   else
      cout << "(FAIL) Character moves UP when horizontally in one "
      << "tile and no walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 13: Wall checking when up movement enters new tile pair and
   //horizontal walls block path
   ////////////////////////////////////////////////////////////////////
   if (!map->WallCheckUp(Point(20, 137), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character doesn't move UP when horizontally in "
      << "two tiles and horizontal walls block path" << endl;
   else
      cout << "(FAIL) Character doesn't move UP when horizontally in "
      << "two tiles and horizontal walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 14: Wall checking when down movement contained in single tile
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckDown(Point(10, 10), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves DOWN when contained in single "
      << "tile" << endl;
   else
      cout << "(FAIL) Character moves DOWN when contained in single "
      << "tile" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 15: Wall checking when down movement enters new tile pair
   //unrestricted
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckDown(Point(130, 43), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves DOWN when horizontally in two "
      << "tiles and no walls block path" << endl;
   else
      cout << "(FAIL) Character moves DOWN when horizontally in two "
      << "tiles and no walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 16: Wall checking when down movement enters new tile pair
   //with vertical wall restricted movement
   ////////////////////////////////////////////////////////////////////
   if (!map->WallCheckDown(Point(130, 88), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character doesn't move DOWN when horizontally "
      << "in two tiles and vertical walls block path" << endl;
   else
      cout << "(FAIL) Character doesn't move DOWN when horizontally "
      << "in two tiles and vertical walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 17: Wall checking when down movement enters new tile
   //unrestricted
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckDown(Point(60, 43), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves DOWN when horizontally in one "
      << "tile and no walls block path" << endl;
   else
      cout << "(FAIL) Character moves DOWN when horizontally in one "
      << "tile and no walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 18: Wall checking when down movement enters new tile pair and
   //horizontal walls block path
   ////////////////////////////////////////////////////////////////////
   if (!map->WallCheckDown(Point(20, 133), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character doesn't move DOWN when horizontally "
      << "in two tiles and horizontal walls block path" << endl;
   else
      cout << "(FAIL) Character doesn't move DOWN when horizontally "
      << "in two tiles and horizontal walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 19: Wall checking when left movement contained in single tile
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckLeft(Point(10, 10), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves LEFT when contained in single "
      << "tile" << endl;
   else
      cout << "(FAIL) Character moves LEFT when contained in single "
      << "tile" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 20: Wall checking when left movement enters new tile pair
   //unrestricted
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckLeft(Point(137, 20), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves LEFT when vertically in two "
      << "tiles and no walls block path" << endl;
   else
      cout << "(FAIL) Character moves LEFT when vertically in two "
      << "tiles and no walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 21: Wall checking when left movement enters new tile pair
   //with vertical wall restricted movement
   ////////////////////////////////////////////////////////////////////
   if (!map->WallCheckLeft(Point(47, 40), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character doesn't move LEFT when vertically "
      << "in two tiles and horizontal walls block path" << endl;
   else
      cout << "(FAIL) Character doesn't move LEFT when vertically "
      << "in two tiles and horizontal walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 22: Wall checking when left movement enters new tile
   //unrestricted
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckLeft(Point(47, 2), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves LEFT when vertically in one "
      << "tile and no walls block path" << endl;
   else
      cout << "(FAIL) Character moves LEFT when vertically in one "
      << "tile and no walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 23: Wall checking when left movement enters new tile pair and
   //horizontal walls block path
   ////////////////////////////////////////////////////////////////////
   if (!map->WallCheckLeft(Point(92, 20), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character doesn't move LEFT when vertically "
      << "in two tiles and vertical walls block path" << endl;
   else
      cout << "(FAIL) Character doesn't move LEFT when vertically "
      << "in two tiles and vertical walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 24: Wall checking when right movement contained in single tile
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckRight(Point(10, 10), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves RIGHT when contained in single "
      << "tile" << endl;
   else
      cout << "(FAIL) Character moves RIGHT when contained in single "
      << "tile" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 25: Wall checking when right movement enters new tile pair
   //unrestricted
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckRight(Point(115, 43), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves RIGHT when vertically in two "
      << "tiles and no walls block path" << endl;
   else
      cout << "(FAIL) Character moves RIGHT when vertically in two "
      << "tiles and no walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 26: Wall checking when right movement enters new tile pair
   //with vertical wall restricted movement
   ////////////////////////////////////////////////////////////////////
   if (!map->WallCheckRight(Point(25, 85), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character doesn't move RIGHT when vertically "
      << "in two tiles and horizontal walls block path" << endl;
   else
      cout << "(FAIL) Character doesn't move RIGHT when vertically "
      << "in two tiles and horizontal walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 27: Wall checking when right movement enters new tile
   //unrestricted
   ////////////////////////////////////////////////////////////////////
   if (map->WallCheckRight(Point(25, 2), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character moves RIGHT when vertically in one "
      << "tile and no walls block path" << endl;
   else
      cout << "(FAIL) Character moves RIGHT when vertically in one "
      << "tile and no walls block path" << endl;

   ////////////////////////////////////////////////////////////////////
   //Case 28: Wall checking when right movement enters new tile pair and
   //horizontal walls block path
   ////////////////////////////////////////////////////////////////////
   if (!map->WallCheckRight(Point(70, 40), map->hero->GetHeight(),
      map->hero->GetWidth()))
      cout << "(PASS) Character doesn't move RIGHT when vertically "
      << "in two tiles and vertical walls block path" << endl;
   else
      cout << "(FAIL) Character doesn't move RIGHT when vertically "
      << "in two tiles and vertical walls block path" << endl;

   cout << endl;
   cout << endl;
   delete map;
   Map* map2 = new Map(2);


   ////////////////////////////////////////////////////////////////////
   //Case 29: Getting the size of a created map
   ////////////////////////////////////////////////////////////////////
   if (map2->GetMapSize() == 2)
      cout << "Map is the correct size" << endl;
   else
      cout << "Incorrect size returned" << endl;

   system("PAUSE");

   return 0;
}
#endif
