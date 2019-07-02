#ifndef   BLUE_MEN_HPP  
#define   BLUE_MEN_HPP 

#include"Character.hpp"

class Blue_Men: public Character
{
  public:
  Blue_Men(Die*);
  int attack();
  int defend();
  Die* dice;
  private:
};

#endif
