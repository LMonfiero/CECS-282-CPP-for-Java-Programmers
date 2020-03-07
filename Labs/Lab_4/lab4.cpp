#include "BankAccount.h"
#include <iostream>
using namespace std;

int main()  {
    /*
    Number 1:
        a)  string * : We might return a pointer if we want someone else to be able to mutate our field,
        and they should know the field might sometimes be null
        
        b)  string & : We want to mutate our field and the field will never be null

        c) string : We want to create a copy of the string so that the original is not changed
        or mutated, but want to make changes to said copy

        d) const string & : We don't want anything to change with our string, but we want to
        access it to maybe get a sub string or an index and we've made sure it won't mutate because of const &

    Number 2: 
        a) True

        b) False : Only the == operator has been overloaded. != is still it's own operator

        c) False : member operators must have the lhs be of the same type the class it is in

        d) True

        e) False : the return type of the operator can be changed; though just because you can doesn't mean you should

        f) False : you only need to overload operators relevant to what your class requires, like comparing 3 cards

    Number 3:
        a) a <= b
        Ans: (a < b || a == b)

        b) a != b
        Ans: (a < b || b < a)

        c) a > b
        Ans: (b < a)

        d) a >= b
        Ans: (b < a || b == a)

    */

    BankAccount WellsFargo = BankAccount {8408, 1234.56};
    BankAccount Chase {90630, 29034.32};
    BankAccount ElonMusk {3, 367000};

    cout << "Wells Fargo #" << WellsFargo.GetAccNum() << " Balance: " << WellsFargo << endl;
    cout << "Chase #" << Chase.GetAccNum() << " Balance: " << Chase << endl;
    cout << "Elon Musk #" << ElonMusk.GetAccNum() << " Balance: " << ElonMusk << "\n\n";

    cout << "Interest rate for Wells Fargo: " << WellsFargo.GetInterestRate() << "%\nApplied: ";
    WellsFargo.ApplyInterest();
    cout << WellsFargo << "\n\n";

    cout << "Interest rate for Chase: " << Chase.GetInterestRate() << "%\nApplied: ";
    Chase.ApplyInterest();
    cout << Chase << "\n\n";

    cout << "Interest rate for Elon Musk: " << ElonMusk.GetInterestRate() << "%\nApplied: ";
    ElonMusk.ApplyInterest();
    cout << ElonMusk << "\n\n";

    if (ElonMusk < WellsFargo)  {
        cout << "No it can't be, impossible!"; 
    }
    else {
        cout << "All is in order.";
    }
    cout << endl;
    if (WellsFargo < Chase) {
        cout << "Yeah they robbed Wells Fargo.";
    }
    else {
        cout << "Aha-ha, robbery failed!";
    }


}