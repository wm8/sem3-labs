// Copyright 2020 Your Name

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <string>
#include <any>
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

using nlohmann::json;
using namespace std;

json getJSON(int argc, char** argv);
#endif // INCLUDE_HEADER_HPP_
