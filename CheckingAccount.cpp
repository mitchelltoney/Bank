#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance, double fee)
    : BankAccount(name, balance), overdraftFee(fee) {}

void CheckingAccount::withdraw(double amount) {
    BankAccount::withdraw(amount);
    if (getBalance() < 0) {
        BankAccount::withdraw(overdraftFee);
    }
}
