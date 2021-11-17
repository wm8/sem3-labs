// Copyright 2021 wm8
#ifndef TEMPLATE_ISPCTRLBLOCK_H
#define TEMPLATE_ISPCTRLBLOCK_H
#include <atomic>
#include <vector>
using std::vector;
using std::atomic_uint;
class ISPCtrlBlock
{
 public:
  std::atomic_uint* counter;
  ~ISPCtrlBlock() = default;
  static vector<ISPCtrlBlock*> links;
};
#endif  // TEMPLATE_ISPCTRLBLOCK_H
