//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Levon Swenson, Zachary Lee, Phillip Patakos
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  This class handles player information and movement
//-----------------------------------------------------------------------

#include "Player.h"

Player::Player(int size):Character(size)
{
   location = new pair<int, int>(INITIAL_LOCATION_X, INITIAL_LOCATION_Y);
   curHealth = maxHealth = PLAYER_MAX_HEALTH;
   DoorKey = false;
   sightRange = PLAYER_SIGHT_RANGE;
   visionBoost = false;
   fullVisibility = false;
   visionBoostTimer = MAX_VISION_BOOST_TIMER;
   fullVisibilityTimer = MAX_VISIBILITY_TIMER;
   attackCoolDown = ATTACK_COOL_DOWN_PLAYER; 

   collectedFlashlight = false;
   collectedWeaponArmor = false;
}

bool Player::FullVisibilityCountdown()
{
   fullVisibilityTimer--;

   if (fullVisibilityTimer <= 0)
   {
      fullVisibility = false;
      fullVisibilityTimer = MAX_VISIBILITY_TIMER;
      return true;
   }
   return false;
}

bool Player::VisionBoostCountdown()
{
   visionBoostTimer--;

   if (visionBoostTimer <= 0)
   {
      visionBoost = false;
      visionBoostTimer = MAX_VISION_BOOST_TIMER;
      return true;
   }
   return false;
}

pair <int, int> Player::GetSXBounds(int attackType)
{
   if (currentDirection == 5)
   {
      if (attackType == 1)
      {
         return make_pair(location->first + swingDistance, location->first + swingDistance + characterWidth / 2);
      }
      else if (attackType == 2)
      {
         return make_pair(location->first + (characterWidth / 4), location->first + (characterWidth / 4) + characterWidth / 2);
      }
   }

   else if (currentDirection == 3)
   {
      if (attackType == 1)
      {
         return make_pair(location->first + characterWidth / 2, location->first + characterWidth / 2 + characterWidth);
      }
      else if (attackType == 2)
      {
         return make_pair(location->first + characterWidth / 2 + swingDistance, location->first + characterWidth / 2 + swingDistance + characterWidth);
      }
   }

   else if (currentDirection == 2)
   {
      if (attackType == 1)
      {
         return make_pair(location->first + swingDistance, location->first + swingDistance + characterWidth / 2);
      }
      else if (attackType == 2)
      {
         return make_pair(location->first + characterWidth / 4, location->first + characterWidth / 4 + characterWidth / 2);
      }
   }
   else if (currentDirection == 1)
   {
      if (attackType == 1)
      {
         return make_pair(location->first - characterWidth / 2, location->first - characterWidth / 2 + characterWidth);
      }
      else if (attackType == 2)
      {
         return make_pair(location->first - characterWidth / 2 - swingDistance, location->first - characterWidth / 2 - swingDistance + characterWidth);
      }
   }
}

pair <int, int> Player::GetSYBounds(int attackType)
{
   if (currentDirection == 5)
   {
      if (attackType == 1)
      {
         return make_pair(location->second - characterHeight / 2, location->second - characterHeight / 2 + characterHeight);
      }
      else if (attackType == 2)
      {
         return make_pair(location->second - characterHeight / 2 - swingDistance, location->second - characterHeight / 2 - swingDistance + characterHeight);
      }
   }

   else if (currentDirection == 3)
   {
      if (attackType == 1)
      {
         return make_pair(location->second + swingDistance, location->second + swingDistance + characterHeight / 2);
      }
      else if (attackType == 2)
      {
         return make_pair(location->second + characterHeight / 4, location->second + characterHeight / 4 + characterHeight / 2);
      }
   }

   else if (currentDirection == 2)
   {
      if (attackType == 1)
      {
         return make_pair(location->second + characterHeight / 2, location->second + characterHeight / 2 + characterHeight);
      }
      else if (attackType == 2)
      {
         return make_pair(location->second + characterHeight / 2 + swingDistance, location->second + characterHeight / 2 + swingDistance + characterHeight);
      }
   }
   else if (currentDirection == 1)
   {
      if (attackType == 1)
      {
         return make_pair(location->second + swingDistance, location->second + swingDistance + characterHeight / 2);
      }
      else if (attackType == 2)
      {
         return make_pair(location->second + characterHeight / 4, location->second + characterHeight / 4 + characterHeight / 2);
      }
   }
}

