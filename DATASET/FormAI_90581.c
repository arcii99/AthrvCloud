//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// function to calculate monthly payment
float calculatePayment(float loanAmount, float interestRate, int loanTerm)
{
    float monthlyInterestRate = interestRate / 1200; // converting interest rate to decimal form
    int numPayments = loanTerm * 12; // calculating the number of payments over the loan term
    float monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numPayments)); // formula to calculate monthly payment
    return monthlyPayment;
}

// main function
int main()
{
    float loanAmount, interestRate, monthlyPayment, totalInterestPaid, totalPayments;
    int loanTerm, numPayments;

    // take input from user
    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);
    printf("Enter interest rate (e.g. 5.5): ");
    scanf("%f", &interestRate);
    printf("Enter loan term in years: ");
    scanf("%d", &loanTerm);

    // calculate monthly payment
    monthlyPayment = calculatePayment(loanAmount, interestRate, loanTerm);

    // calculate total payments and total interest paid
    numPayments = loanTerm * 12;
    totalPayments = monthlyPayment * numPayments;
    totalInterestPaid = totalPayments - loanAmount;

    // display the results to the user
    printf("\nHere is your personal finance planner:\n");
    printf("======================================\n");
    printf("Loan amount: $%.2f\n", loanAmount);
    printf("Interest rate: %.2f%%\n", interestRate);
    printf("Loan term: %d year(s)\n", loanTerm);
    printf("Monthly payment: $%.2f\n", monthlyPayment);
    printf("Number of payments: %d\n", numPayments);
    printf("Total payments: $%.2f\n", totalPayments);
    printf("Total interest paid: $%.2f\n", totalInterestPaid);

    return 0;
}