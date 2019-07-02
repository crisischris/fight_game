/******************************************************************************
** Author: Chris Nelson 
** Date: 05.05.2019 
** Description: This is one of the derived Character classes. see below for 
** any special overrides
******************************************************************************/

#include<iostream>
#include"Barbarian.hpp"
#include"Die.hpp"

//set required data for specific class
Barbarian::Barbarian(Die* diceIn)
{
  dice = diceIn; 
  this->type = "Barbarian";
  this->armor = 0; 
  this->strengthPoints = 12;
  this->specialString = "";
}

//set required data for specific class
int Barbarian::attack()
{
  dice->setSide(6);
  int totalAttack = dice->roll();

  //roll attack dice twice
  totalAttack += dice->roll();
  	
  return totalAttack; 
}

//set required data for specific class
int Barbarian::defend()
{
  dice->setSide(6); 
  int totalDefend = dice->roll();
  
  //roll defend dice twice
	totalDefend += dice->roll();

	return totalDefend; 
}

