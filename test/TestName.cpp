#include <string>
#include <iostream>
#include "Name.h"
#include "gtest/gtest.h"

TEST(TestName, nameConTest) {
    EXPECT_EQ("Peter", Name("Peter").getName());
}

TEST(TestName, getNameTest) {
  Name nme = Name("Divya");
  EXPECT_EQ("Divya", nme.getName());
}
