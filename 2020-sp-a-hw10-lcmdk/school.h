//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: school.h
//Purpose: This file holds the school class that will be texted by driver.


#ifndef SCHOOL_H
#define SCHOOL_H
#include <iostream>
using namespace std;
#include <cstdlib>
#include "drink.h"

//Global Constants
const int MAX = 40;
const char WALL1 = '~';
const char WALL2 = ':';
const char WINDOW = '+';
const char NOTHING = ' ';
const char TRAP = 'T';
const char DRINK = 'D';

//The school constructor can take an argument of a size and will set up 
//the school grid.
//Pre: size is a positive number less than or equal to 25.
//Post: It completely sets up the grid of the school.

//The print() will print out the entire school grid.
//Pre: None
//Post: The school grid is printed with its contents.

//The valid() will check if the random move is valid or not.
//Pre: The parameters are valid coordinates in the grid.
//Post: The validity of the move will be returned.

//The set_sym() will take in coordinates and a symbol, and will
//put the symbol in the school grid.
//Pre: The parameters are valid coordinates in the grid.
//Post: THe symbol is placed in the corresponding coordinates of the array.

//The get_dim() will return the school's size.
//Pre: none
//Post: The size is returned.

//The place_traps will place the traps onto the grid.
//Pre: The parameter is non_negative.
//Post; The traps are placed.

//The place_drinks will place the drinks onto the grid.
//Pre: The parameter is non-negative.
//Post: The drinks are placed.

//The get_sym() will return the symbol that is on the grid.
//Pre: The parameters are positive locations.
//Post: The symbol at that position is returned.

//The get_drink() will return the nth drink's effect.
//Pre: The parameter is positive.
//Post: The drink's effect is returned.

//The get_name() will return the nth drink's name.
//Pre: The parameter is positive.
//Post: The drink's name is returned.

//The build() will build the school grid.
//Pre: The parameter is positive
//Post: The school is built with the walls and windows.

//The clear() will clear the entire 2d array.
//Pre: None
//Post: The 2d array is cleared out.

class school
{
   public:
     school(int size = MAX, int wind = 0): school_size(size)
     { 
        clear();
        build(wind);
     }
     void print() const;
     bool valid(int row, int col) const
     {
       bool works;
       if (arr[row][col] != NOTHING)
         works = false;
       else
         works = true;

      return works;
     }
     void set_sym(const int row, const int col, const char symbol)
     {
        arr[row][col] = symbol;
        return;
     }
     int get_dim() const {return school_size;}
     void place_traps(int traps);
     void place_drinks(int drinks);
     char get_sym(int row, int col){return arr[row][col];}
     float get_drink(int num){return bevs[num-1].get_effect();}
     string get_name(int num){return bevs[num-1].get_name();}
  
   private: 
     void build(int wind);
     void clear(); 
     char arr[MAX][MAX];
     short school_size;
     drink bevs[MAX];
};


#endif
