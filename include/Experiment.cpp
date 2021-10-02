//
// Created by Алекс on 28.09.2021.
//

#include "Experiment.h"

#include <random>

char* Experiment::initArray()
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0,  Experiment::size);
  char* arr = new char[Experiment::size];
  for (int i=0; i < size; i+=16)
    arr[i] = dist(mt);
  return arr;
}

Experiment::Experiment(int i, int s)
{
  Experiment::id = i;
  Experiment::size = s;
}
double Experiment::run() {
  char k = 0;
  char* arr = initArray();
  for (int i = 0; i < Experiment::size; i += 16)
    k = arr[i];
  auto t1 = high_resolution_clock::now();
  switch (Experiment::type)
  {
      case ::forward:
        for(int j=0; j < 1000; j++)
          forward(arr, k);
        break;
      case ::reverse:
        for(int j=0; j < 1000; j++)
          reverse(arr, k);
        break;
      case ::random:
        for(int j=0; j < 1000; j++)
          random(arr, k);
        break;
  }
  auto t2 = high_resolution_clock::now();
  auto ms_int = duration_cast<milliseconds>(t2 - t1);
  duration<double, std::milli> ms = t2 - t1;
  return ms.count();
}
void Experiment::reverse(char* arr, char& k) {
  for (int i = 0; i < Experiment::size; i += 16)
    k = arr[i];
}
void Experiment::random(char* arr, char& k) {
  for (int i = Experiment::size-1; i > 0; i -= 16)
    k = arr[i];
}

void Experiment::forward(char* arr, char& k)
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0,  Experiment::size/16);
  for (int i=0; i < Experiment::size/16; i++)
    k = arr[dist(mt)];
}
