#include "GameManager.h"


GameManager::GameManager(int pnlSize, int s)
{
   size = s;
   panelSize = pnlSize;
   score = 0;
   bonus = BONUS;
   bonusCount = 0;
   level = 1;
   tileWidth = pnlSize / s;
   tileHeight = tileWidth;
   gameRunning = false;
   gameMap = new Map(pnlSize, s, level);
   charMan = new CharacterManager(gameMap, tileWidth, tileHeight);
   undo = new stack<Command*>;
   redo = new stack<Command*>;
   tempCommand = NULL;
   leftInitialTile = true;
   enemyDamageRatio = 1;


}

void GameManager::MovePlayer(int direction)
{
   pair<int, int> startLocation = *charMan->GetHero()->GetLocation();//GetPlayerLocation();
   pair<int, int>* curLocation = charMan->GetHero()->GetLocation();//GetPlayerLocation();



   switch (direction)
   {
   case 5:
      if (gameMap->WallCheckUp(curLocation, charMan->GetHero()->GetHeight(), charMan->GetHero()->GetWidth()))//GetPlayerWidth()))
      {
         charMan->MovePlayer(5);
         if (gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight)->HasPowerUp())
         {
            //charMan->ExecutePowerUp(gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight));
            gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight)->ExecutePowerUp(charMan->GetHero());
         }
         if (gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight)->HasItem())
         {
            charMan->ExecuteItem(gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight));
            //gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight)->ExecuteItem(charMan->GetHero());
         }
         if (!leftInitialTile && gameMap->ChangedTile(5, curLocation, charMan->GetHero()->GetHeight(), charMan->GetHero()->GetWidth()))
            leftInitialTile = true;
      }
      break;
   case 2:
      if (gameMap->WallCheckDown(curLocation, charMan->GetHero()->GetHeight(), charMan->GetHero()->GetWidth()))
      {
         charMan->MovePlayer(2);
         if (gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight)->HasPowerUp())
         {
            //charMan->ExecutePowerUp(gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight));
            gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight)->ExecutePowerUp(charMan->GetHero());
         }
         if (gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight)->HasItem())
         {
            charMan->ExecuteItem(gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight));
            //gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight)->ExecuteItem(charMan->GetHero());
         }
         if (!leftInitialTile && gameMap->ChangedTile(2, curLocation, charMan->GetHero()->GetHeight(), charMan->GetHero()->GetWidth()))
            leftInitialTile = true;
      }
      break;
   case 1:
      if (gameMap->WallCheckLeft(curLocation, charMan->GetHero()->GetHeight(), charMan->GetHero()->GetWidth()))
      {
         charMan->MovePlayer(1);
         if (gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight)->HasPowerUp())
         {
            //charMan->ExecutePowerUp(gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight));
            gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight)->ExecutePowerUp(charMan->GetHero());
         }
         if (gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight)->HasItem())
         {
            charMan->ExecuteItem(gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight));
            //gameMap->GetTile((curLocation->first) / tileWidth, curLocation->second / tileHeight)->ExecutePowerUp(charMan->GetHero());
         }
         if (!leftInitialTile && gameMap->ChangedTile(1, curLocation, charMan->GetHero()->GetHeight(), charMan->GetHero()->GetWidth()))
            leftInitialTile = true;
      }
      break;
   default:
      if (gameMap->WallCheckRight(curLocation, charMan->GetHero()->GetHeight(), charMan->GetHero()->GetWidth()))
      {
         charMan->MovePlayer(3);
         if (gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight)->HasPowerUp())
         {
            //charMan->ExecutePowerUp(gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight));
            gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight)->ExecutePowerUp(charMan->GetHero());
         }
         if (gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight)->HasItem())
         {
            charMan->ExecuteItem(gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight));
            //gameMap->GetTile((curLocation->first + charMan->GetHero()->GetWidth()) / tileWidth, (curLocation->second + charMan->GetHero()->GetHeight()) / tileHeight)->ExecutePowerUp(charMan->GetHero());
         }
         if (!leftInitialTile && gameMap->ChangedTile(3, curLocation, charMan->GetHero()->GetHeight(), charMan->GetHero()->GetWidth()))
            leftInitialTile = true;
      }
   }

   pair <int, int> endLocation = *(curLocation);
   if (!gameMap->CheckForSamePosition(startLocation, endLocation))
   {

      Key *playerLocate = curLocation;
      int playerX = playerLocate->first;
      int playerY = playerLocate->second;
      int playerBoundX = playerX + charMan->GetHero()->GetWidth();
      int playerBoundY = playerY + charMan->GetHero()->GetHeight();

      int startX = gameMap->GetStartPoint().first * tileWidth;
      int startY = gameMap->GetStartPoint().second * tileHeight;
      int startBoundX = startX + tileWidth;
      int startBoundY = startY + tileHeight;

      int finishX = gameMap->GetFinishPoint().first * tileWidth;
      int finishY = gameMap->GetFinishPoint().second * tileHeight;
      int finishBoundX = finishX + tileWidth;
      int finishBoundY = finishY + tileHeight;

      if ((playerX > finishX && playerBoundX < finishBoundX && playerY >= finishY && playerBoundY <= finishBoundY))
         gameMap->tryUnlock(charMan->GetHero()->hasKey());//PlayerHasKey());

      if (playerX > finishX && playerX < finishBoundX && playerBoundY > finishY && playerBoundY < finishBoundY)
         gameMap->tryUnlock(charMan->GetHero()->hasKey());//PlayerHasKey());

      if (gameMap->isUnlocked())
      {
         if (playerX >= finishX && playerBoundX <= finishBoundX)
            if (playerY >= finishY && playerBoundY <= finishBoundY)
               //going down to new level
               if (redo->empty())
               {
                  Map* tempOldMap = new Map(size);
                  *tempOldMap = *gameMap;
                  //Do Difficutly here to catch map creation inbetween 


                  gameMap->SwapPoints();
                  if (level % 2 == 0)
                     AddDifficutly();
                  gameMap->Restart();
                  gameMap->GenerateMap(gameMap->GetStartPoint());
                  gameMap->createPaths = true;

                  charMan->GetHero()->setKey(false);//ResetPlayerKey();

                  level++;
                  score += 100 + bonus;
                  bonus = 100;
                  bonusCount = 0;

                  //delete old enemy set, spawn new ones
                  charMan->ClearEnemies();
                  charMan->SpawnEnemies();

                  Map* tempNewMap = new Map(size);
                  *tempNewMap = *gameMap;

                  tempCommand = new AdvanceCommand(gameMap, tempOldMap, tempNewMap, size);
                  undo->push(tempCommand);

                  leftInitialTile = false;
                  //delete tempOldMap;
                  //delete tempNewMap;
               }
               else
               {
                  //for going down to existing level
                  if (leftInitialTile)
                  {
                     tempCommand = redo->top();
                     redo->pop();
                     tempCommand->Execute();
                     undo->push(tempCommand);
                     leftInitialTile = false;
                     ResetSizing(0, false);

                     //delete old enemy set, spawn new ones
                     charMan->ClearEnemies();
                     charMan->SpawnEnemies();
                  }
               }
      }
      //for going up to existing level
      if (!undo->empty())
         if (leftInitialTile)
            if (playerX > startX && playerBoundX < startBoundX)
               if (playerY > startY && playerBoundY < startBoundY)
               {
                  tempCommand = undo->top();
                  undo->pop();
                  tempCommand->Unexecute();
                  redo->push(tempCommand);
                  leftInitialTile = false;
                  ResetSizing(0, true);

                  //delete old enemy set, spawn new ones
                  charMan->ClearEnemies();
                  charMan->SpawnEnemies();

                  //gameMap->tryUnlock(true);
               }
   }
}

