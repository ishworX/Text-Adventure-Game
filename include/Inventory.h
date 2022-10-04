#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>

class Item;

/**
* Contains all items to be used by the player in the game
*/

class Inventory {
 public:
   /**
   * Class constructor
   */
    Inventory();

    /**
    * Class Destructor
    */
    ~Inventory() {}

    /**
    * Removes the item from the Player inventory.
    * @param[in] Pointer to the item.
    * @return true if successfully removed the item from the Player inventory.
    * false otherwise
    */
    bool removeItem(Item*);

    /**
    * Adds the item to the Player inventory.
    * @param[in] Pointer to the item.
    * @param[in] int which is the number of the item that is to be added.
    * @return true if successfully added the item to the Player inventory.
    * false otherwise
    */
    bool addItem(Item*, int);

    /**
    * Displays the item in the Player inventory to the Player.
    */
    int listInventory();

    /**
    * Changes the quantity of the item in the Player inventory.
    * @param[in] Pointer to the item.
    * @param[in] int which is the amount of the item that is to be adjusted.
    */
    void changeQuantity(Item*, int);

    /**
    * Returns the Inventory of the player
    * @return the Inventory of the player
    */
    std::map <Item*, int> getGameInventory();

 private:
    std::map <Item*, int> gameInventory;
};

#endif
