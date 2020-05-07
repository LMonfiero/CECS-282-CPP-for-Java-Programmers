#pragma once
#include <iostream>
#include <array>

class BoardDirection {
    private:
        //variables here
        char mRowDir;
        char mColDir;
    
    public:
        //Constructors
        //Default Constructor
        BoardDirection();
        //My other constructor
        BoardDirection(const char &rowDir, const char &colDir);
        //Accessors
        inline char getRowDir() const { return mRowDir; }
        inline char getColDir() const { return mColDir; }
        //Mutators//No mutators 
        //Static variable
        static std::array<BoardDirection, 8> CARDINAL_DIRECTIONS;
};