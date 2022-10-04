#include <iostream>
#include <map>
#include <utility>
#include "Inventory.h"
#include "Item.h"

Inventory :: Inventory() {
    gameInventory;
}

bool Inventory::removeItem(Item* throwAway) {
  //Ensures the user cannot throw away a special item -- prevents soft locks
  if (throwAway->getIsSpecial() == true) {
    std::cout << "This item is special, and cannot be removed." << std::endl;
    return false;
  }

  //If the user tries to throw away an item they don't have, not sure if it
  //will happen, but better to be safe than sorry -- else removes the specified
  //item from the inventory
  if (gameInventory.find(throwAway) == gameInventory.end()) {
    std::cout << "Item cannot be removed, because it is not in inventory.";
    std::cout << " It should be impossible to see this message in game.";
    std::cout << std::endl;
    return false;
  } else {
    gameInventory.erase(throwAway);
    return true;
    }
  }

bool Inventory :: addItem(Item* onGround, int tic) {
  if (onGround == nullptr) {
    return false;
  }
  //If the utem they are trying to add already exists in the inventory just
  //change the quantity rather than add another instance of it in the
  //inventory -- else adds another instance in the inventory
  if (gameInventory.find(onGround) != gameInventory.end()) {
    std::cout << "Item is already in Inventory, quantity has been changed.";
    std::cout << std::endl;
    changeQuantity(onGround, tic);
    return false;
  } else {
    gameInventory.insert(std::pair<Item*, int> (onGround, tic));
    return true;
  }
}

int Inventory :: listInventory() {
  //Int counter
  int counter = 0;
  //Displaying the inventory to the screen
  for (auto const& imple : gameInventory) {
     std::cout << counter << " : " << imple.first->getName()->getName() <<
      " : " << imple.second << std::endl;
      counter++;
    }

    return counter;
}

void Inventory :: changeQuantity(Item* onGround, int ticTok) {
  if (ticTok < 0) {
    gameInventory[onGround] += ticTok;
  } else {
    if ((gameInventory[onGround] + ticTok) < 0) {
      std::cout << "Cannot remove that many items! " << std::endl;
    } else {
      gameInventory[onGround] += ticTok;
    }
  }

  //Removes item if the quanity is 0
  if (gameInventory[onGround] == 0) {
    this->removeItem(onGround);
  }
}

std::map <Item*, int> Inventory::getGameInventory() {
  return gameInventory;
}
