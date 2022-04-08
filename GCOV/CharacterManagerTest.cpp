using namespace std;

#include "CharacterManager.h"
#include <iostream>
#include <cassert>

int main()
{
   Map* m = new Map(100, 8, 1);
   CharacterManager* cm = new CharacterManager(m, 10, 10);

   //--------------------------------------------------------------------
   // Case: Player is in correct start position
   //--------------------------------------------------------------------
   assert(cm->GetHero()->GetLocation()->first == 3 && cm->GetHero()->GetLocation()->second == 3);

   //--------------------------------------------------------------------
   // Case: Player is moved right
   //--------------------------------------------------------------------
   cm->MovePlayer(3);
   assert(cm->GetHero()->GetLocation()->first == 4 && cm->GetHero()->GetLocation()->second == 3);


   //--------------------------------------------------------------------
   // Case: Player is moved down
   //--------------------------------------------------------------------
   cm->MovePlayer(2);
   assert(cm->GetHero()->GetLocation()->first == 4 && cm->GetHero()->GetLocation()->second == 4);

   //--------------------------------------------------------------------
   // Case: Player is moved left
   //--------------------------------------------------------------------
   cm->MovePlayer(1);
   assert(cm->GetHero()->GetLocation()->first == 3 && cm->GetHero()->GetLocation()->second == 4);

   //--------------------------------------------------------------------
   // Case: Player is moved up
   //--------------------------------------------------------------------
   cm->MovePlayer(5);
   assert(cm->GetHero()->GetLocation()->first == 3 && cm->GetHero()->GetLocation()->second == 3);

   

   //--------------------------------------------------------------------
   // Case: Spawn enemies
   //--------------------------------------------------------------------
   m->SetLevel(1);
   assert(m->GetLevel() == 1);
   cm->SpawnEnemies();
   assert(cm->getNumEnemies() == 1);
   cm->ClearEnemies();
   assert(cm->getNumEnemies() == 0);

   m->SetLevel(2);
   cm->SpawnEnemies();
   assert(cm->getNumEnemies() == 2);
   cm->ClearEnemies();

   m->SetLevel(3);
   cm->SpawnEnemies();
   assert(cm->getNumEnemies() == 2);
   cm->ClearEnemies();

   m->SetLevel(4);
   cm->SpawnEnemies();
   assert(cm->getNumEnemies() == 3);
   cm->ClearEnemies();

   //--------------------------------------------------------------------
   // Case: kill enemy
   //--------------------------------------------------------------------

   m->SetLevel(4);
   cm->SpawnEnemies();
   Enemy* tempEnemy = cm->GetEnemy(0);
   assert(cm->getNumEnemies() == 3);
   cm->killEnemy(tempEnemy);
   assert(cm->getNumEnemies() == 2);
   cm->ClearEnemies();

   //--------------------------------------------------------------------
   // Case: Move all enemies
   //--------------------------------------------------------------------
   
   /*
   m->SetLevel(2);
   cm->SpawnEnemies();
   tempEnemy = cm->GetEnemy(0);
   Enemy* tempEnemy2 = cm->GetEnemy(1);
   pair<int, int> tempPair = *tempEnemy->GetLocation();
   pair<int, int> tempPair2 = *tempEnemy2->GetLocation();
   cm->MoveAllEnemies();
   cm->MoveAllEnemies(); //might need two?
   cm->MoveAllEnemies(); //might need >1 and odd number?
   assert(*tempEnemy->GetLocation() != tempPair);
   assert(*tempEnemy2->GetLocation() != tempPair2);
   */

   //--------------------------------------------------------------------
   // Case: try unlocking door
   //--------------------------------------------------------------------

   //no test currently

   //--------------------------------------------------------------------
   // Case: Execute Vision Boost Powerup
   //--------------------------------------------------------------------

   //no test currently

   //--------------------------------------------------------------------
   // Case: Set enemy died
   //--------------------------------------------------------------------
   cm->SetEnemyDied();
   assert(cm->GetEnemyDied());
   assert(!cm->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case: Update sizing
   //--------------------------------------------------------------------

   //no test currently

   //--------------------------------------------------------------------
   // Case: enemy hit
   //--------------------------------------------------------------------


   
   //--------------------------------------------------------------------
   // Case: reset enemy is hit
   //--------------------------------------------------------------------

   //no test currently

   //--------------------------------------------------------------------
   // Case: enemy turns left
   //--------------------------------------------------------------------
   Map* m2 = new Map(80, 8, 1);
   m2->MakeMapFromFile("charManTestMap1.txt");
   CharacterManager* cm2 = new CharacterManager(m2, m2->GetTileHeight(), m2->GetTileHeight());
   cm2->SpawnEnemies();
   tempEnemy = cm2->GetEnemy(0);
   tempEnemy->SetDirection(1);
   tempEnemy->SetLocation(make_pair(m2->GetBufferZone(), m2->GetBufferZone()));

   cm2->MoveAllEnemies();
   cm2->MoveAllEnemies();
 
   assert(tempEnemy->GetDirection() == 2);
   int i = 0;
   while(i++ < (m2->GetTileHeight() - tempEnemy->GetHeight()))
      cm2->MoveAllEnemies();
   assert(tempEnemy->GetDirection() == 3);

   i = 0;
   while (i++ < (m2->GetTileHeight() - tempEnemy->GetHeight()))
      cm2->MoveAllEnemies();
   assert(tempEnemy->GetDirection() == 5);

   i = 0;
   while (i++ < (m2->GetTileHeight() - tempEnemy->GetHeight()))
      cm2->MoveAllEnemies();
   assert(tempEnemy->GetDirection() == 1);

   //--------------------------------------------------------------------
   // Case: Turn At Intersection
   //--------------------------------------------------------------------

   cm2->ClearEnemies();
   m2->SetLevel(2);
   cm2->SpawnEnemies();
   tempEnemy = cm2->GetEnemy(0);

   tempEnemy->SetLocation(make_pair(6 * m2->GetTileHeight() + m2->GetBufferZone() + 1,
      m2->GetBufferZone() + 1)); //location = (6,0)
   tempEnemy->SetDestination(make_pair(7 * m2->GetTileHeight() + m2->GetBufferZone() + 1,
      m2->GetBufferZone() + 1)); //destination = (7,0)
   tempEnemy->SetDirection(3);

   i = 0;
   while (i++ < (m2->GetTileHeight()))
      cm2->MoveAllEnemies();
   assert(tempEnemy->GetDirection() == 2);

   i = 0;
   while (i++ < (m2->GetTileHeight()))
      cm2->MoveAllEnemies();
   assert(tempEnemy->GetDirection() == 1);

   tempEnemy->SetLocation(make_pair(m2->GetTileHeight() + m2->GetBufferZone(),
      2 * m2->GetTileHeight() + m2->GetBufferZone())); //location = (1,2)
   tempEnemy->SetDestination(make_pair(m2->GetBufferZone(),
      2 * m2->GetTileHeight() + m2->GetBufferZone())); //destination = (0,2)
   tempEnemy->SetDirection(1);
   
   i = 0;
   while (i++ < (m2->GetTileHeight()))
      cm2->MoveAllEnemies();
   assert(tempEnemy->GetDirection() == 5);

   i = 0;
   while (i++ < (m2->GetTileHeight()))
      cm2->MoveAllEnemies();
   assert(tempEnemy->GetDirection() == 3);

   //--------------------------------------------------------------------
   // Case: Greedy BFS
   //--------------------------------------------------------------------

   cm2->ClearEnemies();
   m2->SetLevel(3);
   cm2->SpawnEnemies();
   tempEnemy = cm2->GetEnemy(0);

   tempEnemy->SetLocation(make_pair(4 * m2->GetTileHeight() + m2->GetBufferZone(),
      m2->GetBufferZone())); //location = (4,0)
   tempEnemy->SetDestination(make_pair(4 * m2->GetTileHeight() + m2->GetBufferZone(),
      m2->GetBufferZone())); //destination = (4,0)
   tempEnemy->SetDirection(1);

   cm2->GetHero()->SetLocation(make_pair(7 * m2->GetTileHeight() + m2->GetBufferZone(),
      2 * m2->GetTileHeight() + m2->GetBufferZone()));  //hero location = (2,7)

   cm2->MoveAllEnemies();
   assert(tempEnemy->GetDirection() == 3);

   tempEnemy->SetLocation(make_pair(4 * m2->GetTileHeight() + m2->GetBufferZone(),
      4 * m2->GetTileHeight() + m2->GetBufferZone())); //location = (4,4)
   tempEnemy->SetDestination(make_pair(4 * m2->GetTileHeight() + m2->GetBufferZone(),
      4 * m2->GetTileHeight() + m2->GetBufferZone())); //destination = (4,4)
   tempEnemy->SetDirection(1);

   cm2->GetHero()->SetLocation(make_pair(2 * m2->GetTileHeight() + m2->GetBufferZone(),
      m2->GetBufferZone()));  //hero location = (2,0)

   cm2->MoveAllEnemies();
   assert(tempEnemy->GetDirection() == 1);
   //--------------------------------------------------------------------
   // Case: enemy hit
   //--------------------------------------------------------------------

  // cm2->ClearEnemies();
  // m2->SetLevel(1);
  // cm2->SpawnEnemies();
  // tempEnemy = cm2->GetEnemy(0);

  // tempEnemy->SetHasBeenHit(true);
  // assert(cm2->EnemyHit());

 //  cm2->ResetEnemyIsHit();
 //  assert(!cm2->EnemyHit());
   
   //--------------------------------------------------------------------
   // Case: try unlocking a door
   //--------------------------------------------------------------------
   cm2->ClearEnemies();
   cm2->GetHero()->setKey(false);

	tempEnemy->SetLocation(make_pair(4 * m2->GetTileHeight() + m2->GetBufferZone(),
		   4 * m2->GetTileHeight() + m2->GetBufferZone())); //location = (4,4)
   tempEnemy->SetDestination(make_pair(4 * m2->GetTileHeight() + m2->GetBufferZone(),
	   4 * m2->GetTileHeight() + m2->GetBufferZone())); //destination = (4,4)
   tempEnemy->SetDirection(1);

   delete m;
   delete cm;
   delete m2;
   delete cm2;
   return 0;
}
