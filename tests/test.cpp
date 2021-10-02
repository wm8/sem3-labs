// Copyright 2021 wm8
#include "Investigation.h"
#include "Experiment.h"
#include <gtest/gtest.h>

TEST(ExperimentTest, forwardTest) {
  try {
    Experiment e(0, forward, 80);
    char* arr = e.initArray();
    char k;
    e._forward(arr, k);
    SUCCEED();
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}
TEST(ExperimentTest, reverseTest) {
  try {
    Experiment e(0,forward, 80);
    char* arr = e.initArray();
    char k=0;
    e.reverse(arr, k);
    SUCCEED();
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}
TEST(ExperimentTest, randomTest) {
  try {
    Experiment e(0, forward,  80);
    char* arr = e.initArray();
    char k;
    e.random(arr, k);
    SUCCEED();
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}
TEST(ExperimentTest, runTest)
{
  try {
    Experiment e(0, _random, 838860);
    int result = e.run();
    if(result >= 0)
      SUCCEED() << result;
    else FAIL() << "Time is " << result;
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}
TEST(ExperimentTest, printTest)
{
  Experiment e(0, _random, 838860);
  e.run();
  std::stringstream ss;
  e.print(ss);
  std::string s("\t- experiment:\n"
      "\t\tnumber: 0\n"
      "\t\tinput_data:\n"
      "\t\t\tbuffer_size: "+ sizeConvertor(e.size) +
      "\n\t\tresults:\n"
      "\t\t\tduration: "+ std::to_string(e.time) +" ms\n");
  std::string s2 = ss.str();
  ASSERT_EQ(s2, s);
}
TEST(InvestigationTest, constructorTest) {
  try {
    std::vector<int64_t> size = {838860, 1677721, 3355443};
    Investigation i(_random, size);
    SUCCEED();
  }
  catch (std::runtime_error const & e)
  {
    FAIL() << e.what();
  }
}