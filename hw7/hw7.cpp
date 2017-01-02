//-----------------------------------------------------
// Project 7 German Dictionary Translation
// Author: Dublin Anondson
// Date: 11/3/2012
//-----------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// open file 
 void Open(string English[], string German[], char s, int c)
  {
        // variables to open
        ifstream Din;     
        string into;
    // file open     
        Din.open("english_german.txt");
        Din >> into;
   // loop to fill 
      while (!Din.eof())
       {

        // Read a word from the file stream
         Din >> English[c];

         Din.get(s);
          // Read the rest of the line from the file stream
            getline (Din, German[c]);
      // count to the next line
         c++;
      
       }
        // close file
         Din.close();

  }


    // Function to search for an English word.

     void TranslateEng(string eng, string English[], string German[])
           {
             // error check to make sure word is in the dictionary
              bool findme = false;
              // loop to search for what the user inputted
             for(int count = 0; count < 250; count++)
               {
                // checks to see if the word is in the array
                if(eng == English[count])
                  {
                    findme = true;
                 // cout the proper translation
                    cout << "Your German word is " <<  German[count] << endl;
                  }

                }
                  // when the find can't work, cout the error 
                  if (findme == false)
                   {
                    cout << "Your word is not contained in the Dictionary." << endl; 
                   }

            }



      // Function to search for a German word.
     // comments for the above function apply in the same places.
         void TranslateGer(string germ, string English[], string German[])
             {
               bool findme = false;
                for(int count = 0; count < 250; count ++)
               {
                 
                 if(germ == German[count])
                  {
                   findme = true; 
                   cout << "Your English word is " << English[count] << endl;
                  }

                }
                   if (findme == false)
                    {
                    cout << "Your word is not contained in the Dictionary." << endl;
                    }

              }

// Main Program
  int main()
  {
   // Variables for strings
     string English [250];
     string German [250];
     int c = 0;
     char s;
     string eng;
     string germ;
     string germ1;
     string germ2;
     int choice = 0;
    // opens file to read into array
       Open(English, German, s, c);

    // Menu out
      cout << "Welcome to the Anondson Patented Translator!" << endl;
      cout << "Please Specify the translator." << endl;
       cout << "1. English - German" << endl;
       cout << "2. German - English" << endl;
       
        cin >> choice;
    
     // switch statement to choose the proper dictionary
      switch(choice)
     {

      case 1:
      // english to german
      cout << "Enter an English word." << endl;
       cin >> eng;
     //function call for translator
       TranslateEng (eng, English, German);

         break;

      case 2:
      // German to english
      cout << "Enter a German word." << endl;
       cin >> germ1 >> germ2;
         germ = germ1 + " " + germ2;
     
        TranslateGer(germ, English, German);

         break;

          default:
           cout << "That Dictionary is not contained within the program." << endl;
   
      }
 
      return 0;
  }
