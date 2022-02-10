// Copyright 2022 wm8

#ifndef LAB5_TESTSTRUCT_H
#define LAB5_TESTSTRUCT_H
struct TestStruct
{
  TestStruct()
  {
    id=0;
  }
  explicit TestStruct(int _id) {id = _id;}
  TestStruct(TestStruct* pStruct) {
    this->id = pStruct->id;
  }
  int id;
};
#endif  // LAB5_TESTSTRUCT_H
