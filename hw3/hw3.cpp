//------------------------------
// Program to print out ASCII shapes
// Author: Dublin Anondson
// Date: 9/22/2012
//------------------------------


    #include <iostream>
    using namespace std;
     int main ()
  {
       
     //Variables
       int size = 0;
       int row = size;
       int column = size;        
       cout << "Enter a number between 5 and 20 for the size.\n";
       cin >> size;
     
     // Error check for size

      while((size < 5) || (size > 20))
      {
          cout << "You've entered an incorrect choice." << endl;
          cout << "Enter a number between 5 and 20 for the size.\n ";
          cin >> size;
      }

        
     // ASCII Box       
     
       for (row  = 1; row <= size;row = row++)
       {
         for (column = 1; column <= size; column = column++)      
        
          cout << "*" << " ";
          cout << endl;
       }
     
     
     // ASCII hollow box       
    
       for (column  = 1; column <= size; column++)      
       { 
       cout << endl;     
     
         for (row = 1; row <=size; row++)
         {    
           if(column > 1 && column < size && row > 1 && row < size)
     
            cout << "  ";
            else
            cout << "* ";
         }
        }     
         cout << endl;
      
    

     //ASCII Triangle

      for (row = 1; row <=size; row++)
      {
        for(column = 1; column <= row; column++)

	cout << "* ";
	cout << endl;
      }

    
     //ASCII X
   
      for (row = 1; row <= size; row++)
      {
        cout << endl;
       
       for (column = 1; column <= size; column++)
       {
         if(row==column || row + column == size + 1)
     
          cout << "* ";
          else 
          cout << "  ";
       }
        cout << endl;
     }
 
 

     //ASCII Z        
     
      for (row = 1; row <= size; row++)
      {
        for(column = 1; column <= size; column++)
        {
          if (row == 1 || row + column == size + 1 || row == size)
           
            cout << "* ";
            else
            cout << "  ";
        }
         cout << endl;
      }
       cout << endl; 
   
     return 0;
  }
