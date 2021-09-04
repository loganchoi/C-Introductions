//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: drink.h
//Purpose: This holds the drink class.


#ifndef DRINK_H
#define DRINK_H
using namespace std;
#include <iostream>

//Global Constants
const int MAX_W = 10;
const int MIN_W = 5;
const int MAX_C = 10;
const int MIN_C = 1;
const int DECI_W = 100;
const int DECI_C = 1000;

//The drink() will randomly set the member variables.
//Pre: None
//Post: The member variables are set and stored.

//The get_effect() will just return the m_effect of that drink.
//Pre: None
//Post: The member variable m_effect is returned.

//The get_name() will just return the m_name of that drink.
//Pre: None
//Post: The member variable m_name is returned.

class drink
{
  public:
    drink()
    {
      if (rand() % 2 == 0)
      {
        m_name  = "whiskey";
        m_effect = static_cast<float>(MIN_W + rand() % (MAX_W - MIN_W + 1));
        m_effect = m_effect / DECI_W;
      }
      else
      {
        m_name = "coffee";
        m_effect = static_cast<float>(MIN_C + rand() % (MAX_C - MIN_C + 1));
        m_effect = -1 * m_effect / DECI_C;
      }
    }
    float get_effect(){return m_effect;}
    string get_name() {return m_name;}
  private:
    float m_effect;
    string m_name;
};

#endif
