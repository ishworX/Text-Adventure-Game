#ifndef TREASUREROOM_H
#define TREASUREROOM_H

#include "Player.h"
#include "Inventory.h"
#include "Room.h"
#include "CompletionRoom.h"

/**
* This class contains all information related to the TreasureRoom
*/
class TreasureRoom : public CompletionRoom {
 public:
   /**
   * Class constructor for the TreasureRoom
   * Player's health.
   * @param[in] pointer to the inventory which contains the items the player
   * has access to.
   */
  TreasureRoom(char);

  /**
  * Class Destructor
  */
  virtual ~TreasureRoom() {}

  /**
  * @return true if player has beaten room else false
  */
  virtual bool isBeaten() {return beaten;}

  /**
  *tells the user what type of room they are in -- used in move()
  */
  virtual void roomInfo();
  /**
  *claims the treasure for the user
  * @param[in] pointer to the player
  */
  virtual bool doRoom(Player*);

 private:
  bool beaten;
  Item* roomInventory;
};

#endif
