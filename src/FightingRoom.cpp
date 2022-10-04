#include "FightingRoom.h"
#include "CompletionRoom.h"
#include "Player.h"
#include "NPC.h"
#include "Inventory.h"
#include "Item.h"
#include "HealthRestoreItem.h"
#include "PoisonItem.h"
#include "WeaponItem.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

FightingRoom::FightingRoom(NPC* atc, std::string stringName, Item* inv,
  char worldInit) {
  npc = atc;
  roomInventory = inv;
  beaten = false;
  identifier = 1;
  belong = worldInit;
  return;
}

bool FightingRoom::isBeaten() {
  return beaten;
}

bool FightingRoom::doRoom(Player* player) {
  //Initializing all the variables we will need for the battle
  bool fighting = true;
  bool valid = false;
  int n = 0;
  std::string selection;
  Item* it;

  //Starting the fight process and displaying this to the user
  std::cout << "You have entered a fighting room!" << std::endl;
  std::cout << "--------------------------------------" << std::endl;
  std::cout << std::endl;

  //While loop which loops if the player is still fighting the NPC, this
  //stops when either the player or the NPC are dead
  while (fighting) {
    //Just in case somehow the player or NPC are dead at the start of the fight
    //If so, the fight is terminated before it begins
    if (player->getHealth()->getHealth() <= 0 ||
      npc->getHealth()->getHealth() <= 0) {
      fighting == false;
      break;
      }
    //Valid refers to the input of the user
    valid = false;

    //Calls the NPC memebr attack. This damages the player for a set damage
    npc->attack(player);

    //Informing the user that the NPC has attacked them, includes how much
    //damage was dealt
    std::cout << "NPC has attacked you for " << npc->getDamage() <<
    " damage." << std::endl;
    std::cout << "You have " << player->getHealth()->getHealth() <<
    " health remaining." << std::endl;
    std::cout << std::endl;

    //If the player died to the npc attack
    if (player->getHealth()->getHealth() <= 0) {
      return false;
    }

    //Informing the user of their items, and which can be used
    std::cout << "Your items are as follows:" << std::endl;
    std::cout << "Item Number : Name : Quantity" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;
    n = player->getInventory()->listInventory();

    std::map <Item*, int> tempMap = player->getInventory()->getGameInventory();

    //Creating of an iterator for the map
    std::map<Item*, int>::iterator itr = tempMap.begin();

    //While loop which forces the player to select a valid item to use in combat
    while (valid == false) {
      //To prevent over incrementing
      itr = tempMap.begin();
      //Informing the user that they can only use one item per turn
      std::cout << "Which item would you like to use?" << std::endl;
      std::cout << "You may only use one item. Enter to item number to use" <<
      std:: endl;

      //isItem is a bool which lets us know if they selected an item
      bool isItem = false;

      //itemInt is the integer after turning the string into and int
      int itemInt = 0;

      //Getting the users selection
      std::cin >> selection;
      std::cout << std::endl;

      //For loop which makes sure every element of the string is an int
      for (int index = 0; index < selection.size(); index++) {
        if (isdigit(selection[index])) {
          isItem = true;
        } else {
          isItem = false;
          break;
        }
      }

      //If the input was not an item, tell the user -- set valid = false
      if (isItem == false) {
        std::cout << "This is not a valid input" << std::endl;
      }

      //If the input was an item, then turn the string into an int
      if (isItem == true) {
        itemInt = stoi(selection);

        //For loop to get the iterator at its proper location
        for (int i = 0; i < itemInt; i++) {
          itr++;
        }

        //If the user enters an item not listed, this will catch it
        if (itemInt >= n) {
          std::cout << "This is not an item you have" << std::endl;
        } else {
          //Setting IT
          it = itr->first;

          player->useItem(it, npc);
          if (it->getIsSpecial() == false) {
            player->getInventory()->changeQuantity(it, -1);
          }

          valid = true;
          }
        }
        it = nullptr;
      }
    }

    //Resetting index to 0 for the next time the player enters a fight
    n = 0;

    //Nulling it
    it = NULL;

  if (player->getHealth()->getHealth() <= 0) {
  return false;
  }


  //Informs the user they have beaten the NPC and sets our value to true
  std::cout << "You have successfully beaten your opponent! Congratulations,"
  " this room is complete!" << std::endl;
  beaten = true;
  std::cout << "You discover spoils on your enemies remain, you loot them"
  << std::endl;
  player->getInventory()->addItem(roomInventory, 1);
  return true;
}

void FightingRoom::roomInfo() {
  //Just displays what type of room it is to the screen
  std::cout << "A fighting room" << std::endl;
}
