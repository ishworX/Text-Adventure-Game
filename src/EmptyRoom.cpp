#include "EmptyRoom.h"
#include <iostream>

EmptyRoom::EmptyRoom() {
  identifier = 4;
  belong = 'z';
  npc = nullptr;
}

void EmptyRoom::roomInfo() {
  //If this ever gets called in the code, then we have a problem with movement
  std::cout << "This should never be called" << std::endl;
}
