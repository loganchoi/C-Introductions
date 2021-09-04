//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: walker.h 
//Purpose: This file contains the function defintion
//         in which it will perform its designated tasks

#include "walker.h"

void newPoint (const int length, const double angle, point & pt)
{
   //This finds the next x and y coordinates.
   pt.m_x += length * cos(angle);
   pt.m_y += length * sin(angle);
   return;
}

double calcDist (const point pt)
{
   //Uses the distance formula to find the final distance
   return sqrt(pt.m_x * pt.m_x + pt.m_y * pt.m_y);
}

void sortArray(double arr[], const int size)
{
   //Local Variables
   double temp;

   //The nested for-loop will take one element, and 
   //go through every other element to see if it is bigger.
   for (int i = 0; i < size; i++)
   {
      for (int j = i+1; j < size; j++)
      {
         //If it is bigger, swap them.
         if (arr[i] > arr[j])
         {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }
   return;
}

void outputData(const double arr[], const int size)
{
   //Local Variables
   double avg = 0;
   double median;
   
   //This for-loop finds the total.
   for (int i = 0; i< size; i++)
   {  cout << arr[i] << endl;
      avg += arr[i];
   }

   //If the size of the array is even, find average of two
   //middle numbers. Otherwise, it is just the middle number.
   if (size % 2 ==0)
     median = (arr[size/2 - 1] + arr[size/2]) / 2;
   else
     median = arr[size/2];

   //Output data
   cout << "Willie's Walking Data!" << endl
        << "The longest distance was " << arr[size-1] << endl
        << "The shortest distance was " << arr[0] << endl
        << "The median distance was " << median << endl
        << "The average distance was " << avg/size << endl;
 
  return;
}
