#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "NPC.h"
#include "Name.h"

class Player; //Forward Declaration of the class to avoid circular dependency

/**
* Contains all informations related to the name of the item, the rarity of
*the item and its number identifier
*/

class Item {
 public:
   /**
   * Class constructor
   */
  Item();

  /**
  * Class Destructor
  */
  ~Item() {
    delete name;
    name = NULL;
  }

  /**
  * Class constructor, sets the health point of the Player or NPC to the
  * specified number.
  * @param[in] string which is the name of the item
  */
  Item(std::string);

  /**
  * virtual function for ability(NPC*).
  */
  virtual void ability(NPC*, Player*);

  /**
  * virtual function for getIsSpecial().
  */
  virtual bool getIsSpecial();

  /**
  * virtual function for getIsSpecial().
  */
  virtual Name* getName();

 protected:
  bool isSpecial;
  Name* name;
  int identifier;
};

#endif
