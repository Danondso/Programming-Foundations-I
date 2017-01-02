#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Person
{
public:
   Person();
   Person(const Person & person);
   ~Person();

   void Set(string first_name, string last_name, int birth_year, int death_year, string contribution);
   void Get(string first_name, string last_name, int birth_year, int death_year, string contribution) const;
   void Print() const; // prints out persons records
   bool Read(ifstream & input);
   float GetProp(); // get the below
   float SetProp(); // sets the properties of the person
//   void  Write(ofstream & output);
private:
   string first_name;
   string last_name;
   int birth_year;
   int death_year;
   string contribution;
};
