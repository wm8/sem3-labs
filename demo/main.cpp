// Copyright (c) 2022 wm8
#include <iostream>
#include "Program.h"
#include "Utils.h"
int main(int argc, char** argv) {
  auto* _p= new Program();
  InitLogging();
  if(ParseArgs(_p, argc, argv) == EXIT_FAILURE)
    return EXIT_FAILURE;
  for(unsigned int i=0; i != _p->M; i++)
  {
    _p->threads.emplace_back(task, i);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  signal(SIGINT, Terminate);
  for(unsigned int i=0; i != _p->M; i++)
    _p->threads[i].join();


  return EXIT_SUCCESS;
}
