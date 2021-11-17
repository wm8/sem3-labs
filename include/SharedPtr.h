// Copyright 2021 wm8

#ifndef TEMPLATE_SHAREDPTR_H
#define TEMPLATE_SHAREDPTR_H
#include "SPControlBlock.h"
template <typename T>
class SharedPtr {
 public:
  SharedPtr();
  SharedPtr(T* ptr);
  SharedPtr(const SharedPtr& r);
  SharedPtr(SharedPtr&& r);
  ~SharedPtr();
  auto operator=(const SharedPtr& r) -> SharedPtr&;
  auto operator=(SharedPtr&& r) -> SharedPtr&;

  operator bool() const;
  auto operator*() const -> T&;
  auto operator->() const -> T*;

  auto get() -> T*;
  void reset();
  void reset(T* ptr);
  void swap(SharedPtr& r);
  auto use_count() const -> size_t;

 private:
  T* item;
  std::atomic_uint* counter;

};
template <typename T>
SharedPtr<T>::SharedPtr() {
  item = nullptr;
  counter = nullptr;
}
template <typename T>
SharedPtr<T>::SharedPtr(T* ptr)
{
  item = ptr;
  counter = SPControlBlock<T>::getCount(ptr);
  (*counter)++;
}
template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr&& r) {
 item = r.item;
 counter = r.counter;
 (*counter)++;
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& r)
{
  item = r.item;
  counter = r.counter;
  (*counter)++;
}
template <typename T>
SharedPtr<T>::~SharedPtr() {
  if(--(*counter) < 1)
  {
    SPControlBlock<T>::deleteItem(item);
    delete item;
    delete counter;
  }
  item = nullptr;
  counter = nullptr;
}
template <typename T>
auto SharedPtr<T>::operator=(const SharedPtr& r)
    -> SharedPtr& {
  item = r.item;
  counter = r.counter;
  return item;
}
template <typename T>
auto SharedPtr<T>::operator=(SharedPtr&& r)
    -> SharedPtr& {
  item = r.item;
  counter = r.counter;
  return item;
}
template <typename T>
SharedPtr<T>::operator bool() const {
  return item == nullptr;
}
template <typename T>
auto SharedPtr<T>::operator*() const -> T & {
  return *item;
}
template <typename T>
auto SharedPtr<T>::operator->() const -> T * {
  return item;
}
template <typename T>
auto SharedPtr<T>::get() -> T * {
  return item;
}
template <typename T>
void SharedPtr<T>::reset() {
  if(--(*counter) < 1)
  {
    SPControlBlock<T>::deleteItem(item);
    delete item;
    delete counter;
  }
  item = nullptr;
  counter = nullptr;
}
template <typename T>
void SharedPtr<T>::swap(SharedPtr& r)
{
  T* t = item;
  atomic_uint* c = counter;
  item = r.item;
  counter = r.counter;
  r.item = t;
  r.counter = c;
  t = nullptr;
  c = nullptr;
}
template <typename T>
auto SharedPtr<T>::use_count() const -> size_t {
  return (*counter);
}
#endif  // TEMPLATE_SHAREDPTR_H
