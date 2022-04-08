#include "..\TheMazeGame\Character.h"
//#include "..\TheMazeGame\Enemy.h"
//#include "..\TheMazeGame\Player.h"

#include <cassert>
#include <iostream>

using namespace std;

void Case1();
void Case2();
void Case3();
void Case4();
void Case5();
void Case6();
void Case7();
void Case8();
void Case9();
void Case10();
void Case11();
void Case12();
void Case13();

int main()
{
   Case1();
   Case2();
   Case3();
   Case4();
   Case5();
   Case6();
   Case7();
   Case8();
   Case9();
   Case10();
   Case11();
   Case12();
   Case13();
   
   cout << "Tests successful!" << endl;
   return 0;
   
   /*
   
   Character* c = new Character(10);

   //--------------------------------------------------------------------
   // Case 1: Character Moves right
   //--------------------------------------------------------------------
   c->Move(3);
   assert(c->GetLocation()->first == 1 && c->GetLocation()->second == 0);

   //--------------------------------------------------------------------
   // Case 2: Character Moves down
   //--------------------------------------------------------------------
   c->Move(2);
   assert(c->GetLocation()->first == 1 && c->GetLocation()->second == 1);

   //--------------------------------------------------------------------
   // Case 3: Character Moves left
   //--------------------------------------------------------------------
   c->Move(1);
   assert(c->GetLocation()->first == 0 && c->GetLocation()->second == 1);

   //--------------------------------------------------------------------
   // Case 4: Character Moves up
   //--------------------------------------------------------------------
   c->Move(5);
   assert(c->GetLocation()->first == 0 && c->GetLocation()->second == 0);

   delete c;
   */
}

