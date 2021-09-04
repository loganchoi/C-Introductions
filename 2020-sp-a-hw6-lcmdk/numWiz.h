//Programmer: Logan Choi
//MST Username: lcmdk
//Section: 101
//File: numWiz.h 
//Purpose: Sets up the prototypes and constants
//         for the math menu options.

#ifndef NUM_WIZ_H
#define NUM_WIZ_H

//constants
const int ROOT_ACC = 20; //root_math accuracy loop
const int EULER_ACC = 11; //euler number accuracy loop
const int X_VAL = 1; //option 1
const int POWER = 2; //option 2
const int NTH_ROOT = 3; //option 3
const int EULER = 4; //option 4
const int SINH = 5; // option 5
const int BYEBYE = 6;//option 6



//The welcome() outputs a greeting message to user.
//Pre: None
//Post: Welcome message is outputted to screen.
void welcome();

//The menu() displays the menu, and returns a user
//inputted value.
//Pre: None
//Post: The menu is displayed on screen, and user 
//      vallue is returned.
int menu();

//The exponent_input() displays a prompt, and returns a
//user-input value.
//Pre: None
//Post: The prompt is displayed and the user-inputted
//      vallue is returned.
int exponent_input();

//The first_input() displays a prompt, and returns a user
//inputted value.
//Pre: None
//Post: The prompt is displayed and the user-inputted
//      value is returned.
float first_input();

//The power_math() calculates and returns the num raised to the nth
//power.
//Pre: Both parameters are positive.
//Post: The num raised to the value of power is calculated
//      and returned.
float power_math(const float num, const int power);

//The root_math() calculates and returns the nth root of num.
//Pre: Both parameters are positive.
//Post: The nth root of num is calculated and returned.
double root_math(const float num, const int root);

//The euler_pow() calculates e raised to the nth power, and
//returns the value.
//Pre: The parameter is positive.
//Post: Result is calculated and returned.
float euler_pow(const float num);

//The sin_h() calculates and returns the hyperbolic sin of
//a value.
//Pre: The parameter is positive.
//Post: Result is calculated and returned.
float sin_h(const float num);

//The factorial() calculates and returns the factorial
//of a number.
//Pre: num is a positive integer.
//Post: The factorial of num is calculated and returned.
int factorial(const int num);

//The goodbye() outputs a goodbye message to user.
//Pre: None
//Post: Goodbye message is displayed on the screen.
void goodbye();

#endif
