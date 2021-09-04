//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: janitor.cpp
//Purpose: This file contains the member functions of the janitor class.

#include "janitor.h"


void janitor::place_me(school & grid)
{
   //Variables
   int size;

   //It will get school size and change the
   //janitor's coordinates, and place him on grid.
   
   size = grid.get_dim();
   m_row = size/2;
   m_col = m_row;
   grid.set_sym(m_row,m_col,m_symbol);
   return;
}

void janitor::rand_walk(school & grid, info& results)
{
   srand(time(NULL));
  
   //Variables
   int dir;
   int temp_row;
   int temp_col;
   
   //Clear out the janitor's current position
   grid.set_sym(m_row,m_col,EMPTY);
 
   //In this do-while loop, I will pick an adjacent square in if-else
   //but if the spot is already occupied, it will keep looping. It
   //also changes the janitor's coordinates
   temp_row = m_row;
   temp_col = m_col;
   do
   {
     m_row = temp_row;
     m_col = temp_col;
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
     if (grid.get_sym == WINDOW)
       results.
   }while (!grid.valid(m_row,m_col));   

  //Set the new position of the janitor on grid
  grid.set_sym(m_row,m_col,m_symbol);

  return;
}

void janitor::print() const
{
  //Print out the janitor's info.
  cout << "\nJanitor's Name: " << m_name << endl
       << "# of Bruises: " << m_bruises << endl
       << "Symbol: " << m_symbol << endl
       << "Alive? " << (m_alive ? "Yes" : "No") << endl
       << "Sober? " << (m_sober ? "Yes" : "No") << endl
       << "Blood-Alcohol Content: " << m_bac << endl
       << "Position: " << m_row << "," <<m_col << endl;
  return;
}
