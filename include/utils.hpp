// Copyright 2021 wm8
#ifndef INCLUDE_UTILS_HPP_
#define INCLUDE_UTILS_HPP_
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
using std::string;
using boost::filesystem::path;
namespace bfs = boost::filesystem;
using bfs::directory_iterator;
using bfs::directory_entry;
auto example() -> void;
std::vector<std::string> split(std::string s);
string printDirectory(path dirPath, std::ostream& os);
#endif // INCLUDE_UTILS_HPP_
