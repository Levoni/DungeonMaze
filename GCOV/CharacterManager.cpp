#include "CharacterManager.h"


void CharacterManager::MoveAllEnemies()
{
   if (enemies->size() != 0)
   {
      list<Enemy*>::iterator iter = enemies->begin();
      while (iter != enemies->end())
      {
         MoveEnemy(*iter);
         iter++;
      }
   }
}

void CharacterManager::ResetEnemyIsHit()
{
   if (enemies->size() != 0)
   {
      list<Enemy*>::iterator iter = enemies->begin();
      while (iter != enemies->end())
      {
         (*iter)->SetHasBeenHit(false);
         iter++;
      }
   }
}


void CharacterManager::SpawnEnemies()
{
	int buffer = gameMap->GetBufferZone();
   int numEnemies = (gameMap->GetLevel() / SPAWN_MULTIPLIER) + 1;
	int enemyTileX, enemyTileY, enemyType;
   int heroTileX = hero->GetLocation()->first / tileWidth;
   int heroTileY = hero->GetLocation()->second / tileHeight;
	Enemy* tempEnemy;

   while (numEnemies > 0)
   {
      enemyTileX = rand() % gameMap->GetMapSize();
      enemyTileY = rand() % gameMap->GetMapSize();

      //selects enemy type
      if (gameMap->GetLevel() <= ENEMY_NUMBER)
         enemyType = gameMap->GetLevel() - 1;
		else
			enemyType = rand() % ENEMY_NUMBER;
		//construct enemy
		if (enemyType == 0)
			tempEnemy = new SlimeEnemy(tileHeight);
		else if (enemyType == 1)
			tempEnemy = new Bat(tileHeight);
		else
			tempEnemy = new Spider(tileHeight);
      //ensures enemy spawns at least 3 tiles from the player
      while (enemyTileX + SPAWN_BUFFER_ZONE > heroTileX
         && enemyTileX - SPAWN_BUFFER_ZONE < heroTileX
         && enemyTileY + SPAWN_BUFFER_ZONE > heroTileY
         && enemyTileY - SPAWN_BUFFER_ZONE < heroTileY)
      {
         enemyTileX = rand() % gameMap->GetMapSize();
         enemyTileY = rand() % gameMap->GetMapSize();
      }

      tempEnemy->SetLocation(make_pair((tileWidth * enemyTileX + buffer + 1),
													(tileHeight * enemyTileY + buffer + 1)));
      tempEnemy->SetDestination(*tempEnemy->GetLocation());

      enemies->push_front(tempEnemy);
      --numEnemies;
   }
}

void CharacterManager::ClearEnemies()
{
   list<Enemy*>::iterator iter = enemies->begin();
   while (iter != enemies->end())
   {
      delete *iter;
      *iter = NULL;
      iter++;
   }
   enemies->clear();
}

Enemy* CharacterManager::GetEnemy(int index)
{
   list<Enemy*>::iterator iter = enemies->begin();
   int count = 0;
   while (iter != enemies->end())
   {
      if (count == index)
         return *iter;
      count++;
      iter++;
   }
   return NULL;
}

bool CharacterManager::tryUnlock()
{
   return(hero->hasKey());
}

CharacterManager::~CharacterManager()
{
   ClearEnemies();
}

void CharacterManager::MovePlayer(int direction)
{

   switch (direction)
   {
   case 5:
      hero->Move(5);
      break;

   case 2:
      hero->Move(2);
      break;

   case 1:
      hero->Move(1);
      break;

   case 3:
      hero->Move(3);
      break;

   default:
      ;//stand still
   }
}

void CharacterManager::killEnemy(Enemy *en)
{
   enemies->remove(en);
   delete en;
   //en = NULL;
}

void CharacterManager::UpdateSizing(int tileSize)
{
   tileHeight = tileWidth = tileSize;
}

void CharacterManager::ExecutePowerUp(Tile* tile)
{
   tile->ExecutePowerUp(hero);
}

void CharacterManager::ExecuteItem(Tile* tile)
{
   tile->ExecuteItem(hero);
}

bool CharacterManager::EnemyHit()
{
   bool hit = false;

   if (enemies->size() != 0)
   {
      list<Enemy*>::iterator iter = enemies->begin();
      while (iter != enemies->end())
      {
         if ((*iter)->CharacterJustHit())
            hit = true;
         iter++;
      }
   }
   return hit;
}


