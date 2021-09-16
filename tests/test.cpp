// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>

#include <Student.hpp>

TEST(printTest, StudentsArray) {
    std::stringstream ss;
    std::vector<Student> students;
    students.emplace_back("test", (string)"test", (size_t)3, vector<string>());
    students.emplace_back("test", (size_t)4, (double)3.33, vector<string>());
    print(students, ss);

    ASSERT_EQ("| name                | group     | avg       | debt      |\n"
        "|---------------------|-----------|-----------|-----------|\n"
        "| test                | test      | 3         | 0         |\n"
        "|---------------------|-----------|-----------|-----------|\n"
        "| test                | 4         | 3.33      | 0         |\n"
        "|---------------------|-----------|-----------|-----------|",  ss.str());
}
TEST(printTest, StudentItem)
{
  std::stringstream ss;
  Student s("test", (string)"test", (size_t)3, vector<string>());
  print(s, ss);
  ASSERT_EQ("| name                | group     | avg       | debt      |\n"
      "|---------------------|-----------|-----------|-----------|\n"
      "| test                | test      | 3         | 0         |\n"
      "|---------------------|-----------|-----------|-----------|\n",  ss.str());
}
TEST(printTest, json)
{
  string jsonData = "{\n"
      "  \"items\": [\n"
      "    {\n"
      "      \"name\": \"Gusov Petr\",\n"
      "      \"group\": \"UI9-11\",\n"
      "      \"avg\": \"4.25\",\n"
      "      \"debt\": null\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Zhdanov Ivan\",\n"
      "      \"group\": 31,\n"
      "      \"avg\": 2.25,\n"
      "      \"debt\": \"pyhton\"\n"
      "    }\n"
      "  ],\n"
      "  \"_meta\": {\n"
      "    \"count\": 2\n"
      "  }\n"
      "}";
  nlohmann::json _json = json::parse(jsonData);
  vector<Student> students_parsed = parseJSON(_json);
  std::stringstream ss;
  print(students_parsed, ss);
  ASSERT_EQ("| name                | group     | avg       | debt      |\n"
      "|---------------------|-----------|-----------|-----------|\n"
      "| Gusov Petr          | UI9-11    | 4.25      | null      |\n"
      "|---------------------|-----------|-----------|-----------|\n"
      "| Zhdanov Ivan        | 31        | 2.25      | pyhton    |\n"
      "|---------------------|-----------|-----------|-----------|", ss.str());
}
TEST(parseTest, jsonParse)
{
    string jsonData = "{\n"
      "  \"items\": [\n"
      "    {\n"
      "      \"name\": \"Gusov Petr\",\n"
      "      \"group\": \"UI9-11\",\n"
      "      \"avg\": \"4.25\",\n"
      "      \"debt\": null\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Zhdanov Ivan\",\n"
      "      \"group\": 31,\n"
      "      \"avg\": 2.25,\n"
      "      \"debt\": \"pyhton\"\n"
      "    }\n"
      "  ],\n"
      "  \"_meta\": {\n"
      "    \"count\": 2\n"
      "  }\n"
      "}";
    nlohmann::json _json = json::parse(jsonData);;
    vector<Student> students_parsed = parseJSON(_json);
    vector<Student> student_inited = {
        Student("Gusov Petr", (string)"UI9-11", (string)"4.25", nullptr),
        Student("Zhdanov Ivan", (size_t)31, (double)2.25, (string)"pyhton")
    };
    ASSERT_EQ(student_inited, students_parsed);
}
