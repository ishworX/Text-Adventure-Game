#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

Game::Game(Player* p) {
  player = p;
}

bool Game::playGame() {
  std::cout << "Welcome " << player->getName()->getName() << "!" << std::endl;
  std::cout << "Just creating the game for you to play" << std::endl;
  std::cout << std::endl;
  std::string line;
  std::ifstream myFile;
  myFile.open("lore.txt");

  if (myFile.is_open()) {
    while (std::getline(myFile, line)) {
      std::cout << line << '\n';
    }
    myFile.close();
  } else {
    std::cout << "Unable to open file";
  }

  std::cout << std::endl;
  //Main game while loop
  bool gameRun = true;
  bool win = false;

  //the int value of the string
  int use;

  //Used for checking the copletion of the game
  bool artifactGot = false;
  int id;

  //NPC pointer
  NPC* npc = nullptr;

  //Declaring variable that will be needed
  //The users choice
  std::string choice;

  //True if the user entered an int
  bool isInt;

  while (gameRun == true) {
    //Seeing if the player is dead
    if (player->getHealth()->getHealth() <= 0) {
      return false;
    }
    //Asking the user what they would like to do
    std::cout << "-------------------------------" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << std::endl;
    std::cout << "You are in: ";
    player->getMovement()->getRoom()->roomInfo();
    std::cout << std::endl;
    std::cout << "Artifacts owned: " << player->getArtifact() << std::endl;
    std::cout << "Enter the number for the following: " << std::endl;
    std::cout << "1 :- Move" << std::endl;
    std::cout << "2 :- To check the Inventory." << std::endl;
    std::cout << "3 :- To use the Item." << std::endl;
    std::cout << "Help :- To get help" << std::endl;
    std::cout << std::endl;
    std::cout << "Quit :- To exit the game -- progress will not be saved "
    << std::endl;
    std::cout << "-------------------------------" << std::endl;

    //Getting the users choice
    std::cin >> choice;
    std::cout << std::endl;

    //Checks if the string they entered is an int
    for (int i = 0; i < choice.size(); i++) {
      if (isdigit(choice[i])) {
        isInt = true;
      } else {
        isInt = false;
        break;
      }
    }

    //If the input was quit
    if (isInt == false && choice == "Quit") {
      gameRun = false;
      break;
    }

    //If the input was help
    if (isInt == false && choice == "Help") {
      player->help();
      continue;
    }

    //If the input was an int, change it to be
    if (isInt == true) {
      use = stoi(choice);
    }

    //If the input was not a int or a valid option
    if (isInt == false && choice != "Quit") {
      std::cout << "Please make a valid selection" << std::endl;
    } else if (isInt == false && choice != "Help") {
      std::cout << "Please make a valid selection" << std::endl;
    }

    //only do this switch case if the string was an int
    if (isInt == true) {
      //switch done on variable use, call appropriate functions based on choice
      switch (use) {
        //case that the user wants to move
        case 1:
        player->move();

        //If statement to see what kind of room was moved to
        //and do the room
        if (player->getMovement()->getRoom()->getIdentifier() == 1) {
          player->getMovement()->getRoom()->doRoom(player);
        } else if (player->getMovement()->getRoom()->getIdentifier() == 3) {
          player->getMovement()->getRoom()->doRoom(player);
        } else {
          player->getMovement()->getRoom()->doRoom();
        }
        break;

        //case that the user wants to see their inventory
        case 2:
        player->getInventory()->listInventory();
        break;

        //Case that the player wants to use their items
        case 3:
        this->doWork();
        //Seeing if the player is dead
        if (player->getHealth()->getHealth() <= 0) {
          return false;
        }
        break;

      //Default case
      default:
      std::cout << "Please enter a valid input" << std::endl;
      break;
    }
        std::cout << "-------------------------------" << std::endl;

        //If the player has all artifacsts -- beat all treasureRooms
        if (player->getArtifact() == 4) {
          win = true;
          gameRun = false;
        }
      }
    }

  return win;
}

void Game::doWork() {
  //Item pointer used for the vector
  Item* it;

  //bool for a valid input
  bool valid = false;

  //int that tracks the item number of the inventory displayed to user
  int n = 0;

  //Bool to see if the item exists in their inventory
  bool isItem;

  //items int value
  int itemInt;

  std::cout << "-------------------------------" << std::endl;
  std::cout << "Your items are as follows" << std::endl;
  std::cout << "Item Number : Name : Quantity"
  << std::endl;
  n = player->getInventory()->listInventory();

  std::map <Item*, int> tempMap = player->getInventory()->getGameInventory();

  //Creating of an iterator for the map
  std::map<Item*, int>::iterator itr = tempMap.begin();

  while (valid == false) {
    //Asking the use which item they'd like to use
    std::cout << "Which item would you like to use?" << std::endl;
    std::cout << "You may only use one item. Enter to item number to use" <<
    std::endl;

    //Giving the user a new an option if they dont want to use an item
    std::cout << "Enter No if you dont want to use an item;" << std:: endl;
    std::string selection;
    std::cin >> selection;

    //for loop to see if their selection is a string
    for (int index = 0; index < selection.size(); index++) {
      if (isdigit(selection[index])) {
        isItem = true;
      } else {
        isItem = false;
        break;
      }
    }

    //If the user doesnt want to use an item
    if (isItem == false && selection == "No") {
      valid = true;
    }

    //If the user enters a string that isn't no
    if (isItem == false && selection != "No") {
      std::cout << "This is not an item you have" << std::endl;
      valid = false;
    }

    //If the user enters a string that is all digits
    if (isItem == true) {
      itemInt = stoi(selection);

      //For loop to get the iterator at its proper location
      for (int i = 0; i < itemInt; i++) {
        itr++;
      }

      //Interal if the digit is bigger than the size of their inventory
      if (itemInt >= n) {
        std::cout << "This is not an item you have" << std::endl;
        break;
      }

      if (itemInt < n) {
        //It definition
        it = itr->first;

        //Getting the NPC of the room
        NPC* npc = player->getMovement()->getRoom()->getNPC();

        //If the player is in a fighting room they already beat
        if (player->getMovement()->getRoom()->getIdentifier() == 1 &&
        player->getMovement()->getRoom()->isBeaten() == true) {
          break;
        }

        //Player usese the selected item
        player->useItem(it, npc);
        if (it->getIsSpecial() == false) {
          player->getInventory()->changeQuantity(it, -1);
        }

        valid = true;
      }
    }
}}
