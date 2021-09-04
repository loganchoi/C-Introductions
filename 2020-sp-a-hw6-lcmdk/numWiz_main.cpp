//Programmer: Logan Choi
//MST Username: lcmdk
//Section: 101
//File: numWiz_main.cpp
//Purpose: Main file that calls functions
//         depending on user input. 


#include <iostream>
using namespace std;
#include "numWiz.h"


int main()
{
    
   //Variables
   bool quit = false;
   bool opt1_used = false;
   float first_num;
   int power_num; 
   int root_num;

   //Welcome function
   welcome();
   
   //do-while loop that will continue until Quit is entered.
   do
   {
      //switch-case by calling menu() which will execute a certain case.
      switch(menu())
      { 
        //Case 1: User enters base number with first_input(), and
        //says that option 1 has been used.
        case X_VAL:
          first_num = first_input();
          opt1_used = true;
          break;
        
        //Case 2: User enters exponenet number with exponent_input()
        //, and outputs the result using power_math(). 
        case POWER:
          if (opt1_used == true)
          {
             power_num = exponent_input();
             cout << first_num << " raised to the " << power_num
                  << " is " << power_math(first_num,power_num) << endl;
          }
          //If option 1 has not been used, output this error. Same
          // for all other cases.
          else
             cout << "ERROR: Type in first number in option 1" << endl;
          break;
        
        //Case 3: User enters root number with exponent_input(), and
        //, and outputs the result using root_math() 
        case NTH_ROOT:
          if (opt1_used ==true)
          {
              root_num = exponent_input();
              cout << first_num << " raised to the 1/" << root_num
                   << " is " << root_math(first_num,root_num) << endl;
          }
          else
             cout << "ERROR: Type in first number in option 1" << endl;
          break;
       
        //Case 4: Outputs the result of euler's number raised to the 
        //first input by using euler_pow()  
        case EULER:
          if (opt1_used == true)
          {
             cout << "e raised to the " << first_num
                  << " is: " << euler_pow(first_num) << endl;
          }
          else
             cout << "ERROR: Type in first number in option 1" << endl;
          break;
        //Case 5: Outputs the result of hyperbolic sin by using sin_h().
        case SINH:
          if (opt1_used == true)
          {
             cout << "sinh(" << first_num << ")"
                  << " is: " << sin_h(first_num) << endl;
          }
          else
             cout << "ERROR: Type in first number in option 1" << endl;
          break;
        
        //Case 6: Outputs goodbye message by using goodbye().
        case BYEBYE:
          goodbye();
          quit = true;
          break;
       
        //Will output error message if user inputs a case number that 
        //does not exist.
        default:
          cout << "ERROR: Pick valid option choice." << endl;
          
      }
      
   } while (!quit);
    
   return 0;
}
