//-----------------------------------------------------------------------
// Names:   Matthew Burgess, Zachary Lee, Phillip Patakos, Jared Sanborn, 
//          Levon Swenson
// Program: Maze Runner game; player must escape from random labyrinths
// Purpose: Contains functions that outline code to manage Character
//          instances.
//-----------------------------------------------------------------------

#include "Character.h"

Character::Character(int mapSize)
{
	characterHeight = characterWidth = mapSize * SIZE_SCALING_FACTOR;
	location = new pair<int, int>(INITIAL_LOCATION_X, INITIAL_LOCATION_Y);

	currentDirection = 1;
	curHealth = maxHealth = 1;
	armor = 0;
	attackDamage = 1;
	attackCoolDown = 0;
	sightRange = 1;
	moveDistance = mapSize / MOVEMENT_SCALING_FACTOR;

	characterHit = false;
	isStraffing = false;
}

void Character::updateSizeLocation(int size, pair<int, int> startLocation)
{
	characterHeight = characterWidth = size * SIZE_SCALING_FACTOR;
	delete location;
	location = new pair<int, int>(startLocation.first*size, startLocation.second*size);
	moveDistance = size / MOVEMENT_SCALING_FACTOR;
}

void Character::Move(int direction)
{
	if (!isStraffing)
		currentDirection = direction;
	if (direction == UP)
		location->second -= moveDistance;
	if (direction == DOWN)
		location->second += moveDistance;
	if (direction == LEFT)
		location->first -= moveDistance;
	if (direction == RIGHT)
		location->first += moveDistance;
}

void Character::Heal(int amount)
{
	if (curHealth + amount > maxHealth)
		curHealth = maxHealth;
	else
		curHealth += amount;
}

void Character::TakeDamage(int amount)
{
	if ((amount - armor) > 0)
	{
		if ((amount - armor) > curHealth)
			curHealth = 0;
		else
			curHealth -= (amount - armor);
	}
	else
		--curHealth;
   characterHit = true;
}

int Character::AttackCoolDown()
{
	if (attackCoolDown == 0) {
		return 0;
	}
	return --attackCoolDown;
}

int Character::DealDamage()
{
	attackCoolDown = COOL_DOWN_TICKS;
	return attackDamage;
}

bool Character::CharacterJustHit()
{
	if (characterHit)
	{
		characterHit = false;
		return true;
	}
	else
		return false;
}