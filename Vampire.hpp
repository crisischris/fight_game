#ifndef   VAMPIRE_HPP
#define   VAMPIRE_HPP

#include"Character.hpp"

class Vampire : public Character
{
  public:
  Vampire(Die*);
  int attack();
  int defend();
  Die* dice;
  private:
};

#endif
