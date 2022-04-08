//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Program: Maze Runner game; player must escape from random labyrinths
// Purpose: Contains code used to create and manipulate instances of a
//          character manager
//-----------------------------------------------------------------------

#ifndef __CHARACTERMANAGER_H
#define __CHARACTERMANAGER_H

#include <list>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Bat.h"
#include "SlimeEnemy.h"
#include "Spider.h"

using namespace std;

const int SPAWN_BUFFER_ZONE = 3;
const int ENEMY_NUMBER = 3;
const int SPAWN_MULTIPLIER = 2;

//-----------------------------------------------------------------------
// Interface for all character instances in game
//-----------------------------------------------------------------------
class CharacterManager
{
public:
   CharacterManager(Map* curMap, int tw, int th)
   {
      gameMap = curMap;
      hero = new Player(th);
      enemies = new list<Enemy*>();
      tileWidth = tw;
      tileHeight = th;
      enemyDied = false;
   }

   ~CharacterManager();

   //--------------------------------------------------------------------
   // Attempts to move player in direction corresponding to direction
   //--------------------------------------------------------------------
   void MovePlayer(int direction);

   //--------------------------------------------------------------------
   // Calls all movement functions for enemeies in game
   //--------------------------------------------------------------------
   void MoveAllEnemies();

   //--------------------------------------------------------------------
   // Spawns a number of enemies corresponding to level of game
   //--------------------------------------------------------------------
   void SpawnEnemies();

   //--------------------------------------------------------------------
   // Removes all enemies from current level
   //--------------------------------------------------------------------
   void ClearEnemies();   
   
   //--------------------------------------------------------------------
   // Sets that player no longer has key
   //--------------------------------------------------------------------
   //void ResetPlayerKey() { hero->setKey(false); }

   //--------------------------------------------------------------------
   // Returns pointer to enemy existing at input index of enemies list
   //--------------------------------------------------------------------
   Enemy* GetEnemy(int index);

   //--------------------------------------------------------------------
   // Attempts to unlock door by checking is player has key
   //--------------------------------------------------------------------
   bool tryUnlock();

   

   //--------------------------------------------------------------------
   // Activates a power up 
   //--------------------------------------------------------------------
   void ExecutePowerUp(Tile* tile);

   //--------------------------------------------------------------------
   // Activates an item
   //--------------------------------------------------------------------
   void ExecuteItem(Tile* tile);

   

   //--------------------------------------------------------------------
   // Sets enemy died
   //--------------------------------------------------------------------
   void SetEnemyDied() { enemyDied = true; }

   //--------------------------------------------------------------------
   // gets enemy died
   //--------------------------------------------------------------------
   bool GetEnemyDied();
   
   //--------------------------------------------------------------------
   // Removes Enemy from the list and deletes it
   //--------------------------------------------------------------------
	void killEnemy(Enemy *en);

   
   //--------------------------------------------------------------------
   // Returns how many enemies are in game
   //--------------------------------------------------------------------
   int getNumEnemies() { return enemies->size(); }

   //--------------------------------------------------------------------
   // Returns hero
   //--------------------------------------------------------------------
   Player* GetHero() { return hero; }

   //--------------------------------------------------------------------
   // Checks whether Enemy will hit a wall in specified direction
   //--------------------------------------------------------------------
   void ResetEnemyIsHit();

   //--------------------------------------------------------------------
   // Updates the size of the tile widths/heights
   //--------------------------------------------------------------------
   void UpdateSizing(int tileSize);

   //--------------------------------------------------------------------
   // Returns whether an enemy was hit this tick or not
   //--------------------------------------------------------------------
   bool EnemyHit();

private:
   //--------------------------------------------------------------------
   // Updates enemy position, and sets current direction of enemy
   //--------------------------------------------------------------------
   void MoveEnemy(Enemy* curEnemy);

   //--------------------------------------------------------------------
   // Enemy movement method: goes straight until it hits a wall, then
	// turns left
   //--------------------------------------------------------------------
   void StraightOrLeft(Enemy* curEnemy);

   //--------------------------------------------------------------------
   // Checks whether Enemy will hit a wall in specified direction
   //--------------------------------------------------------------------
   bool EnemyCanMove(Enemy* curEnemy, int direction);

   //--------------------------------------------------------------------
   // Returns next destination point along path toward hero, calculated
	// using a modified greedy best first search algorithm
   //--------------------------------------------------------------------
   pair<int,int> GetDestPairBFS(Enemy* curEnemy);

   //--------------------------------------------------------------------
   // Returns manhattan distance from current tile to tile occupied by
	// the hero
   //--------------------------------------------------------------------
   int GetHeuristic(const pair<int, int>& curPair);
	
   //--------------------------------------------------------------------
   // Enemy movement method: Moves enemy along shortest path toward hero,
	// calculated by a modified greedy best first search algorithm
   //--------------------------------------------------------------------
	void GreedyBFS(Enemy* curEnemy);

	//--------------------------------------------------------------------
	// Enemy movement method: Moves enemy toward point regardless of walls
	// in its way.
	//--------------------------------------------------------------------
	void DumbMoveTowardPoint(Enemy* curEnemy, pair<int,int> destPoint);

	//--------------------------------------------------------------------
	// Enemy movement method: Moves enemy toward point if no walls prevent
	// from doing so
	//--------------------------------------------------------------------
	void TurnAtIntersection(Enemy* curEnemy);

	//--------------------------------------------------------------------
	// Returns destination point among tiles adjacent to tile occupied by
	// an enemy.
	//--------------------------------------------------------------------
	pair<int,int> GetRandomAdjacentDest(Enemy* curEnemy);


   Map* gameMap;
   Player* hero;
   list<Enemy*>* enemies;
   int tileHeight;
   int tileWidth;
   bool enemyDied;
};

#endif