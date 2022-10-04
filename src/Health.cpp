#include "Health.h"
#include <iostream>


Health::Health() {
  healthPoints = 50;
}

Health::Health(int a) {
  //Makes sure the health is not negative -- we don't have undead in our game
    if (a <= 0) {
        healthPoints = 0;
    } else {
        healthPoints = a;
    }
    return;
}

int Health::getHealth() const {
    return healthPoints;
}

bool Health::changeHealth(int a) {
  //Makes sure that the lowest a health object can get is 0 -- we don't want
  //things to be extra dead
    if (healthPoints + a <= 0) {
        healthPoints = 0;
        return false;
    } else {
        healthPoints += a;
        return true;
    }
}
