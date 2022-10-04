#ifndef FIGHTINGROOM_H
#define FIGHTINGROOM_H

#include "Player.h"
#include "NPC.h"
#include "Item.h"
#include "CompletionRoom.h"
#include <string>

/**
* Creates room for combat in game. Player will fight NPC in the generated room.
*/

class FightingRoom : public CompletionRoom {
 public:
  /**
  * Class constructor, sets the status pointer to a new InCartState,
  * and the shipType to a null pointer.
  * @param[in]  Pointer to the NPC which the player will fight
  * @param[in]  string which contain the name of the NPC being fought.
  * @param[in] Pointer to the inventory which allows the player to use
  * the items in the inventory to fight
  */
  FightingRoom(NPC*, std::string, Item*, char);

  /**
  * Class Destructor
  */
  virtual ~FightingRoom() {}

     /**
     * Initiates combat between the player and the NPC
     * @param[in]  Pointer to the player
     * @return true when the player beats the NPC false otherwise.
     */
  virtual bool doRoom(Player*);

     /**
     * Returns a pointer to the Player's Inventory.
     * @return a pointer to the inventory of the player.
     */
  Item* getRoomInventory();

  /**
  *tells the user what type of room they are in
  */
  virtual void roomInfo();

  /**
  * @returns true if the NPC in the room has been beaten else false
  */
  bool isBeaten();

 private:
  NPC* npc;
  Item* roomInventory;
  bool beaten;
};

#endif // FIGHTINGROOOM_H_INCLUDED
