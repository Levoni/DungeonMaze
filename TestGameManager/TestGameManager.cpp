#include "../TheMazeGame/GameManager.h"
#include <cassert>
#include <iterator>
#include <iostream>
#include <map>

using namespace std;

#define DEFAULT_PANEL_SIZE 440
#define TILES_IN_ROW 10

int main()
{

   GameManager* gm = new GameManager(DEFAULT_PANEL_SIZE, TILES_IN_ROW);

   //--------------------------------------------------------------------
   // Case : Checking for the setting of gameRunning
   //--------------------------------------------------------------------
   assert(gm->CheckGameRunning() == false);
   gm->SetGameRunning(true);
   assert(gm->CheckGameRunning() == true);
   gm->SetGameRunning(false);
   //--------------------------------------------------------------------
   // Case : Player Moves Right onto powerup
   //--------------------------------------------------------------------
   gm->gameMap->GetTile(0, 0)->setPowerUp();
   gm->GetCharacterManager()->GetHero()->TakeDamage(10);
   gm->MovePlayer(3);
   assert(gm->GetCharacterManager()->GetHero()->GetLocation()->first > 3
      && gm->GetCharacterManager()->GetHero()->GetLocation()->second == 3);
   assert(gm->GetCharacterManager()->GetHero()->GetFullVisibility()
      || gm->GetCharacterManager()->GetHero()->GetVisionBoost()
      || gm->GetCharacterManager()->GetHero()->GetHealth() == 100);

   gm->MovePlayer(1);
   gm->GetCharacterManager()->GetHero()->SetFullVisibility(false);
   gm->GetCharacterManager()->GetHero()->SetVisionBoost(false);
   gm->GetCharacterManager()->GetHero()->Heal(10);
   //--------------------------------------------------------------------
   // Case : player moves Right onto item
   //--------------------------------------------------------------------
   gm->gameMap->GetTile(0, 0)->setItem(1);
   gm->MovePlayer(3);
   assert(gm->GetCharacterManager()->GetHero()->GetLocation()->first > 3
      && gm->GetCharacterManager()->GetHero()->GetLocation()->second == 3);
   assert(gm->GetCharacterManager()->GetHero()->GetAttackDamage() > 1
      || gm->GetCharacterManager()->GetHero()->GetArmor() > 1);

   gm->MovePlayer(1);
   gm->GetCharacterManager()->GetHero()->SetDamage(1, 1);
   gm->GetCharacterManager()->GetHero()->SetArmor(1, 1);
   //--------------------------------------------------------------------
   // Case : Player Moves Down onto powerup
   //--------------------------------------------------------------------
   gm->gameMap->GetTile(0, 0)->setPowerUp();
   gm->GetCharacterManager()->GetHero()->TakeDamage(10);
   gm->MovePlayer(2);
   assert(gm->GetCharacterManager()->GetHero()->GetLocation()->first == 3
      && gm->GetCharacterManager()->GetHero()->GetLocation()->second > 3);
   assert(gm->GetCharacterManager()->GetHero()->GetFullVisibility()
      || gm->GetCharacterManager()->GetHero()->GetVisionBoost()
      || gm->GetCharacterManager()->GetHero()->GetHealth());

   gm->MovePlayer(5);
   gm->GetCharacterManager()->GetHero()->SetFullVisibility(false);
   gm->GetCharacterManager()->GetHero()->SetVisionBoost(false);
   gm->GetCharacterManager()->GetHero()->Heal(10);
   //--------------------------------------------------------------------
   // Case : player moves Down onto item
   //--------------------------------------------------------------------
   gm->gameMap->GetTile(0, 0)->setItem(1);
   gm->MovePlayer(2);
   assert(gm->GetCharacterManager()->GetHero()->GetLocation()->first == 3
      && gm->GetCharacterManager()->GetHero()->GetLocation()->second > 3);
   assert(gm->GetCharacterManager()->GetHero()->GetAttackDamage() > 1
      || gm->GetCharacterManager()->GetHero()->GetArmor() > 1);

   gm->MovePlayer(5);
   gm->MovePlayer(3);
   gm->GetCharacterManager()->GetHero()->SetDamage(1, 1);
   gm->GetCharacterManager()->GetHero()->SetArmor(1, 1);
   //--------------------------------------------------------------------
   // Case : Player Moves Left onto powerup
   //--------------------------------------------------------------------
   gm->gameMap->GetTile(0, 0)->setPowerUp();
   gm->GetCharacterManager()->GetHero()->TakeDamage(10);

   gm->MovePlayer(1);
   assert(gm->GetCharacterManager()->GetHero()->GetLocation()->first < 7
      && gm->GetCharacterManager()->GetHero()->GetLocation()->second == 3);
   assert(gm->GetCharacterManager()->GetHero()->GetFullVisibility()
      || gm->GetCharacterManager()->GetHero()->GetVisionBoost()
      || gm->GetCharacterManager()->GetHero()->GetHealth());

   gm->MovePlayer(3);
   gm->GetCharacterManager()->GetHero()->SetFullVisibility(false);
   gm->GetCharacterManager()->GetHero()->SetVisionBoost(false);
   gm->GetCharacterManager()->GetHero()->Heal(10);
   //--------------------------------------------------------------------
   // Case : player moves Left onto item
   //--------------------------------------------------------------------
   gm->gameMap->GetTile(0, 0)->setItem(1);
   gm->MovePlayer(1);
   assert(gm->GetCharacterManager()->GetHero()->GetLocation()->first < 7
      && gm->GetCharacterManager()->GetHero()->GetLocation()->second == 3);
   assert(gm->GetCharacterManager()->GetHero()->GetAttackDamage() > 1
      || gm->GetCharacterManager()->GetHero()->GetArmor() > 1);

   gm->MovePlayer(2);
   gm->GetCharacterManager()->GetHero()->SetDamage(1, 1);
   gm->GetCharacterManager()->GetHero()->SetArmor(1, 1);
   //--------------------------------------------------------------------
   // Case : Player Moves Up onto powerup
   //--------------------------------------------------------------------
   gm->gameMap->GetTile(0, 0)->setPowerUp();
   gm->GetCharacterManager()->GetHero()->TakeDamage(10);
   gm->MovePlayer(5);
   assert(gm->GetCharacterManager()->GetHero()->GetLocation()->first == 3
      && gm->GetCharacterManager()->GetHero()->GetLocation()->second < 7);
   assert(gm->GetCharacterManager()->GetHero()->GetFullVisibility()
      || gm->GetCharacterManager()->GetHero()->GetVisionBoost()
      || gm->GetCharacterManager()->GetHero()->GetHealth());

   gm->MovePlayer(2);
   gm->GetCharacterManager()->GetHero()->SetFullVisibility(false);
   gm->GetCharacterManager()->GetHero()->SetVisionBoost(false);
   gm->GetCharacterManager()->GetHero()->Heal(10);
   //--------------------------------------------------------------------
   // Case : player moves Up onto item
   //--------------------------------------------------------------------
   gm->gameMap->GetTile(0, 0)->setItem(1);
   gm->MovePlayer(5);
   assert(gm->GetCharacterManager()->GetHero()->GetLocation()->first == 3
      && gm->GetCharacterManager()->GetHero()->GetLocation()->second < 7);
   assert(gm->GetCharacterManager()->GetHero()->GetAttackDamage() > 1
      || gm->GetCharacterManager()->GetHero()->GetArmor() > 1);

   gm->MovePlayer(2);
   gm->GetCharacterManager()->GetHero()->SetDamage(1, 1);
   gm->GetCharacterManager()->GetHero()->SetArmor(1, 1);

   //--------------------------------------------------------------------
   // Case : cooldown for Full Visibility
   //--------------------------------------------------------------------

   while (!gm->GetCharacterManager()->GetHero()->GetFullVisibility())
   {
      gm->MovePlayer(3);
      gm->gameMap->GetTile(0, 0)->setPowerUp();
      gm->MovePlayer(1);
   }
   for (int i = 0; i < 101; i++)
      gm->coolDownTick();
   assert(gm->GetCharacterManager()->GetHero()->GetFullVisibility() == false);


   //--------------------------------------------------------------------
   // Case : cooldown for vision boost
   //--------------------------------------------------------------------

   while (!gm->GetCharacterManager()->GetHero()->GetVisionBoost())
   {
      gm->MovePlayer(3);
      gm->gameMap->GetTile(0, 0)->setPowerUp();
      gm->MovePlayer(1);
   }
   for (int i = 0; i < 501; i++)
      gm->coolDownTick();
   assert(gm->GetCharacterManager()->GetHero()->GetVisionBoost() == false);

   //--------------------------------------------------------------------
   // Case : Checking if the instructions are correct
   //--------------------------------------------------------------------
   assert(gm->GetInstructions() == "Movement: Your character is controlled using the arrow keys.\n\r"
      "Attacking: Use 'F' to slash and 'D' to stab");




   int tileHeight = DEFAULT_PANEL_SIZE / TILES_IN_ROW;
   int tileWidth = DEFAULT_PANEL_SIZE / TILES_IN_ROW;
   int locX1;
   int locY1;
   int locX2;
   int locY2;

   //-------------------------------------------------------------------
   //Case 1: Player has "See Everything" power-up
   //-------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetFullVisibility(true); //Add method

   gm->SetLineOfSightHelper();

   for (int i = 0; i < gm->gameMap->GetMapSize(); i++)
      for (int j = 0; j < gm->gameMap->GetMapSize(); j++)
         assert(gm->gameMap->GetTile(i, j)->GetLightLevel() == 4);

   for (int i = 0; i < MAX_VISIBILITY_TIMER; i++) //Let Full Visibility power-up expire
      gm->coolDownTick();


   //-------------------------------------------------------------------
   //Case 2: Player has "Vision Boost" power-up
   //-------------------------------------------------------------------
   delete gm->gameMap;
   gm->gameMap = new Map(528, 12, 1);
   gm->gameMap->MakeMapFromFile("visibility_test_map_2.txt");

   //gam = gm->gameMap->GetTileMap();
   tileHeight = gm->gameMap->GetTileHeight();
   tileWidth = gm->gameMap->GetTileHeight();
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileHeight * 6, tileWidth * 7)); //(6, 7)

   gm->GetCharacterManager()->GetHero()->SetVisionBoost(true); //Add method
   gm->SetLineOfSightHelper();


   pair<int, int>* location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);

   assert(gm->gameMap->GetTile(locX1, locY1 - 1)->GetLightLevel() == 3);

   assert(gm->gameMap->GetTile(locX1, locY1 - 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 - 1, locY1 - 1)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 - 1, locY1 - 1)->GetLightLevel() == 2);

   assert(gm->gameMap->GetTile(locX1, locY1 - 3)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 + 1, locY1 - 2)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 - 1, locY1 - 2)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 - 2, locY1 - 1)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 + 2, locY1 - 1)->GetLightLevel() == 1);

   assert(gm->gameMap->GetTile(locX1, locY1 - 4)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 + 2, locY1 - 2)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 - 2, locY1 - 2)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 - 1, locY1 - 3)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 - 3, locY1 - 1)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 + 3, locY1 - 1)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 - 1, locY1 + 1)->GetLightLevel() == 0);

   for (int i = 0; i < MAX_VISION_BOOST_TIMER; i++) //Let vision boost power-up expire
      gm->coolDownTick();

   //-------------------------------------------------------------------
   //Case 3: Player is horizontally in single tile and no walls oppose
   //        upward vision
   //-------------------------------------------------------------------
   //gm->gameMap->MakeMapFromFile("visibility_test_map_1.txt");
   //tileMap = gm->gameMap->GetTileMap();

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 5)); //(5, 5)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1, locY1 - 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1, locY1 - 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1, locY1 - 3)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1, locY1 - 4)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1, locY1 - 5)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 4: Player is horizontally in single tile and a wall opposes
   //        upward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 3)); //(5, 3)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1, locY1 - 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1, locY1 - 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1, locY1 - 3)->GetLightLevel() == 0);


   //-------------------------------------------------------------------
   //Case 5: Player is horizontally in two tiles and no walls oppose
   //        upward vision
   //-------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>((tileWidth * 6) - 10, tileWidth * 5)); //(5/6, 5)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locX2 = (location->first + gm->GetCharacterManager()->GetHero()->GetWidth()) / ((528) / 12);

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1, locY1 - 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1, locY1 - 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1, locY1 - 3)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1, locY1 - 4)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1, locY1 - 5)->GetLightLevel() == 0);

   assert(gm->gameMap->GetTile(locX2, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX2, locY1 - 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX2, locY1 - 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX2, locY1 - 3)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX2, locY1 - 4)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX2, locY1 - 5)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 6: Player is horizontally in two tiles and a wall opposes
   //        upward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>((tileWidth * 6) - 10, tileWidth * 3)); //(5/6, 3)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locX2 = (location->first + gm->GetCharacterManager()->GetHero()->GetWidth()) / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1, locY1 - 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1, locY1 - 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1, locY1 - 3)->GetLightLevel() == 0);

   assert(gm->gameMap->GetTile(locX2, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX2, locY1 - 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX2, locY1 - 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX2, locY1 - 3)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 7: Player is horizontally in single tile and no walls oppose
   //        downward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 6)); //(5, 6)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1, locY1 + 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1, locY1 + 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1, locY1 + 3)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1, locY1 + 4)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1, locY1 + 5)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 8: Player is horizontally in single tile and a wall opposes
   //        downward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 8)); //(5, 8)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1, locY1 + 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1, locY1 + 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1, locY1 + 3)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 9: Player is horizontally in two tiles and no walls oppose
   //        downward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>((tileWidth * 6) - 10, tileWidth * 6)); //(5/6, 6)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locX2 = (location->first + gm->GetCharacterManager()->GetHero()->GetWidth()) / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1, locY1 + 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1, locY1 + 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1, locY1 + 3)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1, locY1 + 4)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1, locY1 + 5)->GetLightLevel() == 0);

   assert(gm->gameMap->GetTile(locX2, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX2, locY1 + 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX2, locY1 + 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX2, locY1 + 3)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX2, locY1 + 4)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX2, locY1 + 5)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 10: Player is horizontally in two tiles and a wall opposes
   //         downward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>((tileWidth * 6) - 10, tileWidth * 8)); //(5/6, 8)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locX2 = (location->first + gm->GetCharacterManager()->GetHero()->GetWidth()) / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1, locY1 + 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1, locY1 + 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1, locY1 + 3)->GetLightLevel() == 0);

   assert(gm->gameMap->GetTile(locX2, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX2, locY1 + 1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX2, locY1 + 2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX2, locY1 + 3)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 11: Player is vertically in single tile and no walls oppose
   //         leftward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5, tileWidth * 5)); //(5, 5)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 - 1, locY1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 - 2, locY1)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 - 3, locY1)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 - 4, locY1)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 - 5, locY1)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 12: Player is vertically in single tile and a wall opposes
   //         leftward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 3, tileWidth * 5)); //(3, 5)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 - 1, locY1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 - 2, locY1)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 - 3, locY1)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 13: Player is vertically in two tiles and no walls oppose
   //         leftward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5, (tileWidth * 6) - 10)); //(5, 5/6)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locY2 = (location->second + gm->GetCharacterManager()->GetHero()->GetHeight()) / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 - 1, locY1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 - 2, locY1)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 - 3, locY1)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 - 4, locY1)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 - 5, locY1)->GetLightLevel() == 0);

   assert(gm->gameMap->GetTile(locX1, locY2)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 - 1, locY2)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 - 2, locY2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 - 3, locY2)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 - 4, locY2)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 - 5, locY2)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 14: Player is vertically in two tiles and a wall opposes
   //         leftward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 3, (tileWidth * 6) - 10)); //(3, 5/6)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locY2 = (location->second + gm->GetCharacterManager()->GetHero()->GetHeight()) / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 - 1, locY1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 - 2, locY1)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 - 3, locY1)->GetLightLevel() == 0);

   assert(gm->gameMap->GetTile(locX1, locY2)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 - 1, locY2)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 - 2, locY2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 - 3, locY2)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 15: Player is vertically in single tile and no walls oppose
   //         rightward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6, tileWidth * 5)); //(6, 5)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 + 1, locY1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 + 2, locY1)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 + 3, locY1)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 + 4, locY1)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 + 5, locY1)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 16: Player is vertically in single tile and a wall opposes
   //         rightward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 8, tileWidth * 5)); //(8, 5)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 + 1, locY1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 + 2, locY1)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 + 3, locY1)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 17: Player is vertically in two tiles and no walls oppose
   //         rightward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6, (tileWidth * 6) - 10)); //(6, 5/6)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locY2 = (location->second + gm->GetCharacterManager()->GetHero()->GetHeight()) / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 + 1, locY1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 + 2, locY1)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 + 3, locY1)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 + 4, locY1)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 + 5, locY1)->GetLightLevel() == 0);

   assert(gm->gameMap->GetTile(locX1, locY2)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 + 1, locY2)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 + 2, locY2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 + 3, locY2)->GetLightLevel() == 1);
   assert(gm->gameMap->GetTile(locX1 + 4, locY2)->GetLightLevel() == 0);
   assert(gm->gameMap->GetTile(locX1 + 5, locY2)->GetLightLevel() == 0);

   //-------------------------------------------------------------------
   //Case 18: Player is vertically in two tiles and a wall opposes
   //         rightward vision
   //-------------------------------------------------------------------

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 8, (tileWidth * 6) - 10)); //(8, 5/6)
   location = gm->GetCharacterManager()->GetHero()->GetLocation();
   locX1 = location->first / tileWidth;
   locY1 = location->second / tileWidth;

   locY2 = (location->second + gm->GetCharacterManager()->GetHero()->GetHeight()) / tileWidth;

   gm->SetLineOfSightHelper();

   assert(gm->gameMap->GetTile(locX1, locY1)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 + 1, locY1)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 + 2, locY1)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 + 3, locY1)->GetLightLevel() == 0);

   assert(gm->gameMap->GetTile(locX1, locY2)->GetLightLevel() == 4);
   assert(gm->gameMap->GetTile(locX1 + 1, locY2)->GetLightLevel() == 3);
   assert(gm->gameMap->GetTile(locX1 + 2, locY2)->GetLightLevel() == 2);
   assert(gm->gameMap->GetTile(locX1 + 3, locY2)->GetLightLevel() == 0);




   //-------------------------------------------------------------------
   //Case : Checking to see if initial score is 0
   //-------------------------------------------------------------------
   assert(gm->getScore() == 0);

   //-------------------------------------------------------------------
   //Case : Checking if bonus is being decremented
   //-------------------------------------------------------------------
   for (int i = 0;i < 49; i++)
      gm->getBonus();
   assert(gm->getBonus() == 99);

   //-------------------------------------------------------------------
   //Case : Player enters door without key
   //-------------------------------------------------------------------
   int prevLvl = gm->getLevel();
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 11, tileWidth * 11)); //(11, 11)
   gm->MovePlayer(3);
   assert(gm->getLevel() == prevLvl);


   //-------------------------------------------------------------------
   //Case : Player enters door with key
   //-------------------------------------------------------------------
   prevLvl = gm->getLevel();
   gm->GetCharacterManager()->GetHero()->setKey(true);
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 11, tileWidth * 11)); //(11, 11)
   gm->MovePlayer(3);
   assert(gm->getLevel() != prevLvl);
   assert(gm->getScore() == 199);
   assert(gm->getBonus() == 100);

   gm->MovePlayer(1);
   //-------------------------------------------------------------------
   //Case : Player returns up the stairs
   //-------------------------------------------------------------------

   prevLvl = gm->gameMap->GetLevel();
   gm->SetLeftInitialTile(true);

   gm->MovePlayer(3);
   gm->MovePlayer(2);

   assert(gm->gameMap->GetLevel() != prevLvl);

   //-------------------------------------------------------------------
   //Case : Player returns down to already visited floor
   //-------------------------------------------------------------------

   prevLvl = gm->gameMap->GetLevel();
   gm->SetLeftInitialTile(true);

   gm->MovePlayer(3);
   gm->MovePlayer(2);

   assert(gm->gameMap->GetLevel() != prevLvl);

   gm->SetLeftInitialTile(true);
   gm->MovePlayer(2);
   gm->MovePlayer(3);

   tileHeight = gm->gameMap->GetTileHeight();
   tileWidth = gm->gameMap->GetTileHeight();
   int characterWH = gm->GetCharacterManager()->GetHero()->GetWidth();
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 1 - 2, tileHeight * 0 + 3)); //(11, 11)
   //--------------------------------------------------------------------
   // Case : Player Moves Right and has full body on new tile
   //--------------------------------------------------------------------
   gm->SetLeftInitialTile(false);
   gm->MovePlayer(1);
   gm->MovePlayer(3);
   assert(gm->GetLeftInitialTile() == true);

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 1 - characterWH + 2, tileHeight * 0 + 3)); //(11, 11)
   //--------------------------------------------------------------------
   // Case : Player Moves left and has full body on new tile 
   //--------------------------------------------------------------------
   gm->SetLeftInitialTile(false);
   gm->MovePlayer(3);
   gm->MovePlayer(1);
   assert(gm->GetLeftInitialTile() == true);

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 0 + 2, tileHeight * 1 - 2)); //(11, 11)
   //--------------------------------------------------------------------
   // Case : Player Moves down and has full body on new tile 
   //--------------------------------------------------------------------
   gm->SetLeftInitialTile(false);
   gm->MovePlayer(5);
   gm->MovePlayer(2);
   assert(gm->GetLeftInitialTile() == true);

   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 0 + 2, tileHeight * 1 - characterWH + 2));
 
 //--------------------------------------------------------------------
 // Case : Player Moves up and has full body on new tile 
 //--------------------------------------------------------------------
   gm->SetLeftInitialTile(false);
   gm->MovePlayer(2);
   gm->MovePlayer(5);
   assert(gm->GetLeftInitialTile() == true);


   
   gm->GetCharacterManager()->ClearEnemies();
   gm->gameMap->SetLevel(2);
   gm->GetCharacterManager()->SpawnEnemies();
   Enemy* tempEnemy = gm->GetCharacterManager()->GetEnemy(0);
   Enemy* tempEnemy2 = gm->GetCharacterManager()->GetEnemy(1);


   //--------------------------------------------------------------------
   // Case : Player swings left with wall in the way of both ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6 + 2, tileHeight * 5 ));
   gm->GetCharacterManager()->GetHero()->SetDirection(1);
   gm->checkCollision(1);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings right with wall in the way of both ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5 + 2, tileHeight * 5));
   gm->GetCharacterManager()->GetHero()->SetDirection(3);
   gm->checkCollision(1);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings up with wall in the way of both ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 4 + 2, tileHeight * 5));
   gm->GetCharacterManager()->GetHero()->SetDirection(5);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings down with wall in the way of both ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 4 + 2, tileHeight * 5));
   gm->GetCharacterManager()->GetHero()->SetDirection(2);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings down with wall in the way of both ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 4.5, tileHeight * 6));
   gm->GetCharacterManager()->GetHero()->SetDirection(2);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings down with wall in the way of both ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6.5, tileHeight * 6));
   gm->GetCharacterManager()->GetHero()->SetDirection(2);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());


   //--------------------------------------------------------------------
   // Case : Player swings up with wall in the way of left ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 4.5 , tileHeight * 5 + 5));
   gm->GetCharacterManager()->GetHero()->SetDirection(5);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings up with wall in the way of right ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6.5, tileHeight * 5 + 5));
   gm->GetCharacterManager()->GetHero()->SetDirection(5);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings left with wall in the way of top ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5 + 5, tileHeight * 4.5));
   gm->GetCharacterManager()->GetHero()->SetDirection(1);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings left with wall in the way of bettom ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5 + 5, tileHeight * 6.5));
   gm->GetCharacterManager()->GetHero()->SetDirection(1);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings right with wall in the way of top ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6 + 5, tileHeight * 4.5));
   gm->GetCharacterManager()->GetHero()->SetDirection(3);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());

   //--------------------------------------------------------------------
   // Case : Player swings right with wall in the way of bottom ends of sword
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6 + 5, tileHeight * 6.5));
   gm->GetCharacterManager()->GetHero()->SetDirection(3);
   gm->checkCollision(2);
   assert(!gm->GetCharacterManager()->EnemyHit() && !gm->GetCharacterManager()->GetEnemyDied());


   //--------------------------------------------------------------------
   // Case : Player swings and hits an enemy (in single tile
   //--------------------------------------------------------------------
   tempEnemy->SetLocation(pair<int, int>(tileWidth * 6 + 5, tileHeight * 4));
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6 + 5, tileHeight * 4 + tempEnemy->GetHeight() + 5));
   gm->GetCharacterManager()->GetHero()->SetDirection(5);
   gm->checkCollision(2);
   assert(gm->GetCharacterManager()->EnemyHit() == true);

   gm->GetCharacterManager()->ResetEnemyIsHit();
   //--------------------------------------------------------------------
   // Case : Player swings and hits an enemy (in single tile)
   //--------------------------------------------------------------------
   tempEnemy->SetLocation(pair<int, int>(tileWidth * 6 + 5, tileHeight * 6 - tempEnemy->GetHeight() /2));
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 5 + 5, tileHeight * 5.8));
   gm->GetCharacterManager()->GetHero()->SetDirection(3);
   gm->checkCollision(2);
   assert(gm->GetCharacterManager()->EnemyHit() == true);

   //--------------------------------------------------------------------
   // Case : Player swings and kills an enemy
   //--------------------------------------------------------------------
   int timesLeft = tempEnemy->GetHealth() / gm->GetCharacterManager()->GetHero()->GetAttackDamage();
   for (int i = 0; i < timesLeft + 1; i++)
   {
	   gm->GetCharacterManager()->ResetEnemyIsHit();
	   gm->checkCollision(2);
   }
   assert(gm->GetCharacterManager()->GetEnemyDied() == true);

   //--------------------------------------------------------------------
   // Case : Player swings and hits an enemy (in split tile)
   //--------------------------------------------------------------------
   gm->GetCharacterManager()->ResetEnemyIsHit();
   tempEnemy2->SetLocation(pair<int, int>(tileWidth * 6.5, tileHeight * 5));
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6.5, tileHeight * 5 + 5));
   gm->GetCharacterManager()->GetHero()->SetDirection(5);
   gm->checkCollision(2);
   assert(gm->GetCharacterManager()->EnemyHit() == true);

   //--------------------------------------------------------------------
   // Case : enemy hits player
   //--------------------------------------------------------------------
   tempEnemy2->SetLocation(pair<int, int>(tileWidth * 6 + 5, tileHeight * 6 + 3));
   gm->GetCharacterManager()->GetHero()->SetLocation(pair<int, int>(tileWidth * 6, tileHeight * 6));
   gm->checkPlayerHit();
   assert(gm->GetCharacterManager()->GetHero()->GetHealth() < 100);

   //--------------------------------------------------------------------
   // Case : checking colisions, right and top bound inside another obj.
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 15, 5, 30, 15) == true);

   //--------------------------------------------------------------------
   // Case : checking colisions, right and bottom bound inside another obj.
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 15, 15, 30, 30) == true);

   //--------------------------------------------------------------------
   // Case : checking colisions, right bound inside another obj. and top
   //        and bottom bound souround obj.
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 15, 15, 30, 18) == true);

   //--------------------------------------------------------------------
   // Case : checking colisions, left and top bound inside another obj.
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 5, 15, 15, 30) == true);

   //--------------------------------------------------------------------
   // Case : checking colisions, left and bottom bound inside another obj.
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 5, 5, 15, 15) == true);

   //--------------------------------------------------------------------
   // Case : checking colisions, left bound inside another obj. and top
   //        and bottom bound souround obj.
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 5, 15, 15, 18) == true);

   //--------------------------------------------------------------------
   // Case : checking colisions, left bound to left of another obj. and
   //        right bound to right of another obj.
   //        top bound inside another obj.
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 15, 5, 18, 15) == true);

   //--------------------------------------------------------------------
   // Case : checking colisions, left bound to left of another obj. and
   //        right bound to right of another obj.
   //        bottom bound inside another obj.
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 15, 15, 18, 30) == true);

   //--------------------------------------------------------------------
   // Case : checking colisions, left bound to left of another obj. and
   //        right bound to right of another obj. and top
   //        and bottom bound souround obj.
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 15, 15, 18, 18) == true);

   //--------------------------------------------------------------------
   // Case : Objects are not colliding
   //--------------------------------------------------------------------
   assert(gm->CheckBounds(10, 10, 20, 20, 30, 30, 50, 50) == false);


   gm->SetLineOfSightHelper();

   delete gm;

   cout << "Test Successful!" << endl;
   return 0;

}