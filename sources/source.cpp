// Copyright 2020 Your Name <your_email>

#include <header.hpp>
std::string sizeConvertor(int64_t value)
{
  if (value <= 1024)
    return std::to_string(value) +" b";
  if (value >= 1024 && value < 1024*1024)
    return std::to_string(value/1024) +" KB";
  if (value >= 1024*1024 && value < (int64_t)1024*1024*1024)
    return std::to_string(value/1024/1024) +" MB";
  if (value >= (int64_t)1024*1024*1024)
    return std::to_string(value/1024/1024/1024) +" GB";
  return "0";
}
