#include "../TheMazeGame/Player.h"
#include "../TheMazeGame/PowerFullVisibility.h"
#include "../TheMazeGame/PowerHealth.h"
#include "../TheMazeGame/PowerVisionBoost.h"
#include "../TheMazeGame/Weapon.h"

#include <cassert>

using namespace std;

//still need to test get sxbounds, sybounds, calculateswingdistance,

int main()
{
	const int TEST_SIZE = 100;
	const int MAX_HEALTH = 100;
	Player p = Player(TEST_SIZE);
   PowerFullVisibility pfv = PowerFullVisibility();
   PowerHealth ph = PowerHealth();
   PowerVisionBoost pvb = PowerVisionBoost();
   Weapon w = Weapon(1);

   //////////////////////////////////////////////////////////////////
   //Case 1: testing that player doesnt have full visiblity
   //////////////////////////////////////////////////////////////////
   assert(p.GetFullVisibility() == false);

   //////////////////////////////////////////////////////////////////
   //Case 2: checking that player has not collected flashlight
   //////////////////////////////////////////////////////////////////
   assert(p.FlashlightJustCollected() == false);

   //////////////////////////////////////////////////////////////////
   //Case 3: checking that player has not picked up weapon
   //////////////////////////////////////////////////////////////////
   assert(p.WeaponArmorJustCollected() == false);

   //////////////////////////////////////////////////////////////////
   //Case 2: testing that full visiblity timer is counting down
   //////////////////////////////////////////////////////////////////
   pfv.ExecutePowerUp(&p);
   assert(p.FullVisibilityCountdown() == false);
   while (!p.FullVisibilityCountdown());

   //////////////////////////////////////////////////////////////////
   //Case 3: testing that full visiblity timer done
   //////////////////////////////////////////////////////////////////
   assert(p.FullVisibilityCountdown() == false);

   //////////////////////////////////////////////////////////////////
   //Case 4: testing that player doesnt have vision boost
   //////////////////////////////////////////////////////////////////
   assert(p.GetVisionBoost() == false);

   //////////////////////////////////////////////////////////////////
   //Case 5: testing that vision boost countdown is running.
   //////////////////////////////////////////////////////////////////
   pvb.ExecutePowerUp(&p);
   assert(p.VisionBoostCountdown() == false);
   while (!p.VisionBoostCountdown());

   //////////////////////////////////////////////////////////////////
   //Case 6: testing that vision boost timer done
   //////////////////////////////////////////////////////////////////
   assert(p.VisionBoostCountdown() == 0);

   //////////////////////////////////////////////////////////////////
   //Case 8: checking that player has collected flashlight
   //////////////////////////////////////////////////////////////////
   assert(p.FlashlightJustCollected() == true);

   //////////////////////////////////////////////////////////////////
   //Case 9: checking that player doestn have full visiblity
   //////////////////////////////////////////////////////////////////
   assert(p.GetFullVisibility() == false);

   //////////////////////////////////////////////////////////////////
   //Case 10: checking that player has picked up weapon
   //////////////////////////////////////////////////////////////////
   p.SetArmor(1, 1);
   assert(p.WeaponArmorJustCollected() == true);

   //////////////////////////////////////////////////////////////////
   //Case 11: Checking what the armor rarity is
   //////////////////////////////////////////////////////////////////
   assert(p.GetArmorRarity() == 1);

   //////////////////////////////////////////////////////////////////
   //Case 12: Checking what the player's weapon rarity is
   //////////////////////////////////////////////////////////////////
   p.SetDamage(1, 1);
   assert(p.GetWeaponRarity() == 1);

   //////////////////////////////////////////////////////////////////
   //Case 13: Checking player picked up a key
   //////////////////////////////////////////////////////////////////
   p.setKey(true);
   assert(p.hasKey()  == true);

   //////////////////////////////////////////////////////////////////
   //Case 14: Checking to see if player has attacked
   //////////////////////////////////////////////////////////////////
   p.Attack();
   assert(p.AttackCoolDown() == ATTACK_COOL_DOWN_PLAYER - 1);

   //for casses 16 - 21:
   //width=height = 75
   //move distance = 10

   //////////////////////////////////////////////////////////////////
   //Case 16: Checking swinging sword up
   //////////////////////////////////////////////////////////////////
   p.SetLocation(make_pair(50, 60));
   p.Move(5);
   p.caculateSwingDistance(1,1);
   assert(p.GetSXBounds(1).first == 80 && p.GetSXBounds(1).second == 117 );
   assert(p.GetSYBounds(1).first == 13 && p.GetSYBounds(1).second == 88);

   //////////////////////////////////////////////////////////////////
   //Case 17: Checking stabbing sword up
   //////////////////////////////////////////////////////////////////
   p.SetLocation(make_pair(50, 60));
   p.Move(5);
   p.caculateSwingDistance(1, 2);
   assert(p.GetSXBounds(2).first == 68 && p.GetSXBounds(2).second == 105);
   assert(p.GetSYBounds(2).first == -17 && p.GetSYBounds(2).second == 58);

   //////////////////////////////////////////////////////////////////
   //Case 18: Checking swinging sword up
   //////////////////////////////////////////////////////////////////
   p.SetLocation(make_pair(40, 50));
   p.Move(3);
   p.caculateSwingDistance(1, 1);
   assert(p.GetSXBounds(1).first == 87 && p.GetSXBounds(1).second == 162);
   assert(p.GetSYBounds(1).first == 80 && p.GetSYBounds(1).second == 117);

   //////////////////////////////////////////////////////////////////
   //Case 19: Checking stabbing sword right
   //////////////////////////////////////////////////////////////////
   p.SetLocation(make_pair(40, 50));
   p.Move(3);
   p.caculateSwingDistance(1, 2);
   assert(p.GetSXBounds(2).first == 117 && p.GetSXBounds(2).second == 192);
   assert(p.GetSYBounds(2).first == 68 && p.GetSYBounds(2).second == 105);

   //////////////////////////////////////////////////////////////////
   //Case 20: Checking swinging sword down
   //////////////////////////////////////////////////////////////////
   p.SetLocation(make_pair(50, 40));
   p.Move(2);
   p.caculateSwingDistance(1, 1);
   assert(p.GetSXBounds(1).first == 80 && p.GetSXBounds(1).second == 117);
   assert(p.GetSYBounds(1).first == 87 && p.GetSYBounds(1).second == 162);

   //////////////////////////////////////////////////////////////////
   //Case 21: Checking stabbing sword down
   //////////////////////////////////////////////////////////////////
   p.SetLocation(make_pair(50, 40));
   p.Move(2);
   p.caculateSwingDistance(1, 2);
   assert(p.GetSXBounds(2).first == 68 && p.GetSXBounds(2).second == 105);
   assert(p.GetSYBounds(2).first == 117 && p.GetSYBounds(2).second == 192);

   //////////////////////////////////////////////////////////////////
   //Case 21: Checking stabbing sword down
   //////////////////////////////////////////////////////////////////
   p.SetLocation(make_pair(60, 50));
   p.Move(1);
   p.caculateSwingDistance(1, 1);
   assert(p.GetSXBounds(1).first == 13 && p.GetSXBounds(1).second == 88);
   assert(p.GetSYBounds(1).first == 80 && p.GetSYBounds(1).second == 117);

   //////////////////////////////////////////////////////////////////
   //Case 21: Checking stabbing sword down
   //////////////////////////////////////////////////////////////////
   p.SetLocation(make_pair(60, 50));
   p.Move(1);
   p.caculateSwingDistance(1, 2);
   assert(p.GetSXBounds(2).first == -17 && p.GetSXBounds(2).second == 58);
   assert(p.GetSYBounds(2).first == 68 && p.GetSYBounds(2).second == 105);
   return 0;
}