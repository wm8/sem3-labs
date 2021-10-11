// Copyright 2021 wm8

#ifndef TEMPLATE_EXPERIMENT_H
#define TEMPLATE_EXPERIMENT_H
#include <chrono>
#include <ostream>
#include <sstream>
#include "ExperimentType.h"
#include "header.hpp"
class Experiment
{
 public:
    int id;
    int64_t size;
    int time;
    char* arr;
    ExperimentType type;
    Experiment(int id, ExperimentType type, int64_t size);
    ~Experiment();
    double run();
    void _forward(char& k) const;
    void reverse(char& k) const;
    void random(char& k) const;
    void print(std::ostream& os);
};

#endif  // TEMPLATE_EXPERIMENT_H
