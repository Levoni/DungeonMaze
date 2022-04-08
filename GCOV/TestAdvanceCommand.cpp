#include "AdvanceCommand.h"
#include "Map.h"
#include "Tile.h"

#include <cassert>
#include <iostream>

using namespace std;

int main()
{
	//-----------------------------------------------------------------------
	// Case 1:  Execute method is called.
	//-----------------------------------------------------------------------

	int const testPanelSize1 = 100;
	int const testSize1 = 10;
	int const testLevel1 = 1;

	int const testPanelSize2 = 150;
	int const testSize2 = 20;
	int const testLevel2 = 2;

	Map* testGameMap = new Map(testSize1);
	Map* testOldMap = new Map(testPanelSize1, testSize1, testLevel1);
	Map* testNewMap = new Map(testPanelSize2, testSize2, testLevel2);

	testOldMap->GenerateMap(testOldMap->GetGeneratorPostion());
	testOldMap->MakePaths();
	testOldMap->addExtraPaths();

	testNewMap->GenerateMap(testNewMap->GetGeneratorPostion());
	testNewMap->MakePaths();
	testNewMap->addExtraPaths();

	AdvanceCommand* testAdvanceCommand = new AdvanceCommand(testGameMap, testOldMap, testNewMap, testSize1);

	testAdvanceCommand->Execute();

	assert(testGameMap->IsEqualTo(testNewMap));
	delete testAdvanceCommand;

//-----------------------------------------------------------------------
// Case 2:  Unexecute method is called.
//-----------------------------------------------------------------------
	testAdvanceCommand = new AdvanceCommand(testGameMap, testOldMap, testNewMap, testSize1);

	testAdvanceCommand->Unexecute();

	assert(testGameMap->IsEqualTo(testOldMap));

	cout << "Tests successful!" << endl;
	return 0;
}
