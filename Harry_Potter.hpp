#ifndef   HARRY_POTTER_HPP
#define   HARRY_POTTER_HPP

#include"Character.hpp"

class Harry_Potter : public Character
{
  public:
  Harry_Potter(Die*);
  int attack();
  int defend();
  Die* dice;
  void setStrengthPoints(int);
  private:
  int hogwartsUsed = 0;
};

#endif