void GameManager::coolDownTick()
{
   if (charMan->GetHero()->GetFullVisibility())//GetPlayerFullVisibility())
   {
      for (int i = 0; i < size; i++)
         for (int j = 0; j < size; j++)
            gameMap->GetTile(i, j)->SetLightLevel(4);
      if (charMan->GetHero()->FullVisibilityCountdown())
         for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
               gameMap->GetTile(i, j)->SetLightLevel(0);
   }
   if (charMan->GetHero()->GetVisionBoost())//charMan->GetPlayerVisionBoost()) // move to seperatie fuction and call function in tick of the form
      if (charMan->GetHero()->VisionBoostCountdown())//charMan->PlayerVisionBoostCountdown())
         for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
               gameMap->GetTile(i, j)->SetLightLevel(0);
}

void GameManager::SetLineOfSightHelper()
{
   pair<int, int>* curLocation = charMan->GetHero()->GetLocation();//GetPlayerLocation();
   int playerWidth = charMan->GetHero()->GetWidth();//GetPlayerWidth();
   int playerHeight = charMan->GetHero()->GetHeight();//GetPlayerHeight();

   pair<int, int> TL = Key(curLocation->first / tileWidth, curLocation->second / tileHeight);
   pair<int, int> TR = Key((curLocation->first + playerWidth) / tileWidth, curLocation->second / tileHeight);
   pair<int, int> BL = Key(curLocation->first / tileWidth, (curLocation->second + playerHeight) / tileHeight);
   pair<int, int> BR = Key((curLocation->first + playerWidth) / tileWidth, (curLocation->second + playerHeight) / tileHeight);

   for (int y = 0; y < gameMap->GetMapSize(); y++)
      for (int x = 0; x < gameMap->GetMapSize(); x++)
         gameMap->GetTile(x, y)->SetLightLevel(0);


   if (!gameMap->GetTile(TL.first, TL.second)->HasTopWall())
      SetLineOfSight(5, TL.first, TL.second - 1, MAX_LIGHT_LEVEL - 1);
   if (!gameMap->GetTile(TR.first, TR.second)->HasTopWall())
      SetLineOfSight(5, TR.first, TR.second - 1, MAX_LIGHT_LEVEL - 1);

   if (!gameMap->GetTile(TR.first, TR.second)->HasRightWall())
      SetLineOfSight(3, TR.first + 1, TR.second, MAX_LIGHT_LEVEL - 1);
   if (!gameMap->GetTile(BR.first, BR.second)->HasRightWall())
      SetLineOfSight(3, BR.first + 1, BR.second, MAX_LIGHT_LEVEL - 1);

   if (!gameMap->GetTile(BL.first, BL.second)->HasBottomWall())
      SetLineOfSight(2, BL.first, BL.second + 1, MAX_LIGHT_LEVEL - 1);
   if (!gameMap->GetTile(BR.first, BR.second)->HasBottomWall())
      SetLineOfSight(2, BR.first, BR.second + 1, MAX_LIGHT_LEVEL - 1);

   if (!gameMap->GetTile(TL.first, TL.second)->HasLeftWall())
      SetLineOfSight(1, TL.first - 1, TL.second, MAX_LIGHT_LEVEL - 1);
   if (!gameMap->GetTile(BL.first, BL.second)->HasLeftWall())
      SetLineOfSight(1, BL.first - 1, BL.second, MAX_LIGHT_LEVEL - 1);

   if (charMan->GetHero()->GetFullVisibility())//GetPlayerFullVisibility())
   {
      for (int i = 0; i < gameMap->GetMapSize(); i++)
         for (int j = 0; j < gameMap->GetMapSize(); j++)
            gameMap->GetTile(i, j)->SetLightLevel(4);
   }

   gameMap->GetTile(TL.first, TL.second)->SetLightLevel(MAX_LIGHT_LEVEL);
   gameMap->GetTile(TR.first, TR.second)->SetLightLevel(MAX_LIGHT_LEVEL);
   gameMap->GetTile(BL.first, BL.second)->SetLightLevel(MAX_LIGHT_LEVEL);
   gameMap->GetTile(BR.first, BR.second)->SetLightLevel(MAX_LIGHT_LEVEL);
}

