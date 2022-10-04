#include <string>
#include <map>
#include "Item.h"
#include "HealthRestoreItem.h"
#include "PoisonItem.h"
#include "WeaponItem.h"
#include "Player.h"
#include "Inventory.h"
#include "gtest/gtest.h"

TEST(TestNPC, constructorTest) {
  NPC* npc = new NPC(10, 25, "Robby");

  EXPECT_EQ(npc->getHealth()->getHealth(), 25);

  delete npc;
}


TEST(TestNPC, getNameTest) {
  NPC* npc = new NPC(10, 25, "Dhaka");

  EXPECT_EQ(npc->getName()->getName(), "Dhaka");

  delete npc;
}


TEST(TestNPC, getDamageTest) {
  NPC* npc = new NPC(10, 25, "Baka");

  EXPECT_EQ(npc->getDamage(), 10);

  delete npc;
}


TEST(TestNPC, attackTestAlive) {
  NPC* npc = new NPC(10, 25, "Danjo");
  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);

  npc->attack(player);
  EXPECT_EQ(player->getHealth()->getHealth(), 40);

  delete npc;
  delete inventory;
  delete player;
}

TEST(TestNPC, attackTestDead) {
  NPC* npc = new NPC(50, 25, "Robby");
  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);

  npc->attack(player);
  EXPECT_EQ(player->getHealth()->getHealth(), 0);

  delete npc;
  delete inventory;
  delete player;
}
