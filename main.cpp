#include <iostream>
using namespace std;

class bankAccount {
private:
    int accountNumber;

protected:
    float balance;

public:
    bankAccount() {
        balance = 0.0f;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Your new balance is R " << balance << endl;
    }

    void withdraw(float amount) {
        float fee = 10.0f;
        if (amount + fee > balance) {
            cout << "Insufficient funds (incl. fee)." << endl;
        } else {
            balance -= (amount + fee);
            cout << "R " << amount << " withdrawn with R " << fee << " fee." << endl;
        }
    }

    void getBalance() {
        cout << "Account Balance: R " << balance << endl;
    }
};

class savingAccount : public bankAccount {
private:
    float interest;

public:
    savingAccount(float initialBalance, float rate) : interest(rate) {
        balance = initialBalance;
    }

    void applyInterest() {
        balance += (balance * interest / 100);
    }

    void projectGrowth(int months) {
        float tempBalance = balance;
        for (int i = 0; i < months; ++i) {
            tempBalance += (tempBalance * interest / 100);
        }
        cout << "Projected balance after " << months << " months: R " << tempBalance << endl;
    }

    void showBalance() {
        cout << "Savings Account Balance: R " << balance << endl;
    }
};

int main() {
    savingAccount mySavings(5000.0f, 5.0f);
    int choice;
    float amount;
    int months;

    do {
        cout << "\n=== Savings Account Menu ===" << endl;
        cout << "1. Deposit\n2. Withdraw\n3. Show Balance\n4. Apply Interest\n5. Project Growth\n0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                mySavings.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                mySavings.withdraw(amount);
                break;
            case 3:
                mySavings.showBalance();
                break;
            case 4:
                mySavings.applyInterest();
                cout << "Interest applied.\n";
                break;
            case 5:
                cout << "Enter number of months: ";
                cin >> months;
                mySavings.projectGrowth(months);
                break;
            case 0:
                cout << "Thank you for banking with Nova Bank. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}