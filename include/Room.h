#ifndef ROOM_H
#define ROOM_H

#include <string>

class Player;
class NPC;

/**
* This class contains all information related to the different rooms in the game
*/
class Room {
 public:
  Room();

  /**
  * virtual function for getIdentifier
  */
  virtual int getIdentifier();

  /**
  * virtual function for roomInfo.
  */
  virtual void roomInfo() = 0;

  /**
  * virtual function for doRoom.
  */
  virtual void doRoom();

  /**
  * virtual function for doRoom(Player*).
  */
  virtual bool doRoom(Player*);

  /**
  * virtual function for isBeaten().
  */
  virtual bool isBeaten();

  /**
  * @return char which contains where the room belongs
  */
  virtual char getBelong();

  /**
  * @return the NPC in the room
  */
  virtual NPC* getNPC();

 protected:
  int identifier;
  char belong;
  NPC* npc;
};

#endif
