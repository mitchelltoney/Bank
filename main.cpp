#include <iostream>
#include <limits>
#include "BankAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main() {
    std::string name;
    double initialBalance, interestRate, overdraftFee;
    int accountType;

    std::cout << "Select account type:\n";
    std::cout << "1. Bank Account\n2. Savings Account\n3. Checking Account\n";
    std::cin >> accountType;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

    std::cout << "Enter account holder's name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter initial account balance: ";
    std::cin >> initialBalance;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

    // Create account based on type
    BankAccount *account;
    switch (accountType) {
        case 1:
            account = new BankAccount(name, initialBalance);
            break;
        case 2:
            std::cout << "Enter interest rate (as a percentage): ";
            std::cin >> interestRate;
            account = new SavingsAccount(name, initialBalance, interestRate);
            break;
        case 3:
            std::cout << "Enter overdraft fee: ";
            std::cin >> overdraftFee;
            account = new CheckingAccount(name, initialBalance, overdraftFee);
            break;
        default:
            std::cout << "Invalid account type selected. Exiting...\n";
            return 1;
    }

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display account information\n";
        std::cout << "2. Deposit funds\n";
        std::cout << "3. Withdraw funds\n";
        std::cout << "4. Add Interest (Only for Savings Account)\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                account->displayAccountInfo();
                break;
            case 2: {
                double depositAmount;
                std::cout << "Enter deposit amount: ";
                std::cin >> depositAmount;
                account->deposit(depositAmount);
                break;
            }
            case 3: {
                double withdrawAmount;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> withdrawAmount;
                try {
                    account->withdraw(withdrawAmount);
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 4:
                if (accountType == 2) {
                    static_cast<SavingsAccount*>(account)->addInterest();
                    std::cout << "Interest added.\n";
                } else {
                    std::cout << "This option is only available for Savings Accounts.\n";
                }
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    delete account;
    return 0;
}
