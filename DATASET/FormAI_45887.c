//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: rigorous
#include <stdio.h>

int main() {
    float loanAmount, annualInterestRate, monthlyInterestRate, monthlyPayment, balance;
    int numberOfPayments, count;
    
    // User Input
    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);
    printf("Enter the annual interest rate: ");
    scanf("%f", &annualInterestRate);
    printf("Enter the number of payments: ");
    scanf("%d", &numberOfPayments);
    
    // Calculation
    monthlyInterestRate = annualInterestRate / 1200;
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));
    balance = loanAmount;
    
    // Output
    printf("\nLoan Amount: $%.2f\n", loanAmount);
    printf("Annual Interest Rate: %.2f%%\n", annualInterestRate);
    printf("Number of Payments: %d\n", numberOfPayments);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("\nPayment Schedule\n----------------\n");
    for (count = 1; count <= numberOfPayments; count++) {
        float interestPaid = balance * monthlyInterestRate;
        float principalPaid = monthlyPayment - interestPaid;
        balance -= principalPaid;
        printf("Payment %d: $%.2f\n", count, monthlyPayment);
        printf("    Interest Paid: $%.2f\n", interestPaid);
        printf("    Principal Paid: $%.2f\n", principalPaid);
        printf("    Balance: $%.2f\n", balance);
    }
    
    return 0;
}