#include <string>
#include <iostream>
#include "PuzzleRoom.h"
#include "Room.h"
#include "CompletionRoom.h"
#include "gtest/gtest.h"

TEST(TestPuzzleRoom, TestGetIdentifier) {
  std::string a = "Hi!";
  std::string b = "Sup!";
  PuzzleRoom* temple = new PuzzleRoom(a, b, 'a');
  temple->roomInfo();


  EXPECT_EQ(2, temple->getIdentifier());
  delete temple;
}

TEST(TestPuzzleRoom, TestIsBeaten) {
  std::string a = "Hi!";
  std::string b = "Sup!";
  PuzzleRoom* temple = new PuzzleRoom(a, b, 'a');
  temple->roomInfo();

  EXPECT_FALSE(temple->isBeaten());
  delete temple;
}

TEST(TestPuzzleRoom, TestCheckAnswerT) {
  std::string a = "Hi!";
  std::string b = "Sup!";
  PuzzleRoom* temple = new PuzzleRoom(a, b, 'a');
  temple->roomInfo();
  temple->askQuestion();
  temple->preGetAnswer();

  EXPECT_TRUE(temple->checkAnswer());
  delete temple;
}

TEST(TestPuzzleRoom, TestCheckAnswerF) {
  std::string a = "Hi!";
  std::string b = "Sup";
  PuzzleRoom* temple = new PuzzleRoom(a, b, 'a');
  temple->roomInfo();
  temple->askQuestion();

  EXPECT_FALSE(temple->checkAnswer());
  delete temple;
}

TEST(TestPuzzleRoom, addHintsTest) {
  Hint* hint = new Hint("yes", "no");
  PuzzleRoom* temple = new PuzzleRoom("a", "b", 'a');

  temple->addHints(hint);

  delete hint;
  delete temple;
}

TEST(TestPuzzleRoom, getAnswerTest) {
  PuzzleRoom* temple = new PuzzleRoom("a", "b", 'a');

  temple->getAnswer();

  delete temple;
}

TEST(TestPuzzleRoom, doRoomTest) {
  PuzzleRoom* temple = new PuzzleRoom("a", "b", 'a');

  //temple->doRoom(); REQUIERS USER INPUT

  delete temple;
}

TEST(TestPuzzleRoom, TestGetBelong) {
PuzzleRoom* nothing = new PuzzleRoom("a", "b", 'a');

  EXPECT_EQ('a', nothing->getBelong());

  delete nothing;
}

TEST(TestPuzzleRoom, TestGetNPC) {
  PuzzleRoom* nothing = new PuzzleRoom("a", "b", 'a');

  EXPECT_EQ(nullptr, nothing->getNPC());

  delete nothing;
}
