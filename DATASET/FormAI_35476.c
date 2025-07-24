//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to calculate monthly payment
double calculateMonthlyPayment(double principal, double rate, int years)
{
    double numerator = principal * (rate / 12.0);
    double denominator = 1.0 - pow(1.0 + (rate / 12.0), -1.0 * years * 12.0);
    return numerator / denominator;
}

int main()
{
    // input variables
    double principal;
    double rate;
    int years;

    // read input from user
    printf("Enter principal amount: ");
    scanf("%lf", &principal);
    printf("Enter interest rate (e.g. 5.5 for 5.5%%): ");
    scanf("%lf", &rate);
    printf("Enter loan duration in years: ");
    scanf("%d", &years);

    // calculate monthly payment
    double monthlyPayment = calculateMonthlyPayment(principal, rate / 100.0, years);

    // print monthly payment
    printf("Monthly payment: $%.2lf\n", monthlyPayment);

    return 0;
}