//-----------------------------------------------------------------------
// Case 1:  Character moves up (Uses Move(), GetLocation(), SetLocation(), GetMoveDistance())
//-----------------------------------------------------------------------
void Case1()
{
   int testMapSize = 100;
   
   Character* testCharacter = new Character(testMapSize);

   pair<int, int> testStartLocation = make_pair(5, 5);
   pair<int, int> testEndLocation = make_pair(testStartLocation.first, testStartLocation.second - testCharacter->GetMoveDistance());

   testCharacter->SetLocation(testStartLocation);
   testCharacter->Move(5);

   assert(*(testCharacter->GetLocation()) == testEndLocation);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 2:  Character moves down (Uses Move(), GetLocation(), SetLocation(), GetMoveDistance())
//-----------------------------------------------------------------------
void Case2()
{
   int testMapSize = 100;

   Character* testCharacter = new Character(testMapSize);

   pair<int, int> testStartLocation = make_pair(5, 5);
   pair<int, int> testEndLocation = make_pair(testStartLocation.first, testStartLocation.second + testCharacter->GetMoveDistance());

   testCharacter->SetLocation(testStartLocation);
   testCharacter->Move(2);

   assert(*(testCharacter->GetLocation()) == testEndLocation);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 3:  Character moves left (Uses Move(), GetLocation(), SetLocation(), GetMoveDistance())
//-----------------------------------------------------------------------
void Case3()
{
   int testMapSize = 100;

   Character* testCharacter = new Character(testMapSize);

   pair<int, int> testStartLocation = make_pair(5, 5);
   pair<int, int> testEndLocation = make_pair(testStartLocation.first - testCharacter->GetMoveDistance(), testStartLocation.second);

   testCharacter->SetLocation(testStartLocation);
   testCharacter->Move(1);

   assert(*(testCharacter->GetLocation()) == testEndLocation);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 4:  Character moves right (Uses Move(), GetLocation(), SetLocation(), GetMoveDistance())
//-----------------------------------------------------------------------
void Case4()
{
   int testMapSize = 100;

   Character* testCharacter = new Character(testMapSize);

   pair<int, int> testStartLocation = make_pair(5, 5);
   pair<int, int> testEndLocation = make_pair(testStartLocation.first + testCharacter->GetMoveDistance(), testStartLocation.second);

   testCharacter->SetLocation(testStartLocation);
   testCharacter->Move(3);

   assert(*(testCharacter->GetLocation()) == testEndLocation);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 5:  Character changes direction (Uses GetDirection(), SetDirection())
//-----------------------------------------------------------------------
void Case5()
{
   int testMapSize = 100;
   int testDirection = 5;

   Character* testCharacter = new Character(testMapSize);

   testCharacter->SetDirection(testDirection);
   assert(testCharacter->GetDirection() == testDirection);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 6:  Check character height (Uses GetHeight())
//-----------------------------------------------------------------------
void Case6()
{
   int testMapSize = 100;
   float sizeScalingFactor = 0.75; //From Character class

   Character* testCharacter = new Character(testMapSize);

   assert(testCharacter->GetHeight() == testMapSize * sizeScalingFactor);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 7:  Check character width (Uses GetWidth())
//-----------------------------------------------------------------------
void Case7()
{
   int testMapSize = 100;
   float sizeScalingFactor = 0.75; //From Character class

   Character* testCharacter = new Character(testMapSize);

   assert(testCharacter->GetWidth() == testMapSize * sizeScalingFactor);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 8:  Check character sight range (Uses GetSightRange())
//-----------------------------------------------------------------------
void Case8()
{
   int testMapSize = 100;
   int defaultSightRange = 1; //From Character class

   Character* testCharacter = new Character(testMapSize);

   assert(testCharacter->GetSightRange() == defaultSightRange);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 9:  Check character attack damage (Uses GetAttackDamage())
//-----------------------------------------------------------------------
void Case9()
{
   int testMapSize = 100;
   int defaultAttackDamage = 1; //From Character class

   Character* testCharacter = new Character(testMapSize);

   assert(testCharacter->GetAttackDamage() == defaultAttackDamage);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 10:  Update character size and location for new map (Uses UpdateSizeLocation(), GetHeight(), GetWidth(), GetLocation(), GetMoveDistance())
//-----------------------------------------------------------------------
void Case10()
{
   int testMapSize1 = 100;
   int testMapSize2 = 200;
   
   float sizeScalingFactor = 0.75; //From Character class
   int movementScalingFactor = 10; //From Character class

   pair<int, int> testLocation = make_pair(5, 5);

   Character* testCharacter = new Character(testMapSize1);

   assert(testCharacter->GetHeight() == testMapSize1 * sizeScalingFactor);
   assert(testCharacter->GetWidth() == testMapSize1 * sizeScalingFactor);
   assert(testCharacter->GetMoveDistance() == testMapSize1 / movementScalingFactor);

   testCharacter->updateSizeLocation(testMapSize2, testLocation);

   assert(testCharacter->GetHeight() == testMapSize2 * sizeScalingFactor);
   assert(testCharacter->GetWidth() == testMapSize2 * sizeScalingFactor);
   assert(*(testCharacter->GetLocation()) == make_pair(testLocation.first * testMapSize2, testLocation.second * testMapSize2));
   assert(testCharacter->GetMoveDistance() == testMapSize2 / movementScalingFactor);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 11:  Check character armor (Uses GetArmor())
//-----------------------------------------------------------------------
void Case11()
{
   int testMapSize = 100;
   int defaultArmor = 0; //From Character class

   Character* testCharacter = new Character(testMapSize);

   assert(testCharacter->GetArmor() == defaultArmor);

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 12:  Character is healed after being attacked (TakeDamage(), CharacterJustHit(), Heal(), GetHealth())
//-----------------------------------------------------------------------
void Case12()  //Not finished
{
   int testMapSize = 100;
   int maxHealth = 1; //From Character class
   int testDamage1 = 1;
   int testDamage2 = 2;
   int testHeal1 = 1;
   int testHeal2 = 2;

   Character* testCharacter = new Character(testMapSize);

   assert(testCharacter->GetHealth() == maxHealth);

   testCharacter->TakeDamage(0);
   assert(testCharacter->GetHealth() == 0);
   testCharacter->Heal(testHeal1);
   assert(testCharacter->GetHealth() == maxHealth);

   testCharacter->TakeDamage(testDamage1);
   assert(testCharacter->GetHealth() == 0);
   testCharacter->Heal(testHeal2);
   assert(testCharacter->GetHealth() == maxHealth);
   
   testCharacter->TakeDamage(testDamage2);
   assert(testCharacter->GetHealth() == 0);

   assert(testCharacter->CharacterJustHit());
   assert(!testCharacter->CharacterJustHit());

   delete testCharacter;
}

//-----------------------------------------------------------------------
// Case 13:  Character attacks and is waiting to attack again (Uses DealDamage(), AttackCoolDown())
//-----------------------------------------------------------------------
void Case13()
{
   int testMapSize = 100;
   int defaultAttackDamage = 1; //From Character class
   int maxCoolDown = 20; //From Character class

   Character* testCharacter = new Character(testMapSize);

   assert(testCharacter->DealDamage() == defaultAttackDamage);

   assert(testCharacter->AttackCoolDown() == maxCoolDown - 1);
   
   for (int i = 0; i < maxCoolDown - 3; i++)
      testCharacter->AttackCoolDown();
   
   assert(testCharacter->AttackCoolDown() == 1);
   assert(testCharacter->AttackCoolDown() == 0);
   assert(testCharacter->AttackCoolDown() == 0);

   delete testCharacter;
}