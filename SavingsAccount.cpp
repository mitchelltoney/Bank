#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance, double rate)
    : BankAccount(name, balance), interestRate(rate) {}

void SavingsAccount::addInterest() {
    double interest = getBalance() * interestRate / 100;
    deposit(interest);
}
