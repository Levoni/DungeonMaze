# Makefile for freq program

PLAYER_CFILES=PlayerTest.cpp Player.cpp Character.cpp
COMMAND_CFILES=AdvanceCommand.cpp Character.cpp Map.cpp Player.cpp TestAdvanceCommand.cpp Tile.cpp 
ARMOR_CFILES=TestArmor.cpp Player.cpp Character.cpp
CHARACTER_CFILES=CharacterTest.cpp Character.cpp
DOORKEY_CFILES=TestDoorKey.cpp Player.cpp Character.cpp
ENEMY_CFILES=TestEnemy.cpp Spider.cpp SlimeEnemy.cpp Enemy.cpp Character.cpp Bat.cpp
FULLVIS_CFILES=PowerFullVisibilityTest.cpp Player.cpp Character.cpp
HEALTH_CFILES=PowerHealthTest.cpp Player.cpp Character.cpp
VISIONBOOST_CFILES=PowerVisionBoostTest.cpp Player.cpp Character.cpp
WEAPON_CFILES=WeaponTest.cpp Player.cpp Character.cpp
TILE_CFILES=TileTest.cpp Tile.cpp Player.cpp Character.cpp
GAME_CFILES=TestGameManager.cpp Tile.cpp Player.cpp Map.cpp GameManager.cpp Enemy.cpp CharacterManager.cpp Character.cpp AdvanceCommand.cpp Bat.cpp Spider.cpp SlimeEnemy.cpp
CHARMAN_CFILES=CharacterManagerTest.cpp Bat.cpp Character.cpp CharacterManager.cpp Enemy.cpp Map.cpp Player.cpp SlimeEnemy.cpp Spider.cpp Tile.cpp 
MAPGEN_CFILES=MapTest.cpp Map.cpp Character.cpp Player.cpp Tile.cpp

PLAYER_OBJFILES=$(PLAYER_CFILES:.cpp=.o)
COMMAND_OBJFILES=$(COMMAND_CFILES:.cpp=.o)
ARMOR_OBJFILES=$(ARMOR_CFILES:.cpp=.o)
CHARACTER_OBJFILES=$(CHARACTER_CFILES:.cpp=.o)
DOORKEY_OBJFILES=$(DOORKEY_CFILES:.cpp=.o)
ENEMY_OBJFILES=$(ENEMY_CFILES:.cpp=.o)
FULLVIS_OBJFILES=$(FULLVIS_CFILES:.cpp=.o)
HEALTH_OBJFILES=$(HEALTH_CFILES:.cpp=.o)
VISIONBOOST_OBJFILES=$(VISIONBOOST_CFILES:.cpp=.o)
WEAPON_OBJFILES=$(WEAPON_CFILES:.cpp=.o)
TILE_OBJFILES=$(TILE_CFILES:.cpp=.o)
GAME_OBJFILES=$(GAME_CFILES:.cpp=.o)
CHARMAN_OBJFILES=$(CHARMAN_CFILES:.cpp=.o)
MAPGEN_OBJFILES=$(MAPGEN_CFILES:.cpp=.o)
CPPFLAGS=-g -fprofile-arcs -ftest-coverage -std=c++11

# add support for C++ (using g++ by default)
.SUFFIXES: .cpp .cpp.gcov
%.o : %.cpp
	g++ $(CPPFLAGS) -c $<

MakeMe: $(COMMAND_OBJFILES) $(PLAYER_OBJFILES) $(ARMOR_OBJFILES) $(CHARACTER_OBJFILES) $(DOORKEY_OBJFILES) $(ENEMY_OBJFILES) $(FULLVIS_OBJFILES) $(HEALTH_OBJFILES) $(VISIONBOOST_OBJFILES) $(WEAPON_OBJFILES) $(TILE_OBJFILES) $(GAME_OBJFILES) $(CHARMAN_OBJFILES) $(MAPGEN_OBJFILES)
	g++ $(CPPFLAGS) $(COMMAND_OBJFILES) -o AdvCommandTest
	g++ $(CPPFLAGS) $(PLAYER_OBJFILES) -o PlayerTest
	g++ $(CPPFLAGS) $(ARMOR_OBJFILES) -o ArmorTest
	g++ $(CPPFLAGS) $(CHARACTER_OBJFILES) -o CharacterTest
	g++ $(CPPFLAGS) $(DOORKEY_OBJFILES) -o DoorKeyTest
	g++ $(CPPFLAGS) $(ENEMY_OBJFILES) -o EnemyTest
	g++ $(CPPFLAGS) $(FULLVIS_OBJFILES) -o PowerFullVisibilityTest
	g++ $(CPPFLAGS) $(HEALTH_OBJFILES) -o HealthTest
	g++ $(CPPFLAGS) $(VISIONBOOST_OBJFILES) -o VisionBoostTest
	g++ $(CPPFLAGS) $(WEAPON_OBJFILES) -o WeaponTest
	g++ $(CPPFLAGS) $(TILE_OBJFILES) -o TileTest
	g++ $(CPPFLAGS) $(GAME_OBJFILES) -o GameTest
	g++ $(CPPFLAGS) $(CHARMAN_OBJFILES) -o CharManagerTest
	g++ $(CPPFLAGS) $(MAPGEN_OBJFILES) -o MapGenTest

%.cpp.gcov: %.cpp PlayerTest.da AdvanceCommandTest.da ArmorTest.da CharacterTest.da DoorKeyTest.da EnemyTest.da PowerFullVisibilityTest.da HealthTest.da VisionBoostTest.da WeaponTest.da \
TileTest.da GameTest.da CharManagerTest.da MapGenTest.da
	gcov $<