void GameManager::SetLineOfSight(int direction, int curX, int curY,
   int curLightLevel)
{
   pair<int, int> curCoor = make_pair(curX, curY);
   if (curLightLevel > MAX_LIGHT_LEVEL)
   {
      if (!gameMap->GetTile(curCoor.first, curCoor.second)->GetPlayerVisited())
         gameMap->GetTile(curCoor.first, curCoor.second)->SetPlayerVisited(true);
      gameMap->GetTile(curCoor.first, curCoor.second)->SetLightLevel(MAX_LIGHT_LEVEL);
   }
   else if (curLightLevel <= 0)
   {
      gameMap->GetTile(curCoor.first, curCoor.second)->SetLightLevel(0);
   }
   else
   {
      if (!gameMap->GetTile(curCoor.first, curCoor.second)->GetPlayerVisited())
         gameMap->GetTile(curCoor.first, curCoor.second)->SetPlayerVisited(true);
      gameMap->GetTile(curCoor.first, curCoor.second)->SetLightLevel(curLightLevel);
   }

   switch (direction)
   {
   case 5:

      if (!gameMap->GetTile(curX, curY)->HasLeftWall() && curX - 1 >= 0)
      {
         if (charMan->GetHero()->GetVisionBoost())//GetPlayerVisionBoost())
            SetWrapAround(1, curX - 1, curY, curLightLevel - 1);
      }
      if (!gameMap->GetTile(curX, curY)->HasRightWall() && curX + 1 < gameMap->GetMapSize())
      {
         if (charMan->GetHero()->GetVisionBoost())
            SetWrapAround(3, curX + 1, curY, curLightLevel - 1);
      }
      if (!gameMap->GetTile(curX, curY)->HasTopWall())
         if (curLightLevel > 0)
            SetLineOfSight(5, curX, --curY, --curLightLevel);
      break;
   case 2:

      if (!gameMap->GetTile(curX, curY)->HasLeftWall() && curX - 1 >= 0)
      {
         if (charMan->GetHero()->GetVisionBoost())
            SetWrapAround(1, curX - 1, curY, curLightLevel - 1);
      }
      if (!gameMap->GetTile(curX, curY)->HasRightWall() && curX + 1 < gameMap->GetMapSize())
      {
         if (charMan->GetHero()->GetVisionBoost())
            SetWrapAround(3, curX + 1, curY, curLightLevel - 1);
      }
      if (!gameMap->GetTile(curX, curY)->HasBottomWall())
         if (curLightLevel > 0)
            SetLineOfSight(2, curX, ++curY, --curLightLevel);
      break;
   case 1:
      if (!gameMap->GetTile(curX, curY)->HasTopWall() && curY - 1 >= 0)
      {
         if (charMan->GetHero()->GetVisionBoost())
            SetWrapAround(5, curX, curY - 1, curLightLevel - 1);
      }
      if (!gameMap->GetTile(curX, curY)->HasBottomWall() && curY + 1 < gameMap->GetMapSize())
      {
         if (charMan->GetHero()->GetVisionBoost())
            SetWrapAround(2, curX, curY + 1, curLightLevel - 1);
      }
      if (!gameMap->GetTile(curX, curY)->HasLeftWall())
         if (curLightLevel > 0)
            SetLineOfSight(1, --curX, curY, --curLightLevel);
      break;
   default:
      if (!gameMap->GetTile(curX, curY)->HasTopWall() && curY - 1 >= 0)
      {
         if (charMan->GetHero()->GetVisionBoost())
            SetWrapAround(5, curX, curY - 1, curLightLevel - 1);
      }
      if (!gameMap->GetTile(curX, curY)->HasBottomWall() && curY + 1 < gameMap->GetMapSize())
      {
         if (charMan->GetHero()->GetVisionBoost())
            SetWrapAround(2, curX, curY + 1, curLightLevel - 1);
      }
      if (!gameMap->GetTile(curX, curY)->HasRightWall())
         if (curLightLevel > 0)
            SetLineOfSight(3, ++curX, curY, --curLightLevel);
   }
}

