#include <iostream>
#include "OthelloGame.h"
using namespace std;

// 11 lines (15 limit)
void PrintBoard(const OthelloMatrix &board) {
  cout << "\n- 0 1 2 3 4 5 6 7" << endl;
  for (int i = 0; i < BOARD_SIZE; i++)    {
    cout << i;
    for (int j = 0; j < BOARD_SIZE; j++)    {
      if (board[i][j] == 0) {
        cout << " .";
      }

      else if (board[i][j] == 1)  {
        cout << " B";
      }

      else if (board[i][j] == -1)   {
        cout << " W";
      }
    }
    cout << endl;
  }
}

//1 line (2 limit)
bool InBounds(int row, int col) {
  return ((row >= 0 && row <= 7) && (col >= 0 && col <= 7));
}

//3 lines (3 limit)
bool IsValidMove(const OthelloMatrix &board, int row, int col)  {
  if ((InBounds(row, col) && board[row][col] == 0) || (row == -1 && col == -1)) {
    return 1;
  }
  return 0;
}

// 2 lines (2 limit)
void GetMove(int &row, int &col)  {
  char sParenthesis, comma, eParenthesis;
  cin >> sParenthesis >> row >> comma >> col >> eParenthesis;
}

//15 lines (20 limit)
void ApplyMove(OthelloMatrix &board, int row, int col, char currentPlayer)  {
  //Columns (Horizontal)
  //Rows (Vertical)
  /*
  1. Choose a direction (use a loop to choose direction)
  2. Start at (row, col) (use a new variable so you can always come back to this) 
  3. Take 1 step in direction if we find enemy piece, increase counter, repeat
  4. Why did we stop?
    a) Blank/Out of Bounds: return to step 1
    b) If counter == 0: return to step 1
    else: walk back and flip
      i) take one step backward
      ii) change square to player
      iii) repeat once for each enemy found (return to step i)
      iv) return to step 1
  */

  //New Method:
  //Arrays to be read as [r][c]
  //Read as   { right, upper right, up, upper left, left, lower left, down, lower right }
  std::array<int, BOARD_SIZE> rowDir = { 0, 1, 1, 1, 0, -1, -1, -1 };  //Rows directions
  std::array<int, BOARD_SIZE> colDir = { 1, 1, 0, -1, -1, -1, 0, 1 };  //Cols directions
  
  //Flips initially selected piece
  board[row][col] = currentPlayer;
  
  //Dir chooses direction of the search
  for (int dir = 0; dir < BOARD_SIZE; dir++)  {
    int r = row, c = col, counter = 0;
    //Counts enemy pieces found in each direction. If your piece is encountered in a route, 
    //exit loop and flip pieces until you get back to where you started. Also exits loop
    //if gone out of bounds
    while (((InBounds(r, c) && board[r][c] != currentPlayer)) || counter == 0) {
      r += rowDir[dir];
      c += colDir[dir];
      counter++;

      //The piece encountered is empty, therefore all counted pieces are void
      //In which case we go back to the top of the loop
      //Counter set to -1 to avoid flipping unnecessary pieces in the next for loop below
      if (board[r][c] == 0) {
        counter = -1;
      }
    }//end while
    //Walk backwards and flip pieces. Only flips if one of your piece encounters the first piece you placed
    for (int i = 0; i <= counter; i++)  {
      board[r][c] = currentPlayer;
      //(dir + 4) % 8 = opposite direction of current dir
      r += rowDir[(dir + 4) % 8];
      c += colDir[(dir + 4) % 8];
    }//end nested for loop
  }//end for loop
}

//5 lines (5 limit)
int GetValue(const OthelloMatrix &board)  {
  int sum = 0;
  for (int i = 0; i < BOARD_SIZE; i++)  {
    for (int j = 0; j < BOARD_SIZE; j++)  {
      sum += board[i][j];
    }
  }
  return sum;
}