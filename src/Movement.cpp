#include "Movement.h"
#include <iostream>

Movement::Movement() : posX(2), posY(2) {
  gameMap;
  //FOR SOME REASON -- initalizing values in the construtor
  //Doesn't work, so they get defaulted to "2" X,Y in the
  //Building of the map, fix later
}

Movement::~Movement() {
  for (int index1 = 0; index1 < 5; index1++) {
    for (int index2 = 0; index2 < 5; index2++) {
      gameMap[index1][index2] = NULL;
    }
  }
}

int Movement::getPosX() {
  return posX;
}

int Movement::getPosY() {
  return posY;
}

bool Movement::setPosX(int a) {
  //THIS MAY ALSO NEED TO GET CHANGE
  //Temp stores a the current position for later
  int temp = posX;

  //Changes the position to the desired selection
  posX = posX + a;

  //If the move is valid we are good and return true,
  //if not return to the temp and return false
  if (validMove() == true) {
    return true;
  } else {
    posX = temp;
    return false;
  }
}

bool Movement::setPosY(int a) {
  //Temp stores a the current position for later
  int temp = posY;

  //Changes the position to the desired selection
  posY = posY + a;

  //If the move is valid we are good and return true,
  //if not return to the temp and return false
  if (validMove() == true) {
    return true;
  } else {
    posY = temp;
    return false;
  }
}

bool Movement::validMove() {
  //If the new position is outside of the bounds of the map return false
  if (posX >= 5 || posX < 0) {
    return false;
  }

  //If the new position is outside of the bounds of the map return false
  if (posY >= 5 || posY < 0) {
    return false;
  }

  //If the move results in the player being at an empty spot
  //don't let them move there, and return false
  if (this->getRoom()->getIdentifier() == 4) {
    return false;
  }

  //If non of the above conditions are met, the move is valid
  return true;
}

void Movement::buildMap(Room* a1[5][5]) {
  //Two tier for loop to make all elements of the game map equal to
  //the map added in as the parameter
  for (int index1 = 0; index1 <= 5; index1++) {
    for (int index2 = 0; index2 <= 5; index2++) {
      gameMap[index1][index2] = a1[index1][index2];
    }
  }

  //This step wouldnt work in the construtor, but is allowed here... works fine
  posX = 2;
  posY = 2;
}

Room* Movement::getRoom() {
  return gameMap[posY][posX];
}

bool Movement::beatenTreasureRoom() {
  //Temp stores the identifier of the current room
  int temp = this->getRoom()->getIdentifier();

  //Char to store this treasure room's world
  char tempWorld;

  //Bool to determine if the prerequists have been met
  bool preReq1 = false;
  bool preReq2 = false;

  //If the current room is a TreasureRoom we have a few things to look at
  //else the move is allowable and return true
  if (temp == 3) {
    //If the prerequists have been beaten, then we can enter the TreasureRoom
    //Else we cannot
    //Finding which world the room belongs to
    tempWorld = this->getRoom()->getBelong();

    //Iterate through the game map to check if the prerequists have been met
    for (int index1 = 0; index1 < 5; index1++) {
      for (int index2 = 0; index2 < 5; index2++) {
        //If the map at this position belongs to the same world as the treasure
        if (gameMap[index1][index2]->getBelong() == tempWorld) {
          //If its a fighting or puzzle room return its beaten value
          if (gameMap[index1][index2]->getIdentifier() == 1) {
          preReq1 = gameMap[index1][index2]->isBeaten();
        } else if (gameMap[index1][index2]->getIdentifier() == 2) {
          preReq2 = gameMap[index1][index2]->isBeaten();
        }
      }
      }
    }
    //Return true if both preReqs are met
    if (preReq1 == true && preReq2 == true) {
      return true;
    } else {
      return false;
    }
  } else {
    return true;
  }
}
