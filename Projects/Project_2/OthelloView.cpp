#include "OthelloView.h"
// #include "OthelloBoard.h"

using namespace std;

void OthelloView::PrintBoard(std::ostream &s) const  {
    s << "\n- 0 1 2 3 4 5 6 7" << endl;
    for (int i = 0; i < OthelloBoard::BOARD_SIZE; i++)    {
        s << i;
        for (int j = 0; j < OthelloBoard::BOARD_SIZE; j++)    {
            if (mOthelloBoard->mBoard[i][j] == OthelloBoard::Player::EMPTY) {
                s << " .";
            }

            else if (mOthelloBoard->mBoard[i][j] == OthelloBoard::Player::BLACK)  {
                s << " B";
            }

            else if (mOthelloBoard->mBoard[i][j] == OthelloBoard::Player::WHITE)   {
                s << " W";
            }
        }
    s << endl;
  }
  s << endl;
}

//istringstream
//This isn't right, I think; at least the last part?
std::unique_ptr<OthelloMove> OthelloView::ParseMove(const std::string &strFormat)   {
    istringstream iss(strFormat);
    char temp, row, col;
    int r, c;
    iss >> temp >> r >> temp >> c >> temp;
    //End parsing
    row = r;
    col = c;
    BoardPosition parsed2 {row, col};
    auto parsed = std::make_unique<OthelloMove>(parsed2);
    return std::move(parsed);
}

//Somnething wrong with the bottom two
//3 lines
std::ostream& operator<< (std::ostream &lhs, const OthelloView &rhs)    {
    rhs.PrintBoard(lhs);
    string player = (rhs.mOthelloBoard->GetCurrentPlayer() == OthelloBoard::Player::BLACK ? "Black" : "White");
    return lhs << "\nCurrent Player: " << player << endl;
}

//This is probably very wrong -- Google is an "okay" friend
//1 line
std::ostream& operator<<(std::ostream &lhs, const OthelloMove &rhs) {
    return (operator<<(lhs, rhs.operator std::string()));
    // return lhs << (string)rhs;
}

