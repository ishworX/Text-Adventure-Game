#include <iostream>
#include <string>
#include "WorldRoom.h"
#include "Player.h"
#include "Inventory.h"
#include "gtest/gtest.h"

TEST(TestWorldRoom, TestWorldRoomC) {
  WorldRoom* dif = new WorldRoom("SolarS");
  dif->roomInfo();

  EXPECT_EQ(6, dif->getIdentifier());
  delete dif;
}

TEST(TestWorldRoom, TestIsBeaten) {
  WorldRoom* dif = new WorldRoom("SolarS");
  dif->roomInfo();

  EXPECT_TRUE(dif->isBeaten());
  delete dif;
}

TEST(TestWorldRoom, TestdoRoom) {
  WorldRoom* dif = new WorldRoom("SolarS");
  Inventory* gamerr = new Inventory();
  Player* Div = new Player(gamerr);
  dif->roomInfo();

  EXPECT_FALSE(dif->doRoom(Div));
  delete dif;
  delete gamerr;
  delete Div;
}

TEST(TestWorldRoom, TestGetBelong) {
  WorldRoom* nothing = new WorldRoom("yes");

  EXPECT_EQ('z', nothing->getBelong());

  delete nothing;
}

TEST(TestWorldRoom, TestGetNPC) {
  WorldRoom* nothing = new WorldRoom("yes");

  EXPECT_EQ(nullptr, nothing->getNPC());

  delete nothing;
}
