#include "OthelloBoard.h"
#include "OthelloView.h"
using namespace std;

//4 of 5 lines
OthelloBoard::OthelloBoard() : mBoard({Player::EMPTY}), mCurrentValue(0), mCurrentPlayer(Player::BLACK)   {
    //Initialize board
    //mBoard = {Player::EMPTY};
    mBoard[3][3] = Player::WHITE; // -1
    mBoard[3][4] = Player::BLACK; // 1
    mBoard[4][3] = Player::BLACK; // 1
    mBoard[4][4] = Player::WHITE; // -1
}

// 20 of 18/21 lines
//Need to fix points
//I officially never want to name another function applymove lol the nightmares!
void OthelloBoard::ApplyMove(std::unique_ptr<OthelloMove> m) {
    //If it's a pass, simply update list and change players
    if (m->IsPass() == false)  {
        //Flip first piece and increment current val
        //Make sure it's not a pass
        for (int dir = 0; dir < BOARD_SIZE; dir++)    {
            int count = 0;
            BoardPosition newPos {m->mPosition.GetRow(), m->mPosition.GetCol()};
            //Counts enemy piecess found in each direction and flips acoordingly
            while ((newPos.InBounds(BOARD_SIZE) && mBoard[newPos.GetRow()][newPos.GetCol()] != mCurrentPlayer))   {
                newPos = newPos + BoardDirection::CARDINAL_DIRECTIONS[dir];
                //If you run into an empty piece or out of bounds break out of loop and check next direction
                if (mBoard[newPos.GetRow()][newPos.GetCol()] == Player::EMPTY || newPos.InBounds(BOARD_SIZE) == false)  {
                    count = 0;
                    break;
                }
                (PositionIsEnemy(newPos, mCurrentPlayer) ? count += 1 : count += 0);
            }//end while
            if (count > 0)   {
                for (int i = 0; i <= count; i++)    {
                    //Flips pieces
                    mBoard[newPos.GetRow()][newPos.GetCol()] = mCurrentPlayer;
                    newPos = newPos + BoardDirection::CARDINAL_DIRECTIONS[(dir + 4) % 8];
                }//end for
                //Old way // Just in case error in future
                // OthelloMove::FlipSet flips {(char) count, BoardDirection::CARDINAL_DIRECTIONS[dir]};
                // m->OthelloMove::AddFlipSet(flips);
                //One line version?
                m->OthelloMove::AddFlipSet(OthelloMove::FlipSet {(char) count, BoardDirection::CARDINAL_DIRECTIONS[dir]});
                (GetCurrentPlayer() == Player::BLACK ? mCurrentValue += count * 2 : mCurrentValue -= count * 2);
            }//end if
        }//end for
        //After flipping pieces and all that, we now place a piece and increment points!
        mBoard[m->mPosition.GetRow()][m->mPosition.GetCol()] = mCurrentPlayer;
        (GetCurrentPlayer() == Player::BLACK ? mCurrentValue += 1 : mCurrentValue -= 1);
    }//end if

    //Update history of moves
    //Updates who the next player is going to be
    //Also needa double check this! But it should be right
    mHistory.push_back(std::move(m));
    //If black, next player is white, otherwise next is black logic makes sense right????
    mCurrentPlayer = (GetCurrentPlayer() == Player::BLACK ? Player::WHITE : Player::BLACK);
}

//18 of 18/21 lines
std::vector<std::unique_ptr<OthelloMove>> OthelloBoard::GetPossibleMoves() const    {
    std::vector<std::unique_ptr<OthelloMove>> moveList;

    //Rows
    for (int r = 0; r < BOARD_SIZE; r++)    {
        //Cols
        for (int c = 0; c < BOARD_SIZE; c++)    {
            //Possible moves have to be empty
            if (mBoard[r][c] == Player::EMPTY)  {
                //Search in each direction
                for (int dir = 0; dir < BOARD_SIZE; dir++)    {
                    //current Position
                    BoardPosition cPos = BoardPosition(r, c) + BoardDirection::CARDINAL_DIRECTIONS[dir];
                    //If cPos is an enemy piece, keep incrementing position until you run into your piece
                    while (cPos.InBounds(BOARD_SIZE) && PositionIsEnemy(cPos, mCurrentPlayer)) {
                        cPos = cPos + BoardDirection::CARDINAL_DIRECTIONS[dir];
                        //Means you have a piece flanking the selected empty space at board[r][c]
                        //So take board[r][c] and take that position and list it as a possible move
                        if (cPos.InBounds(BOARD_SIZE) && mBoard[cPos.GetRow()][cPos.GetCol()] == mCurrentPlayer) {
                            //Row takes precedent in determining order
                            //Pass in possible move
                            unique_ptr<OthelloMove> posMove = make_unique<OthelloMove>(BoardPosition(r, c));
                            //SEE YA LATER REPEAT
                            //If it's not empty, check if the last in moveList is repeating
                            if (!moveList.empty())  {
                                if (*posMove == *moveList.back())   {
                                    break;
                                }
                            }
                            moveList.push_back(std::move(posMove));
                            //Check next direction
                        }
                    }
                }
            }
        }
    }
    if (moveList.empty())   {
        unique_ptr<OthelloMove> pass = make_unique<OthelloMove>(BoardPosition(-1, -1));
        moveList.push_back(std::move(pass));
    }
    return moveList;
}

//Doess less lines mean it's harder or easssier to implement hmmmmmm?
//12 of 12 lines
void OthelloBoard::UndoLastMove()   {
    //Give ownership of end to undo and remove it from mHistory
    auto undo = std::move(mHistory.back());//GetMoveHistory().back().get();
    mHistory.pop_back();
    //Set the selected position to an empty spot and changes value
    mBoard[undo->mPosition.GetRow()][undo->mPosition.GetCol()] = Player::EMPTY;
    mCurrentValue = (GetCurrentPlayer() == Player::BLACK ? mCurrentValue += 1 : mCurrentValue -= 1);
    //Check flip set to 'reverse' flips by following direction and number of flips
    //saved inside the flipset
    for (OthelloMove::FlipSet flip : undo->mFlips) {
        BoardPosition undoPos = undo->mPosition;
        for (int i = flip.mFlipCount; i > 0; i--)   {
            undoPos = undoPos + flip.mDirection;
            mBoard[undoPos.GetRow()][undoPos.GetCol()] = mCurrentPlayer;
        }
        mCurrentValue = (GetCurrentPlayer() == Player::BLACK ? mCurrentValue += flip.mFlipCount * 2 : mCurrentValue -= flip.mFlipCount * 2);
    }
    mCurrentPlayer = (GetCurrentPlayer() == Player::BLACK ? Player::WHITE : Player::BLACK);
}

bool OthelloBoard::IsFinished() {
    if (mHistory.size() > 1 && *mHistory.rbegin()[0] == BoardPosition(-1, -1)) {
        return *mHistory.rbegin()[0] == *mHistory.rbegin()[1];
    }
    return false;
}