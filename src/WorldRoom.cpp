#include "WorldRoom.h"
#include <iostream>
#include <string>

WorldRoom::WorldRoom(std::string a) {
  identifier = 6;
  worldInfo = a;
  belong = 'z';
  npc = nullptr;
}

void WorldRoom::roomInfo() {
  //Just displays what type of room the user is in -- used in move()
  std::cout << "Main area of " << worldInfo << std::endl;
}
