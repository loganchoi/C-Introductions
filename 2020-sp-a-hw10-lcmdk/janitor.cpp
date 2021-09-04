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

void janitor::rand_walk(school & grid, int & num_drinks, const int i)
{
  
   //Variables
   int dir;
   int temp_row;
   int temp_col;
   
   //Clear out the janitor's current position
   grid.set_sym(m_row,m_col,EMPTY);
   
   //Hold previous position just in case. 
   temp_row = m_row;
   temp_col = m_col;
 
   //This will randomly move him in the four cardinal directions
   dir = rand() % NEWS;
   if (dir == NORTH)
      m_row--;
   else if (dir == SOUTH)
      m_row++;
   else if (dir == EAST)
      m_col++;
   else if (dir == WEST)
      m_col--;
    
   //If it movement hits the wall, Janitor does not move, but his bruises increase.
   //Reset his positions back to his previous position. 
   if (grid.get_sym(m_row,m_col) == WALL1 || grid.get_sym(m_row,m_col) == WALL2)
   {  
      m_row = temp_row;
      m_col = temp_col;
      m_bruises++;

      //Change the school grid
      grid.set_sym(temp_row,temp_col,m_symbol);
   }
   //If the janitor hits a window, his m_wind variable will turn true
   //which will break out of the loop.
   else if (grid.get_sym(m_row,m_col) == WINDOW)
      m_wind = true;
   
   //If the janitor hits a drink. He will drink it, and replace
   //his symbol on to that drink. The total drinks are decreased.
   else if (grid.get_sym(m_row,m_col) == DRINK)
   {
     m_bac += grid.get_drink(num_drinks);
     
     if (i==0)
       cout << "The Janitor has drank: " << grid.get_name(num_drinks) << endl;
     
     grid.set_sym(m_row,m_col,m_symbol);
     num_drinks --;
   }
   //If the janitor finds the lunch, his member variable
   //m_success turns true, which will break out the loop.
   else if (grid.get_sym(m_row,m_col) == LUNCH)
     m_success = true;
   //If the janitor hits a trap, he gets 5 bruises, and 
   //replaces it with himself.
   else if (grid.get_sym(m_row,m_col) == TRAP)
   {
     m_bruises += TRAP_BRUISE;
     grid.set_sym(m_row,m_col,m_symbol);
   }      
  
   //Else the movement is valid, and the janitor is there now.
   else
      grid.set_sym(m_row,m_col,m_symbol);  

  return;
}

void janitor::smart_walk(school & grid, lunch & l, int & num_drinks, const int i)
{
  //Declarations
  int lunch_row;
  int lunch_col;
  int temp_row;
  int temp_col;
   
  //Empty out the janitor's previous position.
  grid.set_sym(m_row,m_col,EMPTY);
  
  //Hold his previous position.
  temp_row = m_row;
  temp_col = m_col;
  
  //Get the lunch positions
  lunch_row = l.get_row();
  lunch_col = l.get_col();

  //Compare the lunch positions with the janitor's positions
  //Move accordingly
  if (lunch_row > m_row)
     m_row++;
  else if (lunch_col > m_col)
     m_col++;
  else if (lunch_row < m_row)
     m_row--;
  else if (lunch_col < m_col)
     m_col--;
   
  //I doubt this will happen, but if the janitor hits a wall. Increase his bruises.
  //Reset his position 
  if (grid.get_sym(m_row,m_col) == WALL1 || grid.get_sym(m_row,m_col) == WALL2)
   {
      m_bruises++;
      m_row = temp_row;
      m_col = temp_col;
      grid.set_sym(temp_row,temp_col,m_symbol);
   }
   //If he hits a window, his variable m_wind turns true, which will break out loop.
   else if (grid.get_sym(m_row,m_col) == WINDOW)
   {
      m_wind = true;
   }
   //If he hits a dirnk, he will drink it, and change his m_bac.
   //Janitor is now moved there. Total drinks decrement
   else if (grid.get_sym(m_row,m_col) == DRINK)
   {
     if (i==0)
       cout << "The Janitor has drank: " << grid.get_name(num_drinks) << endl;
     
     m_bac += grid.get_drink(num_drinks);
     grid.set_sym(m_row,m_col,m_symbol);
     num_drinks --;
   }
   //If he hits a Lunch, his m_success variable will turn true, 
   //which will break out loop
   else if (grid.get_sym(m_row,m_col) == LUNCH)
   {
     m_success = true;
   }
   //If the janitor hits a trap, he gets 5 bruises, and 
   //replaces it with himself.
   else if (grid.get_sym(m_row,m_col) == TRAP)
   {
     m_bruises += TRAP_BRUISE;
     grid.set_sym(m_row,m_col,m_symbol);
   }
   //Otherwise, move janitor to the next position
   else
   {
      grid.set_sym(m_row,m_col,m_symbol);  
   }
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