void GameManager::SetWrapAround(int direction, int curX, int curY,
   int curLightLevel)
{
   pair<int, int> curCoor = make_pair(curX, curY);

   if (curLightLevel >= 0)
   {
      if (gameMap->GetTile(curX, curY)->GetLightLevel() == 0)
      {
         if (curLightLevel > MAX_LIGHT_LEVEL)
         {
            gameMap->GetTile(curX, curY)->SetLightLevel(MAX_LIGHT_LEVEL);
         }
         gameMap->GetTile(curX, curY)->SetLightLevel(curLightLevel);
         if(curLightLevel != 0)
            gameMap->GetTile(curX, curY)->SetPlayerVisited(true);
      }
      switch (direction)
      {
      case 5:
         if (!gameMap->GetTile(curX, curY)->HasTopWall())
            SetWrapAround(5, curX, curY - 1, curLightLevel - 1);
         if (!gameMap->GetTile(curX, curY)->HasLeftWall())
            SetWrapAround(1, curX - 1, curY, curLightLevel - 1);
         if (!gameMap->GetTile(curX, curY)->HasRightWall())
            SetWrapAround(3, curX + 1, curY, curLightLevel - 1);
         break;
      case 2:
         if (!gameMap->GetTile(curX, curY)->HasBottomWall())
            SetWrapAround(2, curX, curY + 1, curLightLevel - 1);
         if (!gameMap->GetTile(curX, curY)->HasLeftWall())
            SetWrapAround(1, curX - 1, curY, curLightLevel - 1);
         if (!gameMap->GetTile(curX, curY)->HasRightWall())
            SetWrapAround(3, curX + 1, curY, curLightLevel - 1);
         break;
      case 1:
         if (!gameMap->GetTile(curX, curY)->HasLeftWall())
            SetWrapAround(1, curX - 1, curY, curLightLevel - 1);
         if (!gameMap->GetTile(curX, curY)->HasTopWall())
            SetWrapAround(5, curX, curY - 1, curLightLevel - 1);
         if (!gameMap->GetTile(curX, curY)->HasBottomWall())
            SetWrapAround(2, curX, curY + 1, curLightLevel - 1);
         break;
      default:
         if (!gameMap->GetTile(curX, curY)->HasRightWall())
            SetWrapAround(3, curX + 1, curY, curLightLevel - 1); //++curX
         if (!gameMap->GetTile(curX, curY)->HasTopWall())
            SetWrapAround(5, curX, curY - 1, curLightLevel - 1);
         if (!gameMap->GetTile(curX, curY)->HasBottomWall())
            SetWrapAround(2, curX, curY + 1, curLightLevel - 1); //++ curY
      }
   }
}

