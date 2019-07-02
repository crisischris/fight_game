/******************************************************************************
** Author: Chris Nelson 
** Date: 05.05.2019 
** Description: This is the main Chararcter base class.  A few functions that
** will share across all derived class are used here. 
******************************************************************************/

#include"Character.hpp"

int Character::getStrengthPoints()
{
  return this->strengthPoints;
}

int Character::getArmorPoints()
{
  return this->armor;
}

void Character::setStrengthPoints(int in)
{
  this->strengthPoints -= in;
}

std::string Character::getSpecialAbility()
{
  return specialString;
}

void Character::setName(std::string nameIn)
{
	this->name = nameIn;
}

std::string Character::getName()
{
  return this->name;
}

