#include "AdvanceCommand.h"

void AdvanceCommand::Execute()
{
   *gameMap = *newMap;
}

void AdvanceCommand::Unexecute()
{
   *gameMap = *oldMap;
}