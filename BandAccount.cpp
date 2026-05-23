/*Bank Accounts
This program should be designed and written by a team of students. Here are some suggestions:
• One or more students may work on a single class.
• The requirements of the program should be analyzed so that each student is given about the same work load.
• The parameters and return types of each function and class member function should be decided in advance.
• The program will be best implemented as a multi-file program.
Design a generic class to hold the following information about a bank account:
• Balance
• Number of deposits this month
• Number of withdrawals
• Annual interest rate
• Monthly service charges
The class should have the following member functions:

constructor:

Accepts arguments for the balance and annual interest rate.

deposit:

A virtual function that accepts an argument for the amount of the deposit. The function should add the argument to the account balance. It should also increment the variable holding the number of deposits.

withdraw:

A virtual function that accepts an argument for the amount of the withdrawal. The function should subtract the argument from the balance. It should also increment the variable holding the number of ­withdrawals.

calcInt:

A virtual function that updates the balance by calculating the monthly interest earned by the account, and adding this interest to the balance. This is performed by the following formulas:


Monthly Interest Rate = (Annual Interest Rate / 12

  Monthly Interest = Balance * Monthly Interest Rate

            Balance = Balance + Monthly Interest

monthlyProc:

A virtual function that subtracts the monthly service charges from the balance, calls the calcInt function, then sets the variables that hold the number of withdrawals, number of deposits, and monthly service charges to zero.



Next, design a savings account class, derived from the generic account class. The savings account class should have the following
additional member:
status (to represent an active or inactive account)
If the balance of a savings account falls below $25, it becomes inactive. (The status member could be a flag variable.) No more withdrawals may be made until the balance is raised above $25, at which time the account becomes active again. The savings account class should have the following member functions:

ithdraw:

Before the base class function is called, this function will determine if a withdrawal (a check written) will cause the balance to go below $0. If the balance goes below $0, a service charge of $15 will be taken from the account. (The withdrawal will not be made.) If there isn’t enough in the account to pay the service charge, the balance will become negative and the customer will owe the negative amount to the bank.

monthlyProc:

Before the base class function is called, this function adds the monthly fee of $5 plus $0.10 per withdrawal (check written) to the base class variable that holds the monthly service charges.


Next, design a checking account class, also derived from the generic account class. It should have the following member functions:

withdraw:

A function that checks to see if the account is inactive before a withdrawal is made. (No withdrawal will be allowed if the account is not active.) A withdrawal is then made by calling the base class version of the function.

deposit:

A function that checks to see if the account is inactive before a deposit is made. If the account is inactive and the deposit brings the balance above $25, the account becomes active again. The deposit is then made by calling the base class version of the function.

monthlyProc:

Before the base class function is called, this function checks the number of withdrawals. If the number of withdrawals for the month is more than 4, a service charge of $1 for each withdrawal above 4 is added to the base class variable that holds the monthly service charges. (Don’t forget to check the account balance after the service charge is taken. If the balance falls below $25, the account becomes inactive.)

Write a complete program that demonstrates these classes by asking the user to enter the amounts of deposits and withdrawals for a savings account and checking account. The program should display statistics for the month, including beginning balance, total amount of deposits, total amount of withdrawals, service charges, and ending balance.*/
#include <iostream>
#include <iomanip>
using namespace std;

class GenericAccount
{
protected:
    double balance;
    double annualInterestRate;
    double monthlyServiceCharges;

    int numDeposits;
    int numWithdrawals;

    double totalDeposits;
    double totalWithdrawals;

    double beginningBalance;

public:
    GenericAccount(double bal = 0, double rate = 0)
    {
        balance = bal;
        annualInterestRate = rate;
        monthlyServiceCharges = 0;

        numDeposits = 0;
        numWithdrawals = 0;

        totalDeposits = 0;
        totalWithdrawals = 0;

        beginningBalance = bal;
    }

    virtual void deposit(double amount)
    {
        balance += amount;

        numDeposits++;
        totalDeposits += amount;
    }

