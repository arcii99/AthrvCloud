//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: immersive
#include <stdio.h>
#include <math.h>

int main() {
    double principalAmount, interestRate, monthlyInterestRate, totalPayment, monthlyPayment;
    int numberOfYears, numberOfPayments;

    // User input
    printf("\nEnter the principal amount: ");
    scanf("%lf", &principalAmount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter the number of years: ");
    scanf("%d", &numberOfYears);

    // Calculations
    monthlyInterestRate = interestRate / 1200;
    numberOfPayments = numberOfYears * 12;
    monthlyPayment = (principalAmount * monthlyInterestRate) /
                      (1 - pow(1 + monthlyInterestRate, -numberOfPayments));
    totalPayment = monthlyPayment * numberOfPayments;

    // Display results
    printf("\nMonthly payment: $%.2lf", monthlyPayment);
    printf("\nTotal payment: $%.2lf\n", totalPayment);

    return 0;
}