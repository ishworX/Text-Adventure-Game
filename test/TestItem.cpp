#include <string>
#include "Item.h"
#include "NPC.h"
#include "Player.h"
#include "Inventory.h"
#include "gtest/gtest.h"


TEST(TestItem, getNameTest) {
  std:: string itemName = "Infinity Stone";
  Item* item = new Item(itemName);
  Name* name = new Name(itemName);
  item->ability(nullptr, nullptr);

  EXPECT_EQ(item->getName()->getName(), "Infinity Stone");

  delete item;
  delete name;
}


TEST(TestItem, getIsSpecial_Test) {
  std:: string itemName = "Granade";
  Item* item = new Item(itemName);
  Inventory* inv = new Inventory();
  Player* player = new Player(inv);

  item->ability(nullptr, player);
  EXPECT_FALSE(item->getIsSpecial());

  delete item;
  delete inv;
  delete player;
}

TEST(TestItem, getIdentifier_Test) {
  std:: string itemName = "Artifact";
  Item* item = new Item(itemName);
  NPC* npc = new NPC(10, 50, "Gunda");

  item->ability(npc, nullptr);

  delete item;
  delete npc;
}

TEST(TestItem, abilityTest) {
  Item* item = new Item("Bob");

  item->ability(nullptr, nullptr);

  delete item;
}
