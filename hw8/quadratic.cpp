#include "quadratic.h"
#include <iostream>
#include <cmath>
using namespace std;
//constructor function
 quadratic::quadratic()
 {
    A = 0;
    B = 0;
    C = 0;
 }
//copy of constructor  
  quadratic::quadratic(const quadratic &d)
  {
    A = d.A;
    B = d.B;
    C = d.C;
  } 
//destructor function   
 quadratic::~quadratic()
  {
  }
//set the values for quad and quad2
  void quadratic::setVal(const float a, const float b, const float c)
   {
    //sets the private variables to the hard-coded ones in main
     A = a;
     B = b;
     C = c;
   }
//set the values for quad and quad2
  void quadratic::getVal(float &a,float &b, float &c)
  {
   //gets them for use in the functions
     a = A;
     b = B;
     c = C;
  }

  void quadratic::Print()
   {
   
    // Prints values to a quadratic equation template    
     cout << A << "x^2" << " + " << B << "x" << " + " << C << endl;
    
   }

//adds quad and quad2's values together
  void quadratic::add(const quadratic &d)
  {
    A =  A + d.A;
    B =  B + d.B;
    C =  C + d.C;
    Print(); //prints out product (same in sub function)
  }
//subtracts the values of quad and quad2
   void quadratic::subtract(const quadratic &d)
     {
       A = A - d.A;
       B = B - d.B;
       C = C - d.C;
       Print();

     }
//takes the derivative of quad
    void quadratic::derivative()
      {
       B = A*2;
       C = B;
       A = 0;
       cout << "Derivative is " << endl;
       cout << B << "x" << " + " << C << endl;
     }   
// evaluates function for x
    float quadratic::evaluate(const float x)
     {
       float y;
            
         y  = A*x*x + B*x + C;
       cout << "X is " << x << endl; 
     // y used as a value holder to make the equation work
      return y;  
     }
//uses the quadratic formula to find the zeros of the equations
   void quadratic::zeros(float &x1, float &x2)
    {
    
      x1 = (-B + sqrt(B*B - 4*A*C))/(2 * A);
    
      x2 = (-B - sqrt(B*B - 4*A*C))/(2 * A);
    
     cout << "Zeros are " << x1 << endl;
     cout << x2 << endl;
      
    }




