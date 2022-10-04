#include "Item.h"
#include "WeaponItem.h"
#include <iostream>
#include <string>

WeaponItem :: WeaponItem(std::string itemName, int dmg) {
  name = new Name(itemName);
  damage = dmg;
  isSpecial = true;
}

WeaponItem::~WeaponItem() {
  delete name;
  name = NULL;
}

void WeaponItem :: ability(NPC* npc, Player* p) {
  //If the npc is null return
  if (npc == nullptr || npc->getHealth()->getHealth() == 0) {
    std::cout << "You can't use that here!" << std::endl;
    return;
  }

  //attacks the npc for the amount of health specified in the item
  npc->getHealth()->changeHealth(-1 * damage);

  //Displays the damage stats and NPC health after attacking them
  std::cout << "You have attacked for " << damage << " damage!" << std::endl;
  std::cout << "They have " << npc->getHealth()->getHealth() <<
  " health remaining!" << std::endl;
}
