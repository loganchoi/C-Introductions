// Programmer: Logan Choi
// Student ID: lcmdk
// Section : 304
// File: hw2.cpp
// Purpose: Find which fork number the user needs
//          depending on the handle length.


#include <iostream>
using namespace std;
int main()
{
  //Declarations of Variables and Types
  short fork;
  short stink;
  float wt_possum;
  float tail;
  float handle;
  float baro_press;

  //Constant Declarations
  const short thresh_score = 8;

  //Ask for input from user

  cout << "Hi! Welcome to Springfield Elementary!!!" << endl;
  cout << "We have a major 'possum problem, and I need your help." << endl;
  cout << "Please enter stink factor of the oppossum." << endl;
  cout << "1(kinda stinky) to 10 (really stinky)" << endl;
  cin >> stink;
  cout << "Now, please enter today's  barometric pressure." << endl;
  cin >> baro_press;
  cout << "What is the tail length of the opossum?" << endl;
  cin >> tail;
  cout << "What is the dead opossum's weight?" << endl;
  cin >> wt_possum;

  //Calculation for handle length

  handle = (static_cast<float>(stink)/thresh_score) * (3*tail + wt_possum) + 30

  //Calculation for fork number

  fork = static_cast<short>(handle) / 10;

  // Output information and result

  cout << "Based off of this information!" << endl;
  cout << "   weight: " << wt_possum << endl;
  cout << "   baro presure: " << baro_press << endl;
  cout << "   stink factor: " << stink << endl;
  cout << "   tail length: " << tail << endl;
  cout << "Your handle length and fork number is..." << endl;
  cout << "   Handle length: " << handle << endl;
  cout << "   Fork number: " << fork << endl;

  return 0;
}
