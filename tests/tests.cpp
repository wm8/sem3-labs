// Copyright 2021 wm8

#include <gtest/gtest.h>

#include <stdexcept>
#include "SharedPtr.h"
#include "TestClass.h"
TEST(countTest, test1)
{
  auto* t = new TestClass(12);
  auto* ptr1= new SharedPtr(t);
  ASSERT_EQ( ptr1->use_count(), 1);
  delete ptr1;
}
TEST(countTest, test2)
{
  auto* t = new TestClass(12);
  auto* ptr1= new SharedPtr(t);
  [[maybe_unused]] auto* ptr2= new SharedPtr(t);

  ASSERT_EQ( ptr1->use_count(), 2);
  delete ptr1;
  delete ptr2;

}
TEST(countTest, test3)
{
  auto* t = new TestClass(12);
  auto* ptr1= new SharedPtr(t);
  [[maybe_unused]] auto* ptr2= new SharedPtr(t);
  [[maybe_unused]] auto* ptr3= new SharedPtr<TestClass>(*ptr1);
  ASSERT_EQ( ptr1->use_count(), 3);
  delete ptr1;
  delete ptr2;
  delete ptr3;
}
TEST(countTest, test4)
{
  auto* t1 = new TestClass(12);
  auto* t2 = new TestClass(52);
  auto* ptr1= new SharedPtr(t1);
  auto* ptr2= new SharedPtr(t2);
  ASSERT_EQ( ptr1->use_count(), 1);
  ASSERT_EQ( ptr2->use_count(), 1);
  delete ptr1;
  delete ptr2;
}
TEST(destructorTest, test1)
{
  auto* t = new TestClass(12);
  auto* ptr1= new SharedPtr(t);
  [[maybe_unused]] auto* ptr2= new SharedPtr(t);
  [[maybe_unused]] auto* ptr3= new SharedPtr<TestClass>(*ptr1);
  delete ptr2;
  ASSERT_EQ( ptr1->use_count(), 2);
  delete ptr1;
  delete ptr3;
}
TEST(swapTest, test1)
{
  auto* t1 = new TestClass(12);
  auto* t2 = new TestClass(52);
  auto* ptr1= new SharedPtr(t1);
  auto* ptr2= new SharedPtr(t2);
  ptr1->swap(*ptr2);
  int id = ptr1->get()->get();
  ASSERT_EQ( id, t2->get());
  id = ptr2->get()->get();
  ASSERT_EQ(id, t1->get());
  delete ptr1;
  delete ptr2;
}