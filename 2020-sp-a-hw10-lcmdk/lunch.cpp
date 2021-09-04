//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: lunch.cpp
//Purpose: This file contains the member function definitions of lunch class.


#include "lunch.h"
#include "janitor.h"

void lunch::place_me(school & grid)
{
   //Variables
   int size;

   size = grid.get_dim();
    
   //Set the lunch in a random position that is valid. 
   do
   {
     m_row = rand() % (size-2)+1;
     m_col = rand() % (size-2)+1;
   }while (!grid.valid(m_row,m_col));
   grid.set_sym(m_row,m_col,m_symbol);

   return;
}

void lunch::rand_move(school & grid)
{ 
   //Variables
   int dir;
   int temp_row;
   int temp_col;
   
   //Empty out the lunch's current position
   grid.set_sym(m_row,m_col,EMPTY);
   
   //Hold the lunch's previous position 
   temp_row = m_row;
   temp_col = m_col;
   
   //Move randomly in the four cardinal directions
   dir = rand() % NEWS;
   if (dir == NORTH)
      m_row++;
   else if (dir == SOUTH)
      m_row--;
   else if (dir == EAST)
      m_col++;
   else if (dir == WEST)
      m_col--;
     
   //If lunch hits a trap, his m_stuck is turned true, and
   //Lunch will be there for the rest of that simulation.
   if (grid.get_sym(m_row,m_col) == TRAP)
   {
     m_stuck = true;
     grid.set_sym(m_row,m_col,m_symbol);
   }
   //If the movement is valid, then lunch moves accordingly.
   else if (grid.valid(m_row,m_col))
     grid.set_sym(m_row,m_col,m_symbol);
  
   //Otherwise, it's not valid, Reset lunch's position.
   else
   {
     m_row = temp_row;
     m_col = temp_col;
     grid.set_sym(m_row,m_col,m_symbol);
   }
  
  return;
}
