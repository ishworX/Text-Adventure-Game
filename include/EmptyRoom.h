#ifndef EMPTYROOM_H
#define EMPTYROOM_H

#include "Room.h"

class EmptyRoom : public Room {
 public:
   /**
   * Class constructor, initializes the identifier variable
   */
    EmptyRoom();

  /**
  *Destructor
  */
  ~EmptyRoom() {}

  /**
  *tells the user what type of room they are in
  */
  virtual void roomInfo();
};

#endif
