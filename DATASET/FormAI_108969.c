//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set variables for mortgage calculation
    double loanAmount, interestRate, monthlyPayment;
    int loanTerm, numPayments;

    // Get input from user
    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter loan term in years: ");
    scanf("%d", &loanTerm);

    printf("Enter interest rate: ");
    scanf("%lf", &interestRate);

    // Convert interest rate from percentage to decimal
    interestRate /= 100;

    // Calculate number of monthly payments
    numPayments = loanTerm * 12;

    // Calculate monthly payment using formula
    monthlyPayment = (loanAmount * (interestRate / 12)) / (1 - pow(1 + (interestRate / 12), -numPayments));

    // Print output to user
    printf("\nMonthly Payment: $%.2lf\n", monthlyPayment);

    return 0;
}