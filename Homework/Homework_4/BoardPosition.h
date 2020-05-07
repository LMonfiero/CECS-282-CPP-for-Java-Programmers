#pragma once
#include <iostream>
#include <vector>
#include "BoardDirection.h"

class BoardPosition {
    private:
        //variables here
        char mRow;
        char mCol;
    
    public:
        //Constructors
        //Default constructor
        BoardPosition();
        //That other constructor
        BoardPosition(const char &row, const char &col);
        //Accessors
        inline char getRow() const { return mRow; }
        inline char getCol() const { return mCol; }
        //Immutable so no mutators
        //Member methods
        bool InBounds(int boardSize);
        bool InBounds(int rows, int columns);
        static std::vector<BoardPosition> GetRectangularPositions(int rows, int columns);
        //Operators
        operator std::string() const;
        bool operator==(BoardPosition rhs);
        bool operator<(BoardPosition rhs);
        friend std::istream& operator>>(std::istream &lhs, BoardPosition& rhs);
        BoardPosition operator+(BoardDirection dir);
};

//Global operator
std::ostream& operator<<(std::ostream &lhs, BoardPosition rhs);