//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Handles input from GUI regarding game entities.
//-----------------------------------------------------------------------

#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H

#include <iostream>
#include <string>
//#include <msclr\marshal_cppstd.h> 
//#include <Windows.h>
#include <map>
#include <stack>
#include <set>
#include <random>
#include <ctime>
#include <fstream>
#include "Tile.h"
#include "Player.h"
#include "Map.h"
#include "CharacterManager.h"
#include "Command.h"
#include "AdvanceCommand.h"

//using namespace msclr::interop;
using namespace std;

const int EASY = 10;
const int MEDIUM = 20;
const int HARD = 30;
const int TUT = 10;
const int BONUS = 100;
const int TOTALTIME = 50; //1000ms = 1sec
const std::string INSTRUCTIONS =
"Movement: Your character is controlled using the arrow keys.\n\r"
"Attacking: Use 'F' to slash and 'D' to stab";

class GameManager
{
public:
   GameManager(int pnlSize, int size);

   //--------------------------------------------------------------------
   // Moves player according to direction
   //--------------------------------------------------------------------
   void MovePlayer(int direction);

   //--------------------------------------------------------------------
   // Sets what part of map player can see and what they can not
   //--------------------------------------------------------------------
   void SetLineOfSightHelper();

   //--------------------------------------------------------------------
   // Sets what level of vison player has for tile depending on distance
   //--------------------------------------------------------------------
   void SetLineOfSight(int direction, int curX, int curY,
      int curLightLevel);

   //--------------------------------------------------------------------
   // Sets vision around corners
   //--------------------------------------------------------------------
   void SetWrapAround(int direction, int curX, int curY,
      int curLightLevel);

   //--------------------------------------------------------------------
   // Decrements time left for powerup
   //--------------------------------------------------------------------
   void coolDownTick();

   //--------------------------------------------------------------------
   // Returns INSTRUCTIONS
   //--------------------------------------------------------------------
   string GetInstructions() { return INSTRUCTIONS; }

   //--------------------------------------------------------------------
   // Sets gameRunning to value
   //--------------------------------------------------------------------
   void SetGameRunning(bool value) { gameRunning = value; }

   //--------------------------------------------------------------------
   // Returns gameRunning
   //--------------------------------------------------------------------
   bool CheckGameRunning() { return gameRunning; }

   //--------------------------------------------------------------------
   // Returns level
   //--------------------------------------------------------------------
   int getLevel() { return level; }

   //--------------------------------------------------------------------
   // Returns score
   //--------------------------------------------------------------------
   int getScore() { return score; }

   //--------------------------------------------------------------------
   // Returns bonus score counter value
   //--------------------------------------------------------------------
   int getBonus();

   //--------------------------------------------------------------------
   // Checks the collision of the player's sword with the enemy and deals
   // appropriate damage
   //--------------------------------------------------------------------
   void checkCollision(int attacktype);

   //--------------------------------------------------------------------
   // Checks if the player is being hit by an enemy and deals damage to
   // the enemy
   //--------------------------------------------------------------------
   void checkPlayerHit();
   
   //--------------------------------------------------------------------
   // Returns character manager
   //--------------------------------------------------------------------
   CharacterManager* GetCharacterManager() { return charMan; }

   //--------------------------------------------------------------------
   // Returns Key value of character position
   //--------------------------------------------------------------------
   Key* GetLocation() { return charMan->GetHero()->GetLocation(); }

   //--------------------------------------------------------------------
   // Returns whether two rectangles overlap, both input as the bounds of
	// their edges
   //--------------------------------------------------------------------
   bool CheckBounds(int OneLB, int OneTB, int OneRB, int OneBB, 
					int TwoLB, int TwoTB, int TwoRB, int TwoBB);

   //--------------------------------------------------------------------
   // Sets leftInitialTile to a inputed bool value
   //--------------------------------------------------------------------
   void SetLeftInitialTile(bool setter) { leftInitialTile = setter; }

   //--------------------------------------------------------------------
   // Gets the value of leftInitialTile
   //--------------------------------------------------------------------
   bool GetLeftInitialTile() { return leftInitialTile; }

   Map* gameMap;

private:
   //--------------------------------------------------------------------
   // Increases difficulty of game
   //--------------------------------------------------------------------
   void AddDifficutly();

   //--------------------------------------------------------------------
   // Recalcultates game sizing so as to adjust view to game alterations
   //--------------------------------------------------------------------
   void ResetSizing(int inc,bool startAtFinish);

   CharacterManager* charMan;
   stack<Command*>* undo;
   stack<Command*>* redo;
   Command* tempCommand;
   int size;
   int panelSize;
   int score;
   int bonus, bonusCount;
   int level;
   int tileWidth;
   int tileHeight;
   float enemyDamageRatio;
   bool gameRunning;
   bool leftInitialTile;
};

#endif