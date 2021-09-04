//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: simulation.cpp
//Purpose: This does the actual simulation that is called from main.


#include "simulation.h"


void simulation(const int size,int num_drinks,
           const int traps, const int wind, const int i, info& results)
{
   //Declarations
   school s(size, wind);
   janitor j;
   lunch l;
   int temp_drinks;
  
   //Hold the total num_drinks
   temp_drinks = num_drinks;

   //Place all of the pieces on the grid
   j.place_me(s);
   l.place_me(s);
   s.place_drinks(num_drinks);
   s.place_traps(traps);
    
   //In this do-while loop, the lunch and janitor will
   //keep moving until the janitor is dead, finds the lunch, 
   //or went through a window.
   do
   {
     //If janitor's bac is greater than or equal to death limit
     //his m_alive turns to false, which will break loop.
     if (j.get_bac() >= DEAD)
     {
       j.set_dead();
     }
     //If janitor is drunk, he will walk randomly.
     else if (j.get_bac() >= DRUNK)
     {
       j.rand_walk(s,num_drinks,i);
     }
     
     //Otherwise, he will walk intelligently.
     else
     {
       j.smart_walk(s,l,num_drinks,i);
     }
     
     //If lunch is not stuck, it moves.
     if (!l.get_stuck())
     {
       l.rand_move(s);
     }
     
     //Print out the grid everytime.
     if (i==0)
     {
       s.print();
       usleep(200000);
     }

   }while(j.get_alive() && !j.get_success() && !j.get_window());
      
   //Update the results accordingly
   results.total_bruises += j.get_bruises();
   results.total_bac += j.get_bac();
   
   //If janitor got window, increase window exits
   if (j.get_window())
     results.total_windows++;
   //If janitor finds lunch, increase successes
   if (j.get_success())
     results.successes++;

   //Reset the num_drinks  
   num_drinks = temp_drinks;
   return;
}




