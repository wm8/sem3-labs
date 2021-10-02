//
// Created by Алекс on 28.09.2021.
//

#ifndef TEMPLATE_INVESTIGATION_H
#define TEMPLATE_INVESTIGATION_H
#include <iostream>
#include <vector>
#include <random>
#include "Experiment.h"
using std::string;
using std::vector;
struct Investigation {
  std::string type;
  std::vector<Experiment> experiments;

 public:
 std::string toString();
};

#endif  // TEMPLATE_INVESTIGATION_H
