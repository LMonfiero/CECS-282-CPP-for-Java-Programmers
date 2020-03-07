#pragma once
#include <iostream>
#include <string>

class BankAccount   {
    private:
        int mAccNum;
        double mBalance;

    public:
        BankAccount(const int& accNum, double balance);

        inline int GetAccNum() const { return mAccNum; }
        inline double GetBalance() const { return mBalance; }

        double GetInterestRate();

        void ApplyInterest();

        bool operator<(BankAccount rhs);

        
};

std::ostream& operator<<(std::ostream& lhs, BankAccount rhs);