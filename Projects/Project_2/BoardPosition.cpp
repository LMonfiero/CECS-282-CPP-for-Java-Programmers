#include "BoardPosition.h"
#include <sstream>
using namespace std;

//BoardPosition class
//Done! (I hope)
//Default constructor initializing to 0
BoardPosition::BoardPosition() :mRow(0), mCol(0)    {
}

//My constructor
BoardPosition::BoardPosition(const char &row, const char &col)
    : mRow(row), mCol(col)  {
}

//Checks if in bounds of a square with size of boardsize
bool BoardPosition::InBounds(int boardSize) {
    return ((mRow >= 0 && mRow <= boardSize - 1) && (mCol >= 0 && mCol <= boardSize - 1));
}

//Checks if in bounds of non-square but rectangule of rows rows and columns columns
bool BoardPosition::InBounds(int rows, int columns){
    return ((mRow >= 0 && mRow <= rows - 1) && (mCol >= 0 && mCol <= columns - 1));
}

//The thing with the vector
vector<BoardPosition> BoardPosition::GetRectangularPositions(int rows, int columns)  {
    //Initialize board
    vector<BoardPosition> myBoard;
    for (int i = 0; i <= rows; i++)  {
        for (int j = 0; j <= columns; j++)   {
            myBoard.push_back(BoardPosition(i, j));
        }
    }
    return myBoard;
}

//String form of BoardPos
BoardPosition::operator std::string() const {
    ostringstream os;
    os << "(" << (int)mRow << ", " << (int)mCol << ")";
    return os.str();
}

//Other operator overloads here
bool BoardPosition::operator==(BoardPosition rhs)   {
    return mRow == rhs.mRow && mCol == rhs.mCol;
}

bool BoardPosition::operator<(BoardPosition rhs)    {
    if (mRow <= rhs.mRow)    {
        return mCol < rhs.mCol;
    }
    return false;
}

BoardPosition BoardPosition::operator+(BoardDirection dir)  {
    BoardPosition lhs;
    lhs.mCol = mCol + dir.GetColDir();
    lhs.mRow = mRow + dir.GetRowDir();
    return lhs;
}

//Friend Operator
//I keep getting ascii values :(
std::istream& operator>>(std::istream &lhs, BoardPosition& rhs)  {
    char parenthesisOne, comma, parenthesisTwo;
    lhs >> parenthesisOne >> rhs.mRow >> comma >> rhs.mCol >> parenthesisTwo;
    //Unsure if there's a better way. Only way I've done that's worked so
    //Rip there's a problem when you go size 10 or more //EDIT: Yeah that makes sense since mrow and mcol are chars
    //Converting with static_cast didn't work for me
    rhs.mRow -= '0';
    rhs.mCol -= '0';
    return lhs;
}

//Global Operator
//Does not accept const & because it can point to null
std::ostream& operator<<(std::ostream &lhs, BoardPosition rhs)  {
    lhs << static_cast<string>(rhs);
    return lhs;
}