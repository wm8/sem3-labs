#include <header.hpp>
#include "iostream"
#include <fstream>
#include "nlohmann/json.hpp"
#include "Student.hpp"
#include "TextTable.h"
using nlohmann::json;
using namespace std;

void print(vector<Student>& students)
{
  TextTable t( '-', '|', '|' );

  t.add( "name" );
  t.add( "group" );
  t.add( "avg" );
  t.add( "debt");
  t.endOfRow();
  for (Student& student : students) {
    print(student, t);
  }
  t.setAlignment(2, TextTable::Alignment::LEFT);
  cout<< t;
}
int main(int argc, char** argv)
{

  if(argc < 2)
    throw std::runtime_error{ "The file path was not passed"};
  string filePath(argv[1]);
  ifstream jsonFile(filePath);
  if (!jsonFile)
    throw std::runtime_error{"unable to open json: " + filePath};
  json data;
  jsonFile >> data;
  vector<Student> students;
  for (auto const& item : data.at("items"))
  {
    Student student1;
    from_json(item, student1);
    students.push_back(student1);
  }
  print(students);
  return 0;
}