bool CharacterManager::GetEnemyDied()
{
   if (enemyDied)
   {
      enemyDied = false;
      return true;
   }
   else
      return false;
}

pair<int, int> CharacterManager::GetRandomAdjacentDest(Enemy* curEnemy) //returns new destination point for enemy
{
	pair<int, int> curPair = make_pair(curEnemy->GetLocation()->first / tileWidth, curEnemy->GetLocation()->second / tileHeight);
	Tile* tempTile = gameMap->GetTile(curPair.first, curPair.second);
	int buffer = gameMap->GetBufferZone();
	int oppDir, curDir = curEnemy->GetDirection();
	int newDir;
	int count = 0;
	int dirs[3];


	//set opposite direction of travel
	if (curDir == LEFT)
		oppDir = RIGHT;
	else if (curDir == RIGHT)
		oppDir = LEFT;
	else if (curDir == UP)
		oppDir = DOWN;
	else
		oppDir = UP;


	if (oppDir != LEFT && !tempTile->HasLeftWall())
		dirs[count++] = LEFT;// put LEFT in list
	if (oppDir != RIGHT && !tempTile->HasRightWall())
		dirs[count++] = RIGHT;// put RIGHT in list
	if (oppDir != UP && !tempTile->HasTopWall())
		dirs[count++] = UP;// put UP in list
	if (oppDir != DOWN && !tempTile->HasBottomWall())
		dirs[count++] = DOWN;// put DOWN in list

	if (count == 0)
		newDir = oppDir;
	else
		newDir = dirs[rand() % count];

	if (newDir == LEFT)
		curPair.first = curPair.first - 1;
	else if (newDir == RIGHT)
		curPair.first = curPair.first + 1;
	else if (newDir == DOWN)
		curPair.second = curPair.second + 1;
	else
		curPair.second = curPair.second - 1;
	
	return make_pair(curPair.first * tileWidth + buffer, curPair.second * tileHeight + buffer);
}

pair<int,int> CharacterManager::GetDestPairBFS(Enemy* curEnemy)
{
   Tile* curTile;
   pair<int, int> heroPair, enemyPair, curPair, tempPair;

   list<pair<int, int>> searchQueue = list<pair<int, int>>();

   map<pair<int, int>, pair<int, int>> path = map<pair<int, int>, pair<int, int>>();
   set<pair<int, int>> visited = set<pair<int, int>>();

   curPair = enemyPair = make_pair(curEnemy->GetLocation()->first / tileWidth,
                                    curEnemy->GetLocation()->second / tileHeight);
   heroPair = make_pair((hero->GetLocation()->first + (hero->GetWidth() / 2))/ tileWidth,
                        (hero->GetLocation()->second + (hero->GetHeight() / 2)) / tileHeight);

	//if in same tile, skip all processes
	if (curPair == heroPair)
		return curPair;

   searchQueue.push_front(curPair);
   visited.insert(curPair);

   while (!searchQueue.empty())
   {
      curPair = searchQueue.front(); //returns value of first element
      searchQueue.pop_front();       //void, removes first element

		if (curPair == heroPair)
		{
			while (path[curPair] != enemyPair)
				curPair = path[curPair];
			return curPair;
		}

      //if neighbors have not been visited, add them to the searchQueue
      curTile = gameMap->GetTile(curPair.first, curPair.second);

      tempPair = make_pair(curPair.first - 1, curPair.second);
      if (!curTile->HasLeftWall() && (visited.find(tempPair) == visited.end()))
      {
         searchQueue.push_front(tempPair);
			visited.insert(tempPair);
			path[tempPair] = curPair;
      }

      tempPair = make_pair(curPair.first + 1, curPair.second);
      if (!curTile->HasRightWall() && (visited.find(tempPair) == visited.end()))
      {
         searchQueue.push_front(tempPair);
			visited.insert(tempPair);
			path[tempPair] = curPair;
      }

      tempPair = make_pair(curPair.first, curPair.second + 1);
      if (!curTile->HasBottomWall() && (visited.find(tempPair) == visited.end()))
      {
         searchQueue.push_front(tempPair);
			visited.insert(tempPair);
			path[tempPair] = curPair;
      }

      tempPair = make_pair(curPair.first, curPair.second - 1);
      if (!curTile->HasTopWall() && (visited.find(tempPair) == visited.end()))
      {
         searchQueue.push_front(tempPair);
			visited.insert(tempPair);
			path[tempPair] = curPair;
      }

		//moves position with lowest heuristic to front of list
		//if (!searchQueue.empty())
      if(searchQueue.size() > 1)
		{
			list<pair<int, int>>::iterator iter = searchQueue.begin();
         tempPair = *iter;
         iter++;
			while (iter != searchQueue.end())
			{

				if (GetHeuristic(*iter) < GetHeuristic(tempPair))
					tempPair = *iter;
				iter++;
			}
			searchQueue.remove(tempPair);
			searchQueue.push_front(tempPair);
		}

   }
   return enemyPair;
}

