//Programmer: Logan Choi
//MST Username: lcmdk
//Section: Price 101
//File: walker.h 
//Purpose: This file contains the structs and prototypes
//         in which the rest of the files will utilize.

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifndef WALKER_H
#define WALKER_H

//Constants
const int MAX_WALKS = 6;
const int MAX_SEGS = 50;
const int MAX_LEN = 21;
const int UNIT_CIRCLE = 360;
const double RADIANS = M_PI/180;

//The struct handles the x,y coordinates
struct point
{
   double m_x;
   double m_y;
};

//The newPoint() calculates the new x and y coordinate.
//Pre: The length should be between 0-20. The angle should be between 0-359.
//Post: The new x and y coordinates are stored in the point.
void newPoint (const int length, const double angle, point & pt);

//The calcDist() calculates and returns the distance of the final point.
//Pre: None
//Post:The distance is calculated and returned.
double calcDist(const point pt);

//The sortArray() sorts the array in ascending order.
//Pre: arr[0]...arr[size-1] is useful data. Size is a positive number, and
//     the length of the array.
//Post: The array is sorted in ascending order.
void sortArray(double arr[], const int size);

//The outputData() calculates and outputs the average and median, and also
//outputs the shortest and longest distances.
//Pre: arr[0]...arr[size-1] is useful data. Size is a positive number, and
//     the length of the array.
//Post: The data is calculated and outputted.
void outputData(const double arr[], const int size);

#endif
