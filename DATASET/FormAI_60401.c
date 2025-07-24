//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: standalone
#include <stdio.h>
#include <math.h>

int main()
{
    // Declaring variables
    double loanAmount, annualInterestRate, monthlyInterestRate, monthlyPayment;
    int loanTerm, numPayments;

    // Taking user input
    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter the annual interest rate (in percentage): ");
    scanf("%lf", &annualInterestRate);

    printf("Enter the loan term (in years): ");
    scanf("%d", &loanTerm);

    // Converting annual interest rate to monthly rate
    monthlyInterestRate = annualInterestRate / 1200;

    // Calculating number of payments
    numPayments = loanTerm * 12;

    // Calculating monthly payment
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numPayments));

    // Displaying the result
    printf("\nLoan Amount: $%.2f\n", loanAmount);
    printf("Annual Interest Rate: %.2f%%\n", annualInterestRate);
    printf("Loan Term: %d years\n", loanTerm);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);

    return 0;
}