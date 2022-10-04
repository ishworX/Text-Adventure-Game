#include <iostream>
#include <string>
#include "Hint.h"
#include "gtest/gtest.h"

TEST(TestHint, TestHintC) {
    Hint* blues = new Hint("Cola");

    EXPECT_EQ("Cola", blues->getHintOne());
    delete blues;
}

TEST(TestHint, TestHintC2) {
    Hint* blues = new Hint("Cola", "Pepsi");

    EXPECT_EQ("Pepsi", blues->getHintTwo());
    delete blues;
}

TEST(TestHint, TestHintC2F) {
    Hint* blues = new Hint("Cola");

    EXPECT_EQ("There is only one hint available: ", blues->getHintTwo());
    delete blues;
}
