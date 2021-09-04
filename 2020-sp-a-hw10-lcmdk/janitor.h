//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: janitor.h
//Purpose: This file contains the janitor class in which driver will text.


#ifndef JANITOR_H
#define JANITOR_H
#include "school.h"
#include "lunch.h"
#include <iostream>
using namespace std;

//Global Constants
const int NEWS = 4; //Number of directions a person can move
const char EMPTY = ' ';
const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;
const float DRUNK  = 0.08;
const float DEAD = 0.25;
const int TRAP_BRUISE = 5;
const char LUNCH = 'L';

//The janitor() can take a name as a parameter, and will set up the rest of 
//the member variables to their default.
//Pre: none
//Post: The janitor's members are set up and stored.

//The place_me() will place the janitor in the middle of the school grid.
//Pre: The school grid is cleared and built.
//Post: The school grid now has the janitor in the middle of the grid.
//His position is also updated.

//The rand_walk() will make the janitor move in a certain direction on grid.
//It will also store his new coordinates.
//Pre:The school grid is cleared and built. The rest are positive.
//Post: The school grid has cleared the janitor's previous position, and 
//moved him. It also updates his new position. 

//The smart_walk() will make the janitor move towards the lunch on the grid.
//It will also store his new coordinates.
//Pre; The school grid is cleared and built. The lunch as valid positions.
//     The rest are positive.
//Post: The school grid has cleared the janitor's previous position, and moved
//It also updates his new position.

//The print() will just print out all the janitor's members.
//Pre: None
//Post: The janitor's info is printed out.

//The get_bac() returns the m_bac variable of janitor.
//Pre: None
//Post: The value of m_bac is returned.

//The get_alive() will return the m_alive variable of janitor.
//Pre: None
//Post; The value of m_alive is returned.

//The get_success() will return the m_success variable of janitor.
//Pre: None
//Post: The value of m_success is returned.

//The get_window() will return the m_wind of janitor.
//Pre: None
//Post: The value of m_wind is returned.

//The get_bruises() will return the m_bruises variable of janitor.
//Pre; None
//Post: The value of m_bruises is returned.

//The set_dead() will change the janitor's m_alive variable.
//Pre; None
//Post: The janitor is now dead. m_alive is false.

class janitor
{
   public:
     janitor(string name = "Willie"):m_name(name),m_symbol('J'),m_bac(0.05),
        m_bruises(0),m_alive(true),m_sober(true),m_row(-1),m_col(-1)
       ,m_success(false), m_wind(false){}
     void place_me(school & grid);
     void rand_walk(school & grid, int & num_drinks,const int i);
     void smart_walk(school & grid, lunch & l, int & num_drinks, const int i);
     void print() const;
     float get_bac() {return m_bac;}
     bool get_alive(){return m_alive;}
     bool get_success(){return m_success;}
     bool get_window() {return m_wind;}
     int get_bruises(){return m_bruises;}
     void set_dead()
     { 
       m_alive = false;
       return;
     }
   private:
     string m_name;
     char m_symbol;
     float m_bac;
     int m_bruises; 
     bool m_alive;
     bool m_sober;
     int m_row;
     int m_col;
     bool m_success;
     bool m_wind;
};

#endif 
