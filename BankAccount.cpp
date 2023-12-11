#include "BankAccount.h"

int BankAccount::nextAccountNumber = 1;

// Default constructor
BankAccount::BankAccount() {
    accountNumber = nextAccountNumber++;
    accountHolderName = "John Doe";
    accountBalance = 0.00;
}

// Constructor with parameters
BankAccount::BankAccount(std::string name, double balance) {
    accountNumber = nextAccountNumber++;
    accountHolderName = name;
    accountBalance = balance;
}

double BankAccount::getBalance() const {
    return accountBalance;
}

void BankAccount::displayAccountInfo() const {
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Account Holder: " << accountHolderName << "\n";
    std::cout << "Account Balance: $" << accountBalance << "\n";
}

void BankAccount::deposit(double amount) {
    accountBalance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount > accountBalance) {
        throw std::runtime_error("Insufficient funds");
    }
    accountBalance -= amount;
}
