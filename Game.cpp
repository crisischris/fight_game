/******************************************************************************
** Author: Chris Nelson 
** Date: 05.05.2019
** Description: This is the Game class.  There are (2) functions that run
** the game.  Update and debug_fight
******************************************************************************/

#include<iostream>
#include<ctime>
#include"Helper.hpp"
#include"Character.hpp"
#include"Vampire.hpp"
#include"Barbarian.hpp"
#include"Blue_Men.hpp"
#include"Medusa.hpp"
#include"Harry_Potter.hpp"
#include"Die.hpp"
#include"Game.hpp"
#include"Queue.hpp"

/****************************************************************************

This function is the main loop.  The entire game logic comes from this.
it expects no parameters and runs until user exits
the input string

****************************************************************************/

void Game::update()
{
	bool keepPlaying = true;
	while(keepPlaying)
	{
  Helper::splashScreen("   FANTASY COMBAT   ",0);
  Helper::printMessage("Chose yout warrior teams!",2);

  Die diceObj;
  Die* dice = &diceObj;
  Helper::printMessage("How many characters for team 1? (1 min 5 max)",1);
  int numFighters1 = Helper::getInt(0,1,5,"");
  Helper::printMessage("How many characters for team 2? (1 min 5 max)",1);
  int numFighters2 = Helper::getInt(0,1,5,"");

  //flag for the char assignment loop
  bool isFighting = true;

	//create the Queue
	Queue Roster1;
	Queue Roster2;
	Queue Losers;

    //assign the character 
		for(int i = 0; i < 2; i++)
		{
			if(i == 0)
			{
				std::cout << "Choose your  warriors for team 1" << std::endl;
			  for(int i = 0; i < numFighters1; i++)
				{
					Roster1.addBack(chooseFighter(dice));
				}	
			}
			else
			{
				std::cout << "Choose your  warriors for team 2" << std::endl;
			  for(int i = 0; i < numFighters2; i++)
				{
					Roster2.addBack(chooseFighter(dice));
				}	
			}
		}

		  
	  
   	int counter = 1;
    bool emptyRoster = false;
    while(!emptyRoster)
		{
			Helper::newLine(2);
			Helper::printMessage("****************************   ROSTERS   ******************************", 1);
			//display status of the Rosters
  		std::cout << "TEAM 1: ";
			Roster1.printQueue();
	 	 	Helper::newLine(1);
			std::cout << "TEAM 2: ";
			Roster2.printQueue();
		  Helper::newLine(1);
			std::cout << "LOSERS: ";
			Losers.printQueue();
	 		Helper::newLine(1);
			Helper::printMessage("****************************   ROSTERS   ******************************", 3);

      std::cout << "********** TURN: " << counter << " **********" << std::endl; 
 			Helper::newLine(1);

			//get health of starting chars, used for healing later
			int roster1StartingHealth = Roster1.getFront()->getStrengthPoints();
			int roster2StartingHealth = Roster2.getFront()->getStrengthPoints();
			int currHealth = 0;
			int healing = 0;

		  //start the fight and return the dead character through an integer	
			int whoDied = debug_fight(Roster1.getFront(), Roster2.getFront());
			if(whoDied == 1)
			{
				//move the loser to the front of Losers queue
				Losers.addFront(Roster1.getFront());
				//delete the loser from the Roster 
				Roster1.removeFront();
			
				//heal the winner of the fight a random range
				currHealth = Roster2.getFront()->getStrengthPoints();
        healing = roster2StartingHealth;

				if(currHealth + healing < roster1StartingHealth)
				{
					std::cout << Roster2.getFront()->getName() << " has healed " << healing+currHealth << " points" << std::endl;
					Roster2.getFront()->setStrengthPoints(healing+currHealth);
				}

				//move Roster2 front to back
				Roster2.moveHeadtoTail();
			}
			else
			{
				//move the loser to the front of Losers queue
				Losers.addFront(Roster2.getFront());
				//delete the loser from the Roster 
				Roster2.removeFront();
	
				//heal the winner of the fight a random range
				currHealth = Roster1.getFront()->getStrengthPoints();
        healing = currHealth / 4;

				if(currHealth + healing < roster1StartingHealth)
				{
					std::cout << Roster1.getFront()->getName() << " has healed " << healing << " points" << std::endl;
					Roster1.getFront()->setStrengthPoints(healing+currHealth);
				}

				//move Roster1 front to back
				Roster1.moveHeadtoTail();
			}
     	counter++;
			if(Roster1.isEmpty() || Roster2.isEmpty())
			{
				emptyRoster = true;	
			}
		}
		

	  Helper::newLine(2);	
	  if(Roster1.isEmpty())
		{
				Helper::printMessage("TEAM 2 IS VICTORIOUS",2);
		}	
		else
		{
				Helper::printMessage("TEAM 1 IS VICTORIOUS",2);
		}
	

		int printList = Helper::menu("Print loser list", "Don't print loser list");

		switch(printList)
		{
			case 1:
			{
				Losers.printQueue();
				Helper::newLine(2);
				break;
			}
			case 2:
			{
				break;
			}

		}
    int stop = Helper::menu("Play again", "Exit");
    switch(stop)
    {
			case 1:
			{
				break;
			}

			case 2:
			{
 	      //tournament is over
				std::cout << "GAME OVER" << std::endl;
				keepPlaying = false;
				break;
			}
		}
  }
}

