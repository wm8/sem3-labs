#include "iostream"
#include <fstream>
#include "Student.hpp"
using nlohmann::json;
using namespace std;

void print(vector<Student>& students)
{
  print( "name", "group", "avg", "debt");/*
  cout << "| " << setw(20) << std::left << "name" << "| "
       <<  setw(10) << std::left << "group" << "| "
       <<  setw(10) << std::left << "avg" << "| "
       <<  setw(10) << std::left << "debt" << "|\n";*/
  for (Student& student : students) {
    print(student);
  }
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
  if(!data.at("items").is_array())
    throw std::runtime_error{"the array must be contained in the file"};
  for (auto const& item : data.at("items"))
  {
    Student student1;
    from_json(item, student1);
    students.push_back(student1);
  }
  print(students);
  return 0;
}