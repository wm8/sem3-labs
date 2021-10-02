// Copyright 2021 wm8
#include "ExperimentType.h"

#include <sstream>
std::ostream & operator<<(std::ostream & os, ExperimentType const & type) {
  switch (type) {
    case forward:
      os << "forward";
      break;
    case reverse:
      os << "forward";
      break;
    case random:
      os << "forward";
      break;
  }
  return os;
}
std::string to_string(ExperimentType type)
{
  std::stringstream ss;
  switch (type) {
    case forward:
      ss << "forward";
      break;
    case reverse:
      ss << "forward";
      break;
    case random:
      ss << "forward";
      break;
  }
  return ss.str();
}