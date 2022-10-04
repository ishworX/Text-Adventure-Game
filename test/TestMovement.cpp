#include <iostream>
#include <string>
#include "NPC.h"
#include "Movement.h"
#include "Room.h"
#include "Inventory.h"
#include "PuzzleRoom.h"
#include "FightingRoom.h"
#include "TreasureRoom.h"
#include "EmptyRoom.h"
#include "CompletionRoom.h"
#include "ShipRoom.h"
#include "WorldRoom.h"
#include "gtest/gtest.h"

TEST(TestMovement, TestGetPosX) {
  Movement* spaceX = new Movement();

  EXPECT_EQ(2, spaceX->getPosX());

  delete spaceX;
}

TEST(TestMovement, TestGetPosY) {
  Movement* spaceY = new Movement();

  EXPECT_EQ(2, spaceY->getPosY());

  delete spaceY;
}

TEST(TestMovement, TestSetPosXF) {
  Movement* space = new Movement();

  EXPECT_FALSE(space->setPosX(9));

  delete space;
}

TEST(TestMovement, TestSetPosYF) {
  Movement* space = new Movement();

  EXPECT_FALSE(space->setPosY(9));

  delete space;
}

TEST(TestMovement, TestSetPosXFN) {
  Movement* space = new Movement();

  EXPECT_FALSE(space->setPosX(-9));

  delete space;
}

TEST(TestMovement, TestSetPosYFN) {
  Movement* space = new Movement();

  EXPECT_FALSE(space->setPosY(-9));

  delete space;
}

// TEST(TestMovement, buildMapTest) {
//   Movement* space = new Movement();
//   EmptyRoom* empty = new EmptyRoom();
//
//   Room* map[5][5] = {
//     {empty, empty, empty, empty, empty},
//     {empty, empty, empty, empty, empty},
//     {empty, empty, empty, empty, empty},
//     {empty, empty, empty, empty, empty},
//     {empty, empty, empty, empty, empty},
//   };
//
//   space->buildMap(map);
//
//   delete space;
//   delete empty;
//
// }
//
// TEST(TestMovement, beatenTreasureRoomTest) {
//   Movement* space = new Movement();
//   EmptyRoom* empty = new EmptyRoom();
//   TreasureRoom* treasure = new TreasureRoom('a');
//
//   Room* map[5][5] = {
//     {empty, empty, empty, empty, empty},
//     {empty, empty, empty, empty, empty},
//     {empty, empty, treasure, empty, empty},
//     {empty, empty, empty, empty, empty},
//     {empty, empty, empty, empty, empty},
//   };
//
//   space->buildMap(map);
//
//   delete space;
//   delete empty;
//   delete treasure;
// }
