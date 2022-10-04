#include <iostream>
#include "Health.h"
#include "gtest/gtest.h"

TEST(TestHealth, defaultConstructorTest) {
  Health* health = new Health();

  EXPECT_EQ(health->getHealth(), 50);

  delete health;
}

TEST(TestHealth, negativeConstructorTest) {
  Health health = Health(-10);

  EXPECT_EQ(health.getHealth(), 0);
}

TEST(TestHealth, getHealthTest) {
  Health pop = Health(100);
  EXPECT_EQ(100, pop.getHealth());
}

TEST(TestHealth, changeHealthTestT) {
  Health pop = Health(100);
  EXPECT_TRUE(pop.changeHealth(50));
}

TEST(TestHealth, changeHealthTestF) {
  Health pop = Health(100);
  EXPECT_FALSE(pop.changeHealth(-120));
}
