/******************************************************************************
** Author: Chris Nelson 
** Date: 05.05.2019 
** Description: This is one of the derived Character classes. see below for 
** any special overrides
******************************************************************************/

#include<iostream>
#include"Medusa.hpp"
#include"Die.hpp"
#include"Helper.hpp"


//set required data for specific class
Medusa::Medusa(Die* diceIn)
{
  dice = diceIn; 
  this->type = "Medusa";
  this->armor = 3; 
  this->strengthPoints = 8;
  this->specialString = "***** Medusa has turned the enemy into stone! Medusa wins *****";
}

//set required data for specific class
//Medusa has a special attack 
int Medusa::attack()
{
  dice->setSide(6);
  int totalAttack = dice->roll();

  //roll attack dice twice
  totalAttack += dice->roll();
  if(totalAttack == 12)
	{
		totalAttack += 100;
    Helper::newLine(1);
    std::cout << "Medusa has focused her stare!" << std::endl;
    Helper::newLine(1);
	}
  	
  return totalAttack; 
}

//set required data for specific class
int Medusa::defend()
{
  dice->setSide(6);
  int totalDefend = dice->roll(); 

	return totalDefend; 

}

