#include <iostream>
#include <string>

class BankAccount {
private:
    static int nextAccountNumber;
    int accountNumber;
    std::string accountHolderName;
    double accountBalance;

public:
    // default (wont be used since inputs are required)
    BankAccount() {
        accountNumber = nextAccountNumber++;
        accountHolderName = "John Doe";
        accountBalance = 0.00;
    }

    // with inputs
    BankAccount(std::string name, double balance) {
        accountNumber = nextAccountNumber++;
        accountHolderName = name;
        accountBalance = balance;
    }

    double getBalance() const {
        return accountBalance;
    }

    void displayAccountInfo() const {
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Account Holder: " << accountHolderName << "\n";
        std::cout << "Account Balance: $" << accountBalance << "\n";
    }

    void deposit(double amount) {
        accountBalance += amount;
    }

    void withdraw(double amount) {
        if (amount > accountBalance) {
            throw std::runtime_error("Insufficient funds");
        }
        accountBalance -= amount;
    }

};

int BankAccount::nextAccountNumber = 1;

int main() {
    std::string name;
    double initialBalance;

    std::cout << "Enter account holder's name: ";
    std::getline(std::cin, name);
    std::cout << "Enter initial account balance: ";
    while (!(std::cin >> initialBalance)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to fix entering input twice
        std::cout << "Invalid. Enter a number.\n";
    }

    BankAccount account(name, initialBalance);

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display account information\n";
        std::cout << "2. Deposit funds\n";
        std::cout << "3. Withdraw funds\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        while (!(std::cin >> choice)) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cout << "Enter your choice: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to fix entering input twice

        switch (choice) {
            case 1:
                account.displayAccountInfo();
                break;
            case 2:
                double depositAmount;
                std::cout << "Enter deposit amount: ";
                std::cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            case 3:
                double withdrawAmount;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> withdrawAmount;
                try {
                    account.withdraw(withdrawAmount);
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                std::cout << choice << std::endl;
                std::cin.clear();
                std::cin >> choice;
                break;
        }
    } while (choice != 4);

    return 0;
}