#include "OthelloBoard.h"
#include "OthelloView.h"
using namespace std;

//5 of 5 lines
OthelloBoard::OthelloBoard() : mBoard({Player::EMPTY}), mCurrentValue(0), mCurrentPlayer(Player::BLACK)   {
    //Initialize board
    //mBoard = {Player::EMPTY};
    mBoard[3][3] = Player::WHITE; // -1
    mBoard[3][4] = Player::BLACK; // 1
    mBoard[4][3] = Player::BLACK; // 1
    mBoard[4][4] = Player::WHITE; // -1
}

// OthelloBoard::std::vector<std::unique_ptr<OthelloMove>> GetPossibleMoves() const    {

// }

//12 of 18 lines ???Def not done 100% endgame
void OthelloBoard::ApplyMove(std::unique_ptr<OthelloMove> m) {
    //Update history of moves
    //Needa double check this 
    // char row = m->mPosition.GetRow(), col = m->mPosition.GetCol();
    //How do I store this into history???
    // mHistory.push_back(std::move(m);
    
    
    // mBoard[r][c] = mCurrentPlayer;
    //Make sure it's not a pass
    for (int dir = 0; dir < BOARD_SIZE; dir++)    {
        int count = 0;
        //New position to manipulate that is not the one we're currently looking at
        //Do I need to make a copy constructor for BoardPosition?
        //And a destructor?
        
        BoardPosition newPos {m->mPosition.GetRow(), m->mPosition.GetCol()};
        
        //Counts enemy piecess found in each direction and flips acoordingly
        while ((newPos.InBounds(BOARD_SIZE) && 
            mBoard[newPos.GetRow()][newPos.GetCol()] != mCurrentPlayer) || count == 0)   {
                newPos = newPos + BoardDirection::CARDINAL_DIRECTIONS[dir];
            
                //Increment if newPos isn't 0, set to -1 if 0; take that line limit!
                count = (mBoard[newPos.GetRow()][newPos.GetCol()] == Player::EMPTY ? (-1) : (count + 1));

                // // Old way
                // count ++;
                // if (mBoard[newPos.GetRow()][newPos.GetCol()] == Player::EMPTY)  {
                //     count = -1;
                // }
        }//end while

        for (int i = 0; i <= count; i++)    {
            //Flips pieces; last one is new piece
            mBoard[newPos.GetRow()][newPos.GetCol()] = mCurrentPlayer;
            newPos = newPos + BoardDirection::CARDINAL_DIRECTIONS[(dir + 4) % 8];
        }

    }
    // cout << endl << endl << row << " x " << col << endl;

    //Updates who the next player is going to be
    //Also needa double check this! But it should be right
    //If black, next player is white, otherwise next is black logic makes sense right????
    mCurrentPlayer = (GetCurrentPlayer() == Player::BLACK ? Player::WHITE : Player::BLACK);
}


//I'm assuming this is where the GetRectangularPositions is gonna be used? it looks similar
//Needa rego at this and study logic cause this was really rushed
//Really tired this is gibberish code lmao
//??? of 18 lines
/*
std::vector<std::unique_ptr<OthelloMove>> OthelloBoard::GetPossibleMoves() const    {
    //Just saw PositionIsEnemy; maybe this isn't needed
    Player otherPlayer = (GetCurrentPlayer() == Player::BLACK ? Player::WHITE : Player::BLACK);
    std::vector<std::unique_ptr<OthelloMove>> moveList;

    for (int r = 0; r < BOARD_SIZE; r++)    {
        for (int c = 0; c < BOARD_SIZE; c++)    {
            //OthelloMove currPos {BoardPosition{r, c}};
            auto currPos = std::make_unique<OthelloMove>(BoardPosition{r, c});
            if (mBoard[r][c] == mCurrentPlayer) {
                for (dir = 0; dir < BOARD_SIZE; dir++)  {
                    while (currPos.InBounds(BOARD_SIZE) && mBoard[currPos->GetRow()][currPos->getCol()] == otherPlayer) {
                        currPos = currPos + BoardDirection::CARDINAL_DIRECTIONS[dir];
                        if (mBoard[currPos->GetRow()][currPos->getCol()] == mCurrentPlayer)   {
                            //Figure out the rest? Maybe revisit entire logic
                            cout<<"temp; tbd";
                        }
                    }
                }
            }
        }
    }

    return moveList;
}
*/

//Doess less lines mean it's harder or easssier to implement hmmmmmm?
//??? of 12 lines
void OthelloBoard::UndoLastMove()   {
    //auto undo = make_unique<OthelloMove>(GetMoveHistory().back);
    //Before going further understand flipset a bit more pls;; watch the videos online
}