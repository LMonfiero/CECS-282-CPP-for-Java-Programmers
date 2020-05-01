#include "BoardDirection.h"
using namespace std;

//Default constructor
BoardDirection::BoardDirection() :mRowDir(0), mColDir(0)    {
}

//My other constructor
BoardDirection::BoardDirection(const char &rowDir, const char &colDir) 
    : mRowDir(rowDir), mColDir(colDir)  {
}

// Read as   { right, upper right, up, upper left, left, lower left, down, lower right }
array<BoardDirection, 8> BoardDirection::CARDINAL_DIRECTIONS = {
    BoardDirection(0, 1),
    BoardDirection(-1, 1),
    BoardDirection(-1, 0),
    BoardDirection(-1, -1),
    BoardDirection(0, -1),
    BoardDirection(1, -1),
    BoardDirection(1, 0),
    BoardDirection(1, 1)
};
