/******************************************************************************
** Author: Chris Nelson 
** Date: 04.14.2019 
** Description:  This is the Die class.  This class creates a Die Object that
** has fucntions such as roll().  Call this class to create a Dice from which
** you can feed into Game::update()
******************************************************************************/

#include<iostream>
#include"Helper.hpp"
#include"Die.hpp"
#include<cstdlib>
#include<ctime>


//in the base class (this one) this function returns a standard random number 
//between 1 and sides N
int Die::roll()
{
  //citation: srand() and time https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/ 
  return rand() % N + 1;
}

int Die::setSide(int in)
{
	this->N = in;
}

//simple getter for sides N
int Die::getSides()
{
  return N;
}

//this function is used for switch cases
int Die::getTypeInt()
{
  return 1;
} 

//this function is used for output
std::string Die::getTypeString()
{
  return this->type;
}
