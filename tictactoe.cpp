#include "tictactoe.h"
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <limits>
using namespace std;

  TicTacToe::TicTacToe()
  {
    system("clear");
    cout << "Game Started !" << endl;
  };

  int TicTacToe::getTableIndexValue(int index)
  {
    return table[index];
  };

  void TicTacToe::setTableIndexValue(int index, int value)
  {
    table[index] = value;
  };

  string TicTacToe::indexToVal(int index)
  {
    string value;
    switch(index)
    {
      case 1:
        value = "X";
        break;
      case 2:
        value = "O";
        break;
      default:
        value = " ";
    }
    return value;
  };

  bool TicTacToe::reqInput(int index)
  {
    int pId = index % 2;
    int tableIndex;
    cout << "\nTurn Player" << pId + 1 << "\n\nEnter the area number you want to select : ";
    cin >> tableIndex;
    if(!std::cin.good())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return 1;
    }
    if(tableIndex < 1 || tableIndex > 9)
    {
      return 1;
    }
    if(getTableIndexValue(tableIndex - 1) != 0)
    {
      return 1;
    }
    
    setTableIndexValue(tableIndex - 1,pId + 1);
    return 0;
  };

  bool* TicTacToe::didWin()
  {
    static bool winInfo[2]{0}; // Information about whether the zeroth index won, who won the first index.
    for(int i = 0; i < 9; i += 3)
      {
        if(getTableIndexValue(i) == 1 && getTableIndexValue(i + 1) == 1 && getTableIndexValue(i + 2) == 1)
        {
          winInfo[0] = 1;
          winInfo[1] = 0;
        }
        else if(getTableIndexValue(i) == 2 && getTableIndexValue(i + 1) == 2 && getTableIndexValue(i + 2) == 2)
        {
          winInfo[0] = 1;
          winInfo[1] = 1;
        }
      }
    
    for(int i = 0; i < 3; i++)
      {
        if(getTableIndexValue(i) == 1 && getTableIndexValue(i + 3) == 1 && getTableIndexValue(i + 6) == 1)
        {
          winInfo[0] = 1;
          winInfo[1] = 0;
        }
        else if(getTableIndexValue(i) == 2 && getTableIndexValue(i + 3) == 2 && getTableIndexValue(i + 6) == 2)
        {
          winInfo[0] = 1;
          winInfo[1] = 1;
        }
      }

    if(getTableIndexValue(0) == 1 && getTableIndexValue(4) == 1 && getTableIndexValue(8) == 1)
    {
      winInfo[0] = 1;
      winInfo[1] = 0;
    }
    else if(getTableIndexValue(0) == 2 && getTableIndexValue(4) == 2 && getTableIndexValue(8) == 2)
    {
      winInfo[0] = 1;
      winInfo[1] = 1;
    }

    if(getTableIndexValue(2) == 1 && getTableIndexValue(4) == 1 && getTableIndexValue(6) == 1)
    {
      winInfo[0] = 1;
      winInfo[1] = 0;
    }
    else if(getTableIndexValue(2) == 2 && getTableIndexValue(4) == 2 && getTableIndexValue(6) == 2)
    {
      winInfo[0] = 1;
      winInfo[1] = 1;
    }
    
    return winInfo;
  };

  void TicTacToe::printTable()
  {
    for(int i = 2; i >= 0; i--){
      if(i == 2)
        {
          cout << "+---+---+---+" << endl;
        }
      
        cout << "| " << indexToVal(getTableIndexValue(i * 3)) << " | " << indexToVal(getTableIndexValue(i * 3 + 1)) << " | " << indexToVal(getTableIndexValue(i * 3 + 2)) << " |" << endl;
      
      if(i == 2 || i == 1)
        {
        cout << "+---+---+---+" << endl;
        }
      
      if(i == 0)
        {
          cout << "+---+---+---+" << endl;
        }
    }
  };

  void TicTacToe::startGame()
  {
    int gameRound = 0;
    cout << "Welcome to tictactoe" << endl;
    
    while(gameRound < 9)
    {
      printTable();
      cout << "Player1 : x    Player2 : o" << endl;
      bool isItFull =reqInput(gameRound);
      if(isItFull)
      {
        system("clear");
        cout << "Please select an empty field! or Use numbers from 1 to 9" << endl;
        continue;
      }
      bool* didWIN = didWin();
      if(didWIN[0])
      {
        system("clear");
        cout << "Player" << didWIN[1] + 1 << " WINS !" << endl;
        break;
      }
      
      gameRound++;
      system("clear");
    }

    printTable();

  } 