//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Project: Maze Runner game; player must escape from random labyrinths
// Purpose: This class handles functionality for swapping maps in game.
//-----------------------------------------------------------------------

#ifndef __ADVANCECOMMAND_H
#define __ADVANCECOMMAND_H

#include "Command.h"
#include "Map.h"

//-----------------------------------------------------------------------
// Handles swapping maps while moving between levels
//-----------------------------------------------------------------------
class AdvanceCommand : public Command
{
public:
   AdvanceCommand(Map* gameMap, Map* oldMap, Map* newMap, int size) : Command::Command()
   {
      this->oldMap = new Map(size);
      this->newMap = new Map(size);
      this->gameMap = gameMap;
      *(this->newMap) = *newMap;
      *(this->oldMap) = *oldMap;
   }

   ~AdvanceCommand()
   {
      delete newMap;
      delete oldMap;
   }
   
   //--------------------------------------------------------------------
   // Instigates creation of new map object and sets current equal to it
   //--------------------------------------------------------------------
   void Execute();

   //--------------------------------------------------------------------
   // Sets active map to previous map and stores the current one in stack
   //--------------------------------------------------------------------
   void Unexecute();

private:
   Map* gameMap;
   Map* newMap;
   Map* oldMap;
};

#endif