void CharacterManager::MoveEnemy(Enemy* curEnemy)
{
   switch (curEnemy->GetMoveMethod())
   {
   case 0:
		TurnAtIntersection(curEnemy);
		break;
   case 2:
      StraightOrLeft(curEnemy);
      break;
   case 3:
		GreedyBFS(curEnemy);
      break;
   default:
      ;//stand still
     
   }
}

void CharacterManager::GreedyBFS(Enemy* curEnemy)
{
	pair<int, int> tempPair;
	
	if(curEnemy->IsAtDestination())
	{
		tempPair = GetDestPairBFS(curEnemy);
		curEnemy->SetDestination(make_pair((tempPair.first * gameMap->GetTileHeight()) + gameMap->GetBufferZone(),
										(tempPair.second * gameMap->GetTileHeight()) + gameMap->GetBufferZone()));
	}

	DumbMoveTowardPoint(curEnemy, curEnemy->GetDestination());
}

int CharacterManager::GetHeuristic(const pair<int, int>& curPair)
{
   return abs(curPair.first - hero->GetLocation()->first / gameMap->GetTileHeight())
      + abs(curPair.second - hero->GetLocation()->second / gameMap->GetTileHeight());
}

void CharacterManager::DumbMoveTowardPoint(Enemy* curEnemy, pair<int,int> destPoint)
{
	int xDiff, yDiff, tempDir = LEFT;
	xDiff = curEnemy->GetLocation()->first - destPoint.first;
	yDiff = curEnemy->GetLocation()->second - destPoint.second;

	if (abs(xDiff) > abs(yDiff) && xDiff > 0)
		tempDir = LEFT;
	else if (abs(xDiff) > abs(yDiff) && xDiff < 0)
		tempDir = RIGHT;
	else if (abs(xDiff) < abs(yDiff) && yDiff > 0)
		tempDir = UP;
	else if (abs(xDiff) < abs(yDiff) && yDiff < 0)
		tempDir = DOWN;

	if (EnemyCanMove(curEnemy, tempDir))
		curEnemy->Move(tempDir);
}

void CharacterManager::StraightOrLeft(Enemy* curEnemy)
{
   if (curEnemy->GetDirection() == UP && !EnemyCanMove(curEnemy, UP))
      curEnemy->SetDirection(LEFT);
   else if (curEnemy->GetDirection() == LEFT && !EnemyCanMove(curEnemy, LEFT))
      curEnemy->SetDirection(DOWN);
   else if (curEnemy->GetDirection() == DOWN && !EnemyCanMove(curEnemy, DOWN))
      curEnemy->SetDirection(RIGHT);
   else if (curEnemy->GetDirection() == RIGHT && !EnemyCanMove(curEnemy, RIGHT))
      curEnemy->SetDirection(UP);
   else
      curEnemy->Move(curEnemy->GetDirection());
}

bool CharacterManager::EnemyCanMove(Enemy* curEnemy, int direction)
{
   switch (direction)
   {
   case RIGHT:
      if (gameMap->WallCheckRight(curEnemy->GetLocation(), curEnemy->GetHeight(), curEnemy->GetWidth()))
         return true;
      break;
   case UP:
      if (gameMap->WallCheckUp(curEnemy->GetLocation(), curEnemy->GetHeight(), curEnemy->GetWidth()))
         return true;
      break;
   case LEFT:
      if (gameMap->WallCheckLeft(curEnemy->GetLocation(), curEnemy->GetHeight(), curEnemy->GetWidth()))
         return true;
      break;
   default:
      if (gameMap->WallCheckDown(curEnemy->GetLocation(), curEnemy->GetHeight(), curEnemy->GetWidth()))
         return true;
   }
   return false;
}

void CharacterManager::TurnAtIntersection(Enemy* curEnemy)
{
	if (curEnemy->IsAtDestination())
		curEnemy->SetDestination(GetRandomAdjacentDest(curEnemy));
	DumbMoveTowardPoint(curEnemy, curEnemy->GetDestination());
}

