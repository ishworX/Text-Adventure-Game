#ifndef WORLDROOM_H
#define WORLDROOM_H

#include "Room.h"
#include <string>

class WorldRoom : public Room {
 public:
   /**
   * Class constructor,
   * @param[in]  string which contains the name of the world
   */
  WorldRoom(std::string);

  /**
  * Class Destructor
  */
  ~WorldRoom() {}

  /**
  *tells the user what type of room they are in
  */
  virtual void roomInfo();

 private:
  std::string worldInfo;
};

#endif
