#include <iostream>
#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main() {
    Bank bank;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a new account\n";
        std::cout << "2. Display all accounts\n";
        std::cout << "3. Perform operations on accounts\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                double balance;
                int accountType;

                std::cout << "Enter account holder's name: ";
                std::cin >> name;

                std::cout << "Enter initial balance: ";
                std::cin >> balance;

                std::cout << "Account Type (1 for Savings, 2 for Checking): ";
                std::cin >> accountType;

                if (accountType == 1) {
                    double interestRate;
                    std::cout << "Enter interest rate: ";
                    std::cin >> interestRate;
                    bank.addAccount(new SavingsAccount(name, balance, interestRate));
                } else if (accountType == 2) {
                    double overdraftFee;
                    std::cout << "Enter overdraft fee: ";
                    std::cin >> overdraftFee;
                    bank.addAccount(new CheckingAccount(name, balance, overdraftFee));
                } else {
                    std::cout << "Invalid account type.\n";
                }
                break;
            }
            case 2:
                bank.displayAllAccounts();
                break;
            case 3:
                bank.performOperations();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    // automatically adding interest when exiting
    bank.addInterestToSavingsAccounts();

    return 0;
}
