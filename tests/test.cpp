// Copyright 2021 wm8

#include <gtest/gtest.h>
#include "header.hpp"
#include <Student.hpp>
TEST(printTest, StudentsArray) {
    std::stringstream ss;
    std::vector<Student> students;
    students.emplace_back("test", (std::string)"test",
                          (size_t)3, std::vector<std::string>());
    students.emplace_back("test", (size_t)4,
                          (double)3.33, std::vector<std::string>());
    print(students, ss);
    ASSERT_EQ("| name                | group     | avg       | debt      |\n"
        "|---------------------|-----------|-----------|-----------|\n"
        "| test                | test      | 3         | 0         |\n"
        "|---------------------|-----------|-----------|-----------|\n"
        "| test                | 4         | 3.33      | 0         |\n"
        "|---------------------|-----------|-----------|-----------|\n",  ss.str());
}
TEST(printTest, StudentItem)
{
  std::stringstream ss;
  Student s("test", (std::string)"test", (size_t)3, std::vector<std::string>());
  print(s, ss);
  ASSERT_EQ("| test                | test      | 3         | 0         |\n"
      "|---------------------|-----------|-----------|-----------|\n",  ss.str());
}
TEST(printTest, json)
{
  std::string jsonData = "{\n"
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
  std::vector<Student> students_parsed = parseJSON(_json);
  std::stringstream ss;
  print(students_parsed, ss);
  ASSERT_EQ("| name                | group     | avg       | debt      |\n"
      "|---------------------|-----------|-----------|-----------|\n"
      "| Gusov Petr          | UI9-11    | 4.25      | null      |\n"
      "|---------------------|-----------|-----------|-----------|\n"
      "| Zhdanov Ivan        | 31        | 2.25      | pyhton    |\n"
      "|---------------------|-----------|-----------|-----------|\n", ss.str());
}

TEST(parseTest, jsonParse)
{
  std::string jsonData = "{\n"
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
    std::vector<Student> students_parsed = parseJSON(_json);
    std::vector<Student> student_inited = {
        Student("Gusov Petr", (std::string)"UI9-11",
                (std::string)"4.25", nullptr),
        Student("Zhdanov Ivan", (size_t)31,
                (double)2.25, (std::string)"pyhton")
    };
    ASSERT_EQ(student_inited, students_parsed);
}
TEST(parseTest, fromFile)
{
  std::string jsonData = "{\n"
      "  \"items\": [\n"
      "    {\n"
      "      \"name\": \"Gusov Petr\",\n"
      "      \"group\": \"1\",\n"
      "      \"avg\": \"4.25\",\n"
      "      \"debt\":  [\n"
      "        \"C++\",\n"
      "        \"Linux\",\n"
      "        \"Network\"\n"
      "      ]\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Zdhanov Ivan\",\n"
      "      \"group\": 31,\n"
      "      \"avg\": 2.25,\n"
      "      \"debt\": \"python\"\n"
      "    }\n"
      "  ],\n"
      "  \"_meta\": {\n"
      "    \"count\": 2\n"
      "  }\n"
      "}";
  nlohmann::json json1 = json::parse(jsonData);
  char* argv[] ={(char*)"", (char*)"../jsonExamples/example1.json"};
  nlohmann::json json2 = getJSON(2, argv);
  ASSERT_EQ(json1, json2) << "Test passed!";
}
TEST(errorCheck, lessArgsTest)
{
  try {
    char* argv[] ={(char*)"", (char*)"../jsonExamples/example1.json"};
    nlohmann::json json2 = getJSON(1, argv);
    FAIL() << "Expected: The file path was not passed";
  }
  catch(std::runtime_error const & err) {
    EXPECT_EQ(err.what(),std::string("The file path was not passed"));
  }
  catch(...) {
    FAIL() << "Expected The file path was not passed";
  }
}
TEST(errorCheck, _metaCheck)
{
  try {
    char* argv[] ={(char*)"", (char*)"../jsonExamples/example2.json"};
    nlohmann::json json2 = getJSON(2, argv);
    FAIL() << "Expected: _meta value does not match the array size";
  }
  catch(std::runtime_error const & err) {
    EXPECT_EQ(err.what(),std::string("_meta value does not match the array size"));
  }
  catch(...) {
    FAIL() << "Expected: _meta value does not match the array size";
  }
}
