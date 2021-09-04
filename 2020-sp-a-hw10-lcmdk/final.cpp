//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: driver.cpp
//Purpose: This main function will test all the classes.

#include "simulation.h"

int main()
{
  srand(time(NULL));

  //Declarations
  int num_sims;
  int num_drinks;
  int num_traps;
  int size;
  int windows;
  info results;
  ifstream in("config.dat");

  //Get input from data file
  in >> num_sims;
  in >> size;
  in >> num_drinks;
  in >> num_traps;
  in >> windows;

  //Set out results struct all to zero
  results.total_bruises = 0;
  results.total_bac = 0;
  results.total_windows = 0;
  results.successes = 0;

  //Loop for the number of simulations.
  for (int i = 0; i < num_sims; i++)
    simulation(size, num_drinks, num_traps, windows, i, results);

  //Output Data
  cout << "\nTotal Successes: " << results.successes << endl
       <<"Total Bruises: " << results.total_bruises << endl
       <<"Total BAC: " << results.total_bac << endl
       <<"Total Windows: " << results.total_windows<< endl << endl;
  cout << static_cast<float>(results.total_windows)/num_sims * PERCENT
       << "% of the time you hit a window." << endl
       << static_cast<float>(results.successes)/num_sims * PERCENT
       << "% of the time you found the lunch." << endl
       << "Average Bruises: " << static_cast<float>(results.total_bruises)/num_sims
       << endl << "Average Blood-Alcohol Level: "
       << results.total_bac/num_sims << endl;

  in.close();
  return 0;
}








