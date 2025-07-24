//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: recursive
#include <stdio.h>
#include <math.h>

// Recursive function to calculate the monthly payment
double calculateMonthlyPayment(double loanAmount, double annualInterestRate,
    double numberOfYears, double monthlyPayment, double balanceDue)
{
    if (numberOfYears * 12 == 0) {
        return 0;
    }

    double monthlyInterestRate = annualInterestRate / 12.0;
    double interest = balanceDue * monthlyInterestRate;
    double principal = monthlyPayment - interest;
    double newBalanceDue = balanceDue - principal;

    printf("Month: %d\tBalance Due: $%.2f\tMonthly Payment: $%.2f\n",
        (int)(numberOfYears * 12), balanceDue, monthlyPayment);

    // Recursive call
    return calculateMonthlyPayment(loanAmount, annualInterestRate,
        numberOfYears - (1.0 / 12.0), monthlyPayment,
        newBalanceDue);
}

int main()
{
    double loanAmount, annualInterestRate, monthlyPayment, balanceDue, numberOfYears;

    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter annual interest rate (in percentage): ");
    scanf("%lf", &annualInterestRate);

    printf("Enter number of years: ");
    scanf("%lf", &numberOfYears);

    balanceDue = loanAmount;
    monthlyPayment = loanAmount * (annualInterestRate / 1200.0) /
        (1 - pow(1 + (annualInterestRate / 1200.0), -12.0 * numberOfYears));

    printf("\nLoan Amount: $%.2f\nAnnual Interest Rate: %.2lf%%\nNumber of Years: %.2f\n",
        loanAmount, annualInterestRate, numberOfYears);

    printf("\nMonthly Payment: $%.2f\n\n", monthlyPayment);

    // Recursive call
    calculateMonthlyPayment(loanAmount, annualInterestRate,
        numberOfYears, monthlyPayment, balanceDue);

    return 0;
}