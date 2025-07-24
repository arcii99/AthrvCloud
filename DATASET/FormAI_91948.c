//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: random
#include <stdio.h>
#include <math.h>

double calculateMonthlyPayment(double principal, double interest, double years);

int main(void)
{
    double principal, interest, years, monthlyPayment;

    printf("Welcome to Mortgage Calculator!\n");
    printf("Please enter your principal amount: ");
    scanf("%lf", &principal);

    while(principal < 1)
    {
        printf("Invalid input! Please enter a positive number: ");
        scanf("%lf", &principal);
    }

    printf("Great! Now please enter the annual interest rate (as a percentage): ");
    scanf("%lf", &interest);

    while(interest <= 0)
    {
        printf("Invalid input! Please enter a positive number: ");
        scanf("%lf", &interest);
    }

    printf("Wonderful! Now please enter the number of years: ");
    scanf("%lf", &years);

    while(years < 1)
    {
        printf("Invalid input! Please enter a positive number: ");
        scanf("%lf", &years);
    }

    monthlyPayment = calculateMonthlyPayment(principal, interest, years);

    printf("Based on a principal of $%.2lf, an annual interest rate of %.2lf%%, and a term of %.0lf years,\n", principal, interest, years);
    printf("your monthly mortgage payment is: $%.2lf\n", monthlyPayment);

    return 0;
}

double calculateMonthlyPayment(double principal, double interest, double years)
{
    double monthlyInterestRate, monthlyPayment, totalPayments;

    monthlyInterestRate = interest / 1200.0; //monthly interest rate
    totalPayments = years * 12.0; //total number of payments

    monthlyPayment = (principal * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -1 * totalPayments));

    return monthlyPayment;
}