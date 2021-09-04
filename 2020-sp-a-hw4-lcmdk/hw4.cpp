//Programmer: Logan Choi
//Student ID: lcmdk
//Section: 304
//File: hw4.cpp
//Purpose: Do exponent math and cube root based off
//         user inputs.

#include <iostream>
using namespace std;

int main()
{
    
   //Variables
   bool first_input = false; //Checks if the base number has been inputted
   int user_input; //user_input
   int base_num; //base number
   int pow_num;  //Exponent number
   float result = 1;  //result for the output statement
   
   //CONSTANTS
   const int BASE_INPUT = 1; //menu option 1
   const int EXPONENT = 2; //menu option 2 
   const int CUBE_ROOT = 3; //menu option 3
   const int QUIT = 4; //menu option 4
    
   //Welcome Message
   cout << "Welcome to Number Power!!!" << endl;
   
   //Present menu in a do-while loop. Loops until the user enters 4 for quit
   do
   {
      //Output Menu for the user to see, and get his input
      cout << "\n      MENU" << endl
         << "    --------" << endl
         << "1. Enter a number." << endl
         << "2. Power the number." << endl
         << "3. Cube root of the number." << endl
         << "4. Quit." <<endl;
    
      cin >> user_input;
      result = 1; //resets number
      //Switch Statement to see what the user inputted
      switch (user_input)
      {
          //Option 1 says that the user has put in a POSITIVE base number
          case BASE_INPUT:
            
            //Do-While loop to make sure the user inputs a POSITIVE number
            //Outputs Error if they do not.
            do
            {
               cout << "Enter a POSITIVE base integer" << endl;
               cin >> base_num;
               if (base_num <= 0)
                 cout << "ERROR: Please enter POSITIVE integer" << endl;
            }while (!(base_num > 0));
            
            //Tells that the first_input has been put in. the base number
            first_input = true;
            break;
          
          //This case inputs the exponent number.
          case EXPONENT:
            
            //If base num has not been inputted, it outputs Error message
            if (first_input == false)
            {
              cout << "ERROR: Please enter base integer through option 1." << endl;
            }
            
            //Otherwise, you find the result through a for-loop and continuously
            //multiplying base_num
            else
            {
              do
              {
                 cout << "Enter a POSITIVE exponent integer for " << base_num << endl;
                 cin >> pow_num;
                 if (pow_num <= 0)
                   cout << "ERROR: Please enter POSITIVE integer" << endl;
              }while (!(pow_num > 0));
              
              for (int i = 1; i <= pow_num ; i++)
              {
                  result = result * base_num;
              }
              cout << "Your result is " << result << endl;
            }
            break;
         
          //This outputs the cube root of base_num
          case CUBE_ROOT:
          
            //If base_num hasn't been inputted yet, Error message is outputted.
            if (first_input == false)
            {
              cout << "ERROR: Please enter base integer through option 1." << endl;
            }
            
            //Otherwise, find cube root using given formula within for loop.
            else
            {
              result = base_num;
              for (int i= 1; i <= 10; i++)
              {
                 result = (2 * result + base_num / (result * result)) / 3;
              }
              cout << "Your result is " << result << endl;
            }
            break;
          
          //If user inputs 4, goodbye message is outputted, and system ends.
          case QUIT:
            cout << "Thanks for using Number Power!!!" << endl
                 << "Have a good day!!!" << endl;
            break;
        
          //If user inputs a non-existent option, error message is outputted.
          default:
            cout << "ERROR: Please pick a valid option number!!!" << endl;
      }
           
   }while (user_input != QUIT);
   
   return 0;
}




