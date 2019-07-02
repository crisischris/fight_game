#ifndef   DIE_HPP
#define   DIE_HPP

class Die
{
  public:

    //citation: https://stackoverflow.com/questions/18885224/how-to-call-derived-class-
    //method-from-base-class-pointer
    int roll();
    int setSide(int);
    int getSides();
    int getTypeInt();
    std::string getTypeString();

  protected:
    int N;
    std::string type;
};

#endif

