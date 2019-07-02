/******************************************************************************
** Author: Chris Nelson 
** Date: 05.05.2019 
** Description: this is the main, all logic done in the Game.cpp 
******************************************************************************/

#include<ctime>
#include"Game.hpp"
#include<iostream>

int main()
{

  //this seeds the rand() function using the internal clock.  we need only to delcare this once
  srand(time(0));

  Game::update();
	std::cout << "game is over" << std::endl;
  return 0;
}

