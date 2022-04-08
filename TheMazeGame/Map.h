//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Contains information of the map, creates the tutorial level 
//          and displays graphics to screen
//-----------------------------------------------------------------------
#ifndef __MAP_H
#define __MAP_H
//#define TESTING_MAP
#ifdef TESTING_MAP
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h> 
#include <Windows.h>
using namespace msclr::interop;
using namespace std;
#endif

#include <map>
#include <stack>
#include <set>
#include <random>
#include <ctime>
#include <fstream>
#include "Tile.h"
#include "Player.h"

typedef std::pair<int, int> Key;

enum Walls { R, U, L, D, F = -1 };
const static int TUTORIAL_SIZE = 10;
const int MAX_LIGHT_LEVEL = 4;
const int BASE_GENERATION_RATE = 50;

//-----------------------------------------------------------------------
// Maintains and changes game data
//-----------------------------------------------------------------------
class Map
{
public:
   Map(int size);

   //--------------------------------------------------------------------
   // Constructor
   //--------------------------------------------------------------------
   Map(int panelSize, int size, int level);

   // -------------------------------------------------------------------
   // Assignment Operator
   //--------------------------------------------------------------------
   Map& operator=(Map & m);

   //--------------------------------------------------------------------
   // Destructor
   //--------------------------------------------------------------------
   ~Map()
   {
      delete deadEnds;
      delete visitedStack;
      for (int y = 0; y < size; y++)
         for (int x = 0; x < size; x++)
         {
            delete tileMap[Key(x, y)];
         }
   }

   //--------------------------------------------------------------------
   // Populates tileMap with items and paths
   //--------------------------------------------------------------------
   void GenerateMap(Key k);

   //--------------------------------------------------------------------
   // Makes the map less linear by adding multiple paths for the user
   // to take
   //--------------------------------------------------------------------
   void addExtraPaths();

   //--------------------------------------------------------------------
   // Sets GeneratorPosition to last visited Tile
   //--------------------------------------------------------------------
   void GoBack();

   //--------------------------------------------------------------------
   // Moves GeneratorPosition to adjacent Tile to continue generation
   //--------------------------------------------------------------------
   void GoForward(int move);

   //--------------------------------------------------------------------
   // Returns set of integers corresponding to what adjacent Tiles are
   // not visited yet during map generation
   //--------------------------------------------------------------------
   set<int> CheckSurroundings();

   //--------------------------------------------------------------------
   // Picks and returns a random int from set s
   //--------------------------------------------------------------------
   int RandomMove(set<int> s);

   //--------------------------------------------------------------------
   // Checks to see what walls need to be removed and since some walls
   // overlap, it perfroms calculations to remove the next tiles opposite 
   // wall  EX: (0,0)--Right wall == false -makePaths()-> (0,1) 
   // --Left wall == false
   //--------------------------------------------------------------------
   void MakePaths();

   //--------------------------------------------------------------------
   // Reads from file names filename and populates tileMap accordingly
   //--------------------------------------------------------------------
   void MakeMapFromFile(string filename);

   //--------------------------------------------------------------------
   // Determines whether or not paths need to be created
   //--------------------------------------------------------------------
   bool PathsNeeded();

   //--------------------------------------------------------------------
   // Calls setters for RestoreHealth, VisionBoost, and FullVisibility
   //--------------------------------------------------------------------
   void GenerateCollectables();

   //--------------------------------------------------------------------
   // Generates Power Ups for the map
   //--------------------------------------------------------------------
   void GeneratePowerUps();

   //--------------------------------------------------------------------
   // Generates Items for the map
   //--------------------------------------------------------------------
   void GenerateItems();

   //--------------------------------------------------------------------
   // Returns true if Player can move up, false otherwise
   //--------------------------------------------------------------------
   bool WallCheckUp(pair<int, int>* characterLocation,
      int characterHeight, int characterWidth);

   //--------------------------------------------------------------------
   // Returns true if Player can move down, false otherwise
   //--------------------------------------------------------------------
   bool WallCheckDown(pair<int, int>* characterLocation,
      int characterHeight, int characterWidth);

   //--------------------------------------------------------------------
   // Returns true if two Tiles are the same, false otherwise
   //--------------------------------------------------------------------
   bool CheckForSamePosition(pair<int, int> one, pair<int, int> two);

   //--------------------------------------------------------------------
   // Returns true if Player can move left, false otherwise
   //--------------------------------------------------------------------
   bool WallCheckLeft(pair<int, int>* characterLocation,
      int characterHeight, int characterWidth);

   //--------------------------------------------------------------------
   // Returns true if Player can move right, false otherwise
   //--------------------------------------------------------------------
   bool WallCheckRight(pair<int, int>* characterLocation,
      int characterHeight, int characterWidth);

