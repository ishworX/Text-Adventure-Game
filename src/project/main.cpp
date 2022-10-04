#include "Game.h"

int main() {
  //Creating the starting items for the player to have
  WeaponItem* sword = new WeaponItem("Beginner Sword", 5);
  HealthRestoreItem* basicPotion = new HealthRestoreItem("Basic Potion", 10);
  PoisonItem* rottenApple = new PoisonItem("Rotten Apple", 5);

  //Making an inventory object and filling it with the items created
  Inventory* playerInv = new Inventory();
  playerInv->addItem(sword, 1);
  playerInv->addItem(basicPotion, 10);
  playerInv->addItem(rottenApple, 1);

  //Creating a playe//r object and adding its inventory
  //This will also prompt the user to enter their name
  Player* player = new Player(playerInv);

  //Creating the gameMap
  //Empty inventory incase we don't want a world to have items
  Inventory* emptyInv = new Inventory();

  //Creating those treasureRooms
  TreasureRoom* tEarth = new TreasureRoom('e');
  TreasureRoom* tMars = new TreasureRoom('m');
  TreasureRoom* tJupiter = new TreasureRoom('j');
  TreasureRoom* tPluto = new TreasureRoom('p');

  //Creating 2 Inventories and their items for fighting rooms
  HealthRestoreItem* goldenApple = new HealthRestoreItem("Golden Apple", 40);
  WeaponItem* axe = new WeaponItem("Axe of Mayhem", 10);
  PoisonItem* bubble = new PoisonItem("Bubbling Brew", 20);

  //Creating the NPC and their appropriate rooms
  NPC* npcEarth = new NPC(3, 10, "EarthNPC");
  NPC* npcMars = new NPC(10, 15, "MarsNPC");
  NPC* npcJupiter = new NPC(2, 40, "JupiterhNPC");
  NPC* npcPluto = new NPC(5, 80, "PlutoNPC");
  FightingRoom* fightEarth = new FightingRoom(npcEarth, "1", goldenApple, 'e');
  FightingRoom* fightMars = new FightingRoom(npcMars, "2", axe, 'm');
  FightingRoom* fightJupiter = new FightingRoom(npcJupiter, "3",
  bubble, 'j');
  FightingRoom* fightPluto = new FightingRoom(npcPluto, "4", nullptr, 'p');

  //Creating the rest of the rooms that will be required for the game
  EmptyRoom* blank = new EmptyRoom();

  ShipRoom* ship = new ShipRoom();

  WorldRoom* earth = new WorldRoom("Earth");
  WorldRoom* mars = new WorldRoom("Mars");
  WorldRoom* jupiter = new WorldRoom("Jupiter");
  WorldRoom* pluto = new WorldRoom("Pluto");

  PuzzleRoom* pEarth = new PuzzleRoom("What is our team name?", "Illusive",
  'e');
  Hint* eHint = new Hint("Check GitLab repository name");
  pEarth->addHints(eHint);
  PuzzleRoom* pMars = new PuzzleRoom("Enter the reverse of the word: Balloon",
   "noollaB", 'm');
  PuzzleRoom* pJupiter = new PuzzleRoom("Enter the reverse of the word: Mongol",
   "lognoM", 'j');
  PuzzleRoom* pPluto = new PuzzleRoom("Enter the reverse of the word: ebube",
  "ebube", 'p');

  //Making a 2D array of Room* which is our game map
  Room* map[5][5] = {
    {blank, tEarth, pEarth, fightEarth, blank},
    {pJupiter, blank, earth, blank, tMars},
    {fightJupiter, jupiter, ship, mars, pMars},
    {tJupiter, blank, pluto, blank, fightMars},
    {blank, pPluto, fightPluto, tPluto, blank}
  };

  //Adding this map to the user, so they can manipulate their position
  Movement* mapBoy = new Movement();
  mapBoy->buildMap(map);
  player->addLocation(mapBoy);

  Game* game = new Game(player);

  bool won = game->playGame();

  if (won == true) {
    std::cout << "Congrats you've collected all the 4 artifacts!" << std::endl;
    std::cout << "With this power you were able to vanquish the great evil";
    std::cout << " known as Thunas. Congratulations on your win!" << std::endl;
  } else {
    std::cout << "Unfortunetly you've lost, please play again!" << std::endl;
  }

  //Deleting things
  delete game;
  delete blank;
  delete ship;
  delete earth;
  delete mars;
  delete jupiter;
  delete pluto;
  delete npcEarth;
  delete npcMars;
  delete npcJupiter;
  delete npcPluto;//
  delete fightEarth;
  delete fightMars;
  delete fightJupiter;
  delete fightPluto;
  delete pEarth;
  delete pMars;
  delete pJupiter;
  delete pPluto;
  delete tEarth;
  delete tMars;
  delete tJupiter;
  delete tPluto;
  delete goldenApple;
  delete axe;
  delete bubble;
  delete eHint;
}
