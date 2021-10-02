//
// Created by Алекс on 28.09.2021.
//

#ifndef TEMPLATE_EXPERIMENT_H
#define TEMPLATE_EXPERIMENT_H
#include <chrono>
#include <ostream>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
enum ExperimentType
{
  forward,
  reverse,
  random
};

class Experiment
{
  int id;
  int size;
  int time;
  ExperimentType type;

 public:
  Experiment(int id, int size);
  char* initArray();
  double run();
  void forward(char* arr, char& k);
  void reverse(char* arr, char& k);
  void random(char* arr, char& k);
};

#endif  // TEMPLATE_EXPERIMENT_H
