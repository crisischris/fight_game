#ifndef   CHARACTER_HPP
#define   CHARACTER_HPP

#include<string>
#include"Die.hpp"

class Character 
{
			
  public:
  virtual int attack() = 0;
  virtual int defend() = 0;
  int getStrengthPoints();
  int getArmorPoints();
  std::string getSpecialAbility();
  virtual void setStrengthPoints(int);
  std::string getType(){return this->type;}
  void setName(std::string nameIn);
  std::string getName();

  protected:
  std::string type;
	std::string name = "unassigned";
  std::string specialString;
  int armor;
  int strengthPoints;


  private:
};

#endif