void Player::caculateSwingDistance(int animationStage, int attackType)
{
   if (currentDirection == 5)
   {
      if (attackType == 1)
      {
         swingDistance = characterWidth / 2 - ((characterWidth / 2) / 5) * animationStage;
      }
      else if (attackType == 2)
      {
         swingDistance = (characterHeight / 2) - (((characterHeight / 2) / 5) * animationStage);
      }
   }
   else if (currentDirection == 3)
   {
      if (attackType == 1)
      {
         swingDistance = (characterHeight / 2) - ((characterHeight / 2) / 5) * animationStage;
      }
      else if (attackType == 2)
      {
         swingDistance = (characterWidth / 2) - (((characterWidth / 2) / 5) * animationStage);
      }
   }
   else if (currentDirection == 2)
   {
      if (attackType == 1)
      {
         swingDistance = (characterWidth / 2) - ((characterWidth / 2) / 5) * animationStage;
      }
      else if (attackType == 2)
      {
         swingDistance = (characterHeight / 2) - (((characterWidth / 2) / 5) * animationStage);
      }
   }
   else if (currentDirection == 1)
   {
      if (attackType == 1)
      {
         swingDistance = (characterHeight / 2) - ((characterHeight / 2) / 5) * animationStage;
      }
      else if (attackType == 2)
      {
         swingDistance = (characterWidth / 2) - (((characterWidth / 2) / 5) * animationStage);
      }
   }
}

bool Player::FlashlightJustCollected()
{
   if (collectedFlashlight)
   {
      collectedFlashlight = false;
      return true;
   }
   else
      return false;
}

bool Player::WeaponArmorJustCollected()
{
   if (collectedWeaponArmor)
   {
      collectedWeaponArmor = false;
      return true;
   }
   else
      return false;
}

/*
#ifdef __TESTING_PLAYER
int main()
{  
   
   Player player;
   pair <int,int> startPoint = make_pair(3,3);
   pair <int,int> testPoint = make_pair(50, 50);
   pair <int,int> lastLocation;

   //////////////////////////////////////////////////////////////////
   //Case 1: testing player constructor's initial position
   //////////////////////////////////////////////////////////////////
   cout << "Testing initial player position: ";
   if (player.GetLocation()->first == startPoint.first && player.GetLocation()->second == startPoint.second)
      cout << "PASS, player is in correct starting position." << endl << endl;
   else
      cout << "FAIL, player is not in correct starting position." << endl << endl;

   //////////////////////////////////////////////////////////////////
   //Case 2: testing SetLocation method
   //////////////////////////////////////////////////////////////////
   cout << "Testing setter method for player location: ";
   player.SetLocation(testPoint);
   if (player.GetLocation()->first == testPoint.first && player.GetLocation()->second == testPoint.second)
      cout << "PASS, player is in correct position." << endl << endl;
   else
      cout << "FAIL, player is not in correct position." << endl << endl;


   //////////////////////////////////////////////////////////////////
   //Case 3: testing upwards movement
   //////////////////////////////////////////////////////////////////
   cout << "Testing movement in upwards direction:    ";
   lastLocation.first = player.GetLocation()->first;
   lastLocation.second = player.GetLocation()->second;
   player.Move(UP);
   if (player.GetLocation()->first == lastLocation.first &&
      player.GetLocation()->second < lastLocation.second)
      cout << "PASS, player moved upwards." << endl;
   else
      cout << "FAIL, player moved incorrectly." << endl;

   //////////////////////////////////////////////////////////////////
   //Case 4: testing downwards movement
   //////////////////////////////////////////////////////////////////
   cout << "Testing movement in downwards direction:  ";
   lastLocation.first = player.GetLocation()->first;
   lastLocation.second = player.GetLocation()->second;
   player.Move(DOWN);
   if (player.GetLocation()->first == lastLocation.first &&
      player.GetLocation()->second > lastLocation.second)
      cout << "PASS, player moved downwards." << endl;
   else
      cout << "FAIL, player moved incorrectly." << endl;

   //////////////////////////////////////////////////////////////////
   //Case 5: testing leftwards movement
   //////////////////////////////////////////////////////////////////
   cout << "Testing movement in leftwards direction:  ";
   lastLocation.first = player.GetLocation()->first;
   lastLocation.second = player.GetLocation()->second;;
   player.Move(LEFT);
   if (player.GetLocation()->first < lastLocation.first &&
      player.GetLocation()->second == lastLocation.second)
      cout << "PASS, player moved leftwards." << endl;
   else
      cout << "FAIL, player moved incorrectly." << endl;

   //////////////////////////////////////////////////////////////////
   //Case 6: testing Righward movement
   //////////////////////////////////////////////////////////////////
   cout << "Testing movement in rightwards direction: ";
   lastLocation.first = player.GetLocation()->first;
   lastLocation.second = player.GetLocation()->second;
   player.Move(RIGHT);
   if (player.GetLocation()->first > lastLocation.first &&
      player.GetLocation()->second == lastLocation.second)
      cout << "PASS, player moved rightwards." << endl;
   else
      cout << "FAIL, player moved incorrectly." << endl;
}


#endif
*/