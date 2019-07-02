#ifndef   BARBARIAN_HPP
#define   BARBARIAN_HPP

#include"Character.hpp"

class Barbarian : public Character
{
  public:
  Barbarian(Die*);
  int attack();
  int defend();
  Die* dice;
  private:
};

#endif
