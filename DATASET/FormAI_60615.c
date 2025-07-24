//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include <stdio.h>

int main() {
    double loanAmount, interestRate, monthlyPayment;
    int numYears;

    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter number of years: ");
    scanf("%d", &numYears);

    // Calculates the monthly interest rate
    double monthlyInterestRate = interestRate / 1200;

    // Calculates the number of months the loan will be for
    int numMonths = numYears * 12;

    // Calculates the monthly payment
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numMonths));

    printf("\nLoan amount: $%.2lf", loanAmount);
    printf("\nInterest rate: %.2lf%%", interestRate);
    printf("\nNumber of years: %d", numYears);
    printf("\nMonthly payment: $%.2lf", monthlyPayment);

    return 0;
}