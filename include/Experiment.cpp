// Copyright 2021 wm8


#include "Experiment.h"

#include <random>
#include <sstream>

char* Experiment::initArray()
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int64_t> dist(0, Experiment::size);
  char* arr = new char[Experiment::size];
  for (int64_t i=0; i < size; i+=16)
    arr[i] = dist(mt);
  return arr;
}

Experiment::Experiment(int i, ExperimentType t, int64_t s)
{
  Experiment::id = i;
  Experiment::type = t;
  Experiment::size = s;
}
double Experiment::run() {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::duration;
  using std::chrono::milliseconds;
  char k = 0;
  char* arr = initArray();
  for (int64_t i = 0; i < Experiment::size; i += 16)
    k = arr[i];
  auto t1 = std::chrono::high_resolution_clock::now();
  switch (Experiment::type)
  {
      case ::forward:
        for (int j = 0; j < 1000; j++) _forward(arr, k);
        break;
      case ::reverse:
        for (int j = 0; j < 1000; j++)
          reverse(arr, k);
        break;
      case ::_random:
        for (int j = 0; j < 1000; j++)
          random(arr, k);
        break;
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  duration<double, std::milli> ms = t2 - t1;
  time = ms.count();
  delete[] arr;
  return time;
}
void Experiment::reverse(char* arr, char& k) {
  for (int64_t i = 0; i < Experiment::size; i += 16)
    k = arr[i];
}
void Experiment::random(char* arr, char& k) {
  for (int64_t i = Experiment::size-1; i > 0; i -= 16)
    k = arr[i];
}

void Experiment::_forward(char* arr, char& k)
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int64_t> dist(0,  Experiment::size/16);
  for (int64_t i=0; i < Experiment::size/16; i++)
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
