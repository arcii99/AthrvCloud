//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, annual_interest_rate, monthly_interest_rate, monthly_payment, total_paid, total_interest;
    int years, months;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the annual interest rate (in decimal form): ");
    scanf("%f", &annual_interest_rate);

    printf("Enter the length of the loan in years: ");
    scanf("%d", &years);

    printf("Enter the length of the loan in months: ");
    scanf("%d", &months);

    monthly_interest_rate = annual_interest_rate / 12;

    int total_months = years*12 + months;
    float numerator = pow((1 + monthly_interest_rate), total_months) - 1;
    float denominator = monthly_interest_rate * pow((1 + monthly_interest_rate), total_months);
    monthly_payment = principal * (numerator / denominator);

    total_paid = monthly_payment * total_months;
    total_interest = total_paid - principal;

    printf("\nResults:\n");
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Paid: $%.2f\n", total_paid);
    printf("Total Interest: $%.2f\n", total_interest);

    return 0;
}