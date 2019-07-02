/******************************************************************************
** Author: Chris Nelson 
** Date: 05.05.2019 
** Description: This is one of the derived Character classes. see below for 
** any special overrides
******************************************************************************/

#include<iostream>
#include"Vampire.hpp"
#include"Die.hpp"
#include"Helper.hpp"

//set required data for specific class
Vampire::Vampire(Die* diceIn)
{
  dice = diceIn; 
  this->type = "Vampire";
  this->armor = 1; 
  this->strengthPoints = 18;
  this->specialString = "***** Vampire has charmed the attacker into not attacking! *****";
}


//set required data for specific class
int Vampire::attack()
{
  dice->setSide(12);
  int totalAttack = dice->roll();
  	
  return totalAttack; 
}


//set required data for specific class
int Vampire::defend()
{
  dice->setSide(6); 
  int totalDefend = dice->roll();

  int charmChance = rand() % 2 + 1;

  if(charmChance == 1)
	{
    totalDefend += 100;
	}
  return totalDefend; 
}

