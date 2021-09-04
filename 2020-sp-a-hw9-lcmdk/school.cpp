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

void school::build()
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
        if (j % WIND_TURN == 0 && j!=0 && j!= school_size - 1)
          arr[i][j] = WINDOW;
        else
          arr[i][j] = WALL1;
      }
      else if (j==0 || j == school_size-1)
      { 
        //For a side, if it is the fourth wall, then make it window
        //otherwise, just make it aa wall. 
        if (i % WIND_TURN == 0 && i!= 0 && i!= school_size -1)
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
