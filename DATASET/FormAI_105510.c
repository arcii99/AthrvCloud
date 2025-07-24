//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: accurate
// Mortgage Calculator program in C

#include <stdio.h>
#include <math.h>

int main() {
    double loanAmount, interestRate, monthlyPayment; 
    int numYears, numMonths;

    // Get loan amount, interest rate, and number of years
    printf("Enter amount of loan (in dollars): ");
    scanf("%lf", &loanAmount);
    printf("Enter interest rate (in percent, per year): ");
    scanf("%lf", &interestRate);
    printf("Enter number of years: ");
    scanf("%d", &numYears);

    // Calculate monthly interest rate and number of months
    double monthlyInterestRate = (interestRate / 12) / 100;
    numMonths = numYears * 12;

    // Calculate monthly payment using formula
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numMonths));

    // Print results
    printf("\nLoan amount: $%.2lf\n", loanAmount);
    printf("Interest rate: %.2lf%% per year\n", interestRate);
    printf("Number of years: %d\n", numYears);
    printf("Monthly payment: $%.2lf\n", monthlyPayment);

    return 0;
}