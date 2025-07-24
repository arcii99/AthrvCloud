//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <math.h>

// Calculate monthly mortgage payment
double calculateMonthlyPayment(double principal, double interestRate, int months) {
    double monthlyInterestRate = interestRate / 1200;
    double result = (principal * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -months));
    return result;
}

int main() {
    double principal, interestRate;
    int years;

    // Get user input for loan details
    printf("Enter loan principal: ");
    scanf("%lf", &principal);

    printf("Enter annual interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    // Calculate monthly payment
    double monthlyPayment = calculateMonthlyPayment(principal, interestRate, years * 12);

    // Print results
    printf("\n");
    printf("Loan Details\n");
    printf("============\n");
    printf("Loan Principal:\t$%.2lf\n", principal);
    printf("Interest Rate:\t%.2lf%%\n", interestRate);
    printf("Loan Term:\t%d years\n", years);
    printf("Monthly Payment:$%.2lf\n", monthlyPayment);
    printf("Total Payment:\t$%.2lf\n", monthlyPayment * years * 12);
    
    return 0;
}