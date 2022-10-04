#include "Item.h"
#include "PoisonItem.h"
#include <iostream>
#include <string>

PoisonItem :: PoisonItem(std::string itemName, int poisnV) {
  name = new Name(itemName);
  poisonvalue = poisnV;
  isSpecial = false;
}

PoisonItem::~PoisonItem() {
  delete name;
  name = NULL;
}

void PoisonItem :: ability(NPC* npc, Player* plyr) {
  //Changes the players health according the the damage of the poisonItem
  //and lets the player know they have been damaged
  plyr->getHealth()->changeHealth(-1 * poisonvalue);
  std::cout << "Oh no! You've accidentally poisoned yourself for "
  << poisonvalue << " health, be careful next time!" << std::endl;
}
