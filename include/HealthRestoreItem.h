#ifndef HEALTHRESTOREITEM_H
#define HEALTHRESTOREITEM_H

#include "Name.h"
#include "Player.h"
#include <string>
#include <iostream>

/**
* This class is used to increase the health of the Player
*/

class HealthRestoreItem : public Item {
 public:
   /**
   * Class constructor, initializes the name of the item and
   *  the amount of health point to increase the Player's health.
   * @param[in] string which contains the name of the item.
   * @param[in] int which is the amount of health point to increase the
   * Player's health.
   */
  HealthRestoreItem(std::string, int);

  /**
  * Class Destructor
  */
  ~HealthRestoreItem() {
    delete name;
    name = NULL;
  }

  /**
  * Uses the selected item to increase the health of the player.
  * @param[in] Pointer to the Player.
  */
    void ability(NPC*, Player*) override;

 private:
  int healing;
};

#endif
