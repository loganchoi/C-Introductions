/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    //Variable Declarations
    
    string name;       //user name
    char level;        //motivation level
    float rain;        //inches of rain
    short child;       //number of children
    short adults;      //number of adults
    char chalmers;     //Superintendent Chalmers
    float gals_gas;         //gallons of gas
    
    
    // Constants
    const char best = 'a';  //level a 
    const char great = 'b';    //level b 
    const char decent = 'c';   //level c 
    const char lazy = 'd';     //level d 
    const char sloth = 'e';    //level e
    const short max_rain = 50; //max rain
    const short max_gas = 500; //max gas
    const short min_mow_gas = 5; //level a low gas
    const short max_mow_gas = 10; //level a max gas
    const float c_test = 1.5;    //lean on rake test (level c)
    const float mow_rain = 0.5; //mowing test (level a)
    const short max_adults = 500; //Max Adults at school
    const short max_child = 500; //Max children at school
    
    
    //Welcome Message
    
    cout << "Welcome to Job Assigner!!!" << endl;
    
    //Get User Name
    cout << "First, what is your name? (NO SPACES)" << endl;
    cin >> name;
    
    //Prompt for Motivation level (MENU)
    do
    {
       cout << "How motivated are you to work today? lowercase (a-e) " << endl;
       cout << "  a: An excellent worker" << endl;
       cout << "  b: Basically good worker" << endl;
       cout << "  c: Can't get good help no more" << endl;
       cout << "  d: Don't plan on work from me" << endl;
       cout << "  e: Elevated slothfulness" << endl;
       cin >> level;
    }while (!(level == best || level == great || level == decent || level == lazy || level == sloth));
    
    // User inputs Level e
    
    if (level == sloth)
    {
       cout << name << " stay in bed and skip work" << endl; 
    }
    
    //User inputs level d
    
    else if (level == lazy)
    {
       //Get rain input, and validate using do while loop
       
       do
       {
          cout << "How many inches did it rain last night?" << endl;
          cin >> rain;
       }  while (!((rain >= 0) && (rain <= max_rain)));
       
       //If rain is zero, hide in hedge, else hide in tool shed
       
       if (rain == 0)
       {
          cout << name << " hide in the hedge" << endl;
       }
       else
       {
          cout << name << " hide in the tool shed" << endl;
       }
    }
    
    // User inputs level c
    
    else if (level == decent)
    {
       // Get rain input and validate using do-while loop
       
       do
       {
          cout << "How many inches did it rain last night?" << endl;
          cin >> rain;
       }  while (!((rain >= 0) && (rain <= max_rain)));
       
       //if rain is less than 1.5 inches, lean on rake 
       //otherwise lean on a broom
       
       if (rain <= c_test)
       {
          cout << name << " lean on a rake" << endl;
       }
       else
       {
          cout << name << " lean on a broom" << endl;
       }
    }  
    
    // level b
    
    else if (level == great)
    {
        // Check if Superintendent Chalmers is nearby
       do
       {
          cout << "Is Superintendent Chalmers present? (y / n)" << endl;
          cin >> chalmers;
       }while(!(chalmers == 'y' || chalmers == 'n'));
       
       //If Chalmers is there, execute branch
       
       if (chalmers == 'y')
       {
          cout << name << " get on hands and knees and scrub floor" << endl;
       }
       
       else
       {
         //If Chalmers isn't there 
         //Check how many children and adults are there
        
         do
         {
            cout << "How many children are there?" << endl;
            cin >> child;
         }while (!(child >= 0 && child < max_child));
       
         do
         {
            cout << "How many adults are there?" << endl;
            cin >> adults;
         }while (!(adults >= 0 && adults < max_adults));
       
         //If there are less children than adults, get on hands and knees
         
         if (child < adults)
         {
            cout << name << " get on hands and knees and scrub floor" << endl;
         }
         
         //Otherwise, mop the floor
        
         else
         {
            cout << name << " mop the floor" << endl; 
         }
       }
    }
    
    //User inputs level a
    
    else if (level == best)
    {
        
        // Get rain and gas inputs, and validate
       do
       {
          cout << "How many inches did it rain last night?" << endl;
          cin >> rain;
       }  while (!((rain >= 0) && (rain <= max_rain)));
       
       do
       {
          cout << "How many gals of gas do you have?" << endl;
          cin >> gals_gas;
       }while (!(gals_gas >= 0 && gals_gas <= max_gas));
       
       //if it rained more than .5 inches, execute this branch.
       
       if (rain > mow_rain)
       {
           //if you have less than 5 gals of gas, burn old text books
           //otherwise use gas to clean bathrooms.
           
          if (gals_gas < min_mow_gas)
          {
             cout << name << " burn old text books from the 1940's" << endl;
          }
          else
          {
             cout << name << " use that gas to clean the bathrooms" << endl;
          }
       }
       
       //Else if it rained less than .5 inches, execute this branch
       
       else if (rain < mow_rain)
       {
           //If you have gas gallons between and including 5 and 10,
           //mow grass
           
          if (gals_gas >= min_mow_gas && gals_gas <=max_mow_gas)
          {
             cout << name << " mow the grass" << endl;
          }
          
          //If you have more than 10 gas gallons, do laps
          
          else if (gals_gas > max_mow_gas)
          {
             cout << name << " get on the tractor and do laps around the school" << endl;
          }
          
          //If you have less than 5 gallons, get more gas
          
          else
          {
             cout << name << " go get more gas" << endl;
          }
       }
       
       // If it rained exactly .5 inches, write C++ programs
       
       else
       {
          cout << name << " write c++ programs" << endl;
       }
       
    }
    
    // Goodbye Message
    
    cout << "NOW GIT!!! YOU LAZY BUM!!!" << endl
         << "Thanks for using Job Assigner!!!" << endl;
    
    return 0;
}






