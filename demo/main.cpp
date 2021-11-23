// Copyright 2021 wm8
#include <iostream>
#include <utils.hpp>

int main(int argc, char** argv)
{
  path dirPath(bfs::current_path());
  if (argc > 1)
    dirPath = argv[1];
  string ss("");
  for (const directory_entry& i : directory_iterator{dirPath})
  {
      if (bfs::is_regular_file(i.status()))
        continue;
      string s = printDirectory(i.path(), std::cout);
      if(!s.empty())
        ss+=s;
  }
  std::cout << '\n' << ss;
  return 0;
}