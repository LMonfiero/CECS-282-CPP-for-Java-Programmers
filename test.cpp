#include <iostream>
#include <string>
using namespace std;

void functionA(Complex param1, Complex*param2)  {
    // see part(b)
}

int main()  {
    cout << "Louis Monfiero\n";
    string a = "Yeet";
    string &b = a;
    delete &b;
    cout << b;
    //cout << a;
}