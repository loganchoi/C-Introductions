//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: janitor.h
//Purpose: This file contains the janitor class in which driver will text.


#ifndef JANITOR_H
#define JANITOR_H
#include "school.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Global Constants
const int NEWS = 4; //Number of directions a person can move
const char EMPTY = ' ';
const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;
//The janitor() can take a name as a parameter, and will set up the rest of 
//the member variables to their default.
//Pre: none
//Post: The janitor's members are set up and stored.

//The place_me() will place the janitor in the middle of the school grid.
//Pre: The school grid is cleared and built.
//Post: The school grid now has the janitor in the middle of the grid.
//His position is also updated.

//The get_sober() will just return the janitor's m_sober variable.
//Pre: None
//Post:The janitor's m_sober variable is returned.

//The get_alive() will just return the janitor's m_alive variable.
//Pre; None
//Post: The janitor's m_alive variable is returned.

//The rand_walk() will make the janitor move in a certain direction on grid.
//It will also store his new coordinates.
//Pre:The school grid is cleared and built.
//Post: The school grid has cleared the janitor's previous position, and 
//moved him. It also updates his new position. 

//The print() will just print out all the janitor's members.
//Pre: None
//Post: The janitor's info is printed out.

class janitor
{
   public:
     janitor(string name = "Willie"):m_name(name),m_symbol('J'),m_bac(0.05),
       m_bruises(0),m_alive(true),m_lunch(false),m_sober(true),m_row(-1),m_col(-1){}
     void place_me(school & grid);
     void rand_walk(school & grid);
     bool get_sober(){return m_sober;}
     bool get_alive(){return m_alive;}
     void print() const;
     
   private:
     string m_name;
     char m_symbol;
     float m_bac;
     int m_bruises; 
     bool m_alive;
     bool m_lunch;;
     bool m_sober;
     int m_row;
     int m_col;
};

#endif
