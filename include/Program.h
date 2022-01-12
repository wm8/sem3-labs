// Copyright (c) 2022 wm8
#ifndef LAB6_PROGRAM_H
#define LAB6_PROGRAM_H
#include <thread>
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>
using nlohmann::json;
struct Program
{
 private:
  static Program* _this;

 public:
  Program();
  static Program* instance();
  void SaveData();
  bool terminated= false;
  unsigned int M;
  std::string file_name;
  std::vector<std::thread> threads;
  json shas;
};
#endif  // LAB6_PROGRAM_H
