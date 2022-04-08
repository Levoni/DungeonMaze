//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Levon Swenson, Zachary Lee, Phillip Patakos
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  GUI for game, able to render map and run commands for
//          movement.
//-----------------------------------------------------------------------

#include "Maze.h"
using namespace System;
using namespace System::Windows::Forms;


#ifndef __TESTING_PLAYER
[STAThread]
void main()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew TheMazeGame::Maze);
}
#endif