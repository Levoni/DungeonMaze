#include "Weapon.h"
#include "Player.h"
#include <cassert>

int main()
{
   //////////////////////////////////////////////////////////////////
   //Case 1: Testing that player doesnt have weapon
   //////////////////////////////////////////////////////////////////
   Weapon w = Weapon(1);
   Player p = Player(100);
   assert(p.GetAttackDamage() == 1);

   //////////////////////////////////////////////////////////////////
   //Case 2: Testing that player has weapon
   //////////////////////////////////////////////////////////////////
   w.ExecuteItem(&p);
   assert(p.GetAttackDamage() > 1);

   //////////////////////////////////////////////////////////////////
   //Case 3: Testing weapon has damage
   //////////////////////////////////////////////////////////////////
   assert(w.getModifier() > 0);

   //////////////////////////////////////////////////////////////////
   //Case 4: Testing weapon has rarity
   //////////////////////////////////////////////////////////////////
   assert(w.getRarity() > 1);
   return 0;
}