int GameManager::getBonus()
{
   bonusCount++;
   if (bonus != 0)
   {
      if (bonusCount == TOTALTIME)
      {
         bonusCount = 0;
         bonus--;
      }
   }
   return bonus;
}

void GameManager::ResetSizing(int inc, bool startAtFinish)
{
   gameMap->updateMapSize(panelSize, inc);
   size = gameMap->GetMapSize();
   tileHeight = tileWidth = panelSize / size;
   GetCharacterManager()->UpdateSizing(tileHeight);
   if (!startAtFinish)
      GetCharacterManager()->GetHero()->updateSizeLocation(tileHeight, gameMap->GetStartPoint());
   else
      GetCharacterManager()->GetHero()->updateSizeLocation(tileHeight, gameMap->GetFinishPoint());
}

void GameManager::AddDifficutly()
{
   bool succeded = false;
   while (!succeded)
   {
      int random = rand() % 5 + 1;
      switch (random) {
      case 1:
         succeded = gameMap->updatePowerRatio(0.1);
         break;
      case 2:
         succeded = gameMap->updateItemRatio(0.1);
         break;
      case 3:
         enemyDamageRatio += .5;
         succeded = true;
         break;
      case 4:
         succeded = gameMap->updateDeadEndRatio(1);
         break;
      case 5:
         ResetSizing(1, false);
         succeded = true;
         break;
      }
   }
}

