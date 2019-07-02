#ifndef   GAME_HPP
#define   GAME_HPP

#include"Character.hpp"
#include"Die.hpp"

class Game 
{

  public:
	static void update();

  protected:


  private:
  static void fight(Character*, Character*, bool&);
  static int debug_fight(Character*, Character*);
  static Character* chooseFighter(Die*);


};
#endif
