//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: safe
#include <stdio.h>
#include <math.h>

double calculateMonthlyPayment(double principal, double interestRate, int term);

int main() {
    double principal, interestRate;
    int term;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the interest rate (APR): ");
    scanf("%lf", &interestRate);
    printf("Enter the mortgage term in years: ");
    scanf("%d", &term);

    double monthlyPayment = calculateMonthlyPayment(principal, interestRate, term);
    printf("Your monthly payment: $%.2lf\n", monthlyPayment);

    return 0;
}

double calculateMonthlyPayment(double principal, double interestRate, int term) {
    double monthlyInterestRate = interestRate / 1200;
    int totalPayments = term * 12;
    double numerator = principal * monthlyInterestRate * pow(1 + monthlyInterestRate, totalPayments);
    double denominator = pow(1 + monthlyInterestRate, totalPayments) - 1;
    double monthlyPayment = numerator / denominator;
    return monthlyPayment;
}