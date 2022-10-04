#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "CompletionRoom.h"
#include "FightingRoom.h"
#include "Player.h"
#include "NPC.h"
#include "Inventory.h"
#include "Item.h"
#include "HealthRestoreItem.h"
#include "PoisonItem.h"
#include "WeaponItem.h"
#include "Room.h"
#include "gtest/gtest.h"

TEST(TestFightingRoom, TestGetIdentifier) {
  NPC* david = new NPC(10, 50, "David");
  PoisonItem* rottenApple = new PoisonItem("Rotten Apple", 50);
  FightingRoom* arena = new FightingRoom(david, "Si", rottenApple, 'a');

  arena->roomInfo();

  EXPECT_EQ(1, arena->getIdentifier());
  delete david;
  delete rottenApple;
  delete arena;
}

TEST(TestFightingRoom, TestIsBeaten) {
  NPC* david = new NPC(10, 50, "David");
  PoisonItem* rottenApple = new PoisonItem("Rotten Apple", 50);
  FightingRoom* arena = new FightingRoom(david, "Si", rottenApple, 'a');

  arena->roomInfo();

  EXPECT_FALSE(arena->isBeaten());
  delete david;
  delete rottenApple;
  delete arena;
}

TEST(TestFightingRoom, TestDoRoomPlayerHF) {
  NPC* david = new NPC(10, 50, "David");
  Inventory* playerI = new Inventory();
  PoisonItem* rottenApple = new PoisonItem("Rotten Apple", 50);
  Player* div = new Player(playerI);
  FightingRoom* arena = new FightingRoom(david, "Si", rottenApple, 'a');

  rottenApple->ability(david, div);
  arena->roomInfo();

  EXPECT_FALSE(arena->doRoom(div));

  delete david;
  delete playerI;
  delete div;
  delete arena;
  delete rottenApple;
}
TEST(TestFightingRoom, TestGetBelong) {
  NPC* david = new NPC(10, 50, "David");
  PoisonItem* rottenApple = new PoisonItem("Rotten Apple", 50);
  FightingRoom* nothing = new FightingRoom(david, "Si", rottenApple, 'a');

  EXPECT_EQ('a', nothing->getBelong());

  delete nothing;
  delete david;
  delete rottenApple;
}

// TEST(TestFightingRoom, TestGetNPC) {
//   NPC* david = new NPC(10, 50, "David");
//   PoisonItem* rottenApple = new PoisonItem("Rotten Apple", 50);
//   FightingRoom* nothing = new FightingRoom(david, "Si", rottenApple, 'a');
//
//   EXPECT_EQ(david, nothing->getNPC());
//
//   delete nothing;
//   delete david;
//   delete rottenApple;
// }

// TEST(TestFightingRoom, TestDoRoomT) {
//   NPC* david = new NPC(10, 50, "David");
//   Inventory* davidI = new Inventory();
//   Inventory* playerI = new Inventory();
//   Player* div = new Player(playerI);
//   FightingRoom* arena = new FightingRoom(david, "Si", davidI);
//
//   arena->roomInfo();
//
//   EXPECT_TRUE(arena->doRoom(div));
// }
//
// TEST(TestFightingRoom, TestDoRoomIsBeatenT) {
//   NPC* david = new NPC(10, 50, "David");
//   Inventory* davidI = new Inventory();
//   Inventory* playerI = new Inventory();
//   Player* div = new Player(playerI);
//   FightingRoom* arena = new FightingRoom(david, "Si", davidI);
//
//   arena->roomInfo();
//   arena->doRoom(div);
//
//   EXPECT_TRUE(arena->isBeaten());
// }
