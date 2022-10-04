#include <iostream>
#include <map>
#include <utility>
#include "Inventory.h"
#include "Item.h"
#include "WeaponItem.h"
#include "gtest/gtest.h"

TEST(TestInventory, removeItemTestF) {
  Inventory* gamesIn = new Inventory();
  WeaponItem* names = new WeaponItem("Thor's Hammer", 1);
  int num = 1;
  gamesIn->addItem(names, num);

  EXPECT_FALSE(gamesIn->removeItem(names));

  delete gamesIn;
  delete names;
}

TEST(TestInventory, emptyRemoveItemTestF) {
  Inventory* gamesIn = new Inventory();
  WeaponItem* names = new WeaponItem("Thor's Hammer", 1);

  EXPECT_FALSE(gamesIn->removeItem(names));

  delete names;
  delete gamesIn;
}

TEST(TestInventory, listIventoryTest) {
  WeaponItem* names = new WeaponItem("Thor's Hammer", 1);
  Inventory* gamesIn = new Inventory();
  int num = 1;
  gamesIn->addItem(names, num);

  EXPECT_EQ(1, gamesIn->listInventory());

  delete gamesIn;
  delete names;
}

TEST(TestInventory, removeItemTestT) {
  Inventory* gamesIn = new Inventory();
  Item* orange = new Item("Oranges");
  int num = 12;
  gamesIn->addItem(orange, num);

  EXPECT_TRUE(gamesIn->removeItem(orange));

  delete gamesIn;
  delete orange;
}

TEST(TestInventory, addItemTestT) {
  Inventory* gamesIn = new Inventory();
  Item* orange = new Item("Oranges");
  int num = 12;

  EXPECT_TRUE(gamesIn->addItem(orange, num));

  delete gamesIn;
  delete orange;
}

TEST(TestInventory, addItemTestF) {
  Inventory* gamesIn = new Inventory();
  Item* orange = new Item("Oranges");
  int num = 12;

  gamesIn->addItem(orange, num);

  EXPECT_FALSE(gamesIn->addItem(orange, num));
  delete gamesIn;
  delete orange;
}

TEST(TestInventory, removeItemNotInInventoryTets) {
  Inventory* gamesIn = new Inventory();
  Item* orange = new Item("Oranges");

  EXPECT_FALSE(gamesIn->removeItem(orange));

  delete gamesIn;
  delete orange;
}

TEST(TestInventory, nullAddItemTest) {
  Inventory* gamesIn = new Inventory();

  EXPECT_FALSE(gamesIn->addItem(nullptr, 1));

  delete gamesIn;
}
