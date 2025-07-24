//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: lively
#include <stdio.h>
#include <math.h>

int main() {

    // Welcome message
    printf("Welcome to the Mortgage Calculator!\n\n");

    // Variables declaration
    float loanAmount, interestRate, payment, principal, balance;
    int month = 0, years = 0, numOfPayments;

    // Get loan amount
    printf("Enter the loan amount: $");
    scanf("%f", &loanAmount);

    // Get interest rate
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &interestRate);

    // Get number of years
    printf("Enter the number of years for the loan: ");
    scanf("%d", &years);

    // Calculate number of payments
    numOfPayments = 12 * years;

    // Calculate monthly interest rate
    float monthlyInterestRate = (interestRate / 100) / 12;

    // Calculate payment amount
    payment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numOfPayments));

    // Display results
    printf("\n--------------------------------------------------------------\n");
    printf("Loan Information:\n");
    printf("Loan amount: $%.2f\n", loanAmount);
    printf("Interest rate: %.2f%%\n", interestRate);
    printf("Loan length: %d years\n", years);
    printf("Number of payments: %d\n", numOfPayments);
    printf("Monthly payment: $%.2f\n", payment);
    printf("--------------------------------------------------------------\n");

    // Display payment table
    for (month = 1; month <= numOfPayments; month++)
    {
        // Calculate principal payment
        principal = payment - (loanAmount * monthlyInterestRate);

        // Calculate balance
        balance = loanAmount - principal;

        // Update loan amount
        loanAmount = balance;

        // Display results for each month
        printf("Month: %d\n", month);
        printf("Payment: $%.2f\n", payment);
        printf("Principal: $%.2f\n", principal);
        printf("Interest: $%.2f\n", payment - principal);
        printf("Balance: $%.2f\n", balance);
        printf("--------------------------------------------------------------\n");
    }

    return 0;
}