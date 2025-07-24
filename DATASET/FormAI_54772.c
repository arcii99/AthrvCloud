//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to calculate the monthly payment */
double calculateMonthlyPayment(double loanAmount, double interestRate, int termInYears)
{
    double monthlyRate = interestRate / 1200;
    int numOfPayments = termInYears * 12;
    double monthlyPayment = loanAmount * monthlyRate / (1 - pow(1 + monthlyRate, -numOfPayments));

    return monthlyPayment;
}

/* Function to display the loan summary */
void displayLoanSummary(double loanAmount, double interestRate, int termInYears, double monthlyPayment)
{
    printf("\n-------------------------------------------\n");
    printf("           Mortgage Loan Summary            \n");
    printf("-------------------------------------------\n");
    printf("Loan Amount: $%.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Loan Term: %d years\n", termInYears);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", monthlyPayment * termInYears * 12);
    printf("-------------------------------------------\n");
}

int main()
{
    double loanAmount, interestRate, monthlyPayment;
    int termInYears;

    /* Input loan amount, interest rate and term in years */
    printf("Enter Loan Amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter Interest Rate: ");
    scanf("%lf", &interestRate);

    printf("Enter Loan Term (in years): ");
    scanf("%d", &termInYears);

    /* Calculate monthly payment */
    monthlyPayment = calculateMonthlyPayment(loanAmount, interestRate, termInYears);

    /* Display loan summary */
    displayLoanSummary(loanAmount, interestRate, termInYears, monthlyPayment);

    return 0;
}