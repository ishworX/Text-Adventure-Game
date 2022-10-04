#include "Item.h"
#include "HealthRestoreItem.h"
#include <string>
#include <iostream>

HealthRestoreItem :: HealthRestoreItem(std::string itemName, int heal) {
  name = new Name(itemName);
  healing = heal;
  isSpecial = false;
}

void HealthRestoreItem :: ability(NPC* npc, Player* plyr) {
  //Adds health to the players health object, then informs the user
  plyr->getHealth()->changeHealth(healing);
  std::cout << "You have restored " << healing << " health!" << std::endl;
}
