//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include<stdio.h>

// function to calculate monthly mortgage payment
double calculateMortgagePayment(double loanAmount, double interestRate, int loanTermYears)
{
    double monthlyInterestRate = interestRate / 1200; // divide by 12 months and 100%
    int loanTermMonths = loanTermYears * 12; // convert loan term to months

    double mortgagePayment = loanAmount * monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -loanTermMonths));

    return mortgagePayment;
}

int main()
{
    double loanAmount, interestRate;
    int loanTermYears;

    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter the loan term in years: ");
    scanf("%d", &loanTermYears);

    double mortgagePayment = calculateMortgagePayment(loanAmount, interestRate, loanTermYears);

    printf("\nYour monthly mortgage payment is: $%.2lf\n", mortgagePayment);

    return 0;
}