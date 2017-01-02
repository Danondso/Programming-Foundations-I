#include <string>
#include <fstream>
#include <iostream>
#include "student.h"
using namespace std;

class Course
{
public: 
   Course();
   Course(const Course & course);
   ~Course();

   void Print() const;
   bool Read(const string filename);
   void AverageGPA();
   void IncreaseGPA(float inc = 0.5);
   void Write(const string filename);

private: 
   static const int MAX_STUDENTS = 100;
   Student students[MAX_STUDENTS];
   int num_students;
};
