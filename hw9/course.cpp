#include "course.h"
using namespace std;

Course::Course()
{
   num_students = 0;
}

Course::Course(const Course & course)
{
   num_students = course.num_students;
   for (int index = 0; index < num_students; index++)
      students[index] = course.students[index];
}

Course::~Course()
{
}

void Course::Print() const 
{
   for (int index = 0; index < num_students; index++)
      students[index].Print();
}





bool People::Read(ifstream & input)
{
  
  if(input << firstname << lastname << birth << death)
  {
  return getline (input, contribution);
  }
}








// For People class
bool People::Read(const string filename)
{
   // Open input file
   ifstream din;
   din.open(filename.c_str());
   if (din.fail())
   {
      cerr << "Could not open file: " << filename << endl;
      return false;
   }

   // Read student data
   num_Programmers = 0;
   while ((num_Programmers < Programmers) && 
      Programmers[num_Programmers].Read(din))
      num_students++;
   din.close();
   return num_Programmers > 0;
}

void Course::AverageGPA()
{
   float Sum = 0;
   float Mean = 0;


 for(int i =0; i < num_students; i++)
{

   Sum = Sum + students[i].GetGPA();


  }

    Mean = (Sum / num_students);

     cout << "Mean Gpa = " << Mean << endl;

}

 void Course::IncreaseGPA(float inc)
{
 float GPA = 0.0;

  for(int i = 0; i < num_students; i++)
 {
   
   GPA = students[i].GetGPA() + inc;
   students[i].SetGPA(GPA);
 }	
   
}

void Course::Write(const string filename)
{
   // Open outnput file
   ofstream dout;
   dout.open(filename.c_str());

   for(int i = 0; i < num_students; i++)
      {
      students[i].Write(dout);
      }  
   dout.close();
   
}

