#include <string>
#include <iostream>
#include "Name.h"

Name :: Name(std::string nameString) {
    name = nameString;
}

Name :: Name() {
  name;
}

std::string Name::getName() {
    return name;
}

void Name :: setName() {
  //Retrieves the players name!
  std::cout << "Please enter your name: ";
  std::cin >> name;
  std::cout << std::endl;
}
