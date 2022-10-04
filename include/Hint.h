#ifndef HINT_H
#define HINT_H

#include <iostream>
#include <string>

/**
* Outputs different hints that helps the player during the game
*/
class Hint {
 public:
   /**
   * Class constructor, Creates a hint object with one hint
   * @param[in] string which is the hint to display to the Player.
   */
    Hint(std::string);

    /**
    * Class constructor, Creates a hint object with two hints
    * @param[in] the two parameters are the hints to display to the Player.
    */
    Hint(std::string, std::string);

    /**
    * Destructor for a hint object
    */
    ~Hint() {}

    /**
    * Returns the string hint1
    * @return the string which is the hint.
    */
    std::string getHintOne();

    /**
    * Returns the string hint1
    * @return the string which is the hint.
    */
    std::string getHintTwo();

 private:
    std::string hint1;
    std::string hint2;
};

#endif
