//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: lunch.h
//Purpose: This holds the lunch class.

#ifndef LUNCH_H
#define LUNCH_H
#include "school.h"
#include <iostream>
using namespace std;

//The lunch constructor does not take any arguments, and just sets its
//members to default.
//Pre: None
//Post: The members are defaulted.

//The place_me() will just put the lunch symbol in a random position
//that is valid
//Pre; The school grid is cleared and built.
//Post: The lunch is in a valid position within the school, and its
//coordinates are updated.

//The rand_move() will just move the lunch symbol in an adjacent spot
//taht is valid.
//Pre: Teh school grid is cleared and built.
//Post: The lunch's coordinates are updated, and is in a valid position.

//The get_stuck() will return the member variable m_stuck.
//Pre: None
//Post: The value of m_stuck is returned.

//The get_row() will return the member variable m_row.
//Pre: None
//Post: The value of m_row is returned.

//The get_col() will return the member variable m_col.
//Pre: None
//Post: The value of m_col is returned.
class lunch
{
   public:
     lunch(): m_row(-1),m_col(-1),m_symbol('L'),m_stuck(false){}
     void place_me (school & grid);
     void rand_move (school & grid);
     bool get_stuck(){return m_stuck;}
     int get_row(){return m_row;}
     int get_col(){return m_col;}
   private:
     int m_row;
     int m_col;
     char m_symbol;
     bool m_stuck;
};

#endif
