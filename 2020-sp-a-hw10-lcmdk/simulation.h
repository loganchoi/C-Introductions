
//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: simulation.h
//Purpose: This holds the function prototypes for main.

#ifndef SIMULATION_H
#define SIMULATION_H

#include <fstream>
#include  <unistd.h>
#include "school.h"
#include "janitor.h"
#include "lunch.h"
#include "drink.h"

//Global Constants
const int PERCENT = 100;


//This struct holds all the results.
struct info
{
  int total_bruises;
  float total_bac;
  int total_windows;
  int successes;
};


//The simulation() will take in all the info, and run the actual simulation.
//Pre:All of the integers should be positive. The info type should hold data.
//Post:The results are updated and returned.
void simulation(const int size,int num_drinks,
           const int traps, const int wind,const int i, info& results);
#endif





