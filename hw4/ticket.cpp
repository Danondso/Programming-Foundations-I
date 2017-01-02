//---------------------------------------------------------------------------
// Program:  prog4.cpp 
// Purpose:  This program simulates a ticket office for sporting events
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

const char CASH = 'C';
const char CREDIT = 'D';
const char NOSEBLEED = 'N';
const char BOX_SEAT = 'B';
const char FIFTY_YARD_LINE = 'F';
const char STUDENT_SECTION = 'S';
const float NOSEBLEED_PRICE = 43.42;
const float BOX_SEAT_PRICE = 353.85;
const float FIFTY_YARD_LINE_PRICE = 94.05;
const float STUDENT_SECTION_PRICE = 19.99;

//---------------------------------------------------------------
// Function: ConfirmChoice
// Purpose:  Confirms the users ticket purchase before processing payment
// Parameters:  TicketType - The type of ticket selected
// Returns:  true if the user confirms the selection, false otherwise
//--------------------------------------------------------------
bool ConfirmChoice(const char TicketType)
{
   char Choice;
   bool Confirmed;

   // Print out their selection
   cout << "\nYou have chosen to purchase ";
   cout << fixed << setprecision(2);
   switch (TicketType)
   {
   case NOSEBLEED:
      cout << "Nosebleed ticket(s) at a price of $";
      cout << NOSEBLEED_PRICE << ".\n";
      break;
   case BOX_SEAT:
      cout << "Box Seat ticket(s) at a price of $";
      cout << BOX_SEAT_PRICE << ".\n";
      break;
   case FIFTY_YARD_LINE:
      cout << "Ticket(s) on the 50 yard line at a price of $";
      cout << FIFTY_YARD_LINE_PRICE << ".\n";
      break;
   case STUDENT_SECTION:
      cout << "Ticket(s) in the Student Section at a price of $";
      cout << STUDENT_SECTION_PRICE << ".\n";
      break;
   }

   // Confirm the selection
   cout << "Do you wish to confirm your purchase? Enter Y or N: ";
   cin >> Choice;
   Choice = toupper(Choice);
   while (Choice != 'Y' && Choice != 'N')
   {
      cout << "Invalid selection.  Please enter either Y or N: ";
      cin >> Choice;
      Choice = toupper(Choice);
   }
   Confirmed = (Choice == 'Y');

   // Check confirmation        
   if (Confirmed)
      cout << "You have confirmed your choice.\n" << endl;
   else
      cout << "You not confirmed your choice.\n" << endl;
   return (Confirmed);
}

//-------------------------------------------
// Function: CalculateChange
// Purpose:  To output the change due
// Parameters:  ChangeDue - The amount of change needed 
// Returns:  Nothing
//-------------------------------------------
void CalculateChange(const float ChangeDue)
{
   int Change = 0;
   int Dollars = 0;
   int Quarters = 0;
   int Dimes = 0;
   int Nickels = 0;
   int Pennies = 0;

   // Compute change  
   Change = ChangeDue * 100;
   Dollars = Change / 100;
   Change = Change % 100;
   Quarters = Change / 25;
   Change = Change % 25;
   Dimes = Change / 10;
   Change = Change % 10;
   Nickels = Change / 5;
   Pennies = Change % 5;

   // Print out change
   cout << "Your change is \n\t";
   cout << Dollars << " Dollars\n\t";
   cout << Quarters << " Quarters\n\t";
   cout << Dimes << " Dimes\n\t";
   cout << Nickels << " Nickels\n\t";
   cout << Pennies << " Pennies\n";
}

//---------------------------------------------------------------------------
// Function: CalculateCost
// Purpose:  Calculate the cost of the ticket purchase(s) (num_tickets * price_per_ticket)
// Parameters: PricePerTicket  - Ticket price based on the type of ticket
// Returns:  The cost of purchasing the chosen number of tickets 
//---------------------------------------------------------------------------
float CalculateCost(const float PricePerTicket)
{
   int TicketCount;
   float Cost;

   cout << "How many tickets would you like? Please enter a positive integer value: ";
   cin >> TicketCount;
   while (TicketCount < 0)
   {
      cout << "Invalid entry.  Please re-enter: ";
      cin >> TicketCount;
   }

   Cost = PricePerTicket * TicketCount;
   cout << "Your bill is: $" << fixed << setprecision(2) << Cost << endl;
   return Cost;
}

