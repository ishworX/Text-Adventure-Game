#include "PoisonItem.h"
#include "Player.h"
#include "Inventory.h"
#include <string>
#include "gtest/gtest.h"


TEST(TestPoisonItem, defaultConstructorTest) {
  std:: string itemName = "Poisoned Apple";
  PoisonItem* poison = new PoisonItem(itemName, 15);

  EXPECT_EQ(poison->getName()->getName(), "Poisoned Apple");
  EXPECT_FALSE(poison->getIsSpecial());

  delete poison;
}

TEST(TestPoisonItem, abilityTest) {
  std:: string itemName = "Painkiller";
  PoisonItem* poisonItem = new PoisonItem(itemName, 15);

  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);

  poisonItem->ability(nullptr, player);

  EXPECT_EQ(player->getHealth()->getHealth(), 35);

  delete poisonItem;
  delete player;
  delete inventory;
}
