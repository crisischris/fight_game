/******************************************************************************
** Author: Chris Nelson 
** Date: 05.05.2019 
** Description: This is one of the derived Character classes. see below for 
** any special overrides
******************************************************************************/

#include<iostream>
#include"Blue_Men.hpp"
#include"Die.hpp"

//set required data for specific class
Blue_Men::Blue_Men(Die* diceIn)
{
  dice = diceIn; 
  this->type = "Blue Men";
  this->armor = 3; 
  this->strengthPoints = 12;
  this->specialString = "";
}

//set required data for specific class
int Blue_Men::attack()
{
  dice->setSide(10);
  int totalAttack = dice->roll();

  //roll attack dice twice
  totalAttack += dice->roll();
  	
  return totalAttack; 
}

//set required data for specific class
//Blue Men have a special way to defend
int Blue_Men::defend()
{
  int totalDefend; 
  if(this->strengthPoints >8)
  {
		dice->setSide(6); 

		totalDefend = dice->roll();
		//roll defend dice twice
		totalDefend += dice->roll();
		//roll defend dice thrice 
		totalDefend += dice->roll();
  }

  else if(this->strengthPoints > 4)
	{
		totalDefend = dice->roll();
		//roll defend dice twice
		totalDefend += dice->roll();
	}

  else
	{
		totalDefend = dice->roll();
	}

	return totalDefend; 

}

