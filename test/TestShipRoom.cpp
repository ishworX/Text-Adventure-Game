#include <iostream>
#include "ShipRoom.h"
#include "Inventory.h"
#include "Player.h"
#include "gtest/gtest.h"

TEST(TestShipRoom, TestGetIdentifier) {
  ShipRoom* sunny = new ShipRoom();
  sunny->roomInfo();
  sunny->doRoom();

  EXPECT_EQ(5, sunny->getIdentifier());
  delete sunny;
}

TEST(TestShipRoom, TestIsBeaten) {
  ShipRoom* sunny = new ShipRoom();
  sunny->roomInfo();
  sunny->doRoom();

  EXPECT_TRUE(sunny->isBeaten());
  delete sunny;
}

TEST(TestShipRoom, TestDoRoom) {
  ShipRoom* sunny = new ShipRoom();
  Inventory* gamerr = new Inventory();
  Player* div = new Player(gamerr);
  sunny->roomInfo();
  sunny->doRoom();

  EXPECT_FALSE(sunny->doRoom(div));
  delete sunny;
  delete gamerr;
  delete div;
}

TEST(TestShipRoom, TestGetBelong) {
  ShipRoom* nothing = new ShipRoom();

  EXPECT_EQ('z', nothing->getBelong());

  delete nothing;
}

TEST(TestShipRoom, TestGetNPC) {
  ShipRoom* nothing = new ShipRoom();

  EXPECT_EQ(nullptr, nothing->getNPC());

  delete nothing;
}
