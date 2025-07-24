//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include <stdio.h>
#include <math.h>

int main(void) {
    double principal, rate, monthlyPayment, totalInterest, term, monthlyRate;
    int numPayments;

    printf("Welcome to the Mortgage Calculator!\n");
    printf("Enter the loan principal:\n");
    scanf("%lf", &principal);

    printf("Enter the interest rate (per year):\n");
    scanf("%lf", &rate);

    printf("Enter the term of the loan in years:\n");
    scanf("%lf", &term);

    monthlyRate = rate / 1200.0;
    numPayments = term * 12;

    monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -numPayments));
    totalInterest = monthlyPayment * numPayments - principal;

    printf("Your monthly payment will be: $%.2lf\n", monthlyPayment);
    printf("Your total interest will be: $%.2lf\n", totalInterest);

    return 0;
}