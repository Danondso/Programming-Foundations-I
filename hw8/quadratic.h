// Implement quadratic file
  #include <iostream>
  
 class quadratic
  {
 
    //Methods available to the user
  
  public:
//info on functions is within the quadratic.cpp file  
  quadratic();
  quadratic(const quadratic &d);
  ~quadratic();
  void setVal(const float a, const float b, const float c);
  void getVal(float &a, float &b, float &c);
  void Print();
  float evaluate(const float x);
  void add(const quadratic &d);
  void subtract(const quadratic &d);
  void derivative(); 
  void zeros (float &x1, float &x2);

//private variables used in functions    
  private:
  
  float A;  
  float B;
  float C;  
 
  };