    virtual void withdraw(double amount)
    {
        balance -= amount;

        numWithdrawals++;
        totalWithdrawals += amount;
    }

    virtual void calcInt()
    {
        double monthlyRate = annualInterestRate / 1200.0;

        double monthlyInterest = balance * monthlyRate;

        balance += monthlyInterest;
    }

    virtual void monthlyProc()
    {
        balance -= monthlyServiceCharges;

        calcInt();

        monthlyServiceCharges = 0;
        numDeposits = 0;
        numWithdrawals = 0;
    }

    void displayStatistics()
    {
        cout << fixed << setprecision(2);

        cout << "\n----- MONTHLY REPORT -----\n";

        cout << "Beginning Balance: $"
             << beginningBalance << endl;

        cout << "Total Deposits: $"
             << totalDeposits << endl;

        cout << "Total Withdrawals: $"
             << totalWithdrawals << endl;

        cout << "Service Charges: $"
             << monthlyServiceCharges << endl;

        cout << "Ending Balance: $"
             << balance << endl;
    }

    double getBalance()
    {
        return balance;
    }
};

class SavingsAccount : public GenericAccount
{
private:
    bool status;

public:
    SavingsAccount(double bal, double rate)
        : GenericAccount(bal, rate)
    {
        status = (balance >= 25);
    }

    void withdraw(double amount) override
    {
        if (!status)
        {
            cout << "Account inactive. Withdrawal denied.\n";
            return;
        }

        GenericAccount::withdraw(amount);

        if (balance < 25)
            status = false;
    }

    void deposit(double amount) override
    {
        GenericAccount::deposit(amount);

        if (balance >= 25)
            status = true;
    }

    void monthlyProc() override
    {
        if (numWithdrawals > 4)
        {
            monthlyServiceCharges +=
                (numWithdrawals - 4);
        }

        GenericAccount::monthlyProc();

        if (balance < 25)
            status = false;
        else
            status = true;
    }
};

class CheckingAccount : public GenericAccount
{
private:
    const double OVERDRAFT_FEE = 15;

public:
    CheckingAccount(double bal, double rate)
        : GenericAccount(bal, rate)
    {
    }

    void withdraw(double amount) override
    {
        if (amount > balance)
        {
            cout << "Insufficient funds.\n";
            cout << "$15 overdraft fee charged.\n";

            balance -= OVERDRAFT_FEE;

            monthlyServiceCharges += OVERDRAFT_FEE;

            return;
        }

        GenericAccount::withdraw(amount);
    }

    void monthlyProc() override
    {
        monthlyServiceCharges +=
            5 + (numWithdrawals * 0.10);

        GenericAccount::monthlyProc();
    }
};

int main()
{
    double balance;
    double rate;

    cout << "Enter initial balance: ";
    cin >> balance;

    cout << "Enter annual interest rate (%): ";
    cin >> rate;

    SavingsAccount savings(balance, rate);
    CheckingAccount checking(balance, rate);

    int choice;

    do
    {
        cout << "\n1. Deposit into Savings\n";
        cout << "2. Withdraw from Savings\n";
        cout << "3. Deposit into Checking\n";
        cout << "4. Withdraw from Checking\n";
        cout << "5. End Month\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        double amount;

        switch (choice)
        {
        case 1:
            cout << "Amount: ";
            cin >> amount;

            savings.deposit(amount);
            break;

        case 2:
            cout << "Amount: ";
            cin >> amount;

            savings.withdraw(amount);
            break;

        case 3:
            cout << "Amount: ";
            cin >> amount;

            checking.deposit(amount);
            break;

        case 4:
            cout << "Amount: ";
            cin >> amount;

            checking.withdraw(amount);
            break;

        case 5:
            savings.monthlyProc();
            checking.monthlyProc();

            cout << "\nSAVINGS ACCOUNT";
            savings.displayStatistics();

            cout << "\nCHECKING ACCOUNT";
            checking.displayStatistics();

            break;
        }

    } while (choice != 0);

    return 0;
}