/****************************************************************************

This function is the fight loop.  In addition to running the fight simulation
it also doubles as the display fuction, displaying all of the data to the
screen.  It expects as input (2) character pointers, and a bool to keep track
of the fighting .

****************************************************************************/


int Game::debug_fight(Character* char1, Character* char2)
{
	while(true)
	{
	//get the first set of attack points and defend points
  int attackPoints = char1->attack(); 
  std::cout << "DEBUG: Attacker is " << char1->getType() << ": " << char1->getName() << std::endl; 
  std::cout << "DEBUG: Attacker attack points is: " << attackPoints << std::endl; 
  int defendPoints = char2->defend();
  std::cout << "DEBUG: Defender is " << char2->getType() << ": " << char2->getName()  << std::endl; 
  std::cout << "DEBUG: Defender points is: " << defendPoints << std::endl; 
  std::cout << "DEBUG: Defender armor: " << char2->getArmorPoints() << std::endl; 
  defendPoints += char2->getArmorPoints();
  std::cout << "DEBUG: Defender points + armor is: " << defendPoints << std::endl; 

  //calculate total damage
  int damage = attackPoints - defendPoints;
  std::cout << "DEBUG: Attacker damage is: " << damage << std::endl; 

  //check to make sure damage was greater than defense
  if(damage > 0)
	{
    //special offence triggered
    if(damage > 50)
		{
			char2->setStrengthPoints(damage);
     	Helper::newLine(1);
      std::cout << char1->getSpecialAbility() << std::endl;
      Helper::newLine(1);
		}
    //no special triggered
    else
		{
			char2->setStrengthPoints(damage);
			std::cout << "DEBUG: Attacker " << char1->getName() << " struck Defender " << char2->getName() << " for: " 
			<< damage << " points" << std::endl; 

			std::cout << "DEBUG: Defender has " << char2->getStrengthPoints() << " life left" << std::endl; 
    }
	}
    
  else
	{
    //special defense triggered
    if(defendPoints > 50)
    {
      Helper::newLine(2);
    	std::cout << char2->getSpecialAbility() << std::endl;
      Helper::newLine(2);
		}
    //no special triggered
    else
    {
			std::cout << "***** The defender blocked the attack! *****" << std::endl;
			std::cout << "DEBUG: Defender has " << char2->getStrengthPoints() << " life left" << std::endl; 
		}
	}

  //check if p2 died!
	if(char2->getStrengthPoints() <= 0)
	{
    Helper::newLine(2);
		std::cout<< "****** Defending " << char2->getName() << " has died! ******" << std::endl;
		return 2;
	}
  Helper::newLine(2);
  Helper::printMessage("***** ROUND SPLIT *****",2);

		//get the second set of attack points and defend points
		attackPoints = char2->attack(); 
    std::cout << "DEBUG: Attacker is " << char2->getType() << ": " << char2->getName() << std::endl; 
  	std::cout << "DEBUG: Attacker attack points is: " << attackPoints << std::endl; 
		defendPoints = char1->defend();
		std::cout << "DEBUG: Defender is " << char1->getType() << ": " << char1->getName() << std::endl; 
		std::cout << "DEBUG: Defender points is: " << defendPoints << std::endl; 
		std::cout << "DEBUG: Defender armor: " << char1->getArmorPoints() << std::endl; 
		defendPoints += char1->getArmorPoints();
    std::cout << "DEBUG: Defender points + armor is: " << defendPoints << std::endl; 

		//calculate total damage
		damage = attackPoints - defendPoints;
  	std::cout << "DEBUG: Attacker damage is: " << damage << std::endl; 

		//check to make sure damage was greater than defense
		if(damage > 0)
		{
			//special offence triggered
			if(damage > 50)
			{
				char1->setStrengthPoints(damage);
      	Helper::newLine(2);
				std::cout << char2->getSpecialAbility() << std::endl;
      	Helper::newLine(2);
			}
			//no special triggered
			else
			{
				char1->setStrengthPoints(damage);
				std::cout << "DEBUG: Attacker " << char2->getName() << " struck Defender " << char1->getName() << " for: " 
								<< damage << " points" << std::endl; 

				std::cout << "DEBUG: Defender has " << char1->getStrengthPoints() << " life left" << std::endl; 
			}
		}
		else
		{
			//special defense triggered
			if(defendPoints > 50)
			{
      	Helper::newLine(2);
				std::cout << char1->getSpecialAbility() << std::endl;
      	Helper::newLine(2);
			}
			//no special triggered
			else
			{
				std::cout << "***** The defender blocked the attack! *****" << std::endl;
				std::cout << "DEBUG: Defender has " << char1->getStrengthPoints() << " life left" << std::endl; 
			}
		}

		//check if p1 has died!
		if(char1->getStrengthPoints() <= 0)
		{
      Helper::newLine(2);
			std::cout<< "****** Defending " << char1->getName() << " has died! ******" << std::endl;
			return 1;
		}

   	//citation:http://www.cplusplus.com/reference/thread/this_thread/sleep_for/
		//std::this_thread::sleep_for(std::chrono::seconds(1));  
	}
}

