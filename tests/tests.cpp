// Copyright 2022 wm8

#include <gtest/gtest.h>
#include "Stack.h"
#include "TestStruct.h"
TEST(unit_test, head_test)
{
  Stack<int> stack{};
  for(int i=0; i !=5; i++)
    stack.push(i);
  ASSERT_EQ(4, stack.head());
}
TEST(unit_test, pop_test1)
{
  Stack<int> stack{};
  for(int i=0; i !=5; i++)
    stack.push(i);
  [[maybe_unused]] auto t = stack.pop();
  ASSERT_EQ(4, t);
}
TEST(unit_test, pop_test2)
{
  Stack<int> stack{};
  for(int i=0; i !=5; i++)
    stack.push(i);
  [[maybe_unused]] auto t = stack.pop();
  ASSERT_EQ(3, stack.head());
}
TEST(unit_test, struct_test)
{
  Stack<TestStruct> stack;
  for(int i=0; i !=5; i++) {
    TestStruct t(i);
    stack.push(t);
  }
  [[maybe_unused]] auto t = stack.pop();
  ASSERT_EQ(3, stack.head().id);
}
TEST(unit_test, stack_pointer)
{
  auto* t = new TestStruct(1);
  TestStruct t2 = new TestStruct(2);
  TestStruct t3 = new TestStruct(3);
  TestStruct t4 = new TestStruct(4);
  TestStruct t5 = new TestStruct(5);
  [[maybe_unused]] auto* stack= new Stack(t);
  stack->push(t2);
  stack->push(t3);
  stack->push(t4);
  stack->push(t5);
  ASSERT_EQ(5, stack->head().id);
  delete(stack);
  delete(t);
}
