//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Program: Maze Runner game; player must escape from random labyrinths
// Purpose: Contains code used to create and manipulate instances of
//          Enemy
//-----------------------------------------------------------------------

#ifndef __ENEMY_H
#define __ENEMY_H

#include "Character.h"
#include <map>
#include "Tile.h"

const int ATTACK_COOL_DOWN_ENEMY = 10;

class Enemy : public Character
{
public:
	//--------------------------------------------------------------------
	// Constructor: generic constructor for enemy, makes adjustments
	//              to values based on map size
	//--------------------------------------------------------------------
	Enemy(int mapSize, int level);

	//--------------------------------------------------------------------
	// Returns integer marking the movement method this enemy will use
	//--------------------------------------------------------------------
	int GetMoveMethod() { return moveMethod; }

	//--------------------------------------------------------------------
	// Sets timer for attack cooldown
	//--------------------------------------------------------------------
	void Attack() { attackCoolDown = ATTACK_COOL_DOWN_ENEMY; }

	/*
   //--------------------------------------------------------------------
	// Returns whether enemy can see the player in line of sight
	//--------------------------------------------------------------------
	int SeesPlayer(int direction, int distanceRemaining, int curTileX,
		int curTileY, int heroCurTileXL, int heroCurTileXR,
		int heroCurTileYT, int heroCurTileYB,
		map<pair<int, int>, Tile*>& tileMap);
   */

	//--------------------------------------------------------------------
	// Sets wheather the bat has been hit duriong the attack animation
	//--------------------------------------------------------------------
	void SetHasBeenHit(bool hit) { hasBeenHit = hit; }

	//--------------------------------------------------------------------
	// gets wheather the bat has been hit duriong the attack animation
	//--------------------------------------------------------------------
	bool GetHasBeenHit() { return hasBeenHit; }

	//--------------------------------------------------------------------
	//returns char* containing image name of enemy
	//--------------------------------------------------------------------
	string GetImgName() { return imgName; }

   //--------------------------------------------------------------------
   // Returns the current destination of an enemy
   //--------------------------------------------------------------------
	pair<int, int> GetDestination() { return destination; }
	
   //--------------------------------------------------------------------
   // Sets the current destination for an enemy
   //--------------------------------------------------------------------
   void SetDestination(pair<int, int> d) { destination = d; }
	
   //--------------------------------------------------------------------
   // Determines whether or not an enemy has reached its destination
   //--------------------------------------------------------------------
   bool IsAtDestination();

   //--------------------------------------------------------------------
   // Returns point value of the enemy 
   //--------------------------------------------------------------------
   int GetPointValue() { return pointValue; }

protected:
   int moveMethod;
   bool hasBeenHit = false;

	pair<int, int> destination;
   
   int pointValue;
};

#endif