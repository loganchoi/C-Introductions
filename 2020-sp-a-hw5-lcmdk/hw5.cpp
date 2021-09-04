//Programmer: Logan Choi


#include <iostream>
using namespace std;


//Constants
const short NUM_OF_LOCKERS = 101;   //just sets number of elements in the array
const short MAX_TEXTBOOKS = 4500;   //Max amount of books in locker
const float MAX_MONEY = 150;  //max amount of money
const short ADD_LOCKER = 1;   //option 1
const short PRINT_LOCKER = 2;  //option 2
const short ALL_USED_LOCK = 3; //option 3
const short DELETE_LOCKER = 4; //option 4
const short QUIT = 5;  //option 5

//Struct for each locker's characteristics
struct locker
{
   string m_name;     //locker's owner
   float m_money;     //how much is in that specific locker
   short m_books;     //how many books is in that locker
   bool m_occupied;   //if the locker is occupied or not.
};

int main()
{
    //Variables
    short menu_input;             //user inputs menu option
    string student;               //user name
    short locker_input;           //user input for which locker number
    locker hall[NUM_OF_LOCKERS];  //array of lockers in hallway.
    float user_money;            //money input
    float total_money = 0;       //total amount of money in occupied lockers
    short user_books;             //books input
    short total_books = 0;         //total amount of books in occupied lockers.
    short used_lockers = 0;
    
    //initializes every locker to be emptied out immediately.
    for (int i=0; i<NUM_OF_LOCKERS; i++)
    {
        hall[i].m_money = 0;
        hall[i].m_books = 0;
        hall[i].m_occupied = false;
    }
    
    //Helps the output look clean
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    
    //Welcome message
    cout << "WELCOME TO LOCKER ASSIGNER!!!" << endl;
    
    //Do while loop to continously prompt menu until user inputs Quit (5)
    do
    {
       //Print outs menu, total lockers used, and average Books
       //and prompt for input
       cout << "\nLOCKER MENU"<< endl 
         << "-----------" << endl
         << "1. Add a locker." << endl
         << "2. Print contents of a locker." << endl
         << "3. Output all lockers' contents." << endl
         << "4. Delete a locker." << endl
         << "5. Quit." << endl
         << "\nThere are a total of " << used_lockers << " used lockers."
         << endl  << "The average books per locker is "
         << (total_books == 0 ? 0 : static_cast<float>( total_books)/used_lockers) 
         << "." << endl << "Choice: ";

       cin >> menu_input;
       
       //Switch case depending on user input
       switch (menu_input)
       {
          //Option 1
          case ADD_LOCKER:
            
            //Do while loop to prompt for which locker the user wants. 
            //Prints error message if needed.
            do
            {
               cout << "\nPick a locker number to be occupied. (101-201)"
                    <<endl;
               cin >> locker_input;
               locker_input -= NUM_OF_LOCKERS;
               if (locker_input < 0)
                  cout << "\nERROR: Please pick locker number within range.\n";
               else if (locker_input >= NUM_OF_LOCKERS)
                  cout << "\nERROR: Please pick locker number within range.\n";
            }while (!(locker_input >= 0 && locker_input < NUM_OF_LOCKERS));
            
            //If locker is occupied output message, otherwise get user inputs.
            if (hall[locker_input].m_occupied == true)
               cout << "\nThis locker is already being used." << endl;
            
            else
            {
               used_lockers ++;   //increments total lockers used
               hall[locker_input].m_occupied = true;  //locker is now occupied
               
               //Prompt for name, and add it to locker's contents
               cout << "\nWhat is your last name? NO WHITESPACE" << endl;
               cin >> student;
               hall[locker_input].m_name = student;
               
               //Prompt for books in locker within range,
               // and add it to locker's contents.
               //Prints error message if needed.
               do
               {
                  cout << "\nHow many books do you have? (0-4500)" << endl;
                  cin >> user_books;
                  if (user_books < 0)
                     cout << "\nERROR: How do you have negative books? "
                          << " Start reading more." << endl;
                  else if (user_books > MAX_TEXTBOOKS)
                     cout << "\nERROR: Take away some books. " 
                          << "you can't fit all that in one locker." << endl;
               }while (!(user_books >= 0 && user_books <= MAX_TEXTBOOKS));
               hall[locker_input].m_books = user_books;
               
               total_books += user_books; //adds to total amount of books
            
               //Prompt for POSITIVE amount of money in locker
               //prints error message if needed.
               do
               {
                  cout << "\nHow much money do you want to put in your locker?"
                       << endl;
                  cin >> user_money;
                  if (user_money < 0)
                     cout << "\nERROR: How do you have debt in your locker?"
                          << endl;
               }while (!(user_money >=0));
               hall[locker_input].m_money = user_money;
               total_money += user_money; //adds to total amount of money 
            
               //If total money is greater than 150, Willie robs them, and all
               //occupied lockers now have $0 through a for loop.
               if (total_money > MAX_MONEY)
               {
                  cout << "\nTIME TO STEAL THE KIDS' LUNCH MONEY!!!" << endl;
                  for (int i = 0; i < NUM_OF_LOCKERS; i++)
                  {
                     total_money = 0; //resets total money
                     if (hall[i].m_occupied == true) 
                       hall[i].m_money = 0;
                  }
               }
            }
            break;
          
          //Option 2
          case PRINT_LOCKER:
            
            //do while loop to prompt for locker number to view.
            do
            {
               cout << "\nPick a locker number to view its contents. (101-201)" 
                    <<endl;
               cin >> locker_input;
               locker_input -= NUM_OF_LOCKERS;
               if (locker_input < 0)
                  cout << "\nERROR: Please pick locker number within range."
                       << endl;
               else if (locker_input >= NUM_OF_LOCKERS)
                  cout << "\nERROR: Please pick locker number within range." 
                       << endl;
            }while (!(locker_input >= 0 && locker_input < NUM_OF_LOCKERS));
            
            //If locker is not occupied, outputs message, and goes back to menu
            //Otherwise it prints out the locker's characteristics
            if (hall[locker_input].m_occupied == false)
              cout << "\nThis locker is already emptied and not being used.\n";
            else
              cout << "\nLocker: " << locker_input + NUM_OF_LOCKERS << endl
                   << "Occupied by: " << hall[locker_input].m_name << endl
                   << "Number of Books: " << hall[locker_input].m_books << endl
                   << "Moolah: $" << hall[locker_input].m_money << endl;
            break;
          
          //Option 3
          case ALL_USED_LOCK:
          
            //print out all occupied lockers
            cout << "\nOCCUPIED LOCKERS\n" 
                 << "--------------------\n" << endl;
            for (int i = 0; i < NUM_OF_LOCKERS; i++)
            {
               if (hall[i].m_occupied == true) 
               {
                  cout << i+NUM_OF_LOCKERS
                       << "\t" << hall[i].m_name
                       << "\t" << hall[i].m_books 
                       << (hall[i].m_books == 1 ?" text": " texts")
                       << "\t$" << hall[i].m_money
                       << endl;
               }
            }
            break;
          
          //Option 4
          case DELETE_LOCKER:
            
            //Do while loop to prompt for which locker the user wants.
            do
            {
               cout << "\nPick a locker number to be emptied (101-201)" 
                    <<endl;
               cin >> locker_input;
               locker_input -= NUM_OF_LOCKERS;
               if (locker_input < 0)
                  cout << "\nERROR: Please pick locker number within range."
                       << endl;
               else if (locker_input >= NUM_OF_LOCKERS)
                  cout << "\nERROR: Please pick locker number within range." 
                       << endl;
            }while (!(locker_input >= 0 && locker_input < NUM_OF_LOCKERS));
            
            //If the locker is not occupied, print out message, otherwise clear 
            //the locker's characteristics.
            if (hall[locker_input].m_occupied == true)
            {
               total_money -= hall[locker_input].m_money; //subtract money
               total_books -= hall[locker_input].m_books; //subtract books
               hall[locker_input].m_occupied = false;
               hall[locker_input].m_money = 0;
               hall[locker_input].m_books = 0;
               hall[locker_input].m_name = "";
               used_lockers --; //decrements total occupied lockers.
            }
            else
              cout << "\nThis locker is already emptied." << endl;
            break;
          
          //Option 5
          case QUIT:
            //Goodbye message, and quits program
            cout << "\nThanks for using LOCKER ASSIGNER!!!" << endl
                 << "Have a good day!!!" << endl;
            break;
          
          //If user inputs an invalid option number,
          // print out this error message.
          default:
            cout << "\nERROR: Pick a valid option number." << endl;
       }
        
    } while (menu_input != QUIT);
    return 0;
}








