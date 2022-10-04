#ifndef POISONITEM_H
#define POISONITEM_H

#include "Name.h"
#include "Player.h"
#include <string>
#include <iostream>

/**
* This class contains all information related to poison items
*/
class PoisonItem : public Item {
 public:
   /**
   * Class constructor, initializes the name of the item and
   *  the amount of damage points to the Player's health.
   * @param[in] string which contains the name of the item
   * @param[in] int which is the amount of damage to the
   * Player's health.
   */
  PoisonItem(std::string, int);

      /**
      * Class Destructor
      */
  ~PoisonItem();

  /**
  *Changes the players health according the the damage of the poisonItem
  * and lets the player know they have been damaged
  * @param[in] pointer to the player
  */
  void ability(NPC*, Player*) override;

 private:
  int poisonvalue;
};

#endif
