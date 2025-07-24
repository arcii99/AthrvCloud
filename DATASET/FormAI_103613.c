//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>

// Function to calculate compound interest
float compound_interest(float principal, float rate, int time_period)
{
    float amount = principal * pow(1 + (rate / 100), time_period);
    float compound_interest = amount - principal;

    return compound_interest;
}

int main()
{
    float principal, rate;
    int time_period;

    printf("Enter the following details:\n");
    printf("Principal Amount: ");
    scanf("%f", &principal);

    printf("Rate of Interest: ");
    scanf("%f", &rate);

    printf("Time Period in years: ");
    scanf("%d", &time_period);

    float simple_interest = (principal * rate * time_period) / 100;
    float compound_int = compound_interest(principal, rate, time_period);

    printf("\nCalculations for Rs.%.2f over %d years at %.2f%% p.a. interest:\n", principal, time_period, rate);
    printf("Simple Interest: Rs.%.2f\n", simple_interest);
    printf("Compound Interest: Rs.%.2f\n\n", compound_int);

    float total_amount = principal + compound_int;

    printf("Total amount after %d years with compound interest: Rs.%.2f\n", time_period, total_amount);

    int no_of_months = time_period * 12;
    float monthly_payment = total_amount / no_of_months;

    printf("Total number of months: %d\n", no_of_months);
    printf("Monthly payment for total amount: Rs.%.2f\n", monthly_payment);

    return 0;
}