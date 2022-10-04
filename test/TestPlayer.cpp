#include <string>
#include <map>
#include "Item.h"
#include "HealthRestoreItem.h"
#include "PoisonItem.h"
#include "WeaponItem.h"
#include "NPC.h"
#include "Player.h"
#include "Movement.h"
#include "Inventory.h"
#include "gtest/gtest.h"


TEST(TestPlayer, constructorTest) {
  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);


  EXPECT_EQ(player->getHealth()->getHealth(), 50);

  delete inventory;
  delete player;
}


TEST(TestPlayer, getInventoryTest) {
  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);
  std:: map <Item*, int> gameInventory;

  gameInventory = inventory->getGameInventory();

  EXPECT_EQ(player->getInventory()->getGameInventory(), gameInventory);

  delete inventory;
  delete player;
}


TEST(TestPlayer, useItemTest) {
  Item* item = new Item("Item1");
  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);
  NPC* npc = new NPC(10, 50, "Robby");

  WeaponItem* weapon = new WeaponItem("Shotgun", 15);
  HealthRestoreItem* health = new HealthRestoreItem("Painkiller", 15);
  PoisonItem* poison = new PoisonItem("Poisoned Apple", 10);

  player->useItem(health, npc);
  EXPECT_EQ(player->getHealth()->getHealth(), 65);

  player->useItem(weapon, npc);
  player->useItem(poison, npc);

  delete item;
  delete inventory;
  delete player;
  delete npc;
  delete weapon;
  delete health;
  delete poison;
}


TEST(TestPlayer, useAnotherItemTest) {
  Item* item = new Item("Item1");
  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);
  NPC* npc = new NPC(10, 50, "Robby");

  WeaponItem* weapon = new WeaponItem("Shotgun", 15);
  HealthRestoreItem* health = new HealthRestoreItem("Painkiller", 15);
  PoisonItem* poison = new PoisonItem("Poisoned Apple", 10);

  player->useItem(poison, npc);
  EXPECT_EQ(player->getHealth()->getHealth(), 40);

  delete item;
  delete inventory;
  delete player;
  delete npc;
  delete weapon;
  delete health;
  delete poison;
}


TEST(TestPlayer, getNameTest) {
  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);
  Movement* map = new Movement();

  //player->move();
  player->getMovement();
  player->addLocation(map);
  player->help();

  EXPECT_EQ(player->getName()->getName(), "");

  delete inventory;
  delete player;
  delete map;
}

TEST(TestPlayer, nullGetMovementTest) {
  Inventory* inventory = new Inventory();
  Player* player = new Player(inventory);

  EXPECT_EQ(player->getMovement(), nullptr);

  delete inventory;
  delete player;
}

TEST(TestPlayer, addLocationTest) {
}

TEST(TestPlayer, moveTest) {
  Player* player = new Player(nullptr);

  //player->move(); REQUIRES USER INPUT

  delete player;
}
