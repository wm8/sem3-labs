// Copyright (c) 2021. wm8

#include "Investigation.h"
#include "Experiment.h"
int main() {
  std::vector<long long> size;

  long long i=1;
  while (i > 0)
  {
    std::cout << "Enter size in bytes (for end enter 0): ";
    std::cin >> i;
    if(i>0)
      size.push_back(i);
  }
  Investigation inv(random, size);
  inv.print(std::cout);
}