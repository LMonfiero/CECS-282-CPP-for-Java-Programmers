#include <iostream>
using namespace std;

/*
Lab 2
Louis Monfiero
*/

void Funk(int);
int RoundToNearest(double);
void frag();
void test(int);

/*int main()  {
    //call Funk #49
    Funk(49);
    //Will not resolve compile time error unless the function
    //Funk() is defined before it is used
    //Resolution: Either place function above main (eww) or 
    //Create a function prototype above main to let the compiler know
    //that it will be exist somewhere in this code.

}*/

void Funk(int f)    {
    f = f * 2;
}

int RoundToNearest(double positiveDub)  {
    return positiveDub + .5;
}

/*
#3
a) Compiler looks for iostream in C:\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++
or wherever the library would be located on your computer
b) It is looking for the file doors.h in C:\AdaProjects\Question3
c) Compiler looks for doors.h in the same directory as the source code
d) Put doors.h in the same directory as your source code(?)
*/

void test(int x)    {//x is created and added to auto Storage
    int a = x;//a is created and stored
    if (a > 0)  {
        int b = a;//b is created and stored
        b++;
    }//b is removed here
}//a is removed then x

int main()  {
    int x = 100;//x is created and stored
    test(x);  
    int y = 8;//y is created and stored
    frag();
}// y is removed then x
/*
#4)
x in main is created and stored
main calls the function test and passes x (from main)
x (from test()) is created and stored
a is created and stored
in the if(), b is then created and stored
b is removed at the end of if()
at the end of test() a is removed and then x is removed
int y is then created 
at the end of the code, y is removed then x
*/

void frag() {
    int a = 9;
    int b = a;
    b++;
    int *c = &a;
    int *d = c;
    int e = *c;
}
