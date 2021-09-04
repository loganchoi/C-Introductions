//Programmer: Logan Choi
//MST Username: lcmdk
//Seciton: 101
//File: numWiz_funct.cpp
//Purpose: This file has all the functions
//         that main will call and use.

#include "numWiz.h"
#include <iostream>
using namespace std;

//Welcome function that just outputs greeting to user.
void welcome()
{
   cout << "Welcome to Number Wizard!!!" << endl;
   return;
}

//Outputs Menu, and asks for input from user.
int menu()
{
   //Variables
   int user_input;
   
   cout <<"MENU" << endl
        <<"----" << endl
        <<"1. Enter first number." << endl
        <<"2. Enter exponent." << endl
        <<"3. Root the number." << endl
        <<"4. Euler's Number." << endl
        <<"5. Sinh(number)." << endl
        <<"6. Quit." << endl;
    
    cin >> user_input;
    return user_input;
}

//This is for the float base number that can only be positive.
float first_input()
{
   //Variables
   float val;
  
   //Do-while loop that will continue until user inputs correctly.
   do
   {
     cout << "Enter a POSITIVE real number" << endl;
     cin >> val;
     if (val <= 0)
       cout << "ERROR: Please enter POSITIVE number." << endl;
   } while (val <= 0);
   return val;

}

//This is for the exponent or root number.
int exponent_input()
{
   //Variables
   int val;
   
   //Do-While loop that will continue until user inputs correctly.
   do
   {
     cout << "Enter a POSITIVE integer" << endl;
     cin >> val;
     if (val <= 0)
       cout << "ERROR: Please enter POSITIVE integer." << endl;
   } while (val <= 0);
   return val;
}

//This calculates the base num raised to a certain power.
float power_math(const float num, const int power)
{
   //Variables
   float result = 1;
   
   //for loop to calculate exponent
   for (int i = 1; i <= power; i++)
      result = result * num;
   return result;
}

//This calculates the nth root of a number.
double root_math(const float num, const int root)
{
   //Variables
   double result = 1;
   
   //for loop that uses a given equation. Loops 20 times to get accurate result.
   //Uses other functions.
   for (int i = 0; i < ROOT_ACC; i++)
      result = ((root - 1) * result + num / power_math(result,(root-1))) / root;

   return result;
}

//This calculates e raised to the num.
float euler_pow(const float num)
{
   //Variables
   float result = 1;
   
   //For loop that uses a given equation, and utilizes
   // other functions. Loops 11 times. 
   for (int i = 1; i < EULER_ACC; i++)
     result = result + power_math(num,i) / factorial(i);
    
   return result;
}

//This calculates the hyperbolic sin of number.
float sin_h(const float num)
{  
   //calculates using given equation 
   //Uses other functions and returns result.
   return 0.5 * (euler_pow(num) - 1/euler_pow(num));
}

//This calcualtes any number's factorial.
int factorial(const int num)
{
   //Variable
   int result = 1;
   
   //For loop that will multiply every positive number
   // less than num (also multiplies with num itself)
   for (int i = num; i > 0; i--)
      result = result * i;

   return result;
}

//This function outputs a goodbye message
void goodbye()
{
   cout << "Thank you for using Number Wizard!!!" << endl
       << "Have a good day!!!" << endl;
   return;
}

