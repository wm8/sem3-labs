// Copyright 2021 wm8

#include <iostream>
#include <map>
#include <utils.hpp>
#include <sstream>
#include "boost/regex.hpp"
using boost::regex;
using std::stringstream;
using std::cout;

std::vector<string> split(string& s, char separator)
{
  std::vector<string> seglist;
  string segment;
  stringstream ss(s);
  while (std::getline(ss, segment, separator))
    seglist.push_back(segment);
  return seglist;
}
string printDirectory(path dirPath, std::ostream& os)
{
  const boost::regex reg("balance_[0-9]{8}_[0-9]{8}.txt");
  std::map<string , std::pair<int, int>> blc;

  for (const directory_entry& i : directory_iterator{dirPath})
  {
    if (!bfs::is_regular_file(i.status()))
      continue;
    boost::smatch what;
    string filename = i.path().filename().string();

    if (!boost::regex_match( filename, what, reg))
      continue;
    os << dirPath.filename().string()
       << " " << filename << std::endl;
    std::ifstream file(i.path().string());
    if (!file)
      throw std::runtime_error{"unable to open file: " + i.path().string()};

    const std::size_t& size = bfs::file_size(i.path());
    string content(size, '\0');
    file.read(content.data(), size);
    auto parts = split(content, '|');
    int date = std::stoi(parts[2]);
    std::string bal_id = parts[1];

    if (blc.find(bal_id) == blc.end())
      blc[bal_id] = {1, date};
    else
    {
      blc[bal_id].first++;
      if (blc[bal_id].second < date)
        blc[bal_id].second = date;
    }
    file.close();
  }
  stringstream ss;
  for ( const auto &[bid, data] : blc )
  {
    ss << "broker:" << dirPath.filename().string()
       << " account:" << bid << " files:" << data.first
       << " lastdate:" << data.second << std::endl;
  }
  return ss.str();
}