//---------------------------------------------------------------------------
// Function: GetPaymentType
// Purpose:  Ask the user how they want to pay, cash or credit
// Parameters: None
// Returns:  Value is CREDIT or CASH (global character constants)  
//---------------------------------------------------------------------------
char GetPaymentType()
{
   char Choice;

   // Print the main menu describing the ticket payment types 
   cout << "+-------------------------------------------------------+\n";
   cout << "+       Welcome to our Ticket Office                    +\n";
   cout << "+-------------------------------------------------------+\n";
   cout << endl << endl;

   // Cash or credit card (in upper case)
   cout << "How would you like to pay?\n";
   cout << "Enter C for cash or D for credit card: ";
   cin >> Choice;
   Choice = toupper(Choice);
   while (Choice != CASH && Choice != CREDIT)
   {
      cout << "Invalid choice.  Please enter C for cash or D for credit card: ";
      cin >> Choice;
      Choice = toupper(Choice);
   }
   return Choice;
}

//---------------------------------------------------------------------------
// Function: GetTicketType
// Purpose:  Get the customer's choice between 4 types of tickets
// Parameters: Choice - Set to the user's choice
// Returns:  Nothing
//---------------------------------------------------------------------------
void GetTicketType(char &Choice)
{
   // Ask the customer what type of ticket s/he prefers to buy 
   cout << "\nWhat type of ticket would you like?\n";
   cout << "\t" << NOSEBLEED << " for Nosebleed Section, Price = $";
   cout << NOSEBLEED_PRICE << endl;
   cout << "\t" << BOX_SEAT << " for Box Seats, Price = $";
   cout << BOX_SEAT_PRICE << endl;
   cout << "\t" << FIFTY_YARD_LINE << " for Seats on the Fifty Yard Line, Price = $";
   cout << FIFTY_YARD_LINE_PRICE << endl;
   cout << "\t" << STUDENT_SECTION << " for Student Section, Price = $";
   cout << STUDENT_SECTION_PRICE << endl;

   // Get ticket choice (in upper case)
   cout << "Enter choice: ";
   cin >> Choice;
   Choice = toupper(Choice);	
   while (Choice != NOSEBLEED && Choice != BOX_SEAT && 
          Choice != FIFTY_YARD_LINE && Choice != STUDENT_SECTION)
   {
      cout << "Invalid choice.  Please re-enter: ";
      cin >> Choice;
      Choice = toupper(Choice);
   }
}

//---------------------------------------------------------------------------
// Function: PayWithCash
// Purpose:  Handles payment by cash.  Asks the user for the money until
//           they enter enough, then updates the ChangeDue parameter
// Parameters: Cost - The amount due for the purchase
//             ChangeDue - The amount of change due to customer
// Returns:  Nothing
//---------------------------------------------------------------------------
void PayWithCash(const float Cost, float &ChangeDue)
{
   float CashOffered;

   // Pay in cash
   cout << "Please enter enough cash.  Your bill is $" << Cost << ": $ ";
   cin >> CashOffered;

   // Check sufficiency
   while (CashOffered < Cost)
   {
      cout << "That is not enough to pay for your purchase!\n"
	 << " Please enter at least $" << Cost << ": ";
      cin >> CashOffered;
   }

   // Calculate change
   ChangeDue = CashOffered - Cost;
}

//---------------------------------------------------------------------------
// Function: PayWithCredit
// Purpose:  Handles payment by credit.  Basically, just prints a statement
//           telling them that their card will be charged.
// Parameters: const float Cost - the amount due for the purchase
// Returns:  Nothing
//---------------------------------------------------------------------------
void PayWithCredit(const float Cost)
{
   cout << "Your credit card will be billed for $" << Cost << ".\n";
}

//---------------------------------------------------------------------------
// Function: main
// Purpose:  This is the main program that calls functions above.
// Parameters: None
// Returns:  Nothing
//---------------------------------------------------------------------------
int main()
{
   // Declarations 
   char TChoice;		// Ticket type: Nosebleed, box seats etc.. 
   char PChoice;		// Payment choice: cash or credit card
   bool Confirmed;		// Did the user confirm the selection
   float Cost;			// The cost of the ticket puchased
   float ChangeDue;		// The amount of change owed (for cash purchases)

   // Print your name and UAID
	cout << "Name: Dublin Anondson\n";
	cout << "ID: 010588684\n";
   // Get the choice of payment type
     PChoice = GetPaymentType ();  
   // Get the choice of ticket type
     void GetTicketType ();
   // Confirm the selection
    bool ConfirmChoice (char &Choice); 
   // If they confirm the purchase

      // Call functions to figure out the price of ticket purchase(s) 

      // Be sure to use the name constants

      // Handle the paymentd

      // Say goodbye 

   // Else

      // Cancel the purchase 

   return 0;
}
