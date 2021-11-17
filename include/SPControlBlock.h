// Copyright 2021 wm8

#ifndef TEMPLATE_SPCONTROLBLOCK_H
#define TEMPLATE_SPCONTROLBLOCK_H
#include <iostream>
#include <atomic>
#include <vector>
#include "ISPCtrlBlock.h"
using std::atomic_uint;
using std::vector;
template <typename T>
class SPControlBlock: public ISPCtrlBlock
{
 public:
  SPControlBlock(T* item);
  ~SPControlBlock();
  static atomic_uint* getCount(T* item);
  static void deleteItem(T* item);
  private:
   T* i;
};
template <typename T>
SPControlBlock<T>::SPControlBlock(T* item) {
  i = item;
  counter = new std::atomic_uint {0};
}
template <typename T>
atomic_uint* SPControlBlock<T>::getCount(T* item) {
  for ( const auto* b: links )
  {
    SPControlBlock* block = (SPControlBlock*)b;
    if(typeid(block->i) != typeid(item) ||
        (*block->i) != *item)
      continue;
    return block->counter;
  }
  auto* block = new SPControlBlock(item);
  links.push_back(block);
  return block->counter;
}
template <typename T>
void SPControlBlock<T>::deleteItem(T* item) {
  int i=-1;
  for ( const auto* b: links )
  {
    i++;
    SPControlBlock* block = (SPControlBlock*)b;
    if(typeid(block->i) != typeid(item) || (*block->i) != *item)
      continue;
    links.erase(links.begin() + i);
    delete block;
  }
}
template <typename T>
SPControlBlock<T>::~SPControlBlock() {
  i= nullptr;
  counter= nullptr;
}

#endif  // TEMPLATE_SPCONTROLBLOCK_H
