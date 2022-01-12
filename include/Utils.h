// Copyright (c) 2022 wm8
#ifndef LAB6_UTILS_H
#define LAB6_UTILS_H
#include <exception>
#include <iostream>
#include <unistd.h>
#include <boost/program_options.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/filesystem.hpp>
#include "Program.h"
#include "Randomizer.h"
namespace logging = boost::log;
namespace po = boost::program_options;
using std::string;
using std::exception;

void InitLogging(std::string logfile="debug.log");
void Terminate(int exit_code);
int ParseArgs(Program* _p, int argc, char** argv);
void task(unsigned int thread_id);
bool checkSHA(std::string sha);
#endif  // LAB6_UTILS_H
