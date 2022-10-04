#include "Item.h"
#include <string>

Item :: Item() {
}

Item :: Item(std::string itemName) {
  name = new Name(itemName);
  isSpecial = false;
}

void Item :: ability(NPC* n, Player* p) {
  std::cout << "This item has no affect in this context" << std::endl;
}

bool Item :: getIsSpecial() {
  return isSpecial;
}

Name* Item :: getName() {
  return name;
}
