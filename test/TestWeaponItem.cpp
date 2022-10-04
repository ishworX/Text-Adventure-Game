#include <string>
#include "WeaponItem.h"
#include "gtest/gtest.h"


TEST(TestWeaponItem, defaultConstructorTest) {
  std:: string itemName = "Shotgun";
  WeaponItem* weapon = new WeaponItem(itemName, 15);

  EXPECT_EQ(weapon->getName()->getName(), "Shotgun");
  EXPECT_TRUE(weapon->getIsSpecial());

  delete weapon;
}

TEST(TestWeaponItem, abilityTest) {
  std:: string itemName = "Sword";
  WeaponItem* weapon = new WeaponItem(itemName, 15);

  NPC* npc = new NPC(10, 50, "Bob");

  weapon->ability(npc, nullptr);
  EXPECT_EQ(npc->getHealth()->getHealth(), 35);

  delete weapon;
  delete npc;
}

TEST(TestWeaponItem, nullNPCTest) {
  WeaponItem* weapon = new WeaponItem("Bob", 15);

  weapon->ability(nullptr, nullptr);

  delete weapon;
}

TEST(TestWeaponItem, deadNPCTest) {
  std:: string itemName = "Sword";
  WeaponItem* weapon = new WeaponItem(itemName, 15);

  NPC* npc = new NPC(10, 0, "Bob");

  weapon->ability(npc, nullptr);
  EXPECT_EQ(npc->getHealth()->getHealth(), 0);

  delete weapon;
  delete npc;
}
