// Copyright 2021 wm8

#ifndef TEMPLATE_INVESTIGATION_H
#define TEMPLATE_INVESTIGATION_H
#include <iostream>
#include <vector>
#include <random>
#include "Experiment.h"
using std::string;
using std::vector;
struct Investigation {
  ExperimentType type;
  std::vector<Experiment*> experiments;
  Investigation(ExperimentType type, std::vector<int64_t>& sizes);

 public:
 void print(std::ostream& os);
};

#endif  // TEMPLATE_INVESTIGATION_H
