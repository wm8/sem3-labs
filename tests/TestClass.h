// Copyright 2021 wm8

#ifndef TEMPLATE_TESTCLASS_H
#define TEMPLATE_TESTCLASS_H
class TestClass
{
 public:
  TestClass(int id);
  ~TestClass() = default;
  bool operator==(TestClass& c);
  bool operator!=(TestClass& c);
  int get() const;

 private:
  int id;
};
bool TestClass::operator==(TestClass& c)
{
  return c.get() == id;
}
bool TestClass::operator!=(TestClass& c)
{
  return c.get() != id;
}
TestClass::TestClass(int i) {
  id = i;
}
int TestClass::get() const { return id; }


#endif  // TEMPLATE_TESTCLASS_H
