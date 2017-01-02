#include "student.h"
using namespace std;

Person::Person()
{
   Uaid = -1;
   Name = "";
   Gpa = -1.0;
}

Person::Person(const Person & person)
{
   Uaid = student.Uaid;
   Name = student.Name;
   Gpa = student.Gpa;
}

Person::~Person()
{
}

void Student::Set(const int uaid, const string name, const float gpa)
{
   Uaid = uaid;
   Name = name;
   Gpa = gpa;
}

void Student::Get(int &uaid, string & name, float &gpa) const
{
   uaid = Uaid;
   name = Name;
   gpa = Gpa;
}

void Student::Print() const
{
   cout << Uaid << " " << Name << " " << Gpa << endl;
}

bool Student::Read(ifstream & input)
{
   return (input >> Uaid >> Name >> Gpa);
}

float Student::GetGPA()
{
  return  Gpa;
}

float Student::SetGPA(float GPA)
{
if(GPA < 0.0)
{
Gpa = 0.0;
}
else if(GPA > 4.0)
{
Gpa = 4.0;
}
else 
{
Gpa = GPA;
}
return Gpa;

}
void Student::Write(ofstream & output)
{

  output << Uaid << " " << Name << " " << Gpa << endl;

}
  
