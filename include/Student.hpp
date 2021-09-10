//
// Created by Алекс on 10.09.2021.
//

#ifndef TEMPLATE_STUDENT_HPP
#define TEMPLATE_STUDENT_HPP
#include <string>
#include <any>
#include <nlohmann/json.hpp>
#include "TextTable.h"

using nlohmann::json;
using namespace std;
struct Student {
  std::string name;
  std::any group;
  std::any avg;
  std::any debt;
};

void from_json(const json& j, Student& s);
void print(Student& student, TextTable& table);
#endif  // TEMPLATE_STUDENT_HPP
