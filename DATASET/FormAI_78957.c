//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double principal, rate, term, monthly_payment;
    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Please enter the annual interest rate: ");
    scanf("%lf", &rate);
    printf("Please enter the term in years: ");
    scanf("%lf", &term);

    double r = rate / 12 / 100;
    double n = term * 12;

    monthly_payment = (principal * r * pow((1 + r), n)) / (pow((1 + r), n) - 1);

    printf("\nMonthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Payment: $%.2lf\n", monthly_payment * n);
    printf("Total Interest: $%.2lf\n", (monthly_payment * n) - principal);

    return 0;
}