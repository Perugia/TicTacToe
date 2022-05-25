#ifndef _TICTACTOE_H_ // include guard
#define _TICTACTOE_H_
#include <iostream>

using namespace std;

class Player {
  int score = 0;
};

class TicTacToe {
  int table[3 * 3]{0};
  Player players[2]{};

  int getTableIndexValue(int);
  void setTableIndexValue(int,int);
  string indexToVal(int);
  bool reqInput(int);
  bool* didWin();
  void printTable();

  public:  
    TicTacToe();
    void startGame();
};

#endif /* _TICTACTOE_H_ */