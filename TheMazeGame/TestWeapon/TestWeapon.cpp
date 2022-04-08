#include "../Weapon.h"
#include "../Player.h"
#include <iostream>
#include <cassert>

using namespace std;

void main()
{
   Weapon w = Weapon(1);
   Player p = Player(100);

   w.ExecuteItem(&p);

   
   assert(w.getRarity() >= 1 && w.getRarity() <= 3);
   assert(w.getModifier() >= 6 && w.getModifier() <= 16);
   assert(p.GetAttackDamage() >= 6 && p.GetAttackDamage() <= 16);
}