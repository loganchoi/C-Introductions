//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: simFuncts.cpp
//Purpose: This does the actual simulation that is called from main.


#include "simulation.h"


void simulation(const int size,int num_drinks,
           const int traps, const int wind, info& results)
{
   //Local Constant
   const int MAX_DRINKS = num_drinks;
   school s(size);
   janitor j;
   lunch l;
   drink arr[MAX_DRINKS];
   bool find_lunch = false;
   bool window_exit = false;

   j.place_me(s);
   l.place_me(s);
   
   do
   {
     j.rand_walk(s);
     l.rand_move(s);

   }while(j.get_alive() && !find_lunch && !window_exit);

   return;
}
