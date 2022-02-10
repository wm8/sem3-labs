// Copyright 2022 wm8

#ifndef LAB5_STACK_H
#define LAB5_STACK_H
#include <iostream>
using std::size_t;

template <typename T>
class Stack
{
 private:
  T* array;
  size_t used;
  size_t size;
 public:
  Stack();
  explicit Stack(T* item);
  Stack(const Stack& st) = delete;
  Stack(const Stack&& st) noexcept;
  ~Stack();
  auto operator=(const Stack& st) -> Stack& = delete;
  auto operator=(Stack&& st) -> Stack&;
  void push(T&& value);
  template <typename ... Args>
  void push_emplace(Args&&... value);
  void push(const T& value);
  T pop();
  const T& head() const;
};
template <typename T>
Stack<T>::Stack()
{
  size = 1;
  used = 0;
  array = static_cast<T*>(malloc(size * sizeof(T)));
}
template <typename T>
Stack<T>::Stack(T* item)
{
  size = 2;
  used = 1;
  array = static_cast<T*>(malloc(size * sizeof(T)));
  array[0] = item;
}
template <typename T>
void Stack<T>::push(T&& value)
{
  if (used == size) {
    size *= 2;
    array = static_cast<T*>(realloc(array, size * sizeof(T)));
  }
  array[used++] = move(value);

}
template <typename T>
void Stack<T>::push(const T& value)
{
  if (used == size) {
    size *= 2;
    array = static_cast<T*>(realloc(array, size * sizeof(T)));
  }
  array[used++] = value;
}
template <typename T>
T Stack<T>::pop()
{
  T res = std::move(array[--used]);
  return res;
}
template <typename T>
const T& Stack<T>::head() const {
  return array[used-1];
}
template <typename T>
Stack<T>::Stack(const Stack&& st) noexcept
{
  size = std::move(st.size);
  used = std::move(st.used);
  this->array = std::move(st.array);
}
template <typename T>
auto Stack<T>::operator=(Stack&& st) -> Stack& {
  size = std::move(st.size);
  used = std::move(st.used);
  this->array = std::move(st.array);
}
template <typename T>
Stack<T>::~Stack() {
  used = 0;
  size = 0;
  free (array);
}
template <typename T>
template <typename... Args>
void Stack<T>::push_emplace(Args&&... args)
{
  if (used == size)
  {
    size *= 2;
    array = static_cast<T*>(realloc(array, size * sizeof(T)));
  }
  array[used++] = *(new T(std::forward<Args>(args)...));
}
#endif  // LAB5_STACK_H
