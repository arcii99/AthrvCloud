//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>

// function to calculate monthly payment
double calculateMonthlyPayment(double loanAmount, double interestRate, int loanTerm) {
    double monthlyInterestRate = interestRate / 1200;
    int numberOfPayments = loanTerm * 12;
    double monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));
    return monthlyPayment;
}

int main() {
    double loanAmount, interestRate, monthlyPayment;
    int loanTerm;

    // get inputs from user
    printf("Enter loan amount: ");
    scanf("%lf", &loanAmount);

    printf("Enter interest rate: ");
    scanf("%lf", &interestRate);

    printf("Enter loan term (in years): ");
    scanf("%d", &loanTerm);

    // calculate monthly payment
    monthlyPayment = calculateMonthlyPayment(loanAmount, interestRate, loanTerm);

    // display result
    printf("\nMonthly payment: $%.2lf\n", monthlyPayment);
    return 0;
}