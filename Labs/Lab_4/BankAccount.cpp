#include "BankAccount.h"
using namespace std;

//default constructor for bank account
BankAccount::BankAccount(const int& accNum, double balance) 
    : mAccNum(accNum), mBalance(balance) {
}

//Returns an interest rate based on balance
double BankAccount::GetInterestRate()   {
    if (mBalance < 10000)   {
        return .001;
    }

    else if (mBalance >= 10000 && mBalance <= 100000)   {
        return .003;
    }

    else if (mBalance > 100000) {
        return .005;
    }

    //Shouldn't go here
    return 0;
}

//Applies the interest rate to the balance
void BankAccount::ApplyInterest() {
    double interest = GetInterestRate() * mBalance; 
    mBalance += interest;
}

//If true: lhs is less than rhs
//if false: lhs is larger than rhs
bool BankAccount::operator<(BankAccount rhs) {
    return mBalance < rhs.mBalance;
}



std::ostream& operator<<(std::ostream& lhs, BankAccount rhs)    {
    string separator = to_string(rhs.GetBalance());
    lhs << '$' << separator;
    return lhs;
}