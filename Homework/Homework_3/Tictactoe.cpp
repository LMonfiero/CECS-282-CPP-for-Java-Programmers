#include "Tictactoe.h"
#include <iostream>
using namespace std;

// PrintBoard takes a 2-dimensional array parameter representing the game state
// and prints it to cout. See the spec for details on formatting the output.
void PrintBoard(const array<array<char, 3>, 3> &board)    {
    cout << "- 0 1 2" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i;
        for (int j = 0; j < 3; j++)
        {
            cout << " ";
            if (board[i][j] == 0)
            {
                cout << ".";
            }

            else if (board[i][j] == 1)
            {
                cout << "X";
            }

            else if (board[i][j] == -1)
            {
                cout << "O";
            }
            //cout << " " << board[i][j];
        }
    cout << endl;
    }
}

// GetMove uses cin to read the user's choice for where to move next on the 
// board. It does NOT update the game board with the move choice; it simply
// scans in values to the row and col variables, which will update whatever
// variables were used as arguments in the main. Do not check move validity
// in this function.
void GetMove(int &row, int &col)
{
    char DUMMY;
    cin >> row >> DUMMY >> col;
}

// MoveIsValid returns true if the board is empty at the requested row/col,
// and false otherwise. Used in main to see if the move is valid and alert
// the user if it is not.
bool MoveIsValid(const array<array<char, 3>, 3> &board, int row, int col)
{

    if ((row >= 3 || row < 0) || (col >= 3 || col < 0))
    {
        cout << "That's out of bounds! Try choosing between 0, 1, and 2: ";
        return false;
    }
    if (board[row][col] == 0)
    {
        return true;
    }
    cout << "That spot's taken! Try again: ";
    return false;
}

// CheckWinner returns looks to see if the game has a winner. It returns 
// 1 if player 1 is the winner, -1 if player 2 is the winner, or 0
// if there is no winner -- either because the game is a draw, or because
// the game is not over yet.
char CheckWinner(const array<array<char, 3>, 3> &board)
{
    for (int i = 0; i < 3; i++)
    {
        int xWinRow = 0;//Player 1
        int oWinRow = 0;//Player 2
        int xWinCol = 0;//Player 1
        int oWinCol = 0;//Player 2
        for (int j = 0; j < 3; j++)
        {
            //Checks Horizontal
            if (board[i][j] == 1)
            {
                xWinCol += 1;
            }

            else if (board[i][j] == -1)
            {
                oWinCol += 1;
            }

            //Checks Vertical
            if (board[j][i] == 1)
            {
                xWinRow += 1;
            }

            else if (board[j][i] == -1)
            {
                oWinRow += 1;
            }
        }//End j Loop
        if (xWinCol == 3 || xWinRow == 3)
        {
            return 1;
        }
        
        if (oWinCol == 3 || oWinRow == 3)
        {
            return -1;
        }
    }//End i Loop

    if (board[0][0] == board[1][1] && board [1][1] == board [2][2] && board[1][1] != 0)
    {
        return board[1][1];
    }

    if (board[2][0] == board[1][1] && board [1][1] == board [0][2] && board[1][1] != 0)
    {
        return board[1][1];
    }


    //Feels redundant because of playerTurn in main but 
    //I was a tad confused on the homework3.pdf instructions
    int outOfMoves = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 0)
            {
                outOfMoves++;
            }
        }
    }

    if (outOfMoves == 9) 
    {
        cout << "There are no more possible moves! The game's a draw!";
        return 0;
    }
    //cout << "There are no winners!";
    return 0;
}
