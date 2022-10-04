#ifndef PUZZLEROOM_H
#define PUZZLEROOM_H

#include "Inventory.h"
#include "CompletionRoom.h"
#include "Hint.h"
#include <string>

/**
* Creates room for puzzles in game. Player will solve puzzles in the generated room.
*/

class PuzzleRoom : public CompletionRoom {
 public:
   /**
   * Class constructor,
   * @param[in]  string which contains the puzzle  question
   * @param[in]  string which contains the puzzle answer
   */
  PuzzleRoom(std::string, std::string, char);

  /**
  * Class Destructor
  */
  ~PuzzleRoom() {}

  void getHints();

  /**
  *Displays the proper formatting then the actual question to the user
  */
  void askQuestion();

  /**
  *Stores the users answer as a temp answer
  */
  void getAnswer();

  std::string preGetAnswer();

  void addHints(Hint*);

  bool checkAnswer();

  /**
  *tells the user what type of room they are in
  */
  virtual void roomInfo();


  virtual void doRoom();

 private:
  std::string question;
  std::string answer;
  std::string tempAnswer;
  Inventory* roomInventory;
  Hint* hint;
};

#endif
