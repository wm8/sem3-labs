// Copyright 2020 Your Name <your_email>

#include <header.hpp>
std::string sizeConvertor(long long value)
{
  if(value <= 1024)
    return std::to_string(value) +" b";
  if(value >= 1024 && value < 1024*1024)
    return std::to_string(value/1024) +" KB";
  if(value >= 1024*1024 && value < (long long)1024*1024*1024)
    return std::to_string(value/1024/1024) +" MB";
  if(value >= (long long)1024*1024*1024)
    return std::to_string(value/1024/1024/1024) +" GB";
  return "0";
}