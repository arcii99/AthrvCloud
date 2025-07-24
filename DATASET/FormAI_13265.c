//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure for savings account
struct SavingsAccount {
    double balance;
    double interestRate;
};

// Define structure for credit card account
struct CreditCardAccount {
    double balance;
    double interestRate;
    bool inDebt;
};

// Function to calculate interest for savings account
double calculateSavingsInterest(struct SavingsAccount acc) {
    return acc.balance * acc.interestRate;
}

// Function to calculate interest for credit card account
double calculateCreditCardInterest(struct CreditCardAccount acc) {
    if (acc.inDebt) {
        return acc.balance * acc.interestRate;
    } else {
        return 0;
    }
}

int main() {

    // Define and initialize savings account
    struct SavingsAccount savingsAcc = {10000.00, 0.05};

    // Define and initialize credit card account
    struct CreditCardAccount creditCardAcc = {5000.00, 0.18, true};

    // Calculate and print interest for savings account
    double savingsInterest = calculateSavingsInterest(savingsAcc);
    printf("Interest earned from savings account: %.2lf\n", savingsInterest);

    // Calculate and print interest for credit card account
    double creditCardInterest = calculateCreditCardInterest(creditCardAcc);
    printf("Interest charged on credit card account: %.2lf\n", creditCardInterest);

    // Update account balances
    savingsAcc.balance += savingsInterest;
    creditCardAcc.balance += creditCardInterest;

    // Print updated account balances
    printf("New savings account balance: %.2lf\n", savingsAcc.balance);
    printf("New credit card account balance: %.2lf\n", creditCardAcc.balance);

    return 0;
}