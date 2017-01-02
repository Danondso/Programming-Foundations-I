//---------------------------------------------------------------------------
// Program:  hw5.cpp 
// Purpose:  This is an implementation of a dice game. When the game starts, 
//           the player has 1000 points.
//           The player starts by wagering a number of points.
//           Then the player rolls a pair of dice. 
//           If the total of the face values of the dice add up to more than
//           seven or the face values are equal, then the player wins. 
//           Otherwise the player loses. 
//           A winning roll will add the wager to the total points.
//           A losing roll causes the player to lose the wager. 
//
//   Author of Functions : Dublin Anondson
//---------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std; 

//---------------------------------------------------------------------------
// Name: RollDice
// Parameters: Die1 and Die2 wiht ampersands
// Returns: Die1 and Die2 rolls
// Purpose: Randomizes the dice roll to get better results
//---------------------------------------------------------------------------
void RollDice (int &Die1, int &Die2)
   {
    // Variables
     Die1 = 0;
     Die2 = 0;
     int total = 0;
    // random functions for die roll
      srand (time(0));

       Die1 = ((rand() % 6) + 1); 
       Die2 = ((rand() % 6) + 1);
     // dice result output
      cout << "Die 1: " << Die1 << endl;
      cout << "Die 2: " << Die2 << endl;
    // total for the dice
      total = Die1 + Die2;

      cout << "Your die total is: " << total << endl;

}


//---------------------------------------------------------------------------
// Name:  CheckWinner
// Parameters: die1 and die2 to check the resulting amount from the die rolls
// Returns: winner as a bool
// Purpose: to check to see the if the die rolls  = a winning requirement
//---------------------------------------------------------------------------
  bool CheckWinner (int Die1, int Die2)
 {
     //variables
     char Choice;   
     bool Winner = false;
     //if statement to check if the player won
     if(((Die1 + Die2) > 7) || (Die1 == Die2))
  {
  // cout the result for winning
   cout << "WINNER!" << endl;
   cout << "Play again?" << endl;
    cin >> Choice;
  }
   // cout the result for losing
   else
     cout << "You Lost" << endl;
   return Winner;
 }
 



//---------------------------------------------------------------------------
// Name: PrintDice
// Parameters: none
// Returns: void
// Purpose: Output dice pattern
//---------------------------------------------------------------------------
void PrintDice()
{
	cout << "        .-------.    ______      \n"
         << "       /   o   /|   /\\     \\   \n"
         << "      /_______/o|  /o \\  o  \\  \n"
         << "      | o     | | /   o\\_____\\ \n"
         << "      |   o   |o/ \\o   /o    /  \n"
         << "      |     o |/   \\ o/  o  /   \n"
         << "      '-------'     \\/____o/    \n\n\n";
}

//---------------------------------------------------------------------------
// Name: ShowHomeScreen
// Parameters: TotalPoints
// Returns: void
// Purpose: introduce the game and show the players starting points	
//---------------------------------------------------------------------------
 void ShowHomeScreen(int TotalPoints)
 {
   // call print dice to introduce the game
   PrintDice();
   // cout your total amount of points
    cout << "Your total points are: " << TotalPoints << endl;

 }


//---------------------------------------------------------------------------
// Name: GetWager
// Parameters: TotalPoints
// Returns: Wager
// Purpose: get the user inputted amount for wager and stores it for the game
//---------------------------------------------------------------------------
  int GetWager(int TotalPoints)
  {
    int Wager = 0;
   // loop to check if the wagered amount is within the parameters
   do
   {
     // user inputted wager
      cout <<  "Please enter your wager.\n";
      cin >> Wager;
    // tells user amount wagered
       cout << "You have wagered " << Wager << endl;
     // if to send out proper message after wager is made
        if(Wager <= TotalPoints)
         cout << "You have sufficient credits." << endl;
     
         else
       
          cout << "You only have " << TotalPoints << " credits. Please try again." << endl;
    }
      // loop to check wagered amount  
       while(Wager > TotalPoints);
  
   return Wager;

  }


//---------------------------------------------------------------------------
// Name: ConfirmContinue
// Parameters: TotalPoints
// Returns: ContinueGame
// Purpose: checks to see if the player wants to continue and checks credit amount
//---------------------------------------------------------------------------

  bool ConfirmContinue(int TotalPoints)
  {
   // no declaration of choice here threw an error  
   char Choice;
   bool ContinueGame = false;
   // if to check points to be able to continue
   if(TotalPoints > 0)
   {

      cout << "Continue?\n";
      cout << "Y for yes, N for no.\n";

      cin >> Choice;
 
     Choice = toupper(Choice);
    // check to see if proper char is entered
      while (Choice != 'Y' && Choice != 'N')
       {
      
        cout << "Invalid choice.  Please enter Y for yes or N for no: ";
        cin >> Choice;
        Choice = toupper(Choice);
       }
      if (Choice == 'Y')
          ContinueGame = true;
    }
    // not enough credits else
    else
    {
     cout << "You have insufficient funds to be able to continue." << endl;
     ContinueGame = false;
     }
     return ContinueGame;
    
}

//---------------------------------------------------------------------------
// Function calls in main have been commented out so that this code will 
// compile. It is you task to write these functions. Once a function
// has been written, you can uncomment its function call to see if the 
// function works. Do not change the function calls.
//---------------------------------------------------------------------------
int main () 
{ 
	// Declare Variables
	int TotalPoints = 1000;
	int Wager = 0;
	int Die1 = 0;
	int Die2 = 0;
	bool Confirm;
	bool Winner;

	// Seed the random number generator
	srand(time(0));

	// Show home screen
	ShowHomeScreen(TotalPoints);
	
	// Each loop is one roll of the dice
	do {
		Wager = GetWager(TotalPoints); // Get the amount of points wagered on this roll
		RollDice(Die1, Die2); // Roll the dice
		
		Winner = CheckWinner(Die1, Die2); // Determine if the roll was a winning roll
		
		if (Winner == false)
			TotalPoints += Wager; // If the roll was a winning roll, add the wager to the total points
		else
			TotalPoints -=  Wager; // If the roll was not a winner, deduct the wager from the total points
		
		ShowHomeScreen(TotalPoints); // Show home screen
       
        // Make sure the player has sufficient points to continue
        // and ask if the player wants to roll again
        Confirm = ConfirmContinue(TotalPoints); 
		
	} while(Confirm);
	
	return 0; 
}
