#include "NPC.h"
#include "Player.h"
#include <iostream>
#include <string>

NPC::NPC(int attackPower, int healthInt, std::string nameString) {
    damage = attackPower;
    healthPoints = new Health(healthInt);
    name = new Name(nameString);
}

NPC::~NPC() {
  delete healthPoints;
  delete name;
  healthPoints = NULL;
  name = NULL;
}

Health* NPC::getHealth() {
    return healthPoints;
}

Name* NPC::getName() {
    return name;
}

int NPC::getDamage() {
    return damage;
}

void NPC::attack(Player* defender) {
  //Makes the NPC attack the user for the amount of damage they have
    int attackPower = this->getDamage();
    defender->getHealth()->changeHealth(-1*attackPower);
}
