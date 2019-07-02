/******************************************************************************
** Author: Chris Nelson 
** Date: 05.05.2019 
** Description: This is one of the derived Character classes. see below for 
** any special overrides
******************************************************************************/

#include<iostream>
#include"Harry_Potter.hpp"
#include"Die.hpp"
#include"Helper.hpp"


//set required data for specific class
Harry_Potter::Harry_Potter(Die* diceIn)
{
  dice = diceIn; 
  this->type = "Harry Potter";
  this->armor = 0; 
  this->strengthPoints = 10;
  this->specialString = "***** Harry Potter has used his magic to come back to life! *****";
}

//set required data for specific class
int Harry_Potter::attack()
{
  dice->setSide(6);
  int totalAttack = dice->roll();
  
	//roll the dice twice
  totalAttack += dice->roll();
  	
  return totalAttack; 
}

//set required data for specific class
int Harry_Potter::defend()
{
  dice->setSide(6); 
  int totalDefend = dice->roll();

	//roll the dice twice
  totalDefend += dice->roll();

  return totalDefend; 
}

//Harry Potter is unique in that he has a special
//function when he gets to 0 life for the first
//time
void Harry_Potter::setStrengthPoints(int in)
{
  this->strengthPoints -= in;
  if(hogwartsUsed == 0)
  {
		if(strengthPoints <= 0)
		{
			this->strengthPoints = 20;
			hogwartsUsed++;
			std::cout << specialString << std::endl;
		}
	}
}

