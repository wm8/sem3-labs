// Copyright 2021 wm8
#ifndef TEMPLATE_EXPERIMENTTYPE_H
#define TEMPLATE_EXPERIMENTTYPE_H
#include <string>
enum ExperimentType
{
  forward,
  reverse,
  random

};
std::string to_string(ExperimentType type);
#endif  // TEMPLATE_EXPERIMENTTYPE_H
