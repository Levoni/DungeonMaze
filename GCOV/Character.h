//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Program: Maze Runner game; player must escape from random labyrinths
// Purpose: Contains code used to create and manipulate instances of
//          character.
//-----------------------------------------------------------------------

#ifndef __CHARACTER_H
#define __CHARACTER_H

#include <utility>
#include <string>

using namespace std;

//-----------------------------------------------------------------------
// Holds information for a character
//-----------------------------------------------------------------------
class Character
{
public:
   //--------------------------------------------------------------------
   // Default constructor: generates new character
   //--------------------------------------------------------------------
   Character(int mapSize);

   //--------------------------------------------------------------------
   // Destructor: deletes pointer to location
   //--------------------------------------------------------------------
   ~Character() { delete location; }

   //--------------------------------------------------------------------
   // Moves character in indicated direction
   //--------------------------------------------------------------------
   void Move(int direction);

   //--------------------------------------------------------------------
   // Returns location of character, measured in pixels
   //--------------------------------------------------------------------
   pair<int, int>* GetLocation() { return location; }

   //--------------------------------------------------------------------
   // Returns direction of character
   //--------------------------------------------------------------------
   int GetDirection() { return currentDirection; }

   //--------------------------------------------------------------------
   // Sets direction of character
   //--------------------------------------------------------------------
   void SetDirection(int dir) { currentDirection = dir; }

   //--------------------------------------------------------------------
   // Sets location of character to new point
   //--------------------------------------------------------------------
   void SetLocation(pair<int, int> newLocation) { *location = newLocation; }

   //--------------------------------------------------------------------
   // Returns size of character in pixels. This assumes all characters 
   // are square in shape.
   //--------------------------------------------------------------------
   int GetHeight() { return characterHeight; }

   //--------------------------------------------------------------------
   // Returns size of character in pixels. This assumes all characters 
   // are square in shape.
   //--------------------------------------------------------------------
   int GetWidth() { return characterWidth; }

   //--------------------------------------------------------------------
   // Returns vision range of character
   //--------------------------------------------------------------------
   int GetSightRange() { return sightRange; }

   //--------------------------------------------------------------------
   // Return attack damage of player
   //--------------------------------------------------------------------
   int GetAttackDamage() { return attackDamage; }

   //--------------------------------------------------------------------
   // Sets size of character and location of character
   //--------------------------------------------------------------------
   void updateSizeLocation(int size,pair<int,int>);

   //--------------------------------------------------------------------
   // Returns current health of character
   //--------------------------------------------------------------------
   int GetHealth() { return curHealth; }

   //--------------------------------------------------------------------
   // Returns current armor of character
   //--------------------------------------------------------------------
   int GetArmor() { return armor; }

   //--------------------------------------------------------------------
   // Increases or decreases health of character, depending on input 
   // value
   //--------------------------------------------------------------------
   void Heal(int amount);

   //--------------------------------------------------------------------
   // Decreases health of character, depending on dammage and armor value
   //--------------------------------------------------------------------
   void TakeDamage(int amount);

   //--------------------------------------------------------------------
   // Returns how much time left before character can attack again
   //--------------------------------------------------------------------
   int AttackCoolDown();

   //--------------------------------------------------------------------
   // Returns how much damage the character should do and sets its
   // attack cool down
   //--------------------------------------------------------------------
   int DealDamage();


   //--------------------------------------------------------------------
   // Sets and returns whether this character was hit/took damage recently
   //--------------------------------------------------------------------
   bool CharacterJustHit();

   //--------------------------------------------------------------------
   // Returns distance character travels per move
   //--------------------------------------------------------------------
	int GetMoveDistance() { return moveDistance; }

	void SetIsStraffing(bool straf) { isStraffing = straf; }


protected:
   const int UP = 5;
   const int DOWN = 2;
   const int LEFT = 1;
   const int RIGHT = 3;
   const int MOVEMENT_SCALING_FACTOR = 10;
   const float SIZE_SCALING_FACTOR = 0.75;
   const int INITIAL_LOCATION_X = 3;
   const int INITIAL_LOCATION_Y = 3;
   const int COOL_DOWN_TICKS = 20;

   int moveDistance;
   int curHealth;
   int maxHealth;
   int characterHeight, characterWidth;
   int currentDirection;
   int armor;
   int sightRange;
   int attackDamage;
   int attackCoolDown;

   bool characterHit;
   bool isStraffing;
  
   string imgName;

   pair<int, int>* location;

};

#endif