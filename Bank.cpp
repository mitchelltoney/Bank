#include "Bank.h"
#include "SavingsAccount.h" 
#include <iostream>

Bank::Bank() {}

Bank::~Bank() {
    for (auto account : accounts) {
        delete account;
    }
    accounts.clear();
}

void Bank::addAccount(BankAccount* account) {
    accounts.push_back(account);
}

void Bank::displayAllAccounts() const {
    for (const auto& account : accounts) {
        account->displayAccountInfo();
    }
}

void Bank::performOperations() {
    int inputAccountNumber, choice;
    double amount;

    std::cout << "Enter account number: ";
    std::cin >> inputAccountNumber;

    BankAccount* account = nullptr;
    for (auto acc : accounts) {
        if (acc->getAccountNumber() == inputAccountNumber) {
            account = acc;
            break;
        }
    }

    if (account == nullptr) {
        std::cout << "Invalid account number.\n";
        return;
    }
    
    std::cout << "1. Deposit\n2. Withdraw\nEnter choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            account->deposit(amount);
            break;
        case 2:
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            account->withdraw(amount);
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}

void Bank::addInterestToSavingsAccounts() {
    for (auto account : accounts) {
        SavingsAccount* sAcc = dynamic_cast<SavingsAccount*>(account);
        if (sAcc != nullptr) {
            sAcc->addInterest();
        }
    }
}