Character* Game::chooseFighter(Die* dice)
{
      Helper::newLine(2);
			int choice = Helper::menu("Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"); 
			Character* currChar;
			switch(choice)
			{
				case 1:
				{
					//assign char pointer to vampire
					currChar = new Vampire(dice);
					Helper::printMessage("Enter the name of the character",1);
					currChar->setName(Helper::getString(0));
					return currChar;
					break;
				}
				case 2:
				{
					//assign char pointer to barbarian 
					currChar = new Barbarian(dice);
					Helper::printMessage("Enter the name of the character",1);
					currChar->setName(Helper::getString(0));
					return currChar;
					break;
				}
				case 3:
				{
					//assign char pointer to blue men 
					currChar = new Blue_Men(dice);
					Helper::printMessage("Enter the name of the character",1);
					currChar->setName(Helper::getString(0));
					return currChar;
					break;
				}
				case 4:
				{
					//assign char pointer to medusa 
					currChar= new Medusa(dice);
					Helper::printMessage("Enter the name of the character",1);
					currChar->setName(Helper::getString(0));
					return currChar;
					break;
				}
				case 5:
				{
					//assign char pointer to Harry Potter 
					currChar = new Harry_Potter(dice);
					Helper::printMessage("Enter the name of the character",1);
					currChar->setName(Helper::getString(0));
					return currChar;
					break;
				}
			}
}

