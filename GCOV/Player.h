//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Handles player movement and attack
//-----------------------------------------------------------------------

#ifndef __PLAYER_H
#define __PLAYER_H

//#define __TESTING_PLAYER
#ifdef __TESTING_PLAYER
#include <iostream>

#endif
#include "Character.h"

using namespace std;

const int UP = 5;
const int DOWN = 2;
const int LEFT = 1;
const int RIGHT = 3;
const int PLAYER_MAX_HEALTH = 100;
const int INITIAL_ARMOR_STRENGTH = 1;
const int INITIAL_WEAPON_STRENGTH = 1;
const int PLAYER_SIGHT_RANGE = 4;
const int RECOVERY_AMOUNT = 20;
const int MAX_VISIBILITY_TIMER = 100;
const int MAX_VISION_BOOST_TIMER = 500;
const int INITIAL_LOCATION_X = 3;
const int INITIAL_LOCATION_Y = 3;
const int MOVEMENT_SCALING_FACTOR = 10;
const float SIZE_SCALING_FACTOR = 0.75;
const int ATTACK_COOL_DOWN_PLAYER = 20;

//-----------------------------------------------------------------------
// Holds information for the player's character
//-----------------------------------------------------------------------
class Player :public Character
{
public:
   //--------------------------------------------------------------------
   // Constructor: places character at starting point
   //--------------------------------------------------------------------
   Player(int size);

   //--------------------------------------------------------------------
   // sets the sightRange of the player
   //--------------------------------------------------------------------
   void SetSightRange(int range) { sightRange = range; }

   //--------------------------------------------------------------------
   // sets whether the player has a sight boost or not.
   //--------------------------------------------------------------------
   void SetVisionBoost(bool visionBoost) 
   { 
      this->visionBoost = visionBoost;
      collectedFlashlight = true; 
      visionBoostTimer = MAX_VISION_BOOST_TIMER;
   }

   //--------------------------------------------------------------------
   // returns whether player has a sightBoost powerup in affect.
   //--------------------------------------------------------------------
   bool GetVisionBoost() { return visionBoost; }

   //--------------------------------------------------------------------
   // sets whether the player has a total visability boost or not.
   //--------------------------------------------------------------------
   void SetFullVisibility(bool fullVisibility) 
   { 
      this->fullVisibility = fullVisibility; 
      collectedFlashlight = true; 
      fullVisibilityTimer = MAX_VISIBILITY_TIMER;
   }

   //--------------------------------------------------------------------
   // returns weather player has a vision boost powerup in affect.
   //--------------------------------------------------------------------
   bool GetFullVisibility() { return fullVisibility; }

   //--------------------------------------------------------------------
   // Subtracts 1 from the vision boost timer.  If the timer has reached
   // 0, the vision boost power-up is turned off and the timer is reset.
   // Returns true if timer reached 0; false if otherwise.
   //--------------------------------------------------------------------
   bool VisionBoostCountdown();

   //--------------------------------------------------------------------
   // Subtracts 1 from the full visibility timer.  If the timer has
   // reached 0, the full visibility power-up is turned off and the timer
   // is reset.
   // Returns true if timer reached 0; false if otherwise.
   //--------------------------------------------------------------------
   bool FullVisibilityCountdown();

   //--------------------------------------------------------------------
   // sets the armor amount the  player has.
   //--------------------------------------------------------------------
   void SetArmor(int equipment, int rarity) { armor = equipment; armorRarity = rarity; collectedWeaponArmor = true; }

   //--------------------------------------------------------------------
   // sets the weapon damage amount the player has.
   //--------------------------------------------------------------------
   void SetDamage(int equipment, int rarity) { attackDamage = equipment; weaponRarity = rarity; collectedWeaponArmor = true; }

   //--------------------------------------------------------------------
   // Rertursn weaponRarity
   //--------------------------------------------------------------------
   int GetWeaponRarity() { return weaponRarity; }

   //--------------------------------------------------------------------
   // Returns armorRarity
   //--------------------------------------------------------------------
   int GetArmorRarity() { return armorRarity; }

   //--------------------------------------------------------------------
   // Sets whether player has key
   //--------------------------------------------------------------------
   void setKey(bool dKey) { DoorKey = dKey; }

   //--------------------------------------------------------------------
   // Returns DoorKey
   //--------------------------------------------------------------------
   bool hasKey() { return DoorKey; }

   //--------------------------------------------------------------------
   // Sets attack cooldown value
   //--------------------------------------------------------------------
   void Attack() { attackCoolDown = ATTACK_COOL_DOWN_PLAYER; }

   //--------------------------------------------------------------------
   // Gets x value of attack distance
   //--------------------------------------------------------------------
   pair <int, int> GetSXBounds(int attackType);

   //--------------------------------------------------------------------
   // Gets y value of attack distance
   //--------------------------------------------------------------------
   pair <int, int> GetSYBounds(int attackType);

   //--------------------------------------------------------------------
   // calculates range of players attack
   //--------------------------------------------------------------------
   void caculateSwingDistance(int animationStage, int attackType);

	//--------------------------------------------------------------------
	// Switches and returns whether flashlight powerup was collected 
	// this tick
	//--------------------------------------------------------------------
   bool FlashlightJustCollected();

	//--------------------------------------------------------------------
	// Switches and returns whether equipment was collected this tick
	//--------------------------------------------------------------------
   bool WeaponArmorJustCollected();

private:
   int weaponRarity = 0;
   int armorRarity = 0;

   // sword bounds
   int SXLB;
   int SXRB;
   int SYUB;
   int SYLB;
   int swingDistance;
   bool collectedFlashlight;
   bool collectedWeaponArmor;

   bool DoorKey;
   bool visionBoost;
   bool fullVisibility;
   int fullVisibilityTimer;
   int visionBoostTimer;
};

#endif