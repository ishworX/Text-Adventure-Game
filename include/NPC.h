#ifndef NPC_H
#define NPC_H

#include "Health.h"
#include "Name.h"
#include <string>

class Player;
/**
* Contains all informations related to the NPC.
*/
class NPC {
 public:
   /**
   *Constructor for a NPC object
   * @param[in] int which contains the amount of damage the NPC can inflict
   * @param[in] int which is the amount of health point the NPC has
   * @param[in] string which contains the Name of the NPC
   */
    NPC(int, int, std::string);

    /**
    *Destructor for a NPC object
    */
    ~NPC();

    /**
    *Gets the Health* stored as healthPoints
    */
    Health* getHealth();

    /**
    *Gets the Name* stored as name
    */
    Name* getName();

    /**
    *Gets the int stored as damage
    */
    int getDamage();

    /**
    *attacks another NPC
    * @param[in] pointer to the Player that is being attacked.
    */
    void attack(Player*);

 private:
    Health* healthPoints;
    Name* name;
    int damage;
};
#endif
