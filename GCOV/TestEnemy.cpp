#include "Bat.h"
#include "SlimeEnemy.h"
#include "Spider.h"
#include "Enemy.h"
#include "Character.h"

#include <cassert>
#include <iostream>

int main()
{
   int testMapSize = 100;
   Enemy testEnemy(100);
   Bat testBat(testMapSize);
   SlimeEnemy testSlimeEnemy(testMapSize);
   Spider testSpider(testMapSize);
   int enemyAttackCoolDown = 10; // From Enemy class
   int batMoveMethod = 0; //From Bat class
   int slimeEnemyMoveMethod = 2; //From SlimeEnemy class
   int spiderMoveMethod = 3; // From Spider class
   string batImageName = "enemyBat"; //From Bat class
   string slimeEnemyImageName = "enemySlime"; //From SlimeEnemy class
   string spiderImageName = "enemySpider"; //From Spider class
   int batPointValue = 25; //From Bat class
   int slimeEnemyPointValue = 10; //From SlimeEnemy class
   int spiderPointValue = 50; //From Spider class
   pair<int, int> testDestination = make_pair(100, 100);
   pair<int, int> testLocation1 = make_pair(100, 100);
   pair<int, int> testLocation2 = make_pair(89, 89);
   pair<int, int> testLocation3 = make_pair(89, 111);
   pair<int, int> testLocation4 = make_pair(111, 89);
   pair<int, int> testLocation5 = make_pair(111, 111);

   //--------------------------------------------------------------------
   // Case 1:  Check enemy's move method (Uses GetMoveMethod())
   //--------------------------------------------------------------------

   assert(testBat.GetMoveMethod() == batMoveMethod);
   assert(testSlimeEnemy.GetMoveMethod() == slimeEnemyMoveMethod);
   assert(testSpider.GetMoveMethod() == spiderMoveMethod);

   //--------------------------------------------------------------------
   // Case 2:  Enemy attacks (Uses Attack())
   //--------------------------------------------------------------------

   testEnemy.Attack();
   assert(testEnemy.AttackCoolDown() == enemyAttackCoolDown - 1);

   //--------------------------------------------------------------------
   // Case 3:  Enemy gets hit (Uses SetHasBeenHit(), GetHasBeenHit())
   //--------------------------------------------------------------------

   assert(!testEnemy.GetHasBeenHit());
   testEnemy.SetHasBeenHit(true);
   assert(testEnemy.GetHasBeenHit());

   //--------------------------------------------------------------------
   // Case 4:  Check enemy's image name (Uses GetImageName())
   //--------------------------------------------------------------------

   assert(testBat.GetImgName() == batImageName);
   assert(testSlimeEnemy.GetImgName() == slimeEnemyImageName);
   assert(testSpider.GetImgName() == spiderImageName);

   //--------------------------------------------------------------------
   // Case 5:  Set enemy's destination (Uses SetDestination(), GetDestination())
   //--------------------------------------------------------------------

   testEnemy.SetDestination(testDestination);
   assert(testEnemy.GetDestination() == testDestination);

   //--------------------------------------------------------------------
   // Case 6:  Check if enemy arrived at destination (Uses IsAtDestination())
   //--------------------------------------------------------------------

   testEnemy.SetLocation(testLocation1);
   testEnemy.SetDestination(testDestination);
   assert(testEnemy.IsAtDestination());

   testEnemy.SetLocation(testLocation2);
   assert(!testEnemy.IsAtDestination());

   testEnemy.SetLocation(testLocation3);
   assert(!testEnemy.IsAtDestination());

   testEnemy.SetLocation(testLocation4);
   assert(!testEnemy.IsAtDestination());

   testEnemy.SetLocation(testLocation5);
   assert(!testEnemy.IsAtDestination());

   //--------------------------------------------------------------------
   // Case 7:  Check enemy's point value (Uses GetPointValue())
   //--------------------------------------------------------------------

   assert(testBat.GetPointValue() == batPointValue);
   assert(testSlimeEnemy.GetPointValue() == slimeEnemyPointValue);
   assert(testSpider.GetPointValue() == spiderPointValue);

   cout << "Tests successful!" << endl;

   return 0;
}
