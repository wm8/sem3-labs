// Copyright (c) 2022 wm8
#ifndef LAB6_RANDOMIZER_H
#define LAB6_RANDOMIZER_H
#include <random>

class Randomizer {
 public:
  Randomizer(unsigned int id);
  ~Randomizer();
  char* get();

 private:
  unsigned int id;
  const char* characters
      = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  const int cc=62;
  const int maxl=16;
  std::seed_seq* seed;
};

#endif  // LAB6_RANDOMIZER_H
