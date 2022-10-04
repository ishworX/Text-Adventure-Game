#ifndef NAME_H
#define NAME_H

#include <string>

/**
* Contains all informations related to the Name of the items, Player, and the NPC.
*/

class Name {
 public:
   /**
   * Class constructor, sets the NAME of the Player NPC or Item  to the
   * string parameter.
   * @param[in] string which is the Name to be initialized.
   */
    Name(std::string);

    /**
    * Class constructor
    */
    Name();

    /**
    * Class destructor
    */
    ~Name() {}

    /**
    *Gets the string stored as name
    * @return string which is the Name.
    */
std::string getName();

/**
* Sets the name of an item
*/
    void setName();

 private:
    std::string name;
};

#endif
