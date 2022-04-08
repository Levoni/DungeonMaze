#include "AudioManager.h"

AudioManager::AudioManager()
{
   intro = Sound(TEXT("INTRO.wav"), true);  //Done
   background = Sound(TEXT("98_Lost_Mine.wav"), true);  //Done
   death = Sound(TEXT("death.wav"), true);  //Done
   walk = Sound(TEXT("walk.wav"), true);  //Done
   swordSwing = Sound(TEXT("swing.wav"), false);  //Done
   flipSwitchOn = Sound(TEXT("switchon.wav"), false); //Done
   flipSwitchOff = Sound(TEXT("switchoff.wav"), false); //Done
   restoreHealth = Sound(TEXT("health.wav"), false); //Done
   equipArmor = Sound(TEXT("equip.wav"), false); //Done
   hitArmor = Sound(TEXT("armorhit.wav"), false); //Done
   hitEnemy = Sound(TEXT("enemyhit.wav"), false); //Done
   doorUnlock = Sound(TEXT("unlockdoor.wav"), false); //Done
   doorOpen = Sound(TEXT("opendoor.wav"), false); //Done
   hitSkin = Sound(TEXT("skinhit.wav"), false); //Done
   collectKey = Sound(TEXT("key.wav"), false); //Done
}