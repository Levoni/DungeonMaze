//-----------------------------------------------------------------------
//Author:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn,
//          Levon Swenson
//Program:  Maze Runner game; player must escape from random labyrinths
//Purpose:  Allows for game panel to have double buffer so as to
//          eliminate/reduce tearing of display
//-----------------------------------------------------------------------

#pragma once
//-----------------------------------------------------------------------
// Makes game panel double buffered
//-----------------------------------------------------------------------
ref class GamePanel : public System::Windows::Forms::Panel
{
public: GamePanel()
{
	this->DoubleBuffered = true;
}
};