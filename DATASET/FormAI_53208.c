//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: invasive
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Welcome to the Mortgage Calculator\n");

    // Input variables
    double loanAmount, interestRate;
    int term;

    // Get input from user
    printf("Enter the loan amount: $");
    scanf("%lf", &loanAmount);
    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);
    printf("Enter the term (in years): ");
    scanf("%d", &term);

    // Calculate Monthly Interest Rate
    double monthlyInterestRate = ((interestRate / 100) / 12);

    // Calculate Number of Payments
    int numberOfPayments = term * 12;

    // Calculate Monthly Payment
    double monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));

    // Calculate Total Payment
    double totalPayment = monthlyPayment * numberOfPayments;

    // Display results
    printf("\n");
    printf("Loan Amount: $%.2lf\n", loanAmount);
    printf("Interest Rate: %.2lf%%\n", interestRate);
    printf("Term: %d years\n", term);
    printf("\n");
    printf("Monthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Payment: $%.2lf\n", totalPayment);

    return 0;
}