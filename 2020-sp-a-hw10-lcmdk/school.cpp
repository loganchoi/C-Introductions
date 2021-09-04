//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: school.cpp
//Purpose: This file holds the member functions for the school class.


#include "school.h"

void school::clear()
{
  //In a nested for-loop, It will clear the entire school grid.
  for (int i = 0; i < school_size; i++)
    for (int j = 0; j< school_size; j++)
      arr[i][j] = NOTHING;

  return;
}

void school::build(int wind)
{
  //In a nested for-loop, the boundaries will be set up.
  for (int i = 0; i < school_size; i++)
  {
    for (int j = 0; j < school_size;j++)
    {
      if (i==0 || i == school_size-1)
      {
        //For a side, if it is the fourth wall, then make it window
        //otherwise, just make it aa wall.
        if (j % wind == 0 && j!=0 && j!= school_size - 1)
          arr[i][j] = WINDOW;
        else
          arr[i][j] = WALL1;
      }
      else if (j==0 || j == school_size-1)
      { 
        //For a side, if it is the fourth wall, then make it window
        //otherwise, just make it aa wall. 
        if (i % wind== 0 && i!= 0 && i!= school_size -1)
          arr[i][j] = WINDOW;
        else
          arr[i][j] = WALL2;
      }
    }
  } 
  return;
}


void school::print() const
{
  cout << "\nSchool's Dimensions: " << school_size
      <<  " by " << school_size << "\n" << endl;
  
  //Just print out the entire school grid with nested-for loop
  for (int i = 0; i< school_size; i++)
  {
    for (int j = 0 ; j < school_size; j++)
    {
      if (i == 0 || i == school_size - 1)
        cout << " " << arr[i][j] << " "; 
      else
        cout << "|"  <<  arr[i][j] << "|";
    }
    cout << endl;
  }
  cout << "\n";

  return;
}

void school::place_traps(int traps)
{
  //Declarations  
  int i = 0;
  int m_row;
  int m_col;

  //This do-while loop will place the traps.
  do
  {
    //Randomize position
    m_row = rand() % (school_size - 2) + 1;
    m_col = rand() % (school_size - 2) + 1;

    //If the space is empty, increment, and set symbol
    if (valid(m_row,m_col))
    {
      i++;
      set_sym(m_row,m_col,TRAP);
    }
  }while (i < traps);
  
  return;
}

void school::place_drinks(int drinks)
{
  //Declarations
  int i = 0;
  int m_row;
  int m_col;
  
  do
  {
    //Randomize position
    m_row = rand() % (school_size - 2) + 1;
    m_col = rand() % (school_size - 2) + 1;
    
    //If the space is empty, increment, and set symbol
    if (valid(m_row,m_col))
    {
      i++;
      set_sym(m_row,m_col, DRINK);
    }
  }while (i < drinks);

  return;
}
