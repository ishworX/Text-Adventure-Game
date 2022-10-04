#include "ShipRoom.h"
#include <iostream>

ShipRoom::ShipRoom() {
  identifier = 5;
  belong = 'z';
  npc = nullptr;
}

void ShipRoom::roomInfo() {
  //Just displays what type of room the user is is -- used in move()
  std::cout << "The ship" << std::endl;
}
