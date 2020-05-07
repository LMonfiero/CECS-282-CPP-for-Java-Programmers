#include "BoardPosition.h"
#include <string>
//#include "BoardDirection.h"
using namespace std;

int main()  {
    BoardPosition name1 { 3, 2 };
    BoardPosition name2 { 0, 0 };
    BoardPosition name3 { 3, 4 };
    BoardPosition name4 { 0, 0 };
    BoardPosition name5;

    // // Board Pos testing
    cout << name1;
    cout << "\nEnter a new BoardPosition: ";
    cin >> name5;
    cout << "\nGet Row: " << name5.getRow() << endl;
    cout << "\nGet Col: " << name5.getCol() << endl;
	cout << "\nTesting! " << string(name4) << endl;
    if (name2 == name4) {
        cout << "\nHey, whattaya kno? (0, 0) = (0, 0)\n";
    }

    if (name1 < name3)  {
        cout << "\nHey that < thing works!\n";
    }

    if (name5.InBounds(3))  {
        cout << "\nAyyy, the thing you entered can fit inside a 3x3 box!\n";
    }

    else {
        cout << "\nNah, it doesn't fit in the 3x3 box :(\n";
    }

    if (name5.InBounds(8, 4))   {
        cout << "\nLooks like it fits in the 8x4 rectangle!\n";
    }
    
    else    {
        cout << "\nNah, it don't fit in that 8x4 rectangle sorry fam :(\n";
    }
    // // end board pos testing

    // // Board dir testing
    //BoardDirection dir1 { BoardDirection::CARDINAL_DIRECTIONS[0] };//Go right
    // cout << "\nGet Row Dir: " << dir1.getRowDir() << endl;
    // cout << "\nGet Col Dir: " << dir1.getColDir() << endl;
	int myDir;
	// cin >> myDir;
    BoardPosition newPos = name5 + BoardDirection::CARDINAL_DIRECTIONS[0];
    cout << "From " << name5 << " to " << newPos << " (Going in the right direction)";
    // // end board dir testing
}