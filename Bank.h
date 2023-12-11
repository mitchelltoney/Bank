#ifndef BANK_H
#define BANK_H

#include <vector>
#include "BankAccount.h"

class Bank {
private:
    std::vector<BankAccount*> accounts;

public:
    Bank();
    ~Bank();
    void addAccount(BankAccount* account);
    void displayAllAccounts() const;
    void performOperations();
    void addInterestToSavingsAccounts();
};

#endif
