//
// Created by Алекс on 10.09.2021.
//

#ifndef TEMPLATE_STUDENT_HPP
#define TEMPLATE_STUDENT_HPP
#include "header.hpp"
using nlohmann::json;
using namespace std;
struct Student {
 public:
  Student();
  Student(string _name, std::any _group, std::any _avg, std::any debt);
  bool operator==(Student const & student) const;
  std::string name;
  std::any group;
  std::any avg;
  std::any debt;
};

void from_json(const json& j, Student& s);
void print(Student& student, std::ostream& os);
void print(string s1, string s2, string s3, string s4, std::ostream& os);
void print(vector<Student>& students, std::ostream& os);
vector<Student> parseJSON(json& data);
#endif  // TEMPLATE_STUDENT_HPP
