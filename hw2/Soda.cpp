//---------------------------------
// Programmable Soda machine
// Author: Dublin Anondson
// Date 9/14/12
//---------------------------------

#include <iostream>
using namespace std;
 
 int main ()
 {
  //Variable for machine
    int Choice = 0;
    int size = 0;
  //Initialization
    cout << "Welcome to the virtual soda machine!\n";   
    cout << "Enter a number for your soda.\n";
       cout << " 1. Coke\n";
       cout << " 2. Pepsi\n";
       cout << " 3. Mt. Dew \n";
       cout << " 4. Dr. Pepper\n";
    cin >> Choice;
    
    //Switch
    switch (Choice)
  {
    case 1:
  
    cout << "You have chosen Coke.\n";   
     cout << "Please select a size:\n"; 
      cout << "1. 20oz\n";
      cout << "2. 2L\n";
    cin >> size;
    if ( size == 1)
    cout << "Your total is $1.50.\n";
      else if ( size == 2)
    cout << "Your total is $1.75.\n";
      else if ( size >= 3)
    cout << "A number for that size doesn't exist.\n";
    break;
   
    case 2:
    
    cout << "You have chosen Pepsi.\n";
     cout << "Please select a size:\n"; 
      cout << "1. 20oz\n";
      cout << "2. 2L\n";
    cin >> size;
    if ( size == 1)
    cout << "Your total is $1.00.\n";
      else if ( size == 2)
    cout << "Your total is is $2.00.\n";
      else if ( size >= 3)
    cout << "A number for that size doesn't exist.\n";    
    break;

    case 3:

    cout << "You have chosen Mt. Dew.\n";
     cout << "Please select a size:\n"; 
       cout << "1. 20oz\n";
       cout << "2. 2L\n";
    cin >> size;
    if ( size == 1)
    cout << "Your total is $0.75.\n";
     else if ( size == 2)
    cout << "Your total is $1.90.\n";
     else if ( size >= 3)
    cout << "A number for that size doesn't exist.\n";    
    break;    

    case 4:

    cout << "You have chosen Dr. Pepper.\n";
     cout << "Please select a size:\n"; 
       cout << "1. 20oz\n";
       cout << "2. 2L\n";
    cin >> size;
    if ( size == 1)
    cout << "Your total is $1.25.\n";
     else if ( size == 2)
    cout << "Your total is $2.25.\n";
     else if ( size >= 3)
    cout << "A number for that size doesn't exist.\n";   
    break;
    
    default:
    
    cout << "That number is not on the menu.\n";
    break;
 
  }
  return 0;
 }
