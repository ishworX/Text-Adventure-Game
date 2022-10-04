#ifndef COMPLETIONROOM_H
#define COMPLETIONROOM_H

#include "Room.h"

/**
* This class contains all information related to the CompletionRoom
*/
class CompletionRoom : public Room {
 public:
   /**
   * Class constructor for the TreasureRoom
   */
    CompletionRoom();

    /**
    * Class Desstructor
    */
    virtual ~CompletionRoom() {}

   /**
   * @return true if player has beaten room else false
   */
  virtual bool isBeaten();

  /**
  * virtual function for roomInfo.
  */
  virtual void roomInfo() = 0;

 protected:
  bool beaten;
};

#endif
