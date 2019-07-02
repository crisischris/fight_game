#ifndef   MEDUSA_HPP  
#define   MEDUSA_HPP 

#include"Character.hpp"

class Medusa: public Character
{
  public:
  Medusa(Die*);
  int attack();
  int defend();
  Die* dice;
  private:
};

#endif
