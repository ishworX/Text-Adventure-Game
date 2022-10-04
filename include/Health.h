#ifndef HEALTH_H
#define HEALTH_H


/**
* Contains all informations related to the health of the Player and the NPC.
*  Allows the manipulation of their health as well.
*/

class Health {
 public:
   /**
   * Class constructor, meant to create variables to use class functions
   * @param[in] int which is the number that the healthpoint will be set to.
   */
  Health();
  /**
  * Class constructor, sets the health point of the Player or NPC to the
  * specified number.
  * @param[in] int which is the number that the healthpoint will be set to.
  */
  Health(int);

  /**
  *Virtual Decontructor
  */
  ~Health() {}

   /**
   * Returns the healthPoints of the NPC or the player
   * @return The healthPoints of the NPC or the player
   */
  int getHealth() const;

    /**
    * Changes the healthPoints of the NPC or the player
    * @return true if successfully changed the health of the specified objects
    * false otherwise
    */
  bool changeHealth(int);

 private:
  int healthPoints;
};

#endif
