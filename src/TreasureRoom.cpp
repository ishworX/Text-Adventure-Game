#include "TreasureRoom.h"
#include "Inventory.h"
#include "Player.h"
#include "Room.h"
#include "CompletionRoom.h"
#include <vector>
#include <iostream>

TreasureRoom::TreasureRoom(char worldInit) {
  beaten = false;
  belong = worldInit;
  npc = nullptr;
  identifier = 3;
}

void TreasureRoom::roomInfo() {
  //Just tells the user what type of room they are in -- used in move()
  std::cout << "A treasure room" << std::endl;
}

bool TreasureRoom::doRoom(Player* player) {
  if (beaten == false) {
    //"Does the room" in this case, claims the treasure for the user
    player->addArtifact();
    std::cout << "You have claimed your treasure!" << std::endl;
  }
  return true;
}
