#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"
#include "Health.h"
#include "Name.h"
#include "Inventory.h"
#include "Movement.h"
#include "Item.h"

Player :: Player(Inventory* inv) {
  healthPoints = new Health(50);
  name = new Name();
  name->setName();
  backPack = inv;
  location = nullptr;
  artifactCounter = 0;
}

Player::~Player() {
  delete healthPoints;
  delete name;
  healthPoints = NULL;
  name = NULL;
}

Inventory* Player :: getInventory() {
  return backPack;
}

void Player :: useItem(Item* item, NPC* npc) {
  //Player using the item
  item->ability(npc, this);
}

Health* Player :: getHealth() {
  return healthPoints;
}

bool Player :: move() {
  //Storng the current location of the player
  int tempx = location->getPosX();
  int tempy = location->getPosY();

  //initalizing bools which will be required for moving the player
  bool right = false;
  bool left = false;
  bool up = false;
  bool down = false;
  bool accessable = true;

  //Displaying to the user their options of where to move
  std::cout << "Where would you like to move to?" << std::endl;
  std::cout << "Your options are as follows:" << std::endl;
  //Check room up one, down one, left and right one

  //Moves the player, sees if its valid -- if it is change the corresponding
  //bool to say so, it not leave it as false, then resets the player
  //to their original position

  //Right
  if (location->setPosX(1) == true) {
    std::cout << "To the right is: ";
    location->getRoom()->roomInfo();
    right = true;
    location->setPosX(-1);
  }
  //Left
  if (location->setPosX(-1) == true) {
    std::cout << "To the left is: ";
    location->getRoom()->roomInfo();
    left = true;
    location->setPosX(1);
  }
  //Up
  if (location->setPosY(-1) == true) {
    std::cout << "Forwards there is: ";
    up = true;
    location->getRoom()->roomInfo();
    location->setPosY(1);
  }
  //Down
  if (location->setPosY(1) == true) {
    std::cout << "Backwards there is: ";
    down = true;
    location->getRoom()->roomInfo();
    location->setPosY(-1);
  }

  //Gettings the users choice as to where they would like to move
  std::cout << "Please indication you choice from the following list"
  << std::endl;
  std::cout << "Right, Left, Forwards, Backwards - using proper capitalization"
  << std::endl;

  //Gets the players selection
  std::string choice;
  std::cin >> choice;
  std::cout << std::endl;

  //If the player has selected a direction and it has been determined as valid
  //move the player there. If the location they have chosen to move to is a
  //TreasureRoom ensure that the corresponding puzzle and fighting rooms have
  //been beaten first, elese return message saying the door is locked
  //IF the plahyer chose to move to an invalid location, display this message
  //to them
  if (choice == "Right" && right == true) {
    location->setPosX(1);
    if (location->beatenTreasureRoom() == true) {
      return true;
    } else {
      std::cout << "This door is locked! Try beating other rooms first"
      << std::endl;
      location->setPosX(-1);
      return false;
    }
  } else if (choice == "Left" && left == true) {
    location->setPosX(-1);
    if (location->beatenTreasureRoom() == true) {
      return true;
    } else {
      std::cout << "This door is locked! Try beating other rooms first"
      << std::endl;
      location->setPosX(1);
      return false;
    }
  } else if (choice == "Forwards" && up == true) {
    location->setPosY(-1);
    if (location->beatenTreasureRoom() == true) {
      return true;
    } else {
      std::cout << "This door is locked! Try beating other rooms first"
      << std::endl;
      location->setPosY(1);
      return false;
    }
  } else if (choice == "Backwards" && down == true) {
    location->setPosY(1);
    if (location->beatenTreasureRoom() == true) {
      return true;
    } else {
      std::cout << "This door is locked! Try beating other rooms first"
      << std::endl;
      location->setPosY(-1);
      return false;
    }
  } else {
    std::cout << "You cannot move there!" << std::endl;
    return false;
  }
}

void Player :: help() {
  std::string line;
  std::ifstream myFile;
  myFile.open("help.txt");

  if (myFile.is_open()) {
    while (std::getline(myFile, line)) {
      std::cout << line << '\n';
    }
    myFile.close();
  } else {
    std::cout << "Unable to open file";
  }
}

Name* Player :: getName() {
  return name;
}

Movement* Player::getMovement() {
  return location;
}

void Player::addLocation(Movement* map) {
  location = map;
}
