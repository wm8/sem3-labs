// Copyright 2021 wm8


#include "Experiment.h"

#include <random>
#include <sstream>
const int RUN_COUNT=1000;
const int STEP=16;
Experiment::Experiment(int i, ExperimentType t, int64_t s)
{
  Experiment::id = i;
  Experiment::type = t;
  Experiment::size = s;
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int64_t> dist(0, Experiment::size);
  arr = new char[Experiment::size];
  for (int64_t _i=0; _i < size; _i+=STEP)
    arr[_i] = dist(mt);
}
double Experiment::run() {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::duration;
  using std::chrono::milliseconds;
  char k = 0;
  for (int64_t i = 0; i < Experiment::size; i += STEP)
    k = arr[i];
  auto t1 = std::chrono::high_resolution_clock::now();
  switch (Experiment::type)
  {
      case ::forward:
        for (int j = 0; j < RUN_COUNT; j++)
          _forward(k);
        break;
      case ::reverse:
        for (int j = 0; j < RUN_COUNT; j++)
          reverse(k);
        break;
      case ::_random:
        for (int j = 0; j < RUN_COUNT; j++)
          random( k);
        break;
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  duration<double, std::milli> ms = t2 - t1;
  time = ms.count();
  return time;
}
void Experiment::reverse(char& k) const {
  for (int64_t i = 0; i < Experiment::size; i += STEP)
    k = arr[i];
}
void Experiment::random(char& k) const {
  for (int64_t i = Experiment::size-1; i > 0; i -= STEP)
    k = arr[i];
}

void Experiment::_forward(char& k) const
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int64_t> dist(0,  Experiment::size/STEP);
  for (int64_t i=0; i < Experiment::size/STEP; i++)
    k = arr[dist(mt)];
}

void Experiment::print(std::ostream& os) {
  os << "\t- experiment:\n"
  << "\t\tnumber: " << id << std::endl
  << "\t\tinput_data:\n\t\t\tbuffer_size: "
  << sizeConvertor(size) << std::endl
  << "\t\tresults:\n\t\t\tduration: "
  << time << " ms\n";
}
Experiment::~Experiment() {
  delete[] arr;
}
