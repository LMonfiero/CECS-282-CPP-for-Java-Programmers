#include <iostream>
using namespace std;

int main()  {
    /*Number 1:
    // a = 1
    // b = 2
    // c points to a new boardposition in dynamic memory
    // up creates a unique pointer to a new board position
    a) 4 Board positions are constructed
    b) a (automatic), b (automatic), and up are destroyed (3)
    c) No. It's a pointer to a boardposition object
    */
    /*Number 2:
    a) T
    b) T
    c) T
    d) F
    e) F
    f) F
    */
    /*Number 3:
    const Deck& is saying it will return a const reference to Deck - object returned cannot be mutated
    const Deck &parameter is saying that our parameter is a const reference passed to/to be used in the function
    DoSomething() const is saying we won't be mutating other members in the class 
    */
    /*Number 4:
    a) F* but you do need it if you're going to be allocating anything to dynamic memory
    b) T* but it's not a deep copy (They'll be pointing to the same nodes in dynamic memory if it is used with dynamic memory)
    c) T* only if you do it right lol
    d) F* it's pretty difficult and you need to be a very responsible coder if you want to use it correctly** 
    */
}