   //--------------------------------------------------------------------
   // Returns a reference to tileMap
   //--------------------------------------------------------------------
   std::map<Key, Tile*>* GetTileMap() { return &tileMap; };

   //--------------------------------------------------------------------
   // Returns key value of GeneratorPosition
   //--------------------------------------------------------------------
   Key GetGeneratorPostion() { return generatorPosition; }

   //--------------------------------------------------------------------
   // Returns Key value of finishPoint
   //--------------------------------------------------------------------
   Key GetFinishPoint() { return finishPoint; }

   //--------------------------------------------------------------------
   // Returns Key value of startPoint
   //--------------------------------------------------------------------
   Key GetStartPoint() { return startPoint; }

   //--------------------------------------------------------------------
   // Returns the map size
   //--------------------------------------------------------------------
   int GetMapSize() { return size; }

   //--------------------------------------------------------------------
   // Clears class containers, generates and begins a new level.
   //--------------------------------------------------------------------
   void Restart();

   //--------------------------------------------------------------------
   // Sets key on a random tile on the map
   //--------------------------------------------------------------------
   void GenerateKey();

   //--------------------------------------------------------------------
   // Swaps the values of startPosition and finishPosition
   //--------------------------------------------------------------------
   void SwapPoints();

   //--------------------------------------------------------------------
   // Returns true if door is unlocked, false otherwise
   //--------------------------------------------------------------------
   bool isUnlocked() { return noDoor; }

   //--------------------------------------------------------------------
   // Attempts to unlock the door
   //--------------------------------------------------------------------
   void tryUnlock(bool open);

   //--------------------------------------------------------------------
   // Returns true if a door was just unlocked, false otherwise
   //--------------------------------------------------------------------
   bool DoorJustUnlocked();

   //--------------------------------------------------------------------
   // Returns tile at positon x,y
   //--------------------------------------------------------------------
   Tile* GetTile(int x, int y) { return tileMap[Key(x, y)]; }

   //--------------------------------------------------------------------
   // Returns whether or not player is entering a different tile
   //--------------------------------------------------------------------
   bool ChangedTile(int direction, pair<int, int>* characterLocation, int characterHeight, int characterWidth);

   //--------------------------------------------------------------------
   // Increments powerRation by update
   //--------------------------------------------------------------------
   bool updatePowerRatio(float update);

   //--------------------------------------------------------------------
   // Increments itemRation by update
   //--------------------------------------------------------------------
   bool updateItemRatio(float update);

   //--------------------------------------------------------------------
   // Increments deadend ration by update
   //--------------------------------------------------------------------
   bool updateDeadEndRatio(int update);

   //--------------------------------------------------------------------
   // Increases map size by incSize
   //--------------------------------------------------------------------
   bool updateMapSize(int pnlSize,int incSize);

   //--------------------------------------------------------------------
   // Returns value of tileHeight
   //--------------------------------------------------------------------
   int GetTileHeight() { return tileHeight; }

	//--------------------------------------------------------------------
	// Returns level number of map
	//--------------------------------------------------------------------
   int GetLevel() { return level; }

   //--------------------------------------------------------------------
   // Sets level number of map
   //--------------------------------------------------------------------
   void SetLevel(int lv) { level = lv; }

   bool IsEqualTo(Map * map);

	//--------------------------------------------------------------------
	// Returns value of bufferZone, important for wall girth
	//--------------------------------------------------------------------
   int GetBufferZone() { return bufferZone; }

   // -------------------------------------------------------------------
   // Copy Constructor: disallowed by private placement
   //--------------------------------------------------------------------
   Map(Map & m) { operator=(m); }
   
   bool createPaths;
   //--------------------------------------------------------------------
   // Returns dead end ratio
   //--------------------------------------------------------------------
   int GetDeadEndRatio()
   {
      return deadEndRatio;
   }

   //--------------------------------------------------------------------
   // Returns item ratio
   //--------------------------------------------------------------------
   int GetItemRatio()
   {
      return itemRatio;
   }

   //--------------------------------------------------------------------
   // Returns item ratio
   //--------------------------------------------------------------------
   float GetPowerRatio()
   {
      return powerUpRatio;
   }
private:
   
   //--------------------------------------------------------------------
   // Returns true if there are no Tiles left to change, false otherwise
   //--------------------------------------------------------------------
   bool CheckEnd();

   std::map<Key, Tile*> tileMap;
   std::set<int> possibleDir;
   std::stack<Key> *visitedStack;
   std::set<Key> *deadEnds;
   Key generatorPosition;
   Key finishPoint;
   Key startPoint;

   bool noDoor;
   bool isTutorial;
   bool isStart;
   int size;
   int tileWidth, tileHeight;
   int bufferZone = 4;
   float powerUpRatio;
   float itemRatio;
   int deadEndRatio;
   int level;
   bool doorJustUnlocked;
};
#endif