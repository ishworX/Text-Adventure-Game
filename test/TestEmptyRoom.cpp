#include <iostream>
#include "EmptyRoom.h"
#include "gtest/gtest.h"

TEST(TestEmptyRoom, TestGetIdentifier) {
  EmptyRoom* nothing = new EmptyRoom();
  nothing->roomInfo();

  EXPECT_EQ(4, nothing->getIdentifier());

  delete nothing;
}

TEST(TestEmptyRoom, TestIsBeaten) {
  EmptyRoom* nothing = new EmptyRoom();
  nothing->roomInfo();

  EXPECT_TRUE(nothing->isBeaten());
  delete nothing;
}

TEST(TestEmptyRoom, TestGetBelong) {
  EmptyRoom* nothing = new EmptyRoom();
  EXPECT_EQ('z', nothing->getBelong());
  delete nothing;
}

TEST(TestEmptyRoom, TestGetNPC) {
  EmptyRoom* nothing = new EmptyRoom();
  EXPECT_EQ(nullptr, nothing->getNPC());
  delete nothing;
}
