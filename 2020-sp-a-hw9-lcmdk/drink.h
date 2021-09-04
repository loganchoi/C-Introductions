//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: drink.h
//Purpose: This file contains the drink class.

#ifndef DRINK_H
#define DRINK_H
#include <iostream>
#include <cstdlib>
using namespace std;

//Global Constants
const int MAX_W = 10;
const int MIN_W = 5;
const int MAX_C = 10;
const int MIN_C = 1;
const int DECI_W = 100;
const int DECI_C = -1000;

class drink
{
  public:
    drink()
    {
      srand(time(NULL));
      if (rand() % 2 == 0)
      {
        name  = "whiskey";
        effect = static_cast<float>(MIN_W + rand() % (MAX_W - MIN_W + 1));
        effect = effect / DECI_W;
      }
      else
      {
        name = "coffee";
        effect = static_cast<float>(MIN_C + rand() % (MAX_C - MIN_C + 1));
        effect = effect / DECI_C;
      }
    }
  private: 
    string name;
    float effect;
};


#endif
