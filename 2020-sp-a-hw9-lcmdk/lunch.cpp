//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: lunch.cpp
//Purpose: This file contains the member function definitions of lunch class.


#include "lunch.h"
#include "janitor.h"

void lunch::place_me(school & grid)
{
   srand(time(NULL));
   //Variables
   int size;

   size = grid.get_dim();
    
   //Th  
   do
   {
     m_row = rand() % (size-2);
     m_col = rand() % (size-2);
   }while (!grid.valid(m_row,m_col));
   grid.set_sym(m_row,m_col,m_symbol);

   return;
}

void lunch::rand_move(school & grid)
{ 
   srand(time(NULL));
   //Variables
   int dir;
   
   //Empty out the lunch's current position
   grid.set_sym(m_row,m_col,EMPTY);

   //In this do-while loop, I will pick an adjacent square in if-else
   //but if the spot is already occupied, it will keep looping. It
   //also changes the lunch's coordinates
   do
   {
     dir = rand() % NEWS;
     if (dir == NORTH)
       m_row++;
     else if (dir == SOUTH)
       m_row--;
     else if (dir == EAST)
       m_col++;
     else if (dir == WEST)
       m_col--;
     else if (dir == NE)
     {
       m_row++;
       m_col++;
     }
     else if (dir == NW)
     {
       m_row++;
       m_col--;
     }
     else if (dir == SE)
     {
       m_row--;
       m_col++;
     }
     else if (dir == SW)
     {
       m_row--;
       m_col--;
     }
   }while (!grid.valid(m_row,m_col));

  //Update the grid and the lunch's new position
  grid.set_sym(m_row,m_col,m_symbol);

  return;
}
