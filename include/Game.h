#ifndef GAME_H
#define GAME_H

#include "HealthRestoreItem.h"
#include "PoisonItem.h"
#include "WeaponItem.h"
#include "FightingRoom.h"
#include "PuzzleRoom.h"
#include "TreasureRoom.h"
#include "ShipRoom.h"
#include "EmptyRoom.h"
#include "WorldRoom.h"
#include "Player.h"
#include "NPC.h"

/**
* Contains all information related to the running of the game
* This class controls and kick starts the entire game
*/
class Game {
 public:
   /**
   * Class constructor,
   * @param[in] pointer to the player
   */
  Game(Player*);

  /**
  * This function commences the game, checks all the different
  * conditions of the players progress
  * @return true if the player gets all 4 artifacts and wins the game else false
  * else false
  */
  bool playGame();

  /**
  * This function is in charge of initializing several actions that
  * with the player in the game
  */
  void doWork();

 private:
  Player* player;
};

#endif
