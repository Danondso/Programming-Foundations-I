//---------------------------------------------------------------------------
// Program:  hw6.cpp 
// Purpose:  This is an implementation of Conway's Game of Life. This is a 
//           zero player game that consists of a board (a grid) containing living 
//           cells and dead cells. At each step of the game, the board updates 
//           according to the following rules.
//
//           1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
//           2. Any live cell with two or three live neighbours lives on to the next generation.
//           3. Any live cell with more than three live neighbours dies, as if by overcrowding.
//           4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
//---------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
using namespace std;

// Global Variables
// Note: DO NOT EDIT THESE
const int SIZE = 20;		// Board size
const int STEPS = 20;		// Number of steps in the game
const int LIVE = 1;		// Integer for living cell
const int DEAD = 0;		// Integer for dead cell

//---------------------------------------------------------------------------
// Name: init_board
// Parameters: board - a 2D integer array, full - integer
// Returns: void
// Purpose: To fill the board with "full" percent LIVE cells
//          The rest of the cells are DEAD. 
// Note: DO NOT EDIT THIS FUNCTION!
//---------------------------------------------------------------------------
void init_board (int board[SIZE][SIZE], int full)
{
  // Init board
  for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
	{
	  // Generate random live cells
	  if (rand () % 100 < full)
	    board[i][j] = LIVE;
	  else
	    board[i][j] = DEAD;
	}
    }
}

//---------------------------------------------------------------------------
// Name: redraw_board
// Parameters: board - a 2D integer array
// Returns: void
// Purpose: Redraw the board to the console
// Note: DO NOT EDIT THIS FUNCTION!
//---------------------------------------------------------------------------
void redraw_board (int board[SIZE][SIZE], const int step)
{
  // Clear screen to redraw board
  system ("clear");
  cout << "\tConway's Game of Life " << step << "\n\n";

  // Draw top of board
  cout << "+";
  for (int i = 0; i < SIZE; i++)
    cout << "--";
  cout << "+\n";

  // Draw board
  for (int i = 0; i < SIZE; i++)
    {
      cout << "|";
      for (int j = 0; j < SIZE; j++)
	{
	  if (board[i][j] == LIVE)
	    cout << "* ";
	  else
	    cout << "  ";
	}
      cout << "|\n";
    }

  // Draw bottom of the board
  cout << "+";
  for (int i = 0; i < SIZE; i++)
    cout << "--";
  cout << "+\n";

  // Pause to make animation slower
  system ("sleep 0.2");
}
//-----------------------------------------
   bool on_board( const int row, const int col)
    {
     bool check = false;

      if((row < 0)||(row > 19)||(col < 0)||(col > 19))
       check = false;
       else
       check = true;

     return check;
    }
//-------------------------------------------------------------------------
//--------------------------------------------------------------------------
 void update_board (int board [SIZE][SIZE])
{ 

  // declare temp board
    int neighbors = 0;
    int temp_board [SIZE][SIZE];   
  
  // for loops used to run through entire board
  for(int row = 0; row < SIZE; row++)
  {  
   for (int col = 0; col < SIZE; col++)
  { 
   // neighbors initialized within loop to reset count neighbors
    neighbors = 0;
    // count neighbors within an exlcusive and as an error check
    
     if((on_board(row -1, col -1)) && (board[row -1][col -1] == LIVE))
      neighbors++;
    
     if((on_board(row -1, col)) && (board[row -1][col]  == LIVE))
      neighbors++;
    
     if((on_board(row -1, col +1)) &&(board[row -1][col +1] == LIVE))
      neighbors++;
    
     if((on_board(row, col -1)) && (board[row][col -1]  == LIVE))
      neighbors++;
    
     if((on_board(row, col +1)) && (board[row][col +1] == LIVE))
      neighbors++;
    
     if((on_board(row +1, col -1)) && (board[row +1][col -1] == LIVE))
      neighbors++;
    
     if((on_board( row +1, col)) && (board [row +1][col] == LIVE))
      neighbors++;
    
     if((on_board( row +1, col +1)) && (board [row +1][col +1]  == LIVE))
      neighbors++;
     
      // Rules for the game of life.
         if (board[row][col] == LIVE)
          { 
             if((neighbors == 2 || neighbors == 3))
              temp_board [row][col]  = LIVE;
               
               else 
               temp_board[row][col] = DEAD;
           }
            else 
             {
               if(neighbors == 3) 
               temp_board[row][col] = LIVE;
             
               else
               temp_board[row][col] = DEAD;
             }                         
                
   }      
 }

   // copy temp board board
   for(int row = 0; row < SIZE; row++)
    {  
     for (int col = 0; col < SIZE; col++)
      { 
       board[row][col] = temp_board[row][col];

      }
    }
 }

  // Add Beehive
 void add_beehive (int board[SIZE][SIZE], const int row, const int col)
{
  for (int row = 10;  row < 15; row++)
   {
    for (int col = 10; col < 16; col++)
    {
    if(board [row][col] != LIVE)
     {
     board [12][11] = LIVE;
     board [11][12] = LIVE;
     board [11][13] = LIVE;
     board [12][14] = LIVE;
     board [13][12] = LIVE;
     board [13][13] = LIVE;
     }
       else
       {
        board [row][col] = DEAD;
       }
     }
    }  
   }  

// Add Blinker
 void add_blinker (int board [SIZE][SIZE], int col, int row)
 {
  for (int row = 0; row < 3; row++)
   {
    for (int col = 15; col <18 ; col++)
     {
     if (board [row][col] != LIVE) 
      {
      board [0][16] = LIVE;
      board [1][16] = LIVE;
      board [2][16] = LIVE;
      }
       else
       {
        board [row][col] = DEAD; 
       }
   }
  }
 }

// Add spaceship thing
  void add_glider (int board [SIZE][SIZE],const int col,const int row)
 {
  for (int row = 0; row < 5; row ++)
   {
    for (int col = 0; col < 5; col ++)
     {
      if (board[row][col] != LIVE)
      {
      board [1][2] = LIVE;
      board [2][3] = LIVE;
      board [3][1] = LIVE;
      board [3][2] = LIVE;
      board [3][3] = LIVE;
      }
        else
        { 
         board [row][col] =DEAD;
        }
     }
   }
 }
// End Spaceship thing

//---------------------------------------------------------------------------
// Name: main
// Parameters: none
// Returns: int
// Purpose: Update and redraw the board step by step
// Note: This function is not finished
//---------------------------------------------------------------------------
int main ()
{
  //Variables
  int row = 0;
  int col = 0;




  // Seed the random number generator 
  srand (time (0));

  // Initialize game board
  int board[SIZE][SIZE];
  init_board (board, 10);


  // beehive call
    add_beehive (board,0,10);

   //add Blinker
     add_blinker (board, 0, 10);
  
  //Glider
   add_glider (board, 0, 10);

  redraw_board(board, 0);
  // Loop to play game of life
  for (int step = 1; step <= STEPS; step++)
    {
      // Update the board
     update_board (board); 
      // Redraw the game board
      redraw_board (board, step);
    }
  return 0;
}

