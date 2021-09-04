//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: driver.cpp
//Purpose: This main function will test all the classes.

#include "simulation.h"

int main()
{
  //Declarations
  int num_sims;
  int num_drinks;
  int num_traps;
  int size;
  int windows;
  info results; 
  ifstream in("config.dat");

  in >> num_sims;
  in >> num_drinks;
  in >> size;
  in >> num_traps;
  in >> windows;
  
  results.total_bruises = 0;
  results.total_bac = 0;
  results.total_windows = 0;
  results.successes = 0;

  for (int i = 0; i < size; i++)
    simulation(size, num_drinks, num_traps, windows, results);

  cout << static_cast<float>(results.total_windows/size) * PERCENT
       << "% of the time you hit a window." << endl
       << static_cast<float>(results.successes/size) * PERCENT
       << "% of the time you found the lunch." << endl
       << "Average Bruises: " << static_cast<float>(results.total_bruises/size)
       << endl << "Average Blood-Alcohol Level: " 
       << results.total_bac/size << endl; 
  
  in.close();
   return 0;
}
