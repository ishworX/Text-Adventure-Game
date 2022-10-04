#include <vector>
#include <string>
#include "TreasureRoom.h"
#include "CompletionRoom.h"
#include "Inventory.h"
#include "Player.h"
#include "gtest/gtest.h"

TEST(TestTreasureRoom, TestIsBeaten) {
  TreasureRoom* treasureLand = new TreasureRoom('a');
  treasureLand->roomInfo();

  EXPECT_FALSE(treasureLand->isBeaten());
  delete treasureLand;
}

TEST(TestTreasureRoom, TestGetIdentifier) {
  TreasureRoom* treasureLand = new TreasureRoom('a');
  treasureLand->roomInfo();

  EXPECT_EQ(3, treasureLand->getIdentifier());
  delete treasureLand;
}

TEST(TestTreasureRoom, TestDoRoom) {
  Inventory* playerI = new Inventory();
  Player* Div = new Player(playerI);
  TreasureRoom* treasureLand = new TreasureRoom('a');
  treasureLand->roomInfo();

  EXPECT_TRUE(treasureLand->doRoom(Div));
  delete treasureLand;
  delete playerI;
  delete Div;
}

TEST(TestTreasureRoom, TestGetBelong) {
  TreasureRoom* nothing = new TreasureRoom('a');

  EXPECT_EQ('a', nothing->getBelong());

  delete nothing;
}

TEST(TestTreasureRoom, TestGetNPC) {
  TreasureRoom* nothing = new TreasureRoom('a');

  EXPECT_EQ(nullptr, nothing->getNPC());

  delete nothing;
}