cov: $(CFILES:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

#Run Exe Files
PlayerTest.da: PlayerTest
	-./PlayerTest
AdvancedCommandTest.da: AdvancedCommandTest
	-./AdvCommandTest
ArmorTest.da: ArmorTest
	-./ArmorTest
CharacterTest.da: CharacterTest
	-./CharacterTest
DoorKeyTest.da: DoorKeyTest
	-./DoorKeyTest
EnemyTest.da: EnemyTest
	-./EnemyTest
PowerFullVisibilityTest.da: PowerFullVisibilityTest
	-./PowerFullVisibilityTest
HealthTest.da: HealthTest
	-./HealthTest
VisionBoostTest.da: VisionBoostTest
	-./VisionBoostTest
WeaponTest.da: WeaponTest
	-./WeaponTest
TileTest.da: TileTest
	-./TileTest
GameTest.da: GameTest
	-./GameTest
CharManagerTest.da: CharManagerTest
	-./CharManagerTest
MapGenTest.da: MapGenTest
	-./MapGenTest

test:
	./AdvCommandTest
	./ArmorTest
	./CharacterTest
	./DoorKeyTest
	./EnemyTest
	./GameTest
	./HealthTest
	./PlayerTest
	./PowerFullVisibilityTest
	./TileTest
	./VisionBoostTest
	./WeaponTest
	./CharManagerTest
	./MapGenTest

	gcov MapTest.cpp
	gcov TestAdvanceCommand.cpp
	gcov PlayerTest.cpp
	gcov TestArmor.cpp
	gcov CharacterTest.cpp
	gcov TestDoorKey.cpp
	gcov TestEnemy.cpp
	gcov TestGameManager.cpp
	gcov PowerFullVisibilityTest.cpp
	gcov PowerHealthTest.cpp
	gcov TestPowerUp.cpp
	gcov PowerVisionBoostTest.cpp
	gcov WeaponTest.cpp
	gcov TileTest.cpp	
	gcov CharacterManagerTest.cpp
	gcov AdvanceCommand.cpp
	gcov Player.cpp
	gcov Armor.h
	gcov Character.cpp
	gcov DoorKey.h
	gcov Enemy.cpp
	gcov GameManager.cpp
	gcov PowerFullVisibility.h
	gcov PowerHealth.h
	gcov PowerUp.h
	gcov PowerVisionBoost.h
	gcov Weapon.h
	gcov Tile.cpp
	gcov CharacterManager.cpp
	gcov Map.cpp

clean:
	rm -f a.out *.o freq *.bbg *.da *.gcov *~ *.gcno *.gcda

depend:
	sed -n '1,/^##DEPENDENCIES##/p' <Makefile >Makefile.bak
	gcc -MM $(CPPFLAGS) $(PLAYER_CFILES) $(COMMAND_CFILES) $(ARMOR_CFILES) $(CHARACTER_CFILES) $(DOORKEY_CFILES) $(ENEMY_CFILES) $(FULLVIS_CFILES) $(HEALTH_CFILERS) \
&(VISIONBOOST_OBJFILES) $(WEAPON_CFILES) $(TILE_CFILES) $(GAME_CFILES) $(CHARMAN_CFILES) $(MAPGEN_CFILES) | cat Makefile.bak - >Makefile

	-rm -f Makefile.bak

##DEPENDENCIES##
PlayerTest.o: PlayerTest.cpp Player.h Weapon.h PowerVisionBoost.h PowerHealth.h PowerFullVisibility.h
Player.o: Player.cpp Player.h Character.h
Character.o: Character.cpp Character.h
TestAdvanceCommand.o: TestAdvanceCommand.cpp AdvanceCommand.h Map.h Tile.h
AdvanceCommand.o: AdvanceCommand.cpp AdvanceCommand.h Map.h Command.h
Command.o: Command.cpp Command.h Tile.h
Map.o: Map.cpp Map.h Tile.h Player.h
Tile.o: Tile.cpp Tile.h PowerUp.h Player.h PowerFullVisibility.h PowerVisionBoost.h PowerHealth.h Items.h Armor.h Weapon.h DoorKey.h
TestArmor.o: TestArmor.cpp Armor.h Player.h
CharacterTest.o: CharacterTest.cpp Character.h
DoorKeyTest.o: DoorKeyTest.cpp DoorKey.h Player.h Character.h
EnemyTest.o: TestEnemy.cpp Character.h Enemy.h Spider.h SlimeEnemy.h Bat.h
Spider.o: Spider.cpp Spider.h Enemy.h
SlimeEnemy.o: SlimeEnemy.cpp SlimeEnemy.h Enemy.h
Bat.o: Bat.cpp Bat.h Enemy.h
Enemy.o: Enemy.cpp Enemy.h Character.h Tile.h
PowerFullVisibilityTest.o: PowerFullVisibilityTest.cpp PowerFullVisibility.h Player.h PowerUp.h
PowerHealth.o: PowerHealthTest.cpp PowerHealth.h Player.h
VisionBoostTest.o: PowerVisionBoostTest.cpp PowerVisionBoost.h
WeaponTest.o: WeaponTest.cpp Weapon.h Player.h
TileTest.o: TileTest.cpp Tile.h Player.h
GameTest.o: TestGameManager.cpp GameManager.h
GameManager.o: GameManager.cpp GameManager.h Tile.h Player.h Map.h CharacterManager.h Command.h AdvanceCommand.h
CharacterManager.o: CharacterManager.cpp CharacterManager.h SlimeEnemy.h Spider.h Bat.h Map.h Player.h Enemy.h
CharManagerTest.o: CharacterManagerTest.cpp CharacterManager.h
MapGenTest.o: MapTest.cpp Map.h
#Armor.o: Armor.h Items.h
#Items.o: Items.h Player.h
