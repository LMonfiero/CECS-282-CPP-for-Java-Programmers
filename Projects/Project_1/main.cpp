#include <iostream>
#include "OthelloGame.h"
using namespace std;

//CECS 282
//Louis Monfiero - 016336266
//43 lines (limit 45)
int main()  {
    //Initialize Variables
    OthelloMatrix board;
    int row = 0, col = 0, pass = 0, piecesOnBoard = 4;
    char playerTurn = 1;
    
    //Initialize board
    // for (int i = 0; i < BOARD_SIZE; i++)    {
    //     for (int j = 0; j < BOARD_SIZE; j++)    {
    //         board[i][j] = 0;
    //     }
    // }
    board = {0};

    //Start board and display it
    board[3][3] = -1;
    board[4][4] = -1;
    board[3][4] = 1;
    board[4][3] = 1;
    PrintBoard(board);
    //Initializing variables to allow game to be played
    bool gameOn = true, valid = false;

    //Game starts here
    while (gameOn)  {
        //Checks if previous player's choice is a pass, thus counting 1 pass
        if (row == -1 && col == -1) {
            pass++;
        }
        
        //Determines player turn 1 = black, -1 = white and displays options
        if (playerTurn == 1)    {
            cout << "\nBlack's turn!\n";
        }
        else    {
            cout << "\nWhite's turn!\n";
        }
        cout << "\n(A choice of (-1, -1) counts as a pass move)\nEnter row and column in the format of (r, c): ";

        //Move is illegal
        while (!valid)    {
            GetMove(row, col);
            valid = IsValidMove(board, row, col);
            if (!valid) {
                cout << "\nMove is invalid, try again: ";
            }
        }
        valid = false;
        //Only applies move if it's not a pass and displays board
        if (row != -1 && col != -1) {
            ApplyMove(board, row, col, playerTurn);
        }
        PrintBoard(board);

        //Switches player
        playerTurn *= -1;
        
        //Player has passed; counts passes to determine game end via passing
        if (row == -1 && col == -1) {
            pass++;
        }

        //Checks if both players have passed or if the board is full
        if (pass == 2 || piecesOnBoard == 64) {
            gameOn = false;
        }  
        
        //Resets pass to 0 since only one player has passed
        //Increments pieces on the board
        pass = 0;
        piecesOnBoard++;
    }
    //Checks for winners and displays the winner
    int points = GetValue(board);
    if (points > 0)    {
        cout << "Player One (Black) Wins! Point tally: " << points;
    }

    else if (points < 0)   {
        cout << "Player Two (White) Wins! Point tally: " << points * (-1);
    }

    else    {
        cout << "It's a tie!";
    }
}
