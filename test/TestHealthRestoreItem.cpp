#include "HealthRestoreItem.h"
#include "Player.h"
#include "Inventory.h"
#include <string>
#include "gtest/gtest.h"


TEST(TestHealthRestoreItem, defaultConstructorTest) {
  std:: string itemName = "Painkiller";
  HealthRestoreItem* health = new HealthRestoreItem(itemName, 15);

  EXPECT_EQ(health->getName()->getName(), "Painkiller");
  EXPECT_FALSE(health->getIsSpecial());

  delete health;
}

TEST(TestHealthRestoreItem, abilityTest) {
  std:: string itemName = "Painkiller";
  HealthRestoreItem* healthRestore = new HealthRestoreItem(itemName, 15);

  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);

  healthRestore->ability(nullptr, player);

  EXPECT_EQ(player->getHealth()->getHealth(), 65);

  delete inventory;
  delete player;
  delete healthRestore;
}
