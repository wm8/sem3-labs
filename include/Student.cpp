

#include "Student.hpp"
#include <iostream>
using namespace std;
auto get_name(const json& j) -> std::string {
  return j.get<std::string>();
}
auto get_debt(const json& j) -> std::any {
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else
    return j.get<std::vector<std::string>>();
}

auto get_avg(const json& j) -> std::any {
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else if (j.is_number_float())
    return j.get<double>();
  else
    return j.get<std::size_t>();
}

auto get_group(const json& j) -> std::any {

  if (j.is_string())
    return j.get<std::string>();
  else
    return j.get<std::size_t>();
}
void from_json(const json& j, Student& s) {
    s.name = get_name(j.at("name"));
    s.group = get_group(j.at("group"));
    s.avg = get_avg(j.at("avg"));
    s.debt = get_debt(j.at("debt"));
}
string toString(std::any& item)
{
  stringstream ss;
  if(item.type() == typeid(nullptr_t))
      ss << "null";
  else if(item.type() == typeid(string))
    ss << any_cast<string>(item);
  else if(item.type() == typeid(double))
    ss << any_cast<double>(item);
  else if(item.type() == typeid(vector<std::string>))
    ss << any_cast<std::vector<std::string> >(item).size();
  else if(item.type() == typeid(size_t))
    ss << any_cast<size_t>(item);
  else  ss << "unknown";
  return ss.str();
}
void print(Student& student, TextTable& table)
{
    table.add(student.name);
    table.add(toString(student.group));
    table.add(toString(student.avg));
    table.add(toString(student.debt));
    table.endOfRow();
}
