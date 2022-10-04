#ifndef WEAPONITEM_H
#define WEAPONITEM_H

#include "Name.h"
#include "Item.h"
#include "NPC.h"
#include <string>
#include <iostream>

/**
* This class contains all information related to weapon items
*/
class WeaponItem : public Item {
 public:
   /**
   * Class constructor, initializes the name of the item and
   *  the amount of damage points the weapon can inflict
   * @param[in] string which contains the name of the item
   * @param[in] int which is the amount of damagepoints
   */
  WeaponItem(std::string, int);

  /**
  * Class Destructor
  */
  ~WeaponItem();

  /**
  *Changes the NPC'S health according the the damage of the weapon item
  * @param[in] pointer to the NPC
  */
  void ability(NPC*, Player*) override;

 private:
  int damage;
};

#endif
