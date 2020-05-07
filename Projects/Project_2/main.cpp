#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

//69/80 Lines ;)
int main(int argc, char* argv[]) {	
	// Initialization
	auto board = std::make_shared<OthelloBoard>(); // the state of the game board
	OthelloView v(board); // a View for outputting the board via operator<<
	string userInput; // a string to hold the user's command choice
	unique_ptr<OthelloMove> m;//initialize m

	// Main loop
	bool gameOn = false;
	do {
		//Prints board, prompt, and possible moves
		cout << v <<  "\nPossible Moves: " << endl;
		auto moveList = board->GetPossibleMoves();
		for (auto itr = moveList.begin(); itr != moveList.end(); itr++)	{
			cout << *(*itr) << " ";
		}
		
		cout << "\nChoose a command: \n";
		getline(cin, userInput);
		cout << "DEBUG OUTPUT: You entered: \"" << userInput << "\"\n";

		if (userInput == "quit")	{
			cout << "\nQuitting Game...\n";
			gameOn = true;
		}

		else if (userInput == "showHistory")	{
			cout << "\nShowing history: \n";
			//auto Doesn't work ???
			// auto historyList = board->GetMoveHistory();
			char prevPlayer = (char) board->GetCurrentPlayer() * -1;
			for (auto itr = board->GetMoveHistory().rbegin(); itr != board->GetMoveHistory().rend(); itr++)	{
				string player = prevPlayer == 1 ? "Black" : "White";
				prevPlayer *= -1;
				if (*(*itr) == BoardPosition {-1, -1})	{
					cout << player << ": pass" << endl;
				}

				else	{
					cout << player << ": " << *(*itr) << endl;
				}
			}
		}

		else if (userInput == "showValue")	{
			cout << "Current points: " << board->GetValue();
		}

		else if (userInput.substr(0, 4) == "undo")	{
			string nString = userInput.substr(5);
			stringstream ss(nString); 
    		int n = 0; 
    		ss >> n; 
			cout << "Preparing to undo " << n << " moves...\n";
			for (int i = 0; i < n; i++)	{
				//call undo
				if (board->GetMoveHistory().size() > 0)	{
					board->UndoLastMove();
				}
				
				else {
					cout << "\nHistory is empty!\n";
				}
			}
		}

		else if (userInput.substr(0, 4) == "move")	{
			//if onlyPass isn't (-1, -1), it will apply move normally
			auto onlyPass = moveList.begin();
			//Lets you pass any time you want - Debug purposes
			// if (userInput.substr(5) == "pass")	{
			//rhs of && is to make sure that pass is the only possible move REAL STUFF HERE
			if (userInput.substr(5) == "pass" && (*(*onlyPass) == BoardPosition {-1, -1}))	{
				cout << "\nPassing.\n";
				m = v.ParseMove("(-1, -1)");
				board->ApplyMove(std::move(m));
			}

			//If they try to apply a move when pass is the only available option
			else if (*(*onlyPass) == BoardPosition {-1, -1})	{
				while (userInput != "move pass")	{
					cout << "No possible moves available! Must pass!\n";
					getline (cin, userInput);
				}
				cout << "\nPassing.\n";
				m = v.ParseMove("(-1, -1)");
				board->ApplyMove(std::move(m));
			}
			
			else {
				bool valid = false;
				m = v.ParseMove(userInput.substr(5));
				for (auto itr = moveList.begin(); itr != moveList.end(); itr++)	{
					if (*m == *(*itr))	{
						// cout << "Applying the move " << *m << endl;
						board->ApplyMove(std::move(m));
						valid = true;
						break;
					}	
				}
				cout << (!valid ? "\nInvalid Move/Cannot Pass!\n" : "");
			}
		}

		else {
			cout << "\nInvalid input!\n";
		}

		//Checks if there's 2 passes
		if (board->IsFinished())	{
			cout << "Game has been passed twice! Game over!";
			gameOn = board->IsFinished();
		}

		//Message if game is over; declares  winner
		if (gameOn)	{
			cout << (board->GetValue() > 0 ? "\nPlayer 1 (B) " : "\nPlayer 2 (W) ")
				<< "has won! Congratulations!\n";
		}

	} while (!gameOn);
}