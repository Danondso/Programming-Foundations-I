#include <iostream>
#include "quadratic.h"
using namespace std;



   int main ()
    {
    // Variables used for hard coding
      float a;
      float b;
      float c;
      float x1 = 0;
      float x2 = 0;         
   //first set of quad values
      quadratic quad;
   // second set of quad values 
      quadratic quad2;      
  
  //values set for quad 
      quad.setVal(4.2, 2.7, 6.9);
  //values set for quad2    
      quad2.setVal(1.4, 11.2, -2.7);
  // Prints out the set value for quad
     quad.Print();
  //values obtained for quad
      quad.getVal(a, b, c);
  //values obtained for quad2
      quad2.getVal(a, b, c);
 
  //evalated the quadratic function with respect to x
      quad.evaluate(5.2);
 
  //values for quad and quad 2 added together
      quad.add(quad2);   
 
  //values for quad and quad 2 subtracted
      quad.subtract(quad2);
 
  //derivative of quad's values
      quad.derivative();
 
  //zeros taken for quad's values
      quad2.zeros(x1, x2);      
        
    
    }
