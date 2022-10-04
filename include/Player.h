#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Health.h"
#include "Name.h"
#include "Inventory.h"
#include "Movement.h"
#include "Item.h"

/**
* Class meant to represent the player and player stats
*/

class Player {
 public:
   /**
   * Class constructor for the player object
   * Player's health.
   * @param[in] pointer to the inventory which contains the items the player
   * has access to.
   */
    Player(Inventory*);

    /**
    * Class Destructor
    */
    ~Player();

    /**
    * @return  a pointer to the inventory object which the player uses
    */
    Inventory* getInventory();

    /**
    * Allows the player to use an item
    * @param[in] pointer to the item which the player uses
    */
    void useItem(Item*, NPC*);

    /**
    * @return  a pointer to the health of the player
    */
    Health* getHealth();

    /**
    * This method is in charge of moving the player from one position to another
    */
    bool move();

    /**
    * This method displays information that helps the player
    */
    void help();

    /**
    * @return a pointer to the name of the player
    */
    Name* getName();

    /**
    * @return  a pointer to the positon of the player
    */
    Movement* getMovement();

    /**
    * Initializes the location require to the map for the player to access
    * @param[in] pointer to a Movment object
    */
    void addLocation(Movement*);

    /**
    * Adds an artifact to the Player's inventory
    */
    void addArtifact() {artifactCounter++;}

    /**
    * @return the number of artifacts the player has
    */
    int getArtifact() {return artifactCounter;}

 private:
    Health * healthPoints;
    Name* name;
    Inventory* backPack;
    Movement* location;
    int artifactCounter;
};

#endif
