//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: walker.cpp
//Purpose: This is the main function in which it cycles through 
//          every walk and their segments.


#include "walker.h"

int main()
{srand(time(NULL));
   
   //Local Variables
   double angle;
   int length;
   point current;
   point final[MAX_WALKS];
   double dist[MAX_WALKS];
   
   //The nested for-loop goes through every walk and their segments.
   for (int i = 0; i< MAX_WALKS; i++)
   {  
      //This resets every walk
      current.m_x = 0;
      current.m_y = 0;
      
      for (int j =0; j < MAX_SEGS; j++)
      {  
         //The length and angle are assigned.
         angle = (rand() % UNIT_CIRCLE) *  RADIANS;
         length = rand() % MAX_LEN;
        
         //The next point is calculated by calling this function.
         newPoint(length,angle,current);
      }

      //Afterwards, the corresponding final  x and y coords are stored, and
      //their distances are calculated and stored.
      final[i].m_x = current.m_x;
      final[i].m_y = current.m_y;
      dist[i] = calcDist(final[i]);
   }

   //This sorts the array in ascending order.
   sortArray(dist,MAX_WALKS);
   //This outputs all the data.
   outputData(dist,MAX_WALKS);
    
   return 0;
}
