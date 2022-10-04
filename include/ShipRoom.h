#ifndef SHIPROOM_H
#define SHIPROOM_H

#include "Room.h"

/**
* This class contains all information related to Shiproom
*/
class ShipRoom : public Room {
 public:
   /**
   * Initializes the identifier variable
   */
  ShipRoom();

  /**
  * Class Destructor
  */
  ~ShipRoom() {}

  /**
  *Displays what type of room the user is in -- used in move()
  */
  virtual void roomInfo();
};

#endif
