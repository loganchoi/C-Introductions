//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: simulation.h
//Purpose: This holds the function prototypes for main.

#ifndef SIMULATION_H
#define SIMULATION_H

#include <fstream>
#include "school.h"
#include "janitor.h"
#include "lunch.h"
#include "drink.h"

//Global Constants
const int PERCENT = 100;

struct info
{
  int total_bruises;
  float total_bac;
  int total_windows;
  int successes;
};


void simulation(const int size,int num_drinks,
           const int traps, const int wind, info& results);
#endif
