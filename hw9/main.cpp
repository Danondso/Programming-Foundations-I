#include "course.h"
using namespace std;

int main()
{
   // Testing Student class
   cout << "Testing Student class\n";
   Student student;
   student.Set(1111, "Joe", 2.5);
   float gpa2 = 0.0;
   student.SetGPA(2.7);

   gpa2 = student.GetGPA();
   cout << gpa2 << endl;
   student.Print();

   // Testing Course class
   cout << "Testing Course class\n";
   Course course;
   course.Read("csce2004.txt");
   course.Print();
   course.AverageGPA();
   course.IncreaseGPA();
   course.Print();
   course.Write("newcsce2004.txt");
   return 0;
}
