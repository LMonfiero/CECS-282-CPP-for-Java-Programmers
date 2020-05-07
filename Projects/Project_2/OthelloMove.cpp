#include "OthelloMove.h"
#include <sstream>
using namespace std;

//1/1 Line -- ???
bool OthelloMove::operator==(const OthelloMove &rhs)    {
    //return (mRow == rhs.mRow && mCol == rhs.mCol ? true : false)
    return (mPosition == rhs.mPosition ? true : false);
}

//3/5 Lines
OthelloMove::operator std::string() const   {
    //Uses BoardPosition form of operator std::string()
    ostringstream os;
    os << "(" << +mPosition.GetRow() << ", " << +mPosition.GetCol() << ")";
    return os.str();
}