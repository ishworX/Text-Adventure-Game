#include <iostream>
#include <string>
#include "Hint.h"

Hint::Hint(std::string one) {
    hint1 = one;
}

Hint::Hint(std::string one, std::string two) {
    hint1 = one;
    hint2 = two;
}

std::string Hint::getHintOne() {
    return hint1;
}

std::string Hint::getHintTwo() {
  //Displays the exact amount of hints available for the puzzle
    if (hint2.empty() == true) {
        return "There is only one hint available: ";
    } else {
        return hint2;
    }
}
