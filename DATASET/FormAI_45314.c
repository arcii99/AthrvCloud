//FormAI DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>

/* Structure definition for a customer account */
typedef struct {
    int accountNumber;      // Bank account number
    char accountType;       // Checking 'c' or savings 's'
    double balance;         // Account balance
} Account;

/* Function prototype for adding a new transaction */
void addTransaction(Account *acctPtr, double amount);

int main() {
    // Declare accounts for two customers
    Account customer1 = {1, 'c', 500.00};
    Account customer2 = {2, 's', 1000.00};

    // Add some transactions to the accounts
    addTransaction(&customer1, -250.00);
    addTransaction(&customer1, 75.00);
    addTransaction(&customer2, -500.00);
    addTransaction(&customer2, 100.00);
    addTransaction(&customer2, -50.00);

    // Display the account status for both customers
    printf("Customer 1:\nAccount Number: %d\nAccount Type: %c\nBalance: %.2lf\n\n",
           customer1.accountNumber, customer1.accountType, customer1.balance);
    printf("Customer 2:\nAccount Number: %d\nAccount Type: %c\nBalance: %.2lf\n",
           customer2.accountNumber, customer2.accountType, customer2.balance);

    return 0;
}

/* Function definition for adding a new transaction */
void addTransaction(Account *acctPtr, double amount) {
    // Ignore negative transaction amounts for savings accounts
    if (acctPtr->accountType == 's' && amount < 0) {
        printf("Warning: Savings accounts do not allow negative balances.\n");
        return;
    }

    // Update the balance
    acctPtr->balance += amount;
}