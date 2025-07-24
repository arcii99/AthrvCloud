//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double principal, interest_rate, monthly_rate;
    int num_years, num_months, total_months;
    double monthly_payment, total_payment, total_interest;

    printf("Mortgage Payment Calculator\n");
    printf("**************************\n");

    printf("Enter the principal amount (in $): ");
    scanf("%lf", &principal);

    printf("Enter the interest rate (in %%): ");
    scanf("%lf", &interest_rate);

    printf("Enter the number of years: ");
    scanf("%d", &num_years);

    num_months = num_years * 12;
    monthly_rate = interest_rate / 1200.0;
    total_months = num_months;

    /* Calculate the monthly payment */
    monthly_payment = (principal * monthly_rate) / (1.0 - pow(1.0 + monthly_rate, -total_months));

    /* Calculate the total payment and total interest */
    total_payment = monthly_payment * total_months;
    total_interest = total_payment - principal;

    printf("\n");
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total payment: $%.2f\n", total_payment);
    printf("Total interest: $%.2f\n", total_interest);

    return 0;
}