#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Room.h"

/**
* This class contains all information related to Movement of the player
* Uses the idea of Matrices, posX is the row position,
*posY is the column position
*/
class Movement {
 public:
   /**
   * Class constructor, initializes posX and PosY
   */
    Movement();

    /**
    * Class Destructor
    */
    ~Movement();

   /**
   * @return PosX
   */
    int getPosX();

   /**
   * @return PosX
   */
    int getPosY();

   /**
   *Initializes the value of posX to the parameter value
   * @param[in] int which contains the new value
   */
    bool setPosX(int);


   /**
   *Initializes the value of posY to the parameter value
   * @param[in] int which contains the new value
   */
    bool setPosY(int);

   /**
   *Ensures that every move made by the player is valid
   */
    bool validMove();

   /**
   * Uses a two tier for loop to make all elements of the game map equal to
   *the map added in as the parameter
   * @param[in] room pointer which contains a two dimensional array
   */
  void buildMap(Room* [][5]);

  /**
  * @return a pointer to the room
  */
  Room* getRoom();

  /**
  *Checks if the treasure room is beaten
  * @return true if room is beaten else return false
  */
  bool beatenTreasureRoom();

 private:
  Room* gameMap[5][5];
  int posX;
  int posY;
};

#endif
