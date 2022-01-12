// Copyright (c) 2022 wm8
#include "Program.h"
Program* Program::_this;
Program::Program()
{
  _this = this;
  json js = json::array();
}
Program* Program::instance()
{
  return _this;
}
void Program::SaveData()
{
  std::ofstream o(file_name);
  o << shas.dump(4) << std::endl;
}
