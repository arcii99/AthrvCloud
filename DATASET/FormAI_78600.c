//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include <stdio.h>
#include <math.h>

#define MONTHS_IN_YEAR 12

double calculateMonthlyPayment(int principal, float annualInterestRate, int years) {
    int numberOfPayments = years * MONTHS_IN_YEAR;
    float monthlyInterestRate = annualInterestRate / MONTHS_IN_YEAR;

    double monthlyPayment = principal * (monthlyInterestRate * pow(1 + monthlyInterestRate, numberOfPayments)) /
                                (pow(1 + monthlyInterestRate, numberOfPayments) - 1);

    return monthlyPayment;
}

int main() {
    int principal;
    float annualInterestRate;
    int years;

    printf("Enter loan amount: ");
    scanf("%d", &principal);

    printf("Enter annual interest rate: ");
    scanf("%f", &annualInterestRate);

    printf("Enter loan term in years: ");
    scanf("%d", &years);

    double monthlyPayment = calculateMonthlyPayment(principal, annualInterestRate, years);

    printf("Monthly Payment: %.2lf", monthlyPayment);

    return 0;
}