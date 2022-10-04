#include "PuzzleRoom.h"
#include "Room.h"
#include <string>
#include <iostream>

PuzzleRoom::PuzzleRoom(std::string q, std::string a, char worldInit) {
  question = q;
  answer = a;
  beaten = false;
  tempAnswer;
  roomInventory;
  identifier = 2;
  belong = worldInit;
  hint = nullptr;
  npc = nullptr;
}

void PuzzleRoom::addHints(Hint* h) {
  hint = h;
}

void PuzzleRoom::getHints() {
    std::cout << hint->getHintOne() << ", " << hint->getHintTwo() << std::endl;
}

void PuzzleRoom::askQuestion() {
  //Displaying the proper formatting then the actual question to the user
  std::cout << "When inputting your answer please capitalize the "
  "first letter and make the rest lower case" << std::endl;
  std::cout << "Please solve the following puzzle:" << std::endl;
  std::cout << question << std::endl;
}

void PuzzleRoom::getAnswer() {
  //Stores the users answer as a temp answer
  tempAnswer;
  std::cin >> tempAnswer;

  //If the user asks for a hint
  if (tempAnswer == "Hint" || tempAnswer == "hint") {
    this->getHints();
  }
}

std::string PuzzleRoom::preGetAnswer() {
  //function mainly used for testing
  tempAnswer = "Sup!";
  return tempAnswer;
}

bool PuzzleRoom::checkAnswer() {
  //If the users answer is correct, they've beaten the room and return true
  //else return false
  if (tempAnswer == answer) {
    beaten = true;
    return true;
  } else {
    return false;
  }
}

void PuzzleRoom::roomInfo() {
  //Just says where the user is -- used in move()
  std::cout << "A puzzle room" << std::endl;
}

void PuzzleRoom::doRoom() {
  //Uses the member functions of the class to "Do the room"
  //While the room has not been answered ask, get the answer and validate it
  while (beaten == false) {
    this->askQuestion();
    this->getAnswer();
    this->checkAnswer();
  }

  //If the room has been beaten, display this to the user
  if (beaten == true) {
    std::cout << "This puzzle has been beaten!" << std::endl;
  }
}
