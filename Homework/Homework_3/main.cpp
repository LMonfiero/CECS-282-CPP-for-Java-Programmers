#include "Tictactoe.h"
#include <iostream>
using namespace std;

int main()  {
    int playerTurn = 1;
    bool isWinner = false;
    int row, col;
    char gameOver;

    array<array<char, 3>, 3> board;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
        board[i][j] = 0;
        }
    }

    PrintBoard(board);

    while (!isWinner)
    {
        if (playerTurn % 2 == 1)//Odds = player one's turn
        {

            cout << "\nPlayer 1's (X) Turn: ";
            GetMove(row, col);
            while (!MoveIsValid(board, row, col))
            {
                GetMove(row,col);
            }
            board[row][col] = 1;

        }

        else if (playerTurn % 2 == 0)//Evens = player two's turns
        {
            cout << "\nPlayer 2's (O) Turn: ";
            GetMove(row, col);
            while (MoveIsValid(board, row, col) == false)
            {
                GetMove(row,col);
            }
            board[row][col] = -1;

        }
        PrintBoard(board);
        gameOver = CheckWinner(board);

        if (gameOver == 1)
        {
            isWinner = true;
            cout << "Player One has won the game!";
        }

        else if (gameOver == -1)
        {
            isWinner = true;
            cout << "Player Two has won the game!";
        }
        playerTurn++;
        
        if (playerTurn == 10)
        {
            isWinner = true;
        }
    }
}