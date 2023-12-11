#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <stdexcept>

class BankAccount {
private:
    static int nextAccountNumber;
    int accountNumber;
    std::string accountHolderName;
    double accountBalance;

public:
    BankAccount();
    BankAccount(std::string name, double balance);

    double getBalance() const;
    void displayAccountInfo() const;
    void deposit(double amount);
    void withdraw(double amount);
};

#endif
