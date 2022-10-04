#include <iostream>
#include "Room.h"

Room::Room() {
}

int Room::getIdentifier() {
  return identifier;
}

void Room::doRoom() {
  std::cout << "There is nothing to do here..." << std::endl;
}

bool Room::doRoom(Player* p) {
  std::cout << "There is nothing to do here..." << std::endl;
  return false;
}

bool Room::isBeaten() {
  return true;
}

char Room::getBelong() {
  return belong;
}

NPC* Room::getNPC() {
  return npc;
}
