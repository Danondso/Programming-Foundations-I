//------------------------------------ 
// Program for converting FFF to SI
// Author: Dublin Anondson
// Date: 8/31/12
//------------------------------------





   #include <iostream>  
   using namespace std;
   int main ()
{
   // Variable declarations
   float firkin = 0;
   float furlong = 0;
   float fortnight = 0;
   const float m = 201.168;
   const float Kg = 40.8233133;
   const float sec = 1290600;
   float Kilogram = 0;
   float Meter = 0;
   float Seconds = 0;
   float Furfort = 0; 
   float msec = 0;  
   float Nutter = 0;   
   // Question Prompt
   cout << "Enter a value for Firkin" << endl;
   cin >> firkin;
   cout << "Enter a value for Furlong" << endl;   
   cin >> furlong;
   cout << "Enter a value for Fortnight" << endl;
   cin >> fortnight;
   
   // Calculations
   Kilogram =  firkin * Kg;
   Meter =  furlong * m;
   Seconds = fortnight * sec;
   Furfort = furlong / fortnight;
   msec = (furlong * m) / (fortnight * sec);
   // Micro-Furlongs per Tera Fortnights
   Nutter = (furlong *0.000001)/ (fortnight * 1000000000000); 
   // Prefixes and numbers are from Wikipedia
   
   //Print Out
   cout << "Value for Kilogram is:" << Kilogram << endl;
   cout << "Value for Meter is:" << Meter << endl;
   cout << "Value for Seconds is:" << Seconds << endl; 
   cout << "Value for Furlongs per Fortnight is:" << Furfort << endl;
   cout << "Value for Furlongs per Fortnight SI conversion is:" << msec << endl;
   cout << "Value for Micro-Furlongs per Tera-Fortnights is:" << Nutter << endl;

  return 0;


}