void GameManager::checkCollision(int attackType) // fix case when between tiles and one corner of the sword's tile doesn't have a wall and the other does 
{
   float damageMultilier = 1;

   if (attackType == 2)
   {
      damageMultilier = 1;
   }
   else if (attackType == 1)
   {
      damageMultilier = 1.5;
   }


   int sx = charMan->GetHero()->GetSXBounds(attackType).first;
   int sy = charMan->GetHero()->GetSYBounds(attackType).first;
   int sxl = charMan->GetHero()->GetSXBounds(attackType).second;
   int syl = charMan->GetHero()->GetSYBounds(attackType).second;

   int secondSX;
   int secondSY;
   int secondSXL;
   int secondSYL;
   bool isSplit = false;



   if (sxl - sx < syl - sy)
   {
      if (charMan->GetHero()->GetDirection() == 5)
      {
         if (gameMap->GetTile(sx / tileWidth, syl / tileHeight)->HasTopWall() && gameMap->GetTile(sxl / tileWidth, syl / tileHeight)->HasTopWall() && sy < (syl / tileHeight) * tileHeight)
         {
            sy = (syl / tileWidth) * tileHeight;
         }
         else if (gameMap->GetTile(sx / tileWidth, syl / tileHeight)->HasTopWall() && !gameMap->GetTile(sxl / tileWidth, syl / tileHeight)->HasTopWall() && sy < (syl / tileHeight) * tileHeight)
         {
            secondSX = sx;
            sx = sxl / tileWidth * tileHeight;
            secondSXL = sx;
            isSplit = true;
         }
         else if (!gameMap->GetTile(sx / tileWidth, syl / tileHeight)->HasTopWall() && gameMap->GetTile(sxl / tileWidth, syl / tileHeight)->HasTopWall() && sy < (syl / tileHeight) * tileHeight)
         {
            secondSXL = sxl;
            sxl = sxl / tileWidth * tileHeight;
            secondSX = sxl;
            isSplit = true;
         }
         secondSY = (syl / tileHeight) * tileHeight;
         secondSYL = syl;
      }
      else if (charMan->GetHero()->GetDirection() == 2)
      {
         if (gameMap->GetTile(sx / tileWidth, sy / tileHeight)->HasBottomWall() && gameMap->GetTile(sxl / tileWidth, sy / tileHeight)->HasBottomWall() && syl > ((sy / tileHeight) + 1) * tileHeight)
         {
            syl = ((sy / tileWidth) + 1) * tileWidth;
         }
         else if (gameMap->GetTile(sx / tileWidth, sy / tileHeight)->HasBottomWall() && !gameMap->GetTile(sxl / tileWidth, sy / tileHeight)->HasBottomWall() && syl > ((sy / tileHeight) + 1) * tileHeight)
         {
            secondSX = sx;
            sx = sxl / tileWidth * tileWidth;
            secondSXL = sx;
            isSplit = true;
         }
         else if (!gameMap->GetTile(sx / tileWidth, sy / tileHeight)->HasBottomWall() && gameMap->GetTile(sxl / tileWidth, sy / tileHeight)->HasBottomWall() && syl > ((sy / tileHeight) + 1) * tileHeight)
         {
            secondSXL = sxl;
            sxl = sxl / tileWidth * tileWidth;
            secondSX = sxl;
            isSplit = true;
         }
         secondSY = sy;
         secondSYL = ((sy / tileWidth) + 1) * tileWidth;
      }
   }
   if (syl - sy < sxl - sx)
   {
      if (charMan->GetHero()->GetDirection() == 1)
      {
         if (gameMap->GetTile(sxl / tileWidth, sy / tileHeight)->HasLeftWall() && gameMap->GetTile(sxl / tileWidth, syl / tileHeight)->HasLeftWall() && sx < (sxl / tileHeight) * tileHeight)
         {
            sx = (sxl / tileWidth) * tileWidth;
         }
         else if (gameMap->GetTile(sxl / tileWidth, sy / tileHeight)->HasLeftWall() && !gameMap->GetTile(sxl / tileWidth, syl / tileHeight)->HasLeftWall() && sx < (sxl / tileHeight) * tileHeight)
         {
            secondSY = sy;
            sy = (syl / tileHeight) * tileHeight;
            secondSYL = sy;
            isSplit = true;
         }
         else if (!gameMap->GetTile(sxl / tileWidth, sy / tileHeight)->HasLeftWall() && gameMap->GetTile(sxl / tileWidth, syl / tileHeight)->HasLeftWall() && sx < (sxl / tileHeight) * tileHeight)
         {
            secondSYL = syl;
            syl = (syl / tileHeight) * tileHeight;
            secondSY = syl;
            isSplit = true;
         }
         secondSX = (sxl / tileWidth) * tileWidth;
         secondSXL = sxl;

      }
      else if (charMan->GetHero()->GetDirection() == 3)
      {
         if (gameMap->GetTile(sx / tileWidth, sy / tileHeight)->HasRightWall() && gameMap->GetTile(sx / tileWidth, syl / tileHeight)->HasRightWall() && sxl > ((sx / tileHeight) + 1) * tileHeight)
         {
            sxl = ((sx / tileWidth) + 1) * tileWidth;
         }
         else if (gameMap->GetTile(sx / tileWidth, sy / tileHeight)->HasRightWall() && !gameMap->GetTile(sx / tileWidth, syl / tileHeight)->HasRightWall() && sx < (sxl / tileHeight) * tileHeight)
         {
            secondSY = sy;
            sy = (syl / tileHeight) * tileHeight;
            secondSYL = sy;
            isSplit = true;
         }
         else if (!gameMap->GetTile(sx / tileWidth, sy / tileHeight)->HasRightWall() && gameMap->GetTile(sx / tileWidth, syl / tileHeight)->HasRightWall() && sx < (sxl / tileHeight) * tileHeight)
         {
            secondSYL = syl;
            syl = (syl / tileHeight) * tileHeight;
            secondSY = syl;
            isSplit = true;
         }
         secondSX = sx;
         secondSXL = ((sx / tileWidth) + 1) * tileWidth;
      }
   }


   if (isSplit)
   {
      int numEnemies = charMan->getNumEnemies();
      for (int i = 0; i < numEnemies; i++)
      {
         Enemy *tempEn = charMan->GetEnemy(i);
         if (!tempEn->GetHasBeenHit())
         {
            int enX = tempEn->GetLocation()->first;
            int enY = tempEn->GetLocation()->second;

            if(CheckBounds(secondSX, secondSY, secondSXL, secondSYL, enX, enY, enX + tempEn->GetWidth(), enY + tempEn->GetHeight()))
            {
               tempEn->TakeDamage(charMan->GetHero()->GetAttackDamage() * damageMultilier);
               tempEn->SetHasBeenHit(true);
            }
         }
      }

   }




   int numEnemies = charMan->getNumEnemies();
   for (int i = 0; i < numEnemies; i++)
   {
      Enemy *tempEn = charMan->GetEnemy(i);
      if (!tempEn->GetHasBeenHit())
      {
         int enX = tempEn->GetLocation()->first;
         int enY = tempEn->GetLocation()->second;

         if (CheckBounds(sx, sy, sxl, syl, enX, enY, enX + tempEn->GetWidth(), enY + tempEn->GetHeight()))
         {
            tempEn->TakeDamage(charMan->GetHero()->GetAttackDamage() * damageMultilier);
            tempEn->SetHasBeenHit(true);
         }
         if (tempEn->GetHealth() <= 0)
         {
            score += tempEn->GetPointValue();
            charMan->killEnemy(tempEn);
            charMan->SetEnemyDied();
            break;
         }
      }
   }
}
void GameManager::checkPlayerHit()
{
   int playerX = charMan->GetHero()->GetLocation()->first;
   int playerY = charMan->GetHero()->GetLocation()->second;
   int playerBoundX = charMan->GetHero()->GetWidth() + playerX;//GetPlayerWidth() + playerX;
   int playerBoundY = charMan->GetHero()->GetHeight() + playerY;//GetPlayerHeight() + playerY;

   int numEnemies = charMan->getNumEnemies();
   for (int i = 0; i < numEnemies; i++)
   {
      Enemy *tempEn = charMan->GetEnemy(i);
      int enX = tempEn->GetLocation()->first;
      int enY = tempEn->GetLocation()->second;
      int enBoundX = enX + tempEn->GetWidth();
      int enBoundY = enY + tempEn->GetHeight();;

      if(tempEn->AttackCoolDown() == 0 && CheckBounds(playerX,playerY,playerBoundX,playerBoundY,enX,enY,enBoundX,enBoundY))
         charMan->GetHero()->TakeDamage(tempEn->DealDamage() * (1 + enemyDamageRatio));
   }
}

bool GameManager::CheckBounds(int OneLB, int OneTB, int OneRB, int OneBB, int TwoLB, int TwoTB, int TwoRB, int TwoBB)
{
   if (OneLB > TwoLB && OneLB < TwoRB)
   {
      if (OneTB > TwoTB && OneTB < TwoBB)
         return true;
      if (OneBB > TwoTB && OneBB < TwoBB)
         return true;
      if (OneTB < TwoTB && OneBB > TwoBB)
         return true;
   }
   else if (OneRB > TwoLB && OneRB < TwoRB)
   {
      if (OneTB > TwoTB && OneTB < TwoBB)
         return true;
      if (OneBB > TwoTB && OneBB < TwoBB)
         return true;
      if (OneTB < TwoTB && OneBB > TwoBB)
         return true;
   }
   else if (OneLB < TwoLB && OneRB > TwoRB)
   {
      if (OneTB > TwoTB && OneTB < TwoBB)
         return true;
      if (OneBB > TwoTB && OneBB < TwoBB)
         return true;
      if (OneTB < TwoTB && OneBB > TwoBB)
         return true;
   }
   return false;
}















