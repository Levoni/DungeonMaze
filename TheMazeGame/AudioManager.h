#ifndef __AUDIOMANAGER_H
#define __AUDIOMANAGER_H

#include "Sound.h"

class AudioManager
{
public:
   AudioManager();

   void PlayIntro() { intro.Play(); }
   void PlayBackground() { background.Play(); }
   void PlayDeath() { death.Play(); }
   void PlayWalk() { walk.Play(); }
   void PlaySwordSwing() { swordSwing.Play(); }
   void PlayFlipSwitchOn() { flipSwitchOn.Play(); }
   void PlayFlipSwitchOff() { flipSwitchOff.Play(); }
   void PlayRestoreHealth() { restoreHealth.Play(); }
   void PlayEquipArmor() { equipArmor.Play(); }
   void PlayHitArmor() { hitArmor.Play(); }
   void PlayHitEnemy() { hitEnemy.Play(); }
   void PlayDoorUnlock() { doorUnlock.Play(); }
   void PlayDoorOpen() { doorOpen.Play(); }
   void PlayHitSkin() { hitSkin.Play(); }
   void PlayCollectKey() { collectKey.Play(); }

   void StopIntro() { intro.Stop(); }
   void StopBackground() { background.Stop(); }
   void StopDeath() { death.Stop(); }
   void StopWalk() { walk.Stop(); }
   void StopSwordSwing() { swordSwing.Stop(); }
   void StopFlipSwitchOn() { flipSwitchOn.Stop(); }
   void StopFlipSwitchOff() { flipSwitchOff.Stop(); }
   void StopRestoreHealth() { restoreHealth.Stop(); }
   void StopEquipArmor() { equipArmor.Stop(); }
   void StopHitArmor() { hitArmor.Stop(); }
   void StopHitEnemy() { hitEnemy.Stop(); }

   bool PlayingWalk() { return walk.On(); }
   bool PlayingIntro() { return intro.On(); }
   bool PlayingDeath() { return death.On(); }

private:
   
   
   Sound intro;
   Sound background;
   Sound death;
   Sound walk;
   Sound swordSwing;
   Sound flipSwitchOn;
   Sound flipSwitchOff;
   Sound restoreHealth;
   Sound equipArmor;
   Sound hitArmor;
   Sound hitEnemy;
   Sound doorUnlock;
   Sound doorOpen;
   Sound hitSkin;
   Sound collectKey;
};

#endif