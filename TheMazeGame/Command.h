//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Program: Maze Runner game; player must escape from random labyrinths
// Purpose: Contains code used to create and manipulate instances of
//          commands
//-----------------------------------------------------------------------

#ifndef __COMMAND_H
#define __COMMAND_H

#include <map>
#include "Tile.h"

using namespace std;

typedef pair<int, int> Key;

//-----------------------------------------------------------------------
// Sets main functionality for child classes of command
//-----------------------------------------------------------------------
class Command
{
public:
   Command() { ; }

   //--------------------------------------------------------------------
   // Virtual function for children of Command
   //--------------------------------------------------------------------
   virtual void Execute() = 0;

   //--------------------------------------------------------------------
   // Virtual function for children of Command
   //--------------------------------------------------------------------
   virtual void Unexecute() = 0;